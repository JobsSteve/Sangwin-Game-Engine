#include "headers/events/CollisionEvent.h"

CollisionEvent::CollisionEvent()
:inUse(false),
 A(),
 B()
{}


CollisionEvent::CollisionEvent(const CollisionEvent& rhs)
:inUse(rhs.inUse),
type(rhs.type),
A(rhs.A),
B(rhs.B)
{}


CollisionEvent& CollisionEvent::operator =(const CollisionEvent& rhs) {

    inUse = rhs.inUse;
    A = rhs.A;
    B = rhs.B;

    return *this;
}


CollisionEvent::~CollisionEvent() {}


CollisionEvent::EventType CollisionEvent::getType() {

    return type;
}


SPtr<Bound> CollisionEvent::getA() {

    return A;
}


SPtr<Bound> CollisionEvent::getB() {

    return B;
}


bool CollisionEvent::isCollisionBetween(const SPtr<Bound>& a, const SPtr<Bound>& b) {

    if(A == a && B == b) {
        return true;
    }
    return false;
}

