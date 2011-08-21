#include "headers/maths/Vec.h"
#include <math.h>

Vec::Vec()
:l(0),
 v(0)
{}


Vec::Vec(int dim)
:l(dim),
 v(new float[dim])
{
    for(int i=0; i<dim; i++) {
        v[i] = 0;
    }
}


Vec::Vec(float vec[], int dim)
:l(dim),
 v(new float[dim])
{
    for(int i=0; i < dim; i++) {
        v[i] = vec[i];
    }
}


Vec::Vec(const Vec& rhs)
:l(rhs.l),
 v(new float[rhs.l])
{
    for(int i=0; i<rhs.l; i++) {
        v[i] = rhs.v[i];
    }
}


Vec& Vec::operator =(const Vec& rhs) {
    
    float* vOrig = v;
    v = new float[rhs.l];
    for(int i=0; i<rhs.l; i++) {
        v[i] = rhs.v[i];
    }
    delete [] vOrig;
    l = rhs.l;

    return *this;
}


Vec::~Vec() {

    delete [] v;
}


Vec& Vec::setTo(const Vec& vec) {

    for(int i=0; i< l; i++) {
        v[i] = vec.v[i];
    }
    return *this;
}


Vec& Vec::setTo(float v[]) {

    for(int i=0; i< l; i++) {
        this->v[i]=v[i];
    }
    return *this;
}


Vec& Vec::setTo(float s) {

    for(int i=0; i< l; i++) {
        v[i]=s;
    }
    return *this;
}


Vec& Vec::toZeros() {

    for(int i=0; i < l; i++) {
        v[i]=0;
    }
    return *this;
}


Vec& Vec::toOnes() {
    for(int i=0; i < l; i++) {
        v[i]=1;
    }
    return *this;
}


Vec& Vec::add(const Vec& vec) {

    for(int i=0; i < l; i++) {
        v[i] += vec.v[i];
    }
    return *this;
}


Vec& Vec::add(float v[]) {

    for(int i=0; i < l; i++) {
        this->v[i] += v[i];
    }
    return *this;
}


Vec& Vec::sub(const Vec& vec) {

    for(int i=0; i < l; i++) {
        v[i] -= vec.v[i];
    }
    return *this;
}


Vec& Vec::sub(float v[]) {

    for(int i=0; i < l; i++) {
        this->v[i] -= v[i];
    }
    return *this;
}


Vec& Vec::mult(float s) {

    for(int i=0; i < l; i++) {
        v[i] *= s;
    }
    return *this;
}


Vec& Vec::mult(const Vec& vec) {

    for(int i=0; i < l; i++) {
        v[i] *= vec.v[i];
    }
    return *this;
}


Vec& Vec::mult(float v[]) {

    for(int i=0; i < l; i++) {
        this->v[i] *= v[i];
    }
    return *this;
}


Vec& Vec::div(float s) {

    for(int i=0; i < l; i++) {
        v[i] /= s;
    }
    return *this;
}


Vec& Vec::div(const Vec& vec) {

    for(int i=0; i < l; i++) {
        v[i] /= vec.v[i];
    }
    return *this;
}


Vec& Vec::div(float v[]) {

    for(int i=0; i < l; i++) {
        this->v[i] /= v[i];
    }
    return *this;
}


float Vec::dot(const Vec& vec) {

    float dot=0;
    for(int i=0; i < l; i++) {
        dot += v[i]*vec.v[i];
    }
    return dot;
}


float Vec::dot(float v[]) {

    float dot=0;
    for(int i=0; i < l; i++) {
        dot += this->v[i]*v[i];
    }
    return dot;
}


float Vec::dist(const Vec& vec) {

    float dist=0;
    float d=0;
    for(int i=0; i < l; i++) {
        d = v[i] - vec.v[i];
        dist += d*d;
    }
    return dist;
}


float Vec::dist(float v[]) {

    float dist=0;
    float d=0;
    for(int i=0; i < l; i++) {
        d = this->v[i]-v[i];
        dist += d*d;
    }
    return dist;
}


float Vec::length() {

    float tl = 0;
    for(int i=0; i < l; i++) {
        tl += v[i]*v[i];
    }
    return sqrt(tl);
}


float Vec::lengthSquared() {

    float tl = 0;
    for(int i=0; i < l; i++) {
        tl += v[i]*v[i];
    }
    return tl;
}


Vec& Vec::norm() {
    
    float t1 = length();
    if(t1 != 0) {
        return div(t1);
    }
    else {
        return *this;
    }
}


bool Vec::equals(const Vec& vec) {

    for(int i=0; i < l; i++) {
        if(v[i] != vec.v[i]) {
            return false;
        }
    }
    return true;
}
