#include "Light.h"

Light::Light()
:on(true),
 type(LIGHT),
 colour(new float[4])
{
    for(int i=0; i<4; i++) {
        colour[i] = 1;
    }
}


Light::Light(float rgbArray[])
:on(true),
 type(LIGHT),
 colour(new float[4])
{
    for(int i=0; i<3; i++) {
        colour[i] = rgbArray[i];
    }
    colour[3] = 1;
}


Light::Light(float red, float green, float blue)
:on(true),
 type(LIGHT),
 colour(new float[4])
{
    colour[0] = red;
    colour[1] = green;
    colour[2] = blue;
    colour[3] = 1;
}


Light::Light(const Light& rhs)
:on(rhs.on),
 type(LIGHT),
 colour(new float[4])
{
    for(int i=0; i<4; i++) {
        colour[i] = rhs.colour[i];
    }
}


Light& Light::operator =(const Light& rhs) {

    on = rhs.on;
    for(int i=0; i<4; i++) {
        colour[i] = rhs.colour[i];
    }

    return *this;
}


Light::~Light() {

    delete [] colour;
}


void Light::setColour(float rgbArray[]) {

    for(int i=0; i<3; i++) {
        colour[i] = rgbArray[i];
    }
    colour[3] = 1;
}


void Light::setColour(float r, float g, float b) {

    colour[0] = r;
    colour[1] = g;
    colour[2] = b;
    colour[3] = 1;
}


SPtr<Light> Light::clone() {

    SPtr<Light> clone(new Light());

    clone->on = on;
    for(int i=0; i<4; i++) {
        clone->colour[i] = colour[i];
    }
    return clone;
}
