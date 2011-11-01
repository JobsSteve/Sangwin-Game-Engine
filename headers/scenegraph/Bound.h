#ifndef BOUND_H
#define	BOUND_H

#include "headers/collision/BoundingVolume.h"
#include "headers/scenegraph/Node.h"

/**
 * The Bound class extends the Node class to be able to have a BoundingVolume.
 * It contains functions to set and update the BoundingVolume for each Node.
 *
 * Bound Nodes are ordered such that leaf children are on the left on non-leaf
 * children. This makes collision detection between Nodes easier.
 *
 * The BoundingVolume held by this Bound wraps around all child Nodes.
 *
 * @see Node
 * @see BoundingVolume
 *
 * @author Ben Constable, original Java code by Oli Winks
 * @version 1.1
 *
 * @ingroup Scenegraph
 */
class Bound: public Node {

    friend class GetNode; ///< friend so that it can access protected constructors

protected:

    SPtr<BoundingVolume> bounds; ///< BoundingVolume held by this Bound

    /**
     * Default constructor. Sets Node to default and no BoundingVolume on this
     * Bound.
     */
    Bound()
    :Node(),
     boundGroup(0)
    {
        type = Node::BOUND;
    }
    /**
     * Constructor that gives this Bound a name. Everything else as in default
     * constructor.
     * 
     * @param name Name of this Bound
     */
    Bound(const char* name)
    :Node(name),
     boundGroup(0)
    {
        type = Node::BOUND;
    }
    /**
     * Copy constructor. See Node for more info. BoundingVolume is a deep copy.
     * 
     * @param rhs Bound to copy from
     */
    Bound(const Bound& rhs)
    :Node(rhs),
     bounds(),
     boundGroup(rhs.boundGroup)
    {
        type = Node::BOUND;
        *bounds = *rhs.bounds;
    }

public:

    int boundGroup; ///< Uniquely identifies groups of Bounds

    /**
     * Assignment operator. See Node for more info. BoundingVolume is a deep 
     * copy.
     * 
     * @param rhs Bound to copy from
     * @return this
     */
    Bound& operator=(const Bound& rhs);
    /**
     * Destructor.
     */
    ~Bound(){}

    /**
     * Sort after attaching child, so scenegraph is ordered correctly for
     * collision detection.
     *
     * @param child child Node to add
     */
    virtual void attachChild(SPtr<Node> child);
    /**
     * Set the BoundingVolume for this Bound.
     * 
     * @param bounds BoundingVolume
     */
    virtual void setBounds(SPtr<BoundingVolume>& bounds);
    /**
     * Get this Bound's BoundingVolume.
     *
     * @return the BoundingVolume
     */
    virtual SPtr<BoundingVolume> getBounds();
    /**
     * Updates this Bound's BoundingVolume (if it has one) by wrapping it round
     * all of its children.
     *
     * @param childBounds child nodes
     * @param from start index in the child node list
     * @param to end index in the child node list
     */
    virtual void updateBounds(ArrayList<SPtr<BoundingVolume> >& childBounds, int from, int to);
    virtual SPtr<Node> clone();
    virtual SPtr<Node> cloneTree(SPtr<Node>& parent);


private:

    /**
     * Order all leaf nodes so that they are on the left of non-leaf nodes.
     */
    void sort();

};

#endif	/* BOUND_H */

