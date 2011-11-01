#include "headers/scenegraph/Spatial.h"

Spatial& Spatial::operator =(const Spatial& rhs) {

    Bound::operator =(rhs);

    hasTransformed = rhs.hasTransformed;
    *localTransform = *rhs.localTransform;
    *worldTransform = *rhs.worldTransform;

    return *this;
}


Trfm& Spatial::getLocalTransform() {

    return *localTransform;
}


Trfm& Spatial::getWorldTransform() {

    return *worldTransform;
}


bool Spatial::transformed() {

    return hasTransformed;
}


void Spatial::setTransformed(bool transformed) {

    hasTransformed = transformed;
}


void Spatial::updateLocalTransform() {

    localTransform->update();
    hasTransformed = true;
}


void Spatial::applyTransform(Trfm& worldTransform) {

    this->worldTransform->setTo(worldTransform);
    hasTransformed = true;
}


SPtr<Node> Spatial::clone() {

    SPtr<Node> clone(new Spatial(this->name));
    clone.smart_static_cast(SPtr<Spatial>())->localTransform->setTo(*localTransform);
    
    if(this->bounds.get()) {
        SPtr<BoundingVolume> boundsClone(this->bounds->clone());
        clone.smart_static_cast(SPtr<Spatial>())->setBounds(boundsClone);
    }

    return clone;
}


SPtr<Node> Spatial::cloneTree(SPtr<Node>& parent) {
    
    SPtr<Node> clone(this->clone());

    //reparent clone
    if(parent.get()) {
        parent->attachChild(clone);
    }

    //recursively clone children
    for(int i=0; i<this->children->size(); i++) {
        this->children->get(i)->cloneTree(clone);
    }

    return clone;
}
