#include "TexCoord.h"

TexCoord::TexCoord(int cSize)
:size(cSize),
 coords(new float[cSize]),
 pos(0)
{}


TexCoord::TexCoord(const TexCoord& rhs)
:size(rhs.size),
 coords(new float[rhs.size]),
 pos(rhs.pos)
{
    for(int i=0; i<rhs.size; i++) {
        coords[i] = rhs.coords[i];
    }
}


TexCoord& TexCoord::operator =(const TexCoord& rhs) {

    size = rhs.size;
    float* coordsOrig = coords;
    coords = new float[rhs.size];
    for(int i=0; i<rhs.size; i++) {
        coords[i] = rhs.coords[i];
    }
    delete [] coordsOrig;
    pos = rhs.pos;
    return *this;
}


TexCoord::~TexCoord() {

    delete [] coords;
}


void TexCoord::addCoord(const Vec2& vec) {

    coords[pos] = vec.v[0];
    coords[pos+1] = vec.v[1];
    pos+=2;
}


void TexCoord::addCoord(float c) {

    coords[pos] = c;
    pos++;
}
