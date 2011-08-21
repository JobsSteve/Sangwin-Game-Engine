#ifndef BOUND_H
#define	BOUND_H


////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//                                 DEFINITION                                 //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////


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
 * Bound Nodes can be used in 2D or 3D scenegraphs. This is controlled by the
 * template parameter, which should eihter be a Vec2 or a Vec3.
 *
 * @see Node
 * @see BoundingVolume
 *
 * @author Ben Constable, original Java code by Oli Winks
 * @version 1.0
 *
 * @ingroup Scenegraph
 */
template<class V>
class Bound: public Node {

    friend class GetNode; ///< friend so that it can access protected constructors

protected:

    SPtr<BoundingVolume<V> > bounds; ///< BoundingVolume held by this Bound

    /**
     * Default constructor. Sets Node to default and no BoundingVolume on this
     * Bound.
     */
    Bound()
    :Node(),
     boundGroup(0)
    {
        type = BOUND;
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
        type = BOUND;
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
        type = BOUND;
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
    virtual void setBounds(SPtr<BoundingVolume<V> >& bounds);
    /**
     * Get this Bound's BoundingVolume.
     *
     * @return the BoundingVolume
     */
    virtual SPtr<BoundingVolume<V> > getBounds();
    /**
     * Updates this Bound's BoundingVolume (if it has one) by wrapping it round
     * all of its children.
     *
     * @param childBounds child nodes
     * @param from start index in the child node list
     * @param to end index in the child node list
     */
    virtual void updateBounds(ArrayList<SPtr<BoundingVolume<V> > >& childBounds, int from, int to);
    virtual SPtr<Node> clone();
    virtual SPtr<Node> cloneTree(SPtr<Node>& parent);


private:

    /**
     * Order all leaf nodes so that they are on the left of non-leaf nodes.
     */
    void sort();

};


////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//                               IMPLEMENTATION                               //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

template<class V>
Bound<V>& Bound<V>::operator =(const Bound& rhs) {

    Node::operator =(rhs);
    *bounds = *rhs.bounds;
    boundGroup = rhs.boundGroup;

    return *this;
}


template<class V>
void Bound<V>::sort() {
    
    int lastLeaf = -1;
    for(int i=0; i<children->size(); i++) {
        if(children->get(i)->isLeaf() && i > lastLeaf + 1) {
            children->add(++lastLeaf, children->remove(i));
            i--;
        }
    }
}


template<class V>
void Bound<V>::attachChild(SPtr<Node> child) {

    Node::attachChild(child);

    //sort this node and it's parent node (if it's a Bound)
    sort();
    if(parent != 0 && parent->type == BOUND) {
        static_cast<Bound*> (parent)->sort();
    }
}


template<class V>
void Bound<V>::setBounds(SPtr<BoundingVolume<V> >& bounds) {

    this->bounds = bounds;
}


template<class V>
SPtr<BoundingVolume<V> > Bound<V>::getBounds() {

    return bounds;
}


template<class V>
void Bound<V>::updateBounds(ArrayList<SPtr<BoundingVolume<V> > >& childBounds, int from, int to) {

    if(bounds.get()) {
        /*
         resize bounding volume according to the bounds of this
         Bound's children
         */
        bounds->wrap(childBounds, from, to);
    }
}


template<class V>
SPtr<Node> Bound<V>::clone() {

    SPtr<Node> clone(new Bound<V>());
    if(bounds.get()) {
        SPtr<BoundingVolume<V> > boundsClone(bounds->clone());
        clone.smart_static_cast(SPtr<Bound<V> >())->setBounds(boundsClone);
    }

    return clone;
}


template<class V>
SPtr<Node> Bound<V>::cloneTree(SPtr<Node>& parent) {

    SPtr<Node> clone(this->clone());

    //reparent clone
    if(parent.get()) {
        parent->attachChild(clone);
    }

    //recursively clone children
    for(int i=0; i<children->size(); i++) {
        children->get(i)->cloneTree(clone);
    }

    return clone;
}


#endif	/* BOUND_H */

