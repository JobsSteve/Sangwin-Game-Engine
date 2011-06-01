#include "Material.h"
#include "Mat.h"

float* Material::defaultAmbient;
float* Material::defaultDiffuse;
float* Material::defaultSpecular;
float* Material::defaultEmissive;

Material::Material()
:ambientBuf(new float[4]),
 diffuseBuf(new float[4]),
 specularBuf(new float[4]),
 emissiveBuf(new float[4]),
 shininess(0),
 ambient(new float[3]),
 diffuse(new float[3]),
 specular(new float[3]),
 emissive(new float[3])
{
    init();
    toDefault();
}


Material::Material(float* cAmbient)
:ambientBuf(new float[4]),
 diffuseBuf(new float[4]),
 specularBuf(new float[4]),
 emissiveBuf(new float[4]),
 shininess(0),
 ambient(new float[3]),
 diffuse(new float[3]),
 specular(new float[3]),
 emissive(new float[3])
{
    init();
    toDefault();
    setAmbient(cAmbient);
}


Material::Material(float* cAmbient, float* cDiffuse)
:ambientBuf(new float[4]),
 diffuseBuf(new float[4]),
 specularBuf(new float[4]),
 emissiveBuf(new float[4]),
 shininess(0),
 ambient(new float[3]),
 diffuse(new float[3]),
 specular(new float[3]),
 emissive(new float[3])
{
    init();
    toDefault();
    setAmbient(cAmbient);
    setDiffuse(cDiffuse);
}


Material::Material(float* cAmbient, float* cDiffuse, float* cSpecular)
:ambientBuf(new float[4]),
 diffuseBuf(new float[4]),
 specularBuf(new float[4]),
 emissiveBuf(new float[4]),
 shininess(0),
 ambient(new float[3]),
 diffuse(new float[3]),
 specular(new float[3]),
 emissive(new float[3])
{
    init();
    toDefault();
    setAmbient(cAmbient);
    setDiffuse(cDiffuse);
    setSpecular(cSpecular);
}


Material::Material(float* cAmbient, float* cDiffuse, float* cSpecular, float* cEmissive)
:ambientBuf(new float[4]),
 diffuseBuf(new float[4]),
 specularBuf(new float[4]),
 emissiveBuf(new float[4]),
 shininess(0),
 ambient(new float[3]),
 diffuse(new float[3]),
 specular(new float[3]),
 emissive(new float[3])
{
    init();
    toDefault();
    setAmbient(cAmbient);
    setDiffuse(cDiffuse);
    setSpecular(cSpecular);
    setEmissive(cEmissive);
}


Material::Material(const Material& rhs)
:ambientBuf(new float[4]),
 diffuseBuf(new float[4]),
 specularBuf(new float[4]),
 emissiveBuf(new float[4]),
 shininess(rhs.shininess),
 ambient(new float[3]),
 diffuse(new float[3]),
 specular(new float[3]),
 emissive(new float[3])
{
    for(int i=0; i<3; i++) {

        ambientBuf[i] = rhs.ambientBuf[i];
        diffuseBuf[i] = rhs.diffuseBuf[i];
        specularBuf[i] = rhs.specularBuf[i];
        emissiveBuf[i] = rhs.emissiveBuf[i];
        ambient[i] = rhs.ambient[i];
        diffuse[i] = rhs.diffuse[i];
        specular[i] = rhs.specular[i];
        emissive[i] = rhs.emissive[i];
    }

    ambientBuf[3] = rhs.ambientBuf[3];
    diffuseBuf[3] = rhs.diffuseBuf[3];
    specularBuf[3] = rhs.specularBuf[3];
    emissiveBuf[3] = rhs.specularBuf[3];
}


Material& Material::operator =(const Material& rhs) {

    //Make sure to handle assignment to self!
    float* ambientBufOrig = ambientBuf;
    float* diffuseBufOrig = diffuseBuf;
    float* specularBufOrig = specularBuf;
    float* emissiveBufOrig = emissiveBuf;
    float* ambientOrig = ambient;
    float* diffuseOrig = diffuse;
    float* specularOrig = specular;
    float* emissiveOrig = emissive;

    for(int i=0; i<3; i++) {

        ambientBuf[i] = rhs.ambientBuf[i];
        diffuseBuf[i] = rhs.diffuseBuf[i];
        specularBuf[i] = rhs.specularBuf[i];
        emissiveBuf[i] = rhs.emissiveBuf[i];
        ambient[i] = rhs.ambient[i];
        diffuse[i] = rhs.diffuse[i];
        specular[i] = rhs.specular[i];
        emissive[i] = rhs.emissive[i];
    }

    ambientBuf[3] = rhs.ambientBuf[3];
    diffuseBuf[3] = rhs.diffuseBuf[3];
    specularBuf[3] = rhs.specularBuf[3];
    emissiveBuf[3] = rhs.specularBuf[3];

    shininess = rhs.shininess;

    delete [] ambientBufOrig;
    delete [] diffuseBufOrig;
    delete [] specularBufOrig;
    delete [] emissiveBufOrig;
    delete [] ambientOrig;
    delete [] diffuseOrig;
    delete [] specularOrig;
    delete [] emissiveOrig;

    return *this;
}


Material::~Material() {

    delete [] ambientBuf;
    delete [] diffuseBuf;
    delete [] specularBuf;
    delete [] emissiveBuf;
    delete [] ambient;
    delete [] diffuse;
    delete [] specular;
    delete [] emissive;
}


void Material::init() {

    if(defaultAmbient == 0) {
        defaultAmbient = new float[4];
        defaultAmbient[0] = 0.5f;
        defaultAmbient[1] = 0.5f;
        defaultAmbient[2] = 0.5f;
        defaultAmbient[3] = 1.0f;
    }
    if(defaultDiffuse == 0) {
        defaultDiffuse = new float[4];
        defaultDiffuse[0] = 0.5f;
        defaultDiffuse[1] = 0.5f;
        defaultDiffuse[2] = 0.5f;
        defaultDiffuse[3] = 1.0f;
    }
    if(defaultSpecular == 0) {
        defaultSpecular = new float[4];
        defaultSpecular[0] = 0.0f;
        defaultSpecular[1] = 0.0f;
        defaultSpecular[2] = 0.0f;
        defaultSpecular[3] = 1.0f;
    }
    if(defaultEmissive == 0) {
        defaultEmissive = new float[4];
        defaultEmissive[0] = 0.0f;
        defaultEmissive[1] = 0.0f;
        defaultEmissive[2] = 0.0f;
        defaultEmissive[3] = 1.0f;
    }
}


void Material::setTo(const Material& material) {

    shininess = material.shininess;
    for(int i=0; i<3; i++) {
            ambient[i] = material.ambient[i];
            diffuse[i] = material.diffuse[i];
            specular[i] = material.specular[i];
            emissive[i] = material.emissive[i];
    }
}


void Material::setShininess(float shininess) {

    if(shininess >= 0 && shininess <= 1) {
        this->shininess = shininess;
    }
}


void Material::setAmbient(float* rgbArray) {

    for(int i=0; i<3; i++) {
        ambient[i] = rgbArray[i];
    }
}


float* Material::getAmbient(float alpha) {

    for(int i=0; i<3; i++) {
        ambientBuf[i] = ambient[i];
    }
    ambientBuf[3] = alpha;
    return ambientBuf;
}


void Material::setDiffuse(float* rgbArray) {

    for(int i=0; i<3; i++) {
        diffuse[i] = rgbArray[i];
    }
}


float* Material::getDiffuse(float alpha) {

    for(int i=0; i<3; i++) {
        diffuseBuf[i] = diffuse[i];
    }
    diffuseBuf[3] = alpha;
    return diffuseBuf;
}


void Material::setSpecular(float* rgbArray) {

    for(int i=0; i<3; i++) {
        specular[i] = rgbArray[i];
    }
}


float* Material::getSpecular(float alpha) {

    for(int i=0; i<3; i++) {
        specularBuf[i] = specular[i];
    }
    specularBuf[3] = alpha;
    return specularBuf;
}


void Material::setEmissive(float* rgbArray) {

    for(int i=0; i<3; i++) {
        emissive[i] = rgbArray[i];
    }
}


float* Material::getEmissive(float alpha) {

    for(int i=0; i<3; i++) {
        emissiveBuf[i] = emissive[i];
    }
    emissiveBuf[3] = alpha;
    return emissiveBuf;
}


void Material::toDefault() {

    for(int i=0; i<3; i++) {
        ambient[i] = 0.5f;
        diffuse[i] = 0.5f;
        specular[i] = 0.0f;
        emissive[i] = 0.0f;
    }
}





