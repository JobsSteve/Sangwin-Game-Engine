#include "headers/scenegraph/Collider.h"

Collider& Collider::operator =(const Collider& rhs) {

    Spatial::operator =(rhs);

    return *this;
}


void Collider::updateBounds(ArrayList<SPtr<BoundingVolume> >& childBounds, int from, int to) {

    if(this->bounds.get()) {
        this->bounds->applyTransform(*(this->worldTransform));
    }
}


void Collider::attachChild(SPtr<Node> child) {}


void Collider::detachChild(const SPtr<Node>& child) {}


SPtr<Node> Collider::detachChild(int i) {

    return SPtr<Node>();
}


SPtr<Node> Collider::clone() {

    SPtr<Node> clone(new Collider(this->name));
    clone.smart_static_cast(SPtr<Collider>())->localTransform->setTo(*(this->localTransform));

    if(this->bounds.get()) {
        SPtr<BoundingVolume> boundsClone(this->bounds->clone());
        clone.smart_static_cast(SPtr<Collider>())->setBounds(boundsClone);
    }

    return clone;
}


SPtr<Node> Collider::cloneTree(SPtr<Node>& parent) {

    return clone();
}
