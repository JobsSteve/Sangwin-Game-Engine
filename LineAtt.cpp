#include "LineAtt.h"

LineAtt::LineAtt() {

    toDefault();
}


LineAtt::LineAtt(const LineAtt& rhs)
:isAntialiased(rhs.isAntialiased),
 lineWidth(rhs.lineWidth)
{}


LineAtt& LineAtt::operator =(const LineAtt& rhs) {

    isAntialiased = rhs.isAntialiased;
    lineWidth = rhs.lineWidth;

    return *this;
}


LineAtt::~LineAtt() {}


void LineAtt::setTo(const LineAtt& att) {

    this->isAntialiased = att.isAntialiased;
    this->lineWidth = att.lineWidth;
}


void LineAtt::toDefault() {

    isAntialiased = false;
    lineWidth = 1;
}
