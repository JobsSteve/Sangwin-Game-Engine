#ifndef QUEUE_H
#define	QUEUE_H

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//                                 DEFINITION                                 //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////


#include "headers/utils/ArrayList.h"

/**
 * The Queue class extends the ArrayList class with basic FIFO queue
 * functionality. All the same rules apply to Queue as with ArrayList.
 *
 * @author Ben Constable
 * @version 1.0
 *
 * @ingroup Utilities
 */
template<class T>
class Queue: public ArrayList<T> {

public:

    /**
     * Default constructor. Sets capacity to 10.
     */
    Queue()
    :ArrayList<T>()
    {}
    /**
     * Constructor that sets the initial capacity.
     *
     * @param c capacity
     */
    Queue(int c)
    :ArrayList<T>(c)
    {}
    /**
     * Copy constructor.
     *
     * @param rhs Queue to copy from
     */
    Queue(const Queue& rhs)
    :ArrayList<T>(rhs)
    {}
    /**
     * Assignmet operator.
     *
     * @param rhs Queue to copy from
     * @return this
     */
    Queue& operator=(const Queue& rhs);
    /**
     * Destructor.
     */
    ~Queue(){}

    /**
     * Get but do not remove the element at the front of this Queue.
     *
     * @return element
     */
    T& peek();
    /**
     * Get and remove the element at the front of this Queue.
     * @return
     */
    T poll();
};


////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//                               IMPLEMENTATION                               //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////


template<class T>
Queue<T>& Queue<T>::operator =(const Queue& rhs) {

    ArrayList<T>::operator =(rhs);

    return *this;
}


template<class T>
T& Queue<T>::peek() {

    return this->list[0];
}


template<class T>
T Queue<T>::poll() {

    return this->remove(0);
}
#endif	/* QUEUE_H */

