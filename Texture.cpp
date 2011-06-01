#include "Texture.h"

Texture::Texture() {}


Texture::Texture(int* cWidth, int* cHeight, void** cData, int cNumOfTextures)
:width(cWidth),
 height(cHeight),
 data(cData),
 numOfTextures(cNumOfTextures),
 alpha(false),
 texPtr(0)
{}


Texture::Texture(const Texture& rhs)
:width(rhs.width),
 height(rhs.height),
 data(rhs.data),
 numOfTextures(rhs.numOfTextures),
 alpha(rhs.alpha),
 texPtr(rhs.texPtr)
{}


Texture& Texture::operator =(const Texture& rhs) {

    width = rhs.width;
    height = rhs.height;
    data = rhs.data;
    numOfTextures = rhs.numOfTextures;
    alpha = rhs.alpha;
    texPtr = rhs.texPtr;

    return *this;
}


Texture::~Texture() {

    delete [] width;
    delete [] height;
    for(int i=0; i<numOfTextures; i++) {

        delete [] (int*)data[i];
    }
    delete [] data;
}


void Texture::setData(void** data) {

    this->data = data;
}



void Texture::setDimensions(int* width, int* height) {

    this->width = width;
    this->height = height;
}

