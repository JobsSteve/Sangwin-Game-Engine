#include "headers/cameras/CameraMan.h"

CameraMan& CameraMan::operator =(const CameraMan& rhs) {

    Spatial::operator =(rhs);

    *worldLookAt = *rhs.worldLookAt;
    *worldDir = *rhs.worldDir;
    *worldUp = *rhs.worldUp;
    *cam = *rhs.cam;

    return *this;
}


void CameraMan::attachChild(SPtr<Node>& child) {}


void CameraMan::detachChild(SPtr<Node>& child) {}


SPtr<Node> CameraMan::detachChild(int i) {

    return SPtr<Node>();
}


Vec3& CameraMan::getWorldLookAt() {

    return *worldLookAt;
}


Vec3& CameraMan::getWorldDir() {

    return *worldDir;
}


Vec3& CameraMan::getWorldUp() {

    return *worldUp;
}


void CameraMan::setCamera(SPtr<Cam>& camera) {

    this->cam = camera;
}


SPtr<Cam> CameraMan::getCamera() {

    return cam;
}


void CameraMan::updateBounds(ArrayList<SPtr<BoundingVolume> >& childBounds, int from, int to) {

    if(this->bounds.get()) {
        bounds->applyTransform(*this->worldTransform);
    }
}


void CameraMan::applyTransform(Trfm& worldTransform) {

    Spatial::applyTransform(worldTransform);

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


SPtr<Node> CameraMan::clone() {

    return SPtr<Node>();
}


SPtr<Node> CameraMan::cloneTree(SPtr<Node>& parent) {

    return clone();
}
