#include "Trfm.h"

Trfm::Trfm()
:at(),
 sc(1),
 tr(),
 ro(),
 pos(),
 tmpV(),
 tmpM()
{}


Trfm::Trfm(const Trfm& rhs)
:at(),
 sc(rhs.sc),
 tr(),
 ro(),
 pos(),
 tmpV(),
 tmpM()
{}


Trfm& Trfm::operator =(const Trfm& rhs) {

    sc = rhs.sc;
    *tr = *rhs.tr;
    *ro = *rhs.ro;
    *at = *rhs.at;
    *pos = *rhs.pos;
    *tmpV = *rhs.tmpV;
    *tmpM = *rhs.tmpM;

    return *this;
}


Trfm::~Trfm() {}


void Trfm::toIdentity() {

    sc = 1;
    tr->toZeros();
    ro->toIdentity();
    at->toIdentity();
}


void Trfm::getPos(Vec& store) {

    store.toZeros();
    this->apply(store);
}


void Trfm::apply(Vec& vec) {

    at->mult(vec);
}