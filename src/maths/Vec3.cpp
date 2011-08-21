#include "headers/maths/Vec3.h"

Vec3& Vec3::operator =(const Vec3& rhs) {

    Vec::operator =(rhs);

    return *this;
}


Vec3& Vec3::setTo(float x, float y, float z) {

    v[0] = x;
    v[1] = y;
    v[2] = z;

    return *this;
}


Vec3& Vec3::setTo(float s) {

    Vec::setTo(s);

    return *this;
}


Vec3& Vec3::add(const Vec& vec) {

    return add(vec.v[0],vec.v[1],vec.v[2]);
}


Vec3& Vec3::add(float x, float y, float z) {

    v[0] += x;
    v[1] += y;
    v[2] += z;

    return *this;
}


Vec3& Vec3::sub(const Vec& vec) {

    return sub(vec.v[0],vec.v[1],vec.v[2]);
}


Vec3& Vec3::sub(float x, float y, float z) {

    v[0] -= x;
    v[1] -= y;
    v[2] -= z;

    return *this;
}


Vec3& Vec3::mult(float s) {

    return mult(s,s,s);
}


Vec3& Vec3::mult(const Vec& vec) {

    return mult(vec.v[0],vec.v[1],vec.v[2]);
}


Vec3& Vec3::mult(float x, float y, float z) {

    v[0] *= x;
    v[1] *= y;
    v[2] *= z;

    return *this;
}


Vec3& Vec3::div(float s) {

    return div(s,s,s);
}


Vec3& Vec3::div(const Vec& vec) {

    return div(vec.v[0],vec.v[1],vec.v[2]);
}


Vec3& Vec3::div(float x, float y, float z) {

    v[0] /= x;
    v[1] /= y;
    v[2] /= z;

    return *this;
}


float Vec3::dot(const Vec& vec) {

    return dot(vec.v[0],vec.v[1],vec.v[2]);
}


float Vec3::dot(float x, float y, float z) {

    return (v[0]*x) + (v[1]*y) + (v[2]*z);
}


Vec3& Vec3::cross(const Vec3& vec) {

    float nx = (v[1]*vec.v[2]) - (v[2]*vec.v[1]);
    float ny = (v[2]*vec.v[0]) - (v[0]*vec.v[2]);
    float nz = (v[0]*vec.v[1]) - (v[1]*vec.v[0]);

    v[0] = nx;
    v[1] = ny;
    v[2] = nz;

    return *this;
}


Vec3& Vec3::cross(float x, float y, float z) {

    float nx = (v[1]*z) - (v[2]*y);
    float ny = (v[2]*x) - (v[0]*z);
    float nz = (v[0]*y) - (v[1]*x);

    v[0] = nx;
    v[1] = ny;
    v[2] = nz;

    return *this;
}


float Vec3::dist(const Vec& vec) {

    return dist(vec.v[0],vec.v[1],vec.v[2]);
}


float Vec3::dist(float x, float y, float z) {

    float tx = v[0] - x;
    float ty = v[1] - y;
    float tz = v[2] - z;

    return sqrt((tx*tx)+(ty*ty)+(tz*tz));
}


Vec3& Vec3::norm() {

    float length = Vec::length();

    if(length != 0) {
        return div(length);
    }
    else {
        return *this;
    }
}
