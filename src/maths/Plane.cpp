#include "headers/maths/Plane.h"

Plane::Plane()
:normal(new Vec3(0,1,0)),
 D(0),
 temp1(new Vec3()),
 temp2(new Vec3())
{}


Plane::Plane(const Vec3& cNormal, float cD)
:normal(new Vec3(cNormal)),
 D(cD),
 temp1(new Vec3()),
 temp2(new Vec3())
{}


Plane::Plane(const Vec3& a, const Vec3& b, const Vec3& c)
:normal(new Vec3()),
 D(0),
 temp1(new Vec3(c)),
 temp2(new Vec3(c))
{
    temp1->sub(a).norm();
    temp2->sub(b).norm();
    setTo(a,b,c);
}


Plane::Plane(const Plane& rhs)
:normal(new Vec3(*rhs.normal)),
 D(rhs.D),
 temp1(new Vec3(*rhs.temp1)),
 temp2(new Vec3(*rhs.temp2))
{}


Plane& Plane::operator =(const Plane& rhs) {

    *normal = *rhs.normal;
    D = rhs.D;
    *temp1 = *rhs.temp1;
    *temp2 = *rhs.temp2;

    return *this;
}


Plane& Plane::setTo(const Plane& plane) {

    normal->setTo(*plane.normal);
    D = plane.D;

    return *this;
}


Plane& Plane::setTo(const Vec3& vec, float D) {

    normal->setTo(vec);
    this->D = D;

    return *this;
}


Plane& Plane::setTo(const Vec3& a, const Vec3& b, const Vec3& c) {

    temp1->setTo(c).sub(a).norm();
    temp2->setTo(c).sub(b).norm();

    normal->setTo(*temp1).cross(*temp2).norm();

    temp1->setTo(0,0,0).sub(a);
    D = temp1->dot(*normal);

    return *this;
}


bool Plane::findIntersection(const Vec3& rayPos,
                             const Vec3& rayDir,
                                   Vec3& intersection) {

    //Check if ray intersects plane
    float a = normal->dot(rayDir);
    if(a > -0.00001f && a < 0.00001f) {
        return false;
    }

    //Check if ray position is behind the plane
    float b = -(normal->dot(rayPos) - D)/a;
    if(b < 0.00001f) {
        return false;
    }

    intersection.setTo(rayDir).mult(b).add(rayPos);

    return true;
}
