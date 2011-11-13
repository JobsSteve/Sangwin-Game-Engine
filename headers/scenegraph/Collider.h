#ifndef COLLIDER_H
#define	COLLIDER_H

#include "headers/scenegraph/Spatial.h"

/**
 * A Collider is a leaf Node that is used as a collision area. It is a
 * lightweight Node that can be used to set event areas based on collisions,
 * without the need for any visual information.
 *
 * @author Ben Constable, original Java code by Oli Winks
 * @version 1.1
 *
 * @ingroup Scenegraph
 */
class Collider: public Spatial {

    friend class GetNode; ///< friend so GetNode can access protected constructors

protected:


    /**
     * Default constructor. Create a Collider with the given name and default
     * Spatial information. No BoundingVolume is set.
     * 
     * @param name
     */
    Collider(const char* name)
    :Spatial(name)
    {
        this->type = Node::COLLIDER;
    }
    /**
     * Copy constructor. See Node for more information on copy behaviour.
     *
     * @param rhs Collider to copy from
     */
    Collider(const Collider& rhs)
    :Spatial(rhs)
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
    void updateBounds(ArrayList<SPtr<BoundingVolume> >& childBounds, int from, int to);
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


#endif	/* COLLIDER_H */

