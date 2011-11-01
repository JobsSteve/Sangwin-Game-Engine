#include "headers/scenegraph/Bound.h"

Bound& Bound::operator =(const Bound& rhs) {

    Node::operator =(rhs);
    *bounds = *rhs.bounds;
    boundGroup = rhs.boundGroup;

    return *this;
}


void Bound::sort() {
    
    int lastLeaf = -1;
    for(int i=0; i<children->size(); i++) {
        if(children->get(i)->isLeaf() && i > lastLeaf + 1) {
            children->add(++lastLeaf, children->remove(i));
            i--;
        }
    }
}


void Bound::attachChild(SPtr<Node> child) {

    Node::attachChild(child);

    //sort this node and it's parent node (if it's a Bound)
    sort();
    if(parent != 0 && parent->type == BOUND) {
        static_cast<Bound*> (parent)->sort();
    }
}


void Bound::setBounds(SPtr<BoundingVolume>& bounds) {

    this->bounds = bounds;
}


SPtr<BoundingVolume> Bound::getBounds() {

    return bounds;
}


void Bound::updateBounds(ArrayList<SPtr<BoundingVolume> >& childBounds, int from, int to) {

    if(bounds.get()) {
        /*
         resize bounding volume according to the bounds of this
         Bound's children
         */
        bounds->wrap(childBounds, from, to);
    }
}


SPtr<Node> Bound::clone() {

    SPtr<Node> clone(new Bound());
    if(bounds.get()) {
        SPtr<BoundingVolume> boundsClone(bounds->clone());
        clone.smart_static_cast(SPtr<Bound>())->setBounds(boundsClone);
    }

    return clone;
}


SPtr<Node> Bound::cloneTree(SPtr<Node>& parent) {

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
