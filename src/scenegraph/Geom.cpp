#include "headers/scenegraph/Geom.h"

Geom& Geom::operator=(const Geom& rhs) {

    Visual::operator =(rhs);

    trimesh = rhs.trimesh;

    return *this;
}


void Geom::attachChild(SPtr<Node> child) {}


void Geom::detachChild(const SPtr<Node>& child) {}


SPtr<Node> Geom::detachChild(int i) {

    return SPtr<Node>();
}


void Geom::setBounds(SPtr<BoundingVolume>& bounds) {

    this->bounds = bounds;
    this->bounds->wrap(trimesh->getVertices(), trimesh->getVLength());
}


SPtr<BoundingVolume> Geom::getBounds() {

    return this->bounds;
}


void Geom::updateBounds(ArrayList<SPtr<BoundingVolume> >& childBounds, int from, int to) {

    if(this->bounds.get() && this->hasTransformed) {
        this->bounds->applyTransform(*(this->worldTransform));
    }
}


SPtr<Trimesh> Geom::getTrimesh() {

    return trimesh;
}


SPtr<Node> Geom::clone() {

    SPtr<Node> clone(new Geom(this->name, trimesh));
    clone.smart_static_cast(SPtr<Geom>())->localTransform->setTo(*(this->localTransform));
    clone.smart_static_cast(SPtr<Geom>())->localAppearance->setTo(*(this->localAppearance));

    if(this->bounds.get()) {
        SPtr<BoundingVolume> boundsClone(this->bounds->clone());
        clone.smart_static_cast(SPtr<Geom>())->setBounds(boundsClone);
    }

    return clone;
}


SPtr<Node> Geom::cloneTree(SPtr<Node>& parent) {

    return clone();
}
