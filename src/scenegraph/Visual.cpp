#include "headers/scenegraph/Visual.h"

Visual& Visual::operator =(const Visual& rhs) {

    Spatial::operator =(rhs);

    *worldAppearance = *rhs.worldAppearance;
    *localAppearance = *rhs.localAppearance;
    hasVisualStateChanged = rhs.hasVisualStateChanged;

    return *this;
}


App& Visual::getLocalAppearance() {

    hasVisualStateChanged = true;
    return *localAppearance;
}


App& Visual::getWorldAppearance() {

    return *worldAppearance;
}


void Visual::applyAppearance(const App& worldAppearance) {

    this->worldAppearance->setTo(worldAppearance);
    hasVisualStateChanged = true;
}


SPtr<Node> Visual::clone() {

    SPtr<Node> clone(new Visual(this->name));
    clone.smart_static_cast(SPtr<Visual>())->localTransform->setTo(*(this->localTransform));
    clone.smart_static_cast(SPtr<Visual>())->localAppearance->setTo(*localAppearance);
    
    if(this->bounds.get()) {
        SPtr<BoundingVolume> boundsClone(this->bounds->clone());
        clone.smart_static_cast(SPtr<Visual>())->setBounds(boundsClone);
    }

    return clone;
}


SPtr<Node> Visual::cloneTree(SPtr<Node>& parent) {

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
