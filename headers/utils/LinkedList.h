#ifndef LINKEDLIST_H
#define	LINKEDLIST_H


////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//                                 DEFINITION                                 //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////


#include "headers/utils/Object.h"

/**
 * LinkedList provides all of the standard operations expected from any linked
 * list. LinkedlList operations are quite expensive, and so this class should
 * be used sparingly.
 *
 * Please look at the ArrayList class for suggested use of this container
 * class.
 *
 * @see ArrayList
 *
 * @author Ben Constable
 * @version 1.0
 *
 * @ingroup Utilities
 */
template<class T>
class LinkedList: public Object {

private:

    /**
     * List node, with data and pointer to the next node in the list.
     */
    struct node {
        T data;
        node *next;
    };

    node *head; ///< 'head' (start marker) of this list. No data!
    node *z; ///< 'tail' (end marker) of this list. No data!
    int currentSize; ///< current size of this list

    /**
     * Delete given node and all the ones after it.
     *
     * @param n start node
     */
    void deleteNode(node* n);

public:

    /**
     * Default constructor. Sets head marker to point to tail maker and tail
     * marker to point to itself.
     */
    LinkedList();
    /**
     * Copy constructor.
     *
     * @param rhs LinkedList to copy from
     */
    LinkedList(const LinkedList& rhs);
    /**
     * Assignemnt operator.
     * 
     * <strong>This does not handle assignment to self! Undefined behaviour will
     * occur if this happens.</strong>
     * 
     * @param rhs LinkedList to copy from
     * @return this
     */
    LinkedList& operator=(const LinkedList& rhs);
    /**
     * Destructor.
     */
    ~LinkedList();

    /**
     * Add an element to the given position in this list.
     *
     * @param i position
     * @param t element
     */
    void add(int i, T t);
    /**
     * Add an element to the head of this list.
     *
     * @param t element
     */
    void addFirst(T t);
    /**
     * Add an element to the tail of this list.
     *
     * @param t element
     */
    void addLast(T t);
    /**
     * Get the element from the given position in this list.
     *
     * @param i position
     * @return element
     */
    T& get(int i);
    /**
     * Get the first element in this list.
     *
     * @return first element
     */
    inline T& getFirst();
    /**
     * Get the last element in this list.
     *
     * @return last element
     */
    T& getLast();
    /**
     * Remove element from the given position in the list. If current list size
     * is 0, an element with default constructor is returned.
     * 
     * @param i position
     * @return element
     */
    T remove(int i);
    /**
     * Remove the first element from this list. If current list size
     * is 0, an element with default constructor is returned.
     *
     * @return element
     */
    T removeFirst();
    /**
     * Remove the last element from this list. If current list size
     * is 0, an element with default constructor is returned.
     *
     * @return element
     */
    T removeLast();
    /**
     * Set the element at the given position in this list to the given element.
     *
     * @param i position
     * @param t element
     */
    void set(int i, T t);
    /**
     * Get the current number of elements in this list.
     *
     * @return number of elements
     */
    inline int size();
    /**
     * Delete all elements in this list and set size to 0.
     */
    void clear();
};


////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//                               IMPLEMENTATION                               //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////


template<class T>
LinkedList<T>::LinkedList()
:head(new node),
 z(new node),
 currentSize(0)
{
    head->next = z;
    z->next = z;
}


template<class T>
LinkedList<T>::LinkedList(const LinkedList& rhs)
:head(new node),
 z(new node),
 currentSize(0)
{
    head->next = z;
    z->next = z;

    for(int i=0; i<rhs.currentSize; i++) {
        this->addLast(rhs.get(i));
    }
}


template<class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList& rhs) {

    this->clear();
    for(int i=0; i<rhs.currentSize; i++) {
        this->addLast(rhs.get(i));
    }
    return *this;
}


template<class T>
LinkedList<T>::~LinkedList() {

    deleteNode(head);
    delete z;
}


template<class T>
void LinkedList<T>::deleteNode(node* n) {

    if(n->next != z) {
        deleteNode(n->next);
    }
    delete n;
}


template<class T>
void LinkedList<T>::add(int i, T t) {

    if(i == currentSize) {
        addLast(t);
    }
    else if(i == 0) {
        addFirst(t);
    }
    else {
        node* current;
        node* temp = new node;
        temp->data = t;
        current = head->next;
        int j = 0;
        while(j < i-1) {
            current = current->next;
            j++;
        }
        temp->next = current->next;
        current->next = temp;
        currentSize++;
    }
}


template<class T>
void LinkedList<T>::addFirst(T t) {

    node *temp = new node;
    temp->data = t;
    temp->next = head->next;
    head->next = temp;
    currentSize++;
}


template<class T>
void LinkedList<T>::addLast(T t) {

    node* temp = new node;
    temp->data = t;
    temp->next = z;

    if(currentSize == 0) {
        head->next = temp;
    }
    else {
        node* temp2 = head;
        while(temp2->next != z) {
            temp2 = temp2->next;
        }
        temp2->next = temp;
    }
    currentSize++;
}


template<class T>
T& LinkedList<T>::get(int i) {

    node *current;
    current = head->next;
    int j = 0;
    while((j < i) && (current->next != z)) {
        current = current->next;
        j++;
    }
    return current->data;
}


template<class T>
inline T& LinkedList<T>::getFirst() {

    return head->next->data;
}


template<class T>
T& LinkedList<T>::getLast() {

    node *current;
    current = head->next;
    while(current->next != z) {
        current = current->next;
    }
    return current->data;
}


template<class T>
T LinkedList<T>::remove(int i) {

    if(i == currentSize){
        return removeLast();
    }
    else if(i == 0) {
        return removeFirst();
    }
    else {
        node *current, *temp;
        T obj;
        current = head->next;
        int j = 0;
        while(j < i-1) {
            current = current->next;
            j++;
        }
        temp = current->next;
        current->next = temp->next;
        obj = temp->data;
        currentSize--;
        delete temp;
        return obj;
    }
}


template<class T>
T LinkedList<T>::removeFirst() {

    if(currentSize != 0) {
        node *temp;
        T obj;
        temp = head->next;
        head->next = temp->next;
        obj = temp->data;
        delete temp;
        currentSize--;
        return obj;
    }
    return T();
}


template<class T>
T LinkedList<T>::removeLast() {

    if(currentSize != 0) {
        node *temp, *temp2;
        T obj;
        temp = head->next;
        while(temp->next != z) {
            temp2 = temp;
            temp = temp->next;
        }
        obj = temp->data;
        delete temp;
        temp2->next = z;
        currentSize--;
        return obj;
    }
    return T();
}


template<class T>
void LinkedList<T>::set(int i, T t) {

    node *current;
    current = head->next;
    int j = 0;
    while((j < i) && (current->next != z)) {
        current = current->next;
        j++;
    }
    current->data = t;
}


template<class T>
inline int LinkedList<T>::size() {

    return currentSize;
}


template<class T>
void LinkedList<T>::clear() {

    if(currentSize != 0) {
        deleteNode(head->next);
        head->next = z;
    }
    currentSize = 0;
}


#endif	/* LINKEDLIST_H */



