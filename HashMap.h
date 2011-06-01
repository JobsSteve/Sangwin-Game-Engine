#ifndef HASHMAP_H
#define	HASHMAP_H


////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//                                 DEFINITION                                 //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

#include <string.h>

#include "LinkedList.h"
#include "ArrayList.h"

/**
 * Simple HashMap class. This implementation uses the separate chaining
 * algorithm for handling collisions. Keys can only be char arrays, and must be
 * null terminated. String literals are expected. Hashing is calculated based on
 *  the characters in the string.
 *
 * HashMap is best used with SPtrs, see ArrayList documentation for more details
 *
 * @see ArrayList
 * @see LinkedList
 * 
 * @author Ben Constable
 * @version 1.0
 *
 * @ingroup Utilities
 */
template<class T>
class HashMap: public Object {

private:

    /**
     * This class represents a basic key value pair, based on a string key.
     *
     * @author Ben Constable
     * @version 1.0
     *
     * @ingroup Utilities
     */
    template<class V>
    class KeyValuePair {

    public:

        const char* key; ///< key
        V value; ///< value

        /**
         * Default constructor. Key is " " and value is a default of they type
         * of this pair.
         */
        KeyValuePair()
        :key(" "),
         value(V())
        {}
        /**
         * Constructor that takes a key and value association.
         *
         * @param cKey key
         * @param cValue associated value
         */
        KeyValuePair(const char* cKey,V cValue)
        :key(cKey),
         value(cValue)
        {}
        /**
         * Assignment operator. Copies key to copy of this value.
         *
         * @param rhs KeyValuePair to copy from
         * @return this
         */
        KeyValuePair& operator=(const KeyValuePair& rhs) {

            key = rhs.key;
            value = rhs.value;

            return *this;
        }
        /**
         * Destructor.
         */
        ~KeyValuePair() {}
    };
    
    LinkedList<KeyValuePair<T> >* pairs; ///< Array of LinkedLists containing key value pairs.
    int load; ///< current number of elements in the map.
    int capacity; ///< capacity i.e number of individual hash positions
    T NULLREFERENCE; ///< empty type, returned on error

    /**
     * Hash function. Calculates hash based on characters in key.
     *
     * @param key string key
     * @return hash
     */
    int hash(const char* key);
    
public:

    /**
     * Default constructor. Capacity is 21.
     */
    HashMap();
    /**
     * Copying is not supported.
     *
     * @param rhs
     */
    HashMap(const HashMap& rhs);
    /**
     * Copying is not supported.
     *
     * @param rhs
     * @return
     */
    HashMap& operator=(const HashMap& rhs);
    /**
     * Destructor.
     */
    ~HashMap();

    /**
     * Check if this HashMap contains the given key.
     *
     * @param key key to check for
     * @return true if key is used in this map, false if not
     */
    bool containsKey(const char* key);
    /**
     * Check if this HashMap contains the given value. Equality operator must be
     * defined for the type stored in this map.
     *
     * @param value value to check for.
     * @return true if value is in this map, false if not
     */
    bool containsValue(T value);
    /**
     * Retrieve the value associated with the given key from this map.
     *
     * @param key key
     * @return value
     */
    T& get(const char* key);
    /**
     * Put the value into this map based on the given key.
     *
     * @param key
     * @param value
     */
    void put(const char* key, T value);
    /**
     * Remove the value associated with the given key from this map.
     *
     * @param key
     * @return value
     */
    T remove(const char* key);
    /**
     * Returns a view of the values in this map as an ArrayList.
     *
     * NOTE: Set method of ArrayList will not modify contents of this map.
     * Instead, use list.get(i) to modify values.
     *
     * @return ArrayList containing values in this map
     */
    SPtr<ArrayList<T> > values();
    /**
     * Return an array containing all of they keys used in this map.
     *
     * @return Array of used keys.
     */
    const char** keySet();
    /**
     * Check to see if this map is empty.
     *
     * @return true if map is empty, false if not
     */
    bool isEmpty();
    /**
     * Get the curren load of this map.
     *
     * @return load
     */
    int size();
    /**
     * Remove all key/associations from this map.
     */
    void clear();
};


////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//                               IMPLEMENTATION                               //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////


template<class T>
HashMap<T>::HashMap()
:pairs(new LinkedList<KeyValuePair<T> >[21]),
 load(0),
 capacity(21),
 NULLREFERENCE()
{}


template<class T>
HashMap<T>::~HashMap() {

    delete [] pairs;
}


template<class T>
int HashMap<T>::hash(const char* key) {

    int h;
    //Increment through char array
    for(h=0; *key; key++) {
        //Multiply ASCII value of key by a constant, and use modulus to ensure
        //key stays in scope of array.
        h = (64*h + *key) % 21;
    }
    return h;
}


template<class T>
bool HashMap<T>::containsKey(const char* key) {

    int h = hash(key);
    for(int i=0; i<pairs[h].size(); i++) {
        if(!strcmp(pairs[h].get(i).key,key)) {
            return true;
        }
    }
    return false;
}


template<class T>
bool HashMap<T>::containsValue(T value) {

    for(int i=0; i<capacity; i++) {
        for(int j=0; j<pairs[i].size(); j++) {
            if(pairs[i].get(j).value == value) {
                return true;
            }
        }
    }
    return false;
}


template<class T>
T& HashMap<T>::get(const char* key) {

    int h = hash(key);
    for(int i=0; i<pairs[h].size(); i++) {
        if(!strcmp(pairs[h].get(i).key,key)) {
            return pairs[h].get(i).value;
        }
    }
    return NULLREFERENCE;
}


template<class T>
void HashMap<T>::put(const char* key, T value) {

    if(containsKey(key)) {
        get(key) = value;
    }
    else {
        KeyValuePair<T> k = KeyValuePair<T>(key,value);
        pairs[hash(key)].addLast(k);
        load++;
    }
}


template<class T>
T HashMap<T>::remove(const char* key) {

    int h = hash(key);
    for(int i=0; i<pairs[h].size(); i++) {
        if(!strcmp(pairs[h].get(i).key,key)) {
            return pairs[h].remove(i).value;
        }
    }
    return T();
}


template<class T>
SPtr<ArrayList<T> > HashMap<T>::values() {

    SPtr<ArrayList<T> > list(new ArrayList<T>);
    for(int i=0; i<capacity; i++) {
        for(int j=0; j<pairs[i].size(); j++) {
            list->add(pairs[i].get(j).value);
        }
    }
    return list;
}


template<class T>
const char** HashMap<T>::keySet() {

    const char** keys = new const char*[load];
    int count = 0;
    for(int i=0; i<capacity; i++) {
        for(int j=0; j<pairs[i].size(); j++) {
            keys[count] = pairs[i].get(j).key;
            count++;
        }
    }
    return keys;
}


template<class T>
bool HashMap<T>::isEmpty() {

    return load == 0;
}


template<class T>
int HashMap<T>::size() {

    return load;
}


template<class T>
void HashMap<T>::clear() {

    for(int i=0; i<capacity; i++) {
        pairs[i].clear();
    }
}

#endif	/* HASHMAP_H */

