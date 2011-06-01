#ifndef _OBJECT_H
#define	_OBJECT_H

#include "SPtr.h"

/**
 * The Object class is the subclass for all objects which require reference
 * counting. It ensures the every time a smart pointer to an object is created,
 * its reference count increases, and decreases when a smart pointer is
 * destroyed. Objects are destroyed when their reference count reaches 0.
 *
 * @see SPtr
 * 
 * @author Ben Constable, taken from Scott Meyers reference counted reference
 * counted smart pointer implementation
 * @version 1.0
 *
 * @ingroup Utilities
 */
class Object {
    
public:

    /**
     * Construct a new Object with a reference count of 0.
     */
    Object();
    /**
     * Copy constructor. No data is copied, reference count is set to 0.
     *
     * @param rhs
     */
    Object(const Object& rhs);
    /**
     * Assignment operator. Nothing happens, this Object is returned.
     *
     * @param rhs
     * @return this
     */
    Object& operator=(const Object& rhs);
    /**
     * Destructor.
     */
    virtual ~Object();
    
    /**
     * Increase the reference count of this Object by one.
     */
    inline void addReference();
    /**
     * Decrement the reference count of this Object by one. If it is 0, delete
     * this Object.
     */
    inline void removeReference();
    /**
     * Get the reference count of this Object.
     * @return
     */
    inline int getRefCount();

protected:

    int refCount; ///< Current reference count of this Object.
};

//INLINE FUNCTION DEFINITIONS

inline void Object::addReference() {
    ++refCount;
}

inline void Object::removeReference() {
    if(--refCount == 0) delete this;
}

inline int Object::getRefCount() {
    return refCount;
}

/**
 *
 * @defgroup Math
 * @defgroup Appearance
 * @defgroup Lights
 * @defgroup Cameras
 * @defgroup Collision
 * @defgroup Scenegraph
 * @defgroup Resource
 * @defgroup Events
 * @defgroup Utilities
 *
 */

/**
 * @mainpage Sangwin C++ Game Engine Documentation
 * @section intro_sec Introduction
 *
 * The Sangwin C++ Game Engine...
 *
 * @section back_sec Background
 *
 * This is some background info.
 */
#endif	/* _OBJECT_H */



