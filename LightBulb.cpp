#include "LightBulb.h"

LightBulb& LightBulb::operator =(const LightBulb& rhs) {

    Light::operator =(rhs);

    hasAmbience = rhs.hasAmbience;
    *pos = *rhs.pos;
    constAttenuation = rhs.constAttenuation;
    linearAttenuation = rhs.linearAttenuation;
    quadAttenuation = rhs.quadAttenuation;

    return *this;
}

LightBulb::~LightBulb() {}


void LightBulb::setAttenuation(float constant, float linear, float quadratic) {

    if(constant >= 0) {
            constAttenuation = constant;
    }
    if(linear >= 0) {
        linearAttenuation = linear;
    }
    if(quadratic >= 0) {
        quadAttenuation = quadratic;
    }
}


SPtr<Light> LightBulb::clone() {

    SPtr<Light> clone(new LightBulb());

    clone->on = on;

    for(int i=0; i<4; i++) {
        clone->getColour()[i] = colour[i];
    }

    static_cast<LightBulb*> (clone.get())->hasAmbience = hasAmbience;
    static_cast<LightBulb*> (clone.get())->pos->setTo(*pos);
    static_cast<LightBulb*> (clone.get())->constAttenuation = constAttenuation;
    static_cast<LightBulb*> (clone.get())->linearAttenuation = linearAttenuation;
    static_cast<LightBulb*> (clone.get())->quadAttenuation = quadAttenuation;

    return clone;
}
