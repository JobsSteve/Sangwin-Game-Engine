#ifndef ARRAYLIST_H
#define	ARRAYLIST_H

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//                                 DEFINITION                                 //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

#include "headers/utils/Object.h"

/**
 * The ArrayList class works like a Java ArrayList. It is a an array of no-fixed
 *  size, which automatically increase when its capacity is reached.
 *
 * NOTE: type int cannot be used with this ArrayList implementation, as it
 * causes ambiguity in some function definitions. This will be fixed at a later
 * date.
 *
 * NOTE: ArrayLists should be used with primitive types, objects and SPtrs to
 * work effectively. Do not pass raw pointers into ArrayLists. If memory leaks
 * may occur if this happens.
 *
 * NOTE: Add, remove, set and get functions do no bounds checking. Please ensure
 * that bounds are checked before attempting these functions.
 * 
 * @author Ben Constable
 * @version 1.0
 *
 * @ingroup Utilities
 */
template<class T>
class ArrayList: public Object {

protected:

    int capacity; ///< initial capacity of the ArrayList
    int currentSize; ///< current number of elements in the list
    T* list; ///< elements

    /**
     * Increase the size of this ArrayList, when capacity is reached. Capacity
     * is double the current capacity.
     */
    void increaseSize();

public:

    /**
     * Default constructor. Capacity is 10.
     */
    ArrayList();
    /**
     * Constructor that sets the initial capacity.
     *
     * @param c capacity
     */
    ArrayList(int c);
    /**
     * Copy constructor. Copies size info and elements.
     *
     * @param rhs
     */
    ArrayList(const ArrayList& rhs);
    /**
     * Assignment operator. Copies size info and elements.
     * @param other
     * @return
     */
    ArrayList<T>& operator=(const ArrayList<T>& other);
    /**
     * Destructor.
     */
    virtual ~ArrayList();

    /**
     * Set this ArrayList to default capacity (10) and clear all elements.
     */
    void clear();
    /**
     * Add the given element to the end of the list.
     *
     * @param t element to add
     */
    void add(T t);
    /**
     * Add the given element to the given position in the list.
     *
     * @param i position
     * @param t element
     */
    void add(int i, T t);
    /**
     * Get the element from the given position in the list.
     *
     * @param i position
     * @return element
     */
    inline T& get(int i);
    /**
     * Check if this list is empty.
     *
     * @return true if empty, false if not
     */
    inline bool isEmpty();
    /**
     * Remove the element at the given position from the list.
     *
     * @param i position
     * @return element
     */
    T remove(int i);
    /**
     * Remove the given element from the list. For this to work correctly, an
     * equality operator must be defined in the list type. Works best with
     * SPtrs.
     *
     * @param t element
     * @return element
     */
    T remove(T t);
    /**
     * Set the element at the given position to the parameter element. Equality
     * operator must be defined.
     *
     * @param t element
     * @param i position
     */
    inline void set(T t, int i);
    /**
     * Get the current number of elements in this list.
     *
     * @return number of elements
     */
    inline int size();
    /**
     * Check if this list contains the given element. Equality operator must be
     * defined. Works best with SPtrs.
     *
     * @param t element
     * @return true if list contains element, false if not
     */
    bool contains(T t);
    /**
     * Get the index of the given element in this list. Equality operator must
     * be defined. Workds best with SPtrs.
     *
     * @param t element
     * @return index of element, -1 if not in list
     */
    int indexOf(T t);
};


////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//                               IMPLEMENTATION                               //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////


template<class T>
void ArrayList<T>::increaseSize() {

    T* list2 = new T [capacity*2];
    for(int i = 0; i < capacity; i++) {
        list2[i] = list[i];
    }
    delete [] list;
    list = list2;
    capacity = capacity*2;
}


template<class T>
ArrayList<T>::ArrayList()
:capacity(10),
 currentSize(0),
 list(new T[10])
{}


template<class T>
ArrayList<T>::ArrayList(int c)
:capacity(c),
 currentSize(0),
 list(new T[c])
{}


template<class T>
ArrayList<T>::ArrayList(const ArrayList& rhs)
:capacity(rhs.capacity),
 currentSize(rhs.currentSize),
 list(new T[rhs.capacity])
{
    for(int i=0; i < rhs.capacity; i++) {
        list[i] = rhs.list[i];
    }
}


template<class T>
ArrayList<T>& ArrayList<T>::operator =(const ArrayList<T>& other) {

    if(this != &other) {

        delete [] list;
        list = new T[other.capacity];
        for(int i=0; i < other.capacity; i++) {
            list[i] = other.list[i];
        }

        this->capacity = other.capacity;
        this->currentSize = other.currentSize;
    }

    return *this;
}


template<class T>
ArrayList<T>::~ArrayList() {

    delete [] list;
}


template<class T>
void ArrayList<T>::clear() {

    delete [] list;
    list = new T[10];
    capacity = 10;
    currentSize = 0;
}


template<class T>
void ArrayList<T>::add(T t) {

    if(currentSize == capacity-2) {
        increaseSize();
    }
    list[currentSize] = t;
    currentSize++;
}


template<class T>
void ArrayList<T>::add(int i, T t) {

    if(currentSize == capacity-2) {
        increaseSize();
    }
    for(int j=currentSize; j>i; j--) {
        list[j] = list[j-1];
    }
    list[i] = t;
    currentSize++;
}


template<class T>
inline T& ArrayList<T>::get(int i) {

    return list[i];
}


template<class T>
inline bool ArrayList<T>::isEmpty() {

    return currentSize == 0;
}


template<class T>
T ArrayList<T>::remove(int i) {

    T obj = list[i];
    for(int j = i; j <= currentSize; j++) {
        list[j] = list[j+1];
    }
    currentSize--;
    return obj;
}


template<class T>
T ArrayList<T>::remove(T t) {

    int pos = 0;
    while(pos < currentSize) {
        if(list[pos] == t) {
            return remove(pos);
        }
        pos++;
    }
    return T();
}


template<class T>
inline void ArrayList<T>::set(T t, int i) {

    list[i] = t;
}


template<class T>
inline int ArrayList<T>::size() {

    return currentSize;
}

template<class T>
bool ArrayList<T>::contains(T t) {

    for(int i=0; i<currentSize; i++) {
        if(list[i] == t) {
            return true;
        }
    }
    return false;
}


template<class T>
int ArrayList<T>::indexOf(T t) {

    for(int i=0; i<currentSize; i++) {
        if(list[i] == t) {
            return i;
        }
    }
    return -1;
}
#endif	/* ARRAYLIST_H */





