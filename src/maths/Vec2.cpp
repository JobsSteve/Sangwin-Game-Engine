#include "headers/maths/Vec2.h"

Vec2& Vec2::operator =(const Vec2& rhs) {

    Vec::operator =(rhs);

    return *this;
}


Vec2& Vec2::setTo(const Vec& vec) {

    return setTo(vec.v[0],vec.v[1]);
}


Vec2& Vec2::setTo(float x, float y) {

    v[0] = x;
    v[1] = y;

    return *this;
}


Vec2& Vec2::setTo(float s) {

    Vec::setTo(s);

    return *this;
}


Vec2& Vec2::add(const Vec& vec) {

    return add(vec.v[0],vec.v[1]);
}


Vec2& Vec2::add(float x, float y) {

    v[0] += x;
    v[1] += y;

    return *this;
}


Vec2& Vec2::sub(const Vec& vec) {

    return sub(vec.v[0],vec.v[1]);
}


Vec2& Vec2::sub(float x, float y) {

    v[0] -= x;
    v[1] -= y;

    return *this;
}


Vec2& Vec2::mult(float s) {

    return mult(s,s);
}


Vec2& Vec2::mult(const Vec& vec) {

    return mult(vec.v[0],vec.v[1]);
}


Vec2& Vec2::mult(float x, float y) {

    v[0] *= x;
    v[1] *= y;

    return *this;
}


Vec2& Vec2::div(float s) {

    return div(s,s);
}


Vec2& Vec2::div(const Vec& vec) {

    return div(vec.v[0],vec.v[1]);
}


Vec2& Vec2::div(float x, float y) {

    v[0] /= x;
    v[1] /= y;

    return *this;
}


float Vec2::dot(const Vec& vec) {

    return dot(vec.v[0],vec.v[1]);
}


float Vec2::dot(float x, float y) {

    return (v[0]*x) + (v[1]*y);
}


float Vec2::dist(const Vec& vec) {

    return dist(vec.v[0],vec.v[1]);
}


float Vec2::dist(float x, float y) {

    float tx = v[0] - x;
    float ty = v[1] - y;

    return sqrt((tx*tx)+(ty*ty));
}


Vec2& Vec2::norm() {

    float length = Vec::length();

    if(length != 0) {
        return div(length);
    }
    else {
        return *this;
    }
}