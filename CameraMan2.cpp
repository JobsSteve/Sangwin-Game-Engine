#include "CameraMan2.h"

CameraMan2& CameraMan2::operator =(const CameraMan2& rhs) {

    Spatial<Vec2,Trfm2>::operator =(rhs);

    *cam = *rhs.cam;

    return *this;
}


void CameraMan2::attachChild(SPtr<Node>& child) {}


void CameraMan2::detachChild(const SPtr<Node>& child) {}


SPtr<Node> CameraMan2::detachChild(int i) {

    return SPtr<Node>();
}


void CameraMan2::updateBounds(ArrayList<SPtr<BoundingVolume<Vec2> > >& childBounds, int from, int to) {

    if(this->bounds.get()) {
        this->bounds->applyTransform(*(this->worldTransform));
    }
}


void CameraMan2::applyTransform(Trfm2& worldTransform) {

    Spatial<Vec2,Trfm2>::applyTransform(worldTransform);

    //set position, and orientation
    cam->getPos().toZeros();
    this->worldTransform->apply(cam->getPos());

    //calculate orientation
    cam->rot = worldTransform.getRotation();

    cam->update();
}


SPtr<Node> CameraMan2::clone() {

    return SPtr<Node>();
}


SPtr<Node> CameraMan2::cloneTree(SPtr<Node>& parent) {

    return clone();
}
