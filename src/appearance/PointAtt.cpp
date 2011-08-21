#include "headers/appearance/PointAtt.h"

PointAtt::PointAtt() {

    toDefault();
}


PointAtt::PointAtt(const PointAtt& rhs)
:isAntialiased(rhs.isAntialiased),
 pointSize(rhs.pointSize)
{}


PointAtt& PointAtt::operator =(const PointAtt& rhs) {

    isAntialiased = rhs.isAntialiased;
    pointSize = rhs.pointSize;

    return *this;
}


PointAtt::~PointAtt() {}


void PointAtt::setTo(const PointAtt& att) {

    this->isAntialiased = att.isAntialiased;
    this->pointSize = att.pointSize;
}


void PointAtt::toDefault() {

    isAntialiased = false;
    pointSize = 1;
}