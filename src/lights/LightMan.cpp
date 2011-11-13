#include "headers/lights/LightMan.h"

LightMan& LightMan::operator =(const LightMan& rhs) {

    Spatial::operator =(rhs);

    *worldDir = *rhs.worldDir;
    *light = *rhs.light;
    
    return *this;
}


void LightMan::attachChild(SPtr<Node> child) {}


void LightMan::detachChild(const SPtr<Node>& child) {}


SPtr<Node> LightMan::detachChild(int i) {

    return SPtr<Node>();
}


Vec3& LightMan::getWorldDir() {

    return *worldDir;
}


void LightMan::setLight(SPtr<LightBulb>& light) {

    this->light = light;
}


SPtr<LightBulb> LightMan::getLight() {

    return light;
}


SPtr<Node> LightMan::cloneTree(SPtr<Node>& parent) {

    return clone();
}


void LightMan::updateBounds(ArrayList<SPtr<BoundingVolume> >& childBounds, int from, int to) {

    /*If this LightMan has a Bounding Volume, then apply this LightMan's
      world transform to it. This ensures the Bounding Volume matches the
      position, scale and rotation of this LightMan.*/
    if(this->bounds.get()) {
        this->bounds->applyTransform(*(this->worldTransform));
    }
}


void LightMan::applyTransform(Trfm& worldTransform) {

    //Apply the transform to the spatial information of this LightMan.
    Spatial::applyTransform(worldTransform);

    //Update the position of the light to be the position of the worldTransform.
    light->getPos().toZeros();
    worldTransform.getPos(light->getPos());

    //If this LightMan's light is a SpotLight, update the world direction and
    //apply it to the SpotLight.
    if(light->type == Light::SPOTLIGHT) {

        worldDir->setTo(0,0,1);
        this->worldTransform->apply(*worldDir);

        SPtr<SpotLight> sl(light.smart_static_cast(SPtr<SpotLight>()));
        sl->getDir().setTo(sl->getPos());
        sl->getDir().sub(*worldDir);
        sl->getDir().norm();
    }
}


SPtr<Node> LightMan::clone() {

    SPtr<LightBulb> l(light->clone().smart_static_cast(SPtr<LightBulb>()));
    SPtr<Node> clone(new LightMan(name, l));
    static_cast<LightMan*> (clone.get())->localTransform->setTo(*(this->localTransform));

    return clone;
}