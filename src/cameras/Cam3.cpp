#include "headers/cameras/Cam3.h"
#include "headers/maths/FastMath.h"
#include <math.h>

Cam3& Cam3::operator =(const Cam3& rhs) {

    Cam<Vec3>::operator =(rhs);

    fov = rhs.fov;
    halfFOV = rhs.halfFOV;
    ratio = rhs.ratio;
    nearClip = rhs.nearClip;
    farClip = rhs.farClip;
    for(int i=0; i<6; i++) {
        planes[i].setTo(rhs.planes[i]);
    }
    nh = rhs.nh;
    nw = rhs.nw;
    fh = rhs.fh;
    fw = rhs.fw;
    tanFOV = rhs.tanFOV;
    *tmp1 = *rhs.tmp1;
    *tmp2 = *rhs.tmp2;
    *tmp3 = *rhs.tmp3;
    *tmp4 = *rhs.tmp4;
    *ntl = *rhs.ntl;
    *ntr = *rhs.ntr;
    *nbl = *rhs.nbl;
    *nbr = *rhs.nbr;
    *ftl = *rhs.ftl;
    *ftr = *rhs.ftr;
    *fbl = *rhs.fbl;
    *fbr = *rhs.fbr;
    *x = *rhs.x;
    *y = *rhs.y;
    *z = *rhs.z;
    *up = *rhs.up;
    *lookAt = *rhs.lookAt;
    frustumChanged = rhs.frustumChanged;

    return *this;
}


void Cam3::setFOV(float fov) {

    frustumChanged = true;
    if(fov > 0 && fov < 180) {
        this->fov = fov;
        this->halfFOV = fov/2;
    }
}


void Cam3::setNearClip(float nearClip) {

    frustumChanged = true;
    if(nearClip < farClip) {
        this->nearClip = nearClip;
    }
}


void Cam3::setFarClip(float farClip) {

    frustumChanged = true;
    if(farClip > nearClip) {
        this->farClip = farClip;
    }
}


bool Cam3::isVisible(const Vec3& pos) {

    for(int i=0; i<6; i++) {
        if(planes[i].dist(pos) < 0) {
            return false;
        }
    }
    return true;
}


bool Cam3::isVisible(const BoundingVolume<Vec3>& bounds) {

    if(bounds.type == bounds.SPHERE) {

        return isVisible(static_cast<const BoundingSphere<Vec3>&> (bounds));
    }
    return true;
}


bool Cam3::isVisible(const BoundingSphere<Vec3>& bounds) {

    for(int i=0; i<6; i++) {
        if(planes[i].dist(bounds.getWorldPos()) < -bounds.getWorldExtent().v[0]) {
            return false;
        }
    }
    return true;
}


void Cam3::calculatePlanes() {

    // compute width and height of the near and far plane sections
        if(frustumChanged) {
            float tang = tan(FastMath::instance()->fmPi()/180 * halfFOV) ;
            nh = nearClip*tang;
            nw = nh*ratio;
            fh = farClip*tang;
            fw = fh*ratio;
        }

        // compute the Z axis of camera
        // this axis points in the opposite direction from the looking direction
        z->setTo(*pos).sub(*lookAt).norm();

        // X axis of camera with given "up" vector and Z axis
        x->setTo(*up).cross(*z).norm();

        // the real "up" vector is the cross product of Z and X
        y->setTo(*z).cross(*x);

        // near plane
        tmp4->setTo(*z).mult(nearClip);
        tmp1->setTo(*pos).sub(*tmp4);
        tmp2->setTo(*y).mult(nh);
        tmp3->setTo(*x).mult(nw);
        ntl->setTo(*tmp1).add(*tmp2).sub(*tmp3);
        ntr->setTo(*tmp1).add(*tmp2).add(*tmp3);
        nbl->setTo(*tmp1).sub(*tmp2).sub(*tmp3);
        nbr->setTo(*tmp1).sub(*tmp2).add(*tmp3);

        // far plane
        tmp4->setTo(*z).mult(farClip);
        tmp1->setTo(*pos).sub(*tmp4);
        tmp2->setTo(*y).mult(fh);
        tmp3->setTo(*x).mult(fw);
        ftl->setTo(*tmp1).add(*tmp2).sub(*tmp3);
        ftr->setTo(*tmp1).add(*tmp2).add(*tmp3);
        fbl->setTo(*tmp1).sub(*tmp2).sub(*tmp3);
        fbr->setTo(*tmp1).sub(*tmp2).add(*tmp3);

        // compute the six planes
        planes[0].setTo(*ntl,*ntr,*nbr); // near
        planes[1].setTo(*ftr,*ftl,*fbl); // far
        planes[2].setTo(*ntr,*ntl,*ftl); // top
        planes[3].setTo(*nbl,*nbr,*fbr); // bottom
        planes[4].setTo(*ntl,*nbl,*fbl); // left
        planes[5].setTo(*nbr,*ntr,*fbr); // right
}


void Cam3::generatePickRay(float screenX, float screenY, Vec3& pickPos, Vec3& pickDir) {

    // normalize the screen coords
    float sx = (screenX/(viewport->getDimensions().v[0]/2) - 1.0f)/ratio;
    float sy = 1.0f - screenY/(viewport->getDimensions().v[1]/2);

    // convert normalized screen coords to frustum coords
    sx *= tanFOV;
    sy *= tanFOV;

    // create a line in the frustum between the near and far clipping plane
    pickPos.setTo(sx*nearClip, sy*nearClip, nearClip);
    pickDir.setTo(sx*farClip , sy*farClip , -farClip);

    // invert the view matrix
    modelViewInv->setTo(*modelView);
    modelViewInv->invert();

    // convert frustum line to world line by transform the frustum line
    // by the inverse view matrix
    modelViewInv->mult(pickPos);
    modelViewInv->mult(pickDir);

    // convert line to ray
    pickDir.sub(pickPos).norm();
}


void Cam3::update() {

    // recalculate frustum
    calculatePlanes();
    tanFOV = tan(FastMath::instance()->fmToRadians(halfFOV));

    // recalculate model view matrix
    tmp1->setTo(*lookAt).sub(*pos).norm(); // (forward)
    tmp2->setTo(*tmp1).cross(*up).norm();  // (side)
    tmp3->setTo(*up);                     // (up)

    modelView->setTo(
             tmp2->v[0],  tmp2->v[1],  tmp2->v[2],  -pos->dot(*tmp2),
             tmp3->v[0],  tmp3->v[1],  tmp3->v[2],  -pos->dot(*tmp3),
            -tmp1->v[0], -tmp1->v[1], -tmp1->v[2],   pos->dot(*tmp1),
             0.0f,    0.0f,    0.0f,     1.0f);
}


void Cam3::onCanvasChanged(int width, int height) {

    Cam<Vec3>::onCanvasChanged(width,height);

    // recalculate frustum
    ratio = (static_cast<float>(width)/static_cast<float>(height));
    calculatePlanes();

    // calculate modelview matrix
    tmp1->setTo(*lookAt).sub(*pos).norm(); // (forward)
    tmp2->setTo(*tmp1).cross(*up).norm();  // (side)
    tmp3->setTo(*up);                     // (up)

    modelView->setTo(
             tmp2->v[0],  tmp2->v[1],  tmp2->v[2],  -pos->dot(*tmp2),
             tmp3->v[0],  tmp3->v[1],  tmp3->v[2],  -pos->dot(*tmp3),
            -tmp1->v[0], -tmp1->v[1], -tmp1->v[2],   pos->dot(*tmp1),
             0.0f,    0.0f,    0.0f,     1.0f);
}