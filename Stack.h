#ifndef STACK_H
#define	STACK_H

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//                                 DEFINITION                                 //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////


#include "ArrayList.h"

/**
 * The Stack class extends the ArrayList class with typical stack operations.
 * All the same rules apply for Stack as for ArrayList.
 *
 * @see ArrayList
 *
 * @author Ben Constable
 * @version 1.0
 *
 * @ingroup Utilities
 */
template<class T>
class Stack: public ArrayList<T> {

    //Redeclared so they can be seen by this class
    using ArrayList<T>::capacity;
    using ArrayList<T>::currentSize;
    using ArrayList<T>::list;

public:

    /**
     * Default constructor. Sets initial capacity to 10.
     */
    Stack()
    :ArrayList<T>()
    {}
    /**
     * Constructor that sets the initial capacity.
     *
     * @param c capacity
     */
    Stack(int c)
    :ArrayList<T>(c)
    {}
    /**
     * Copy constructor.
     *
     * @param rhs Stack top copy from
     */
    Stack(const Stack& rhs)
    :ArrayList<T>(rhs)
    {}
    /**
     * Assignment operator.
     *
     * @param rhs Stack top copy from
     * @return this
     */
    Stack& operator=(const Stack& rhs);
    /**
     * Destructor.
     */
    ~Stack(){}

    /**
     * Get the element at the top of this Stack, and remove it.
     *
     * @return element
     */
    inline T pop();
    /**
     * Add an element to the top of this Stack.
     * @param t
     */
    inline void push(T t);
    /**
     * Get the element at the top of this Stack, but do not remove it.
     *
     * @return element
     */
    inline T& peek();
};


////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//                               IMPLEMENTATION                               //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

template<class T>
Stack<T>& Stack<T>::operator =(const Stack& rhs) {

    ArrayList<T>::operator =(rhs);

    return *this;
}


template<class T>
inline T Stack<T>::pop() {

    T obj = list[currentSize-1];
    list[currentSize - 1] = T();
    currentSize--;

    return obj;
}


template<class T>
inline void Stack<T>::push(T t) {

    if(currentSize == capacity) {
        this->increaseSize();
    }
    list[currentSize] = t;
    currentSize++;
}


template<class T>
inline T& Stack<T>::peek() {

    return list[currentSize-1];
}


#endif	/* STACK_H */

