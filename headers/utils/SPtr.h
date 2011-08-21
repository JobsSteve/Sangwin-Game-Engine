#ifndef SPTR_H
#define	SPTR_H

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//                                 DEFINITION                                 //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

/**
 * The SPtr class is reference counted smart pointer implementation. It is
 * a simple interface that provides ease of use when dealing with shared
 * objects. SPtrs are created as a wrapper around 'real' pointers. However,
 * they cannot be used interchangeably, and the programmer should make sure that
 * a SPtr is used only when needed.
 *
 * Implicit casting can be used by non-references to SPtrs, and explicit casting
 * is allowed through the use of the smart_static_cast() function. This allows
 * SPtrs to behave as much like real pointers as possible.
 *
 * To use a SPtr, ensure that the class being wrapped extends the Object class.
 *
 * Example usage:
 *
 *      SPtr<Type> mySptr(new Type());
 * cast:SPtr<OtherType> mySPtr2(mySptr.smart_static_cast(SPtr<OtherType>()));
 *
 * @see Object
 *
 * @author Ben Constable, adapted from Scott Meyers reference counted smart
 * pointer implementation
 * @version 1.0
 *
 * @ingroup Utilities
 */
template<class T>
class SPtr {

private:
    
    T* pointee; ///< What this SPtr is pointing to

    /**
     * Add a reference to the real pointer, if it is not 0.
     */
    void init();

public:

    /**
     * Construct a SPtr with a real pointer. Defaults to 0.
     *
     * @param realPtr Pointer to reference count
     */
    explicit SPtr(T* realPtr = 0);
    /**
     * Copy constructor. Points this SPtr to the real pointer of the parameter
     * SPtr, and increases its reference count.
     *
     * @param rhs SPtr to get pointer from
     */
    SPtr(const SPtr& rhs);
    /**
     * Destructor. Remove reference from real pointer, and delete if reference
     * count is 0.
     */
    ~SPtr();

    /**
     * Get the real pointer from this SPtr.
     *
     * @return real pointer
     */
    T* get();

    /**
     * Assignment operator. Assigns this SPtr's real pointer to that of the
     * parameter SPtr, and increases its reference count.
     *
     * @param rhs SPtr to get pointer from
     * @return this
     */
    SPtr& operator=(const SPtr& rhs);
    /**
     * Equality operator. Check equality by comparing the memory addresses of
     * the real pointers to see if they are the same object.
     *
     * @param rhs SPtr to check equality with
     * @return true if both SPtrs point to the same object, false if not
     */
    bool operator==(const SPtr& rhs);
    /**
     * Dereference this SPtr, just like a normal pointer.
     *
     * @return real pointer
     */
    T* operator->() const;
    /**
     * Dereference this SPtr, just like a normal pointer.
     * @return
     */
    T& operator*() const;
    /**
     * Not operator. If the real pointer contained this smart pointer is 0,
     * return true.
     *
     * @return true if pointer is 0, false if not
     */
    bool operator!() const;

    /**
     * Wrapper for static_cast. Casts the real pointer of this SPtr to the type
     * of the parameter SPtr's real pointer.
     *
     * @param SPtr Type to cast to
     * @return SPtr to new type
     */
    template<class U>
    SPtr<U> smart_static_cast(const SPtr<U>&) {

        return SPtr<U>(static_cast<U*>(pointee));
    }

    /**
     * Implicit conversion of smart pointers to others in the same heirarchy.
     * Allows SPtrs in the same heirarchy to be passed as parameters to
     * functions.
     * 
     * @return SPtr to related type.
     */    
    template<class newType>
    operator SPtr<newType>() {
        return SPtr<newType>(pointee);
    }
};


////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//                               IMPLEMENTATION                               //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////


template<class T>
void SPtr<T>::init() {
    if (pointee == 0) {
            return;
    }
    pointee->addReference();
}


template<class T>
SPtr<T>::SPtr(T* realPtr)
:pointee(realPtr)
{
    init();
}


template<class T>
SPtr<T>::SPtr(const SPtr& rhs)
:pointee(rhs.pointee)
{
    init();
}


template<class T>
SPtr<T>::~SPtr() {
    if(pointee) {
        pointee->removeReference();
    }
}


template<class T>
T* SPtr<T>::get() {
    return pointee;
}


template<class T>
SPtr<T>& SPtr<T>::operator =(const SPtr& rhs) {
    if(pointee != rhs.pointee) {
        T* oldPointee = pointee;
        pointee = rhs.pointee;
        init();
        if(oldPointee) {
            oldPointee->removeReference();
        }
    }
    return *this;
}


template<class T>
bool SPtr<T>::operator ==(const SPtr& rhs) {

    return pointee == rhs.pointee;
}


template<class T>
T* SPtr<T>::operator ->() const {
    return pointee;
}


template<class T>
T& SPtr<T>::operator *() const {
    return *pointee;
}


template<class T>
bool SPtr<T>::operator !() const {

    return (!pointee);
}

#endif	/* _SPTR_H */


