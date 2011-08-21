#include "headers/lights/DirLight.h"

DirLight& DirLight::operator =(const DirLight& rhs) {

    Light::operator =(rhs);

    *dir = *rhs.dir;

    return *this;
}


DirLight::~DirLight() {}


SPtr<Light> DirLight::clone() {

    SPtr<Light> clone(new DirLight());

    clone->on = on;

    for(int i=0; i<4; i++) {
        clone->getColour()[i] = colour[i];
    }

    static_cast<DirLight*> (clone.get())->dir->setTo(*dir);

    return clone;
}
