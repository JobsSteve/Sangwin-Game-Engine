#include "headers/cameras/Cam.h"
#include "headers/maths/FastMath.h"
#include <math.h>

Cam::Cam()
:viewportChanged(true),
 viewport(new Viewport()),
 pos(new Vec3()),
 modelView(new Mat4()),
 modelViewInv(new Mat4()),
 fov(45.0f),
 halfFOV(22.5f),
 nearClip(1),
 farClip(100),
 planes(new Plane[6]),
 tmp1(new Vec3()),
 tmp2(new Vec3()),
 tmp3(new Vec3()),
 tmp4(new Vec3()),
 ntl(new Vec3()),
 ntr(new Vec3()),
 nbl(new Vec3()),
 nbr(new Vec3()),
 ftl(new Vec3()),
 ftr(new Vec3()),
 fbl(new Vec3()),
 fbr(new Vec3()),
 x(new Vec3()),
 y(new Vec3()),
 z(new Vec3()),
 up(new Vec3(0,1,0)),
 lookAt(new Vec3(0,0,0)),
 frustumChanged(true)
{
    for(int i=0; i<6; i++) {
        planes[i] = Plane();
    }
    pos->setTo(0,0,1);
}


Cam::Cam(SPtr<Viewport>& aViewport, float cFov, float cNearClip, float cFarClip)
:viewportChanged(true),
 viewport(aViewport),
 pos(new Vec3()),
 modelView(new Mat4()),
 modelViewInv(new Mat4()),
 fov(cFov),
 halfFOV(cFov/2),
 nearClip(cNearClip),
 farClip(cFarClip),
 planes(new Plane[6]),
 tmp1(new Vec3()),
 tmp2(new Vec3()),
 tmp3(new Vec3()),
 tmp4(new Vec3()),
 ntl(new Vec3()),
 ntr(new Vec3()),
 nbl(new Vec3()),
 nbr(new Vec3()),
 ftl(new Vec3()),
 ftr(new Vec3()),
 fbl(new Vec3()),
 fbr(new Vec3()),
 x(new Vec3()),
 y(new Vec3()),
 z(new Vec3()),
 up(new Vec3(0,1,0)),
 lookAt(new Vec3(0,0,0)),
 frustumChanged(true)
{
    for(int i=0; i<6; i++) {
        planes[i] = Plane();
    }
    pos->setTo(0,0,1);
}


Cam::Cam(const Cam& rhs)
:viewportChanged(rhs.viewportChanged),
 viewport(new Viewport(*rhs.viewport)),
 pos(new Vec3(*rhs.pos)),
 modelView(new Mat4(*rhs.modelView)),
 modelViewInv(new Mat4(*rhs.modelViewInv)),
 fov(rhs.fov),
 halfFOV(rhs.halfFOV),
 ratio(rhs.ratio),
 nearClip(rhs.nearClip),
 farClip(rhs.farClip),
 planes(new Plane[6]),
 nh(rhs.nh),
 nw(rhs.nw),
 fh(rhs.fh),
 fw(rhs.fw),
 tanFOV(rhs.tanFOV),
 tmp1(new Vec3(*rhs.tmp1)),
 tmp2(new Vec3(*rhs.tmp2)),
 tmp3(new Vec3(*rhs.tmp3)),
 tmp4(new Vec3(*rhs.tmp4)),
 ntl(new Vec3(*rhs.ntl)),
 ntr(new Vec3(*rhs.ntr)),
 nbl(new Vec3(*rhs.nbl)),
 nbr(new Vec3(*rhs.nbr)),
 ftl(new Vec3(*rhs.ftl)),
 ftr(new Vec3(*rhs.ftr)),
 fbl(new Vec3(*rhs.fbl)),
 fbr(new Vec3(*rhs.fbr)),
 x(new Vec3(*rhs.x)),
 y(new Vec3(*rhs.y)),
 z(new Vec3(*rhs.z)),
 up(new Vec3(*rhs.up)),
 lookAt(new Vec3(*rhs.lookAt)),
 frustumChanged(rhs.frustumChanged)
{
    for(int i=0; i<6; i++) {
        planes[i] = rhs.planes[i];
    }
}



Cam& Cam::operator =(const Cam& rhs) {

    viewportChanged = rhs.viewportChanged;
    *viewport = *rhs.viewport;
    *pos = *rhs.pos;
    *modelView = *rhs.modelView;
    *modelViewInv = *rhs.modelViewInv;

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


void Cam::setViewport(SPtr<Viewport>& viewport) {

    viewportChanged = true;
    this->viewport = viewport;
}


Viewport& Cam::getViewport() {

    return *viewport;
}


void Cam::setPos(const Vec3& pos) {

    this->pos->setTo(pos);
}


Vec3& Cam::getPos() {

    return *pos;
}


Mat4& Cam::getModelView() {

    return *modelView;
}


void Cam::setFOV(float fov) {

    frustumChanged = true;
    if(fov > 0 && fov < 180) {
        this->fov = fov;
        this->halfFOV = fov/2;
    }
}


float Cam::getFOV() {

    return fov;
}


float Cam::getAspectRatio() {

    return ratio;
}


void Cam::setNearClip(float nearClip) {

    frustumChanged = true;
    if(nearClip < farClip) {
        this->nearClip = nearClip;
    }
}


float Cam::getNearClip() {

    return nearClip;
}


void Cam::setFarClip(float farClip) {

    frustumChanged = true;
    if(farClip > nearClip) {
        this->farClip = farClip;
    }
}


float Cam::getFarClip() {

    return farClip;
}


void Cam::setPos(float x, float y, float z) {

    pos->setTo(x,y,z);
}


void Cam::setUp(const Vec3& up) {

    this->up->setTo(up);
}


void Cam::setUp(float x, float y, float z) {

    this->up->setTo(x,y,z);
}


Vec3& Cam::getUp() {

    return *up;
}


void Cam::setLookAt(const Vec3& lookAt) {

    this->lookAt->setTo(lookAt);
}


void Cam::setLookAt(float x, float y, float z) {

    this->lookAt->setTo(x,y,z);
}


Vec3& Cam::getLookAt() {

    return *lookAt;
}


Vec3& Cam::getXAxis() {

    return *x;
}


Vec3& Cam::getYAxis() {

    return *y;
}


Vec3& Cam::getZAxis() {

    return *z;
}


bool Cam::isVisible(const Vec3& pos) {

    for(int i=0; i<6; i++) {
        if(planes[i].dist(pos) < 0) {
            return false;
        }
    }
    return true;
}


bool Cam::isVisible(const BoundingVolume& bounds) {

    if(bounds.type == bounds.SPHERE) {

        return isVisible(static_cast<const BoundingSphere&> (bounds));
    }
    return true;
}


void Cam::update() {

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


void Cam::onCanvasChanged(int width, int height) {

    viewport->onCanvasChanged(width,height);
    viewportChanged = true;
    
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


void Cam::generatePickRay(float screenX, float screenY, Vec3& pickPos, Vec3& pickDir) {

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


bool Cam::isVisible(const BoundingSphere& bounds) {

    for(int i=0; i<6; i++) {
        if(planes[i].dist(bounds.getWorldPos()) < -bounds.getWorldExtent().v[0]) {
            return false;
        }
    }
    return true;
}


void Cam::calculatePlanes() {

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