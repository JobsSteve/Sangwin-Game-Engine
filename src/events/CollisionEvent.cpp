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


bool CollisionEvent::isCollisionBetween(const SPtr<Bound<Vec3> >& a, const SPtr<Bound<Vec3> >& b) {

    if(A == a && B == b) {
        return true;
    }
    return false;
}

