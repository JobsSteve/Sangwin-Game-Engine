#include "headers/utils/Object.h"

Object::Object()
:refCount(0)
{}

Object::Object(const Object& rhs)
:refCount(0)
{}

Object& Object::operator=(const Object& rhs) {
    return *this;
}

Object:: ~Object() {}
