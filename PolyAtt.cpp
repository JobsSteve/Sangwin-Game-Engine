#include "PolyAtt.h"

PolyAtt::PolyAtt() {

    toDefault();
}


PolyAtt::PolyAtt(const PolyAtt& rhs)
:cullFace(rhs.cullFace)
{}


PolyAtt& PolyAtt::operator =(const PolyAtt& rhs) {

    cullFace = rhs.cullFace;

    return *this;
}


PolyAtt::~PolyAtt() {}
