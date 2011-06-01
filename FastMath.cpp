#include "FastMath.h"
#include <math.h>

FastMath* FastMath::inst;
float FastMath::sinTable[720];
float FastMath::cosTable[720];
const float FastMath::PI;
const float FastMath::step;
const float FastMath::PI2;
const float FastMath::HALFPI;


FastMath::FastMath() {}
FastMath::~FastMath() {}


FastMath* FastMath::instance() {

    if(!inst) {
        inst = new FastMath();
        inst->build();
    }
    return inst;
}


void FastMath::build() {

    for(int i=0; i<720; i++) {
        sinTable[i] = sin(step*i);
    }

    for(int i=0; i<720; i++) {
        cosTable[i] = cos(step*i);
    }
}


float FastMath::fmAbs(float a) {

    int sign = a<0 ? -1 : 1;
    return sign*a;
}


float FastMath::fmSin(float a) {

    int sign = a <0 ? -1 : 1;
    a = fmod(a,6.283185308f);

    int index = static_cast<int>((sign*a)/step);
    return sign*sinTable[index];
}


float FastMath::fmCos(float a) {

    int sign = a <0 ? -1 : 1;
    a = fmod(a,6.283185308f);

    int index = static_cast<int>((sign*a)/step);
    return sign*cosTable[index];
}
