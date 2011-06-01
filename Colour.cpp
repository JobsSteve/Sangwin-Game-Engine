#include "Colour.h"

Colour::Colour()
:colour(new float[3])
{
    toDefault();
}


Colour::Colour(float* rgbArray)
:colour(new float[3])
{
    for(int i=0; i<3; i++) {
        colour[i] = rgbArray[i];
    }
}


Colour::Colour(const Colour& rhs)
:colour(new float[3])
{
    for(int i=0; i<3; i++) {
        colour[i] = rhs.colour[i];
    }
}


Colour& Colour::operator =(const Colour& rhs) {

    float* colourOrig = colour;
    colour = new float[3];
    for(int i=0; i<3; i++) {
        colour[i] = rhs.colour[i];
    }
    delete [] colourOrig;
    return *this;
}


Colour::~Colour() {

    delete [] colour;
}


void Colour::setTo(const Colour& att) {

    for(int i=0; i<3; i++) {
        colour[i] = att.colour[i];
    }
}


void Colour::setColour(float* rgbArray) {

    for(int i=0; i<3; i++) {
        colour[i] = rgbArray[i];
    }
}


void Colour::toDefault() {

    for(int i=0; i<3; i++) {
        colour[i] = 1;
    }
}