#ifndef COLLIDER_H
#define	COLLIDER_H

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//                                 DEFINITION                                 //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

#include "headers/scenegraph/Spatial.h"

/**
 * A Collider is a leaf Node that is used as a collision area. It is a
 * lightweight Node that can be used to set event areas based on collisions,
 * without the need for any visual information.
 *
 * @author Ben Constable, original Java code by Oli Winks
 * @version 1.0
 *
 * @ingroup Scenegraph
 */
template<class V, class T>
class Collider: public Spatial<V,T> {

    friend class GetNode; ///< friend so GetNode can access protected constructors

protected:


    /**
     * Default constructor. Create a Collider with the given name and default
     * Spatial information. No BoundingVolume is set.
     * 
     * @param name
     */
    Collider(const char* name)
    :Spatial<V,T>(name)
    {
        this->type = Node::COLLIDER;
    }
    /**
     * Copy constructor. See Node for more information on copy behaviour.
     *
     * @param rhs Collider to copy from
     */
    Collider(const Collider& rhs)
    :Spatial<V,T>(rhs)
    {
        this->type = Node::COLLIDER;
    }

public:

    /**
     * Assignment operator. See Node for more information on copy behaviour.
     *
     * @param rhs Collider to copy from
     * @return this
     */
    Collider& operator=(const Collider& rhs);
    /**
     * Destructor.
     */
    ~Collider(){}

    /**
     * Updates this Colliders BoundingVolume, if it has one. Colliders are leaf
     * nodes, so childBounds will be empty.
     *
     * @param childBounds empty, list of this Node's children
     * @param from not used
     * @param to not used
     */
    void updateBounds(ArrayList<SPtr<BoundingVolume<V> > >& childBounds, int from, int to);
    /**
     * Does nothing as Collider is a leaf Node.
     *
     * @param child
     */
    void attachChild(SPtr<Node> child);
    /**
     * Does nothing as Collider is a leaf Node.
     *
     * @param child
     */
    void detachChild(const SPtr<Node>& child);
    /**
     * Does nothing as Collider is a leaf Node.
     *
     * @param i
     * @return null pointer to Node
     */
    SPtr<Node> detachChild(int i);
    SPtr<Node> clone();
    SPtr<Node> cloneTree(SPtr<Node>& parent);

};


////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//                               IMPLEMENTATION                               //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////


template<class V, class T>
Collider<V,T>& Collider<V,T>::operator =(const Collider& rhs) {

    Spatial<V,T>::operator =(rhs);

    return *this;
}


template<class V, class T>
void Collider<V,T>::updateBounds(ArrayList<SPtr<BoundingVolume<V> > >& childBounds, int from, int to) {

    if(this->bounds.get()) {
        this->bounds->applyTransform(*(this->worldTransform));
    }
}


template<class V, class T>
void Collider<V,T>::attachChild(SPtr<Node> child) {}


template<class V, class T>
void Collider<V,T>::detachChild(const SPtr<Node>& child) {}


template<class V, class T>
SPtr<Node> Collider<V,T>::detachChild(int i) {

    return SPtr<Node>();
}


template<class V, class T>
SPtr<Node> Collider<V,T>::clone() {

    SPtr<Node> clone(new Collider<V,T>(this->name));
    clone.smart_static_cast(SPtr<Collider<V,T> >())->localTransform->setTo(*(this->localTransform));

    if(this->bounds.get()) {
        SPtr<BoundingVolume<V> > boundsClone(this->bounds->clone());
        clone.smart_static_cast(SPtr<Collider<V,T> >())->setBounds(boundsClone);
    }

    return clone;
}


template<class V, class T>
SPtr<Node> Collider<V,T>::cloneTree(SPtr<Node>& parent) {

    return clone();
}


#endif	/* COLLIDER_H */

