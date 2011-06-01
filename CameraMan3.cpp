#include "CameraMan3.h"

CameraMan3& CameraMan3::operator =(const CameraMan3& rhs) {

    Spatial<Vec3,Trfm3>::operator =(rhs);

    *worldLookAt = *rhs.worldLookAt;
    *worldDir = *rhs.worldDir;
    *worldUp = *rhs.worldUp;
    *cam = *rhs.cam;

    return *this;
}


void CameraMan3::attachChild(SPtr<Node>& child) {}


void CameraMan3::detachChild(SPtr<Node>& child) {}


SPtr<Node> CameraMan3::detachChild(int i) {

    return SPtr<Node>();
}


void CameraMan3::updateBounds(ArrayList<SPtr<BoundingVolume<Vec3> > >& childBounds, int from, int to) {

    if(this->bounds.get()) {
        bounds->applyTransform(*this->worldTransform);
    }
}


void CameraMan3::applyTransform(Trfm3& worldTransform) {

    Spatial<Vec3,Trfm3>::applyTransform(worldTransform);

    //calculate camera pos
    cam->getPos().toZeros();
    this->worldTransform->apply(cam->getPos());

    //calculate up vector
    worldUp->setTo(0,1,0);
    this->worldTransform->apply(*worldUp);
    worldUp->sub(cam->getPos()).norm(); // testing

    //calculate lookat vector
    worldLookAt->setTo(0,0,1);
    this->worldTransform->apply(*worldLookAt);

    //set position, look at direction and up direction
    cam->getUp().setTo(*worldUp);
    cam->getLookAt().setTo(*worldLookAt);

    //calculate direction
    worldDir->setTo(*worldLookAt).sub(cam->getPos());

    //recalculate frustum
    cam->update();
}


SPtr<Node> CameraMan3::clone() {

    return SPtr<Node>();
}


SPtr<Node> CameraMan3::cloneTree(SPtr<Node>& parent) {

    return clone();
}
