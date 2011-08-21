#include "headers/lights/SpotLight.h"

SpotLight& SpotLight::operator =(const SpotLight& rhs) {

    LightBulb::operator =(rhs);

    *dir = *rhs.dir;
    angle = rhs.angle;
    focus = rhs.focus;

    return *this;
}


SpotLight::~SpotLight() {}


void SpotLight::setAngle(float angle) {

    if( (angle >= 0 && angle <= 90) || angle == 180) {
        this->angle = angle;
    }
}


SPtr<Light> SpotLight::clone() {

    SPtr<Light> clone(new SpotLight());

        clone->on = on;

    for(int i=0; i<4; i++) {
        clone->getColour()[i] = colour[i];
    }

    static_cast<SpotLight*> (clone.get())->hasAmbience = hasAmbience;
    static_cast<SpotLight*> (clone.get())->pos->setTo(*pos);
    static_cast<SpotLight*> (clone.get())->constAttenuation = constAttenuation;
    static_cast<SpotLight*> (clone.get())->linearAttenuation = linearAttenuation;
    static_cast<SpotLight*> (clone.get())->quadAttenuation = quadAttenuation;

    static_cast<SpotLight*> (clone.get())->dir->setTo(*dir);
    static_cast<SpotLight*> (clone.get())->angle = angle;
    static_cast<SpotLight*> (clone.get())->focus = focus;
    
    return clone;
}