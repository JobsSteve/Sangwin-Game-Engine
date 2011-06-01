#include "Trfm2.h"

Trfm2& Trfm2::operator =(const Trfm2& rhs) {

    Trfm::operator =(rhs);

    return *this;
}


void Trfm2::decompose() {

    //scale
    static_cast<Vec2*> (tmpV.get())->setTo(at->m[0][0], at->m[0][1]);
    sc = tmpV->length();

    //translate
    static_cast<Vec2*> (tr.get())->setTo(at->m[0][2], at->m[1][2]);

    //rotate
    ro->setTo(*at);
    ro->mult(1.0/sc);
}


void Trfm2::translateTo(float x, float y) {

    static_cast<Vec2*> (tr.get())->setTo(x, y);
}


void Trfm2::translateBy(float dx, float dy) {

     static_cast<Vec2*> (tr.get())->add(dx, dy);
}


void Trfm2::rotateTo(float angle) {

    float myCos = FastMath::instance()->fmCos(angle);
    float mySin = FastMath::instance()->fmSin(angle);

    ro->m[0][0]= myCos; ro->m[0][1]=-mySin;
    ro->m[1][0]= mySin; ro->m[1][1]= myCos;
}


void Trfm2::update() {

    static_cast<Mat3*> (at.get())->setTo(
                ro->m[0][0]*sc, ro->m[0][1]*sc, tr->v[0],
                ro->m[1][0]*sc, ro->m[1][1]*sc, tr->v[1],
                0.0, 0.0, 1.0);
}


void Trfm2::apply(Vec& vec) {

    at->mult(vec);
}


void Trfm2::applyInverse(Vec& vec) {

    tmpM->setTo(*at);
    static_cast<Mat2*> (tmpM.get())->invert();
    tmpM->mult(vec);
}
