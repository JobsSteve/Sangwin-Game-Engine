#include "headers/scenegraph/Trfm3.h"

Trfm3& Trfm3::operator =(const Trfm3& rhs) {

    Trfm::operator =(rhs);

    return *this;
}


void Trfm3::decompose() {

    //scale
    static_cast<Vec3*> (tmpV.get())->setTo(at->m[0][0], at->m[0][1], at->m[0][2]);
    sc = tmpV->length();

    //translate
    static_cast<Vec3*> (tr.get())->setTo(at->m[0][3], at->m[1][3], at->m[2][3]);

    //rotate
    ro->setTo(*at);
    ro->mult(1.0f/sc);
}


float Trfm3::getRotation(Vec3& axis) {

    float fTrace = ro->m[0][0] + ro->m[1][1] + ro->m[2][2];
    float fCos = 0.5f*(fTrace - 1.0f);
    float angle = acos(fCos);  // in [0,PI]

    if(angle > 0.0f) {
        if(angle < FastMath::instance()->fmPi()) {
            axis.v[0] = ro->m[1][2] - ro->m[2][1];
            axis.v[1] = ro->m[2][0] - ro->m[0][2];
            axis.v[2] = ro->m[0][1] - ro->m[1][0];
            axis.norm();
        }
        else {
            // angle is PI
            float halfInverse;
            if(ro->m[0][0] >= ro->m[1][1]) {
                // r00 >= r11
                if(ro->m[0][0] >= ro->m[2][2]) {
                    // r00 is maximum diagonal term
                    axis.v[0] = 0.5f*sqrt(ro->m[0][0] - ro->m[1][1] - ro->m[2][2] + 1.0f);
                    halfInverse = 0.5f/axis.v[0];
                    axis.v[1] = halfInverse*ro->m[1][0];
                    axis.v[2] = halfInverse*ro->m[2][0];
                }
                else {
                    // r22 is maximum diagonal term
                    axis.v[2] = 0.5f*sqrt(ro->m[2][2] - ro->m[0][0] - ro->m[1][1] + 1.0f);
                    halfInverse = 0.5/axis.v[2];
                    axis.v[0] = halfInverse*ro->m[2][0];
                    axis.v[1] = halfInverse*ro->m[2][1];
                }
            }
            else {
                // r11 > r00
                if(ro->m[1][1] >= ro->m[2][2]) {
                    // r11 is maximum diagonal term
                    axis.v[1] = 0.5f*sqrt(ro->m[1][1] - ro->m[0][0] - ro->m[2][2] + 1.0f);
                    halfInverse  = 0.5f/axis.v[1];
                    axis.v[0] = halfInverse*ro->m[1][0];
                    axis.v[2] = halfInverse*ro->m[2][1];
                }
                else {
                    // r22 is maximum diagonal term
                    axis.v[2] = 0.5f*sqrt(ro->m[2][2] - ro->m[0][0] - ro->m[1][1] + 1.0f);
                    halfInverse = 0.5f/axis.v[2];
                    axis.v[0] = halfInverse*ro->m[2][0];
                    axis.v[1] = halfInverse*ro->m[2][1];
                }
            }
        }
    }
    else {
        /*
         * The angle is 0 and the matrix is the identity. Any axis will work
         * so just use the x-axis.
         */
        axis.v[0] = 1.0f;
        axis.v[1] = 0.0f;
        axis.v[2] = 0.0f;
    }

    return FastMath::instance()->fmToDegrees(angle);
}


void Trfm3::getRotationXYZ(const Vec3& store) {

    if(ro->m[0][2] < +1) {
        if(ro->m[0][2] > -1) {
            store.v[1] = asin(ro->m[0][2]);
            store.v[0] = atan2(-ro->m[1][2], ro->m[2][2]);
            store.v[2] = atan2(-ro->m[0][1], ro->m[0][0]);
        }
        else {
            store.v[1] = -FastMath::instance()->fmPi()/2;
            store.v[0] = -atan2(ro->m[1][0], ro->m[1][1]);
            store.v[2] = 0;
        }
    }
    else {
        store.v[1] = FastMath::instance()->fmPi()/2;
        store.v[0] = atan2(ro->m[1][0], ro->m[1][1]);
        store.v[2] = 0;
    }
}


void Trfm3::getRotationYXZ(const Vec3& store) {

    if(ro->m[1][2] < +1) {
        if(ro->m[1][2] > -1) {
            store.v[0] = asin(-ro->m[1][2]);
            store.v[1] = atan2(ro->m[0][2], ro->m[2][2]);
            store.v[2] = atan2(ro->m[1][0], ro->m[1][1]);
        }
        else {
            // Not a unique solution!
            store.v[0] = FastMath::instance()->fmPi()/2;
            store.v[1] = -atan2(-ro->m[0][1], ro->m[0][0]);
            store.v[2] = 0;
        }
    }
    else {
        // Not a unique solution!
        store.v[0] = -FastMath::instance()->fmPi()/2;
        store.v[1] = atan2(-ro->m[0][1], ro->m[0][0]);
        store.v[2] = 0;
    }
}


void Trfm3::translateTo(float x, float y, float z) {

    static_cast<Vec3*> (tr.get())->setTo(x, y, z);
}


void Trfm3::translateBy(float dx, float dy, float dz) {

    static_cast<Vec3*> (tr.get())->add(dx, dy, dz);
}


void Trfm3::rotateTo(float angle, float x, float y, float z) {

    float myCos = FastMath::instance()->fmCos(angle);
    float mySin = FastMath::instance()->fmSin(angle);

    float oneMinusCos = 1.0f - myCos;
    float x2 = x*x;
    float y2 = y*y;
    float z2 = z*z;
    float xym = x*y*oneMinusCos;
    float xzm = x*z*oneMinusCos;
    float yzm = y*z*oneMinusCos;
    float xSin = x*mySin;
    float ySin = y*mySin;
    float zSin = z*mySin;

    ro->m[0][0] = x2*oneMinusCos + myCos;
    ro->m[0][1] = xym - zSin;
    ro->m[0][2] = xzm + ySin;
    ro->m[1][0] = xym + zSin;
    ro->m[1][1] = y2*oneMinusCos + myCos;
    ro->m[1][2] = yzm - xSin;
    ro->m[2][0] = xzm - ySin;
    ro->m[2][1] = yzm + xSin;
    ro->m[2][2] = z2*oneMinusCos + myCos;
}


void Trfm3::rotateTo(float angle, const Vec3& axis) {

    float myCos = FastMath::instance()->fmCos(angle);
    float mySin = FastMath::instance()->fmSin(angle);

    float oneMinusCos = 1.0f-myCos;
    float x2 = axis.v[0]*axis.v[0];
    float y2 = axis.v[1]*axis.v[1];
    float z2 = axis.v[2]*axis.v[2];
    float xym = axis.v[0]*axis.v[1]*oneMinusCos;
    float xzm = axis.v[0]*axis.v[2]*oneMinusCos;
    float yzm = axis.v[1]*axis.v[2]*oneMinusCos;
    float xSin = axis.v[0]*mySin;
    float ySin = axis.v[1]*mySin;
    float zSin = axis.v[2]*mySin;

    ro->m[0][0] = x2*oneMinusCos + myCos;
    ro->m[0][1] = xym - zSin;
    ro->m[0][2] = xzm + ySin;
    ro->m[1][0] = xym + zSin;
    ro->m[1][1] = y2*oneMinusCos + myCos;
    ro->m[1][2] = yzm - xSin;
    ro->m[2][0] = xzm - ySin;
    ro->m[2][1] = yzm + xSin;
    ro->m[2][2] = z2*oneMinusCos + myCos;
}


void Trfm3::rotateToXYZ(float pitch, float yaw, float roll) {

    float sy = FastMath::instance()->fmSin(yaw);
    float cy = FastMath::instance()->fmCos(yaw);
    float sp = FastMath::instance()->fmSin(pitch);
    float cp = FastMath::instance()->fmCos(pitch);
    float sr = FastMath::instance()->fmSin(roll);
    float cr = FastMath::instance()->fmCos(roll);

    // rotate around X then Y then Z
    ro->m[0][0] = cy*cr;
    ro->m[0][1] = cy*-sr;
    ro->m[0][2] = sy;
    ro->m[1][0] = -sp*-sy*cr + cp*sr;
    ro->m[1][1] = -sp*-sy*-sr + cp*cr;
    ro->m[1][2] = -sp*cy;
    ro->m[2][0] = cp*-sy*cr + sp*sr;
    ro->m[2][1] = cp*-sy*-sr + sp*cr;
    ro->m[2][2] = cp*cy;
}


void Trfm3::rotateToXYZ(const Vec3& rot) {

    float sy = FastMath::instance()->fmSin(rot.v[1]);
    float cy = FastMath::instance()->fmCos(rot.v[1]);
    float sp = FastMath::instance()->fmSin(rot.v[0]);
    float cp = FastMath::instance()->fmCos(rot.v[0]);
    float sr = FastMath::instance()->fmSin(rot.v[2]);
    float cr = FastMath::instance()->fmCos(rot.v[2]);

    // rotate around X then Y then Z
    ro->m[0][0] = cy*cr;
    ro->m[0][1] = cy*-sr;
    ro->m[0][2] = sy;
    ro->m[1][0] = -sp*-sy*cr + cp*sr;
    ro->m[1][1] = -sp*-sy*-sr + cp*cr;
    ro->m[1][2] = -sp*cy;
    ro->m[2][0] = cp*-sy*cr + sp*sr;
    ro->m[2][1] = cp*-sy*-sr + sp*cr;
    ro->m[2][2] = cp*cy;
}


void Trfm3::rotateToYXZ(float pitch, float yaw, float roll) {

    float sy = FastMath::instance()->fmSin(yaw);
    float cy = FastMath::instance()->fmCos(yaw);
    float sx = FastMath::instance()->fmSin(pitch);
    float cx = FastMath::instance()->fmCos(pitch);
    float sz = FastMath::instance()->fmSin(roll);
    float cz = FastMath::instance()->fmCos(roll);

    // rotate around Y then X then Z
    ro->m[0][0] = cy*cz + sy*sx*sz;
    ro->m[0][1] = cy*-sz + sy*sx*cz;
    ro->m[0][2] = sy*cx;
    ro->m[1][0] = cx*sz;
    ro->m[1][1] = cx*cz;
    ro->m[1][2] = -sx;
    ro->m[2][0] = -sy*cz + cy*sx*sz;
    ro->m[2][1] = -sy*-sz + cy*sx*cz;
    ro->m[2][2] = cy*cx;
}


void Trfm3::rotateToYXZ(const Vec3& rot) {

    float sy = FastMath::instance()->fmSin(rot.v[1]);
    float cy = FastMath::instance()->fmCos(rot.v[1]);
    float sx = FastMath::instance()->fmSin(rot.v[0]);
    float cx = FastMath::instance()->fmCos(rot.v[0]);
    float sz = FastMath::instance()->fmSin(rot.v[2]);
    float cz = FastMath::instance()->fmCos(rot.v[2]);

    // rotate around Y then X then Z
    ro->m[0][0] = cy*cz + sy*sx*sz;
    ro->m[0][1] = cy*-sz + sy*sx*cz;
    ro->m[0][2] = sy*cx;
    ro->m[1][0] = cx*sz;
    ro->m[1][1] = cx*cz;
    ro->m[1][2] = -sx;
    ro->m[2][0] = -sy*cz + cy*sx*sz;
    ro->m[2][1] = -sy*-sz + cy*sx*cz;
    ro->m[2][2] = cy*cx;
}


void Trfm3::update() {

    at.smart_static_cast(SPtr<Mat4>())->setTo(
                ro->m[0][0]*sc, ro->m[0][1]*sc, ro->m[0][2], tr->v[0],
                ro->m[1][0]*sc, ro->m[1][1]*sc, ro->m[1][2], tr->v[1],
                ro->m[2][0]*sc, ro->m[2][1]*sc, ro->m[2][2], tr->v[2],
                0.0f, 0.0f, 0.0f, 1.0f);
}


void Trfm3::applyInverse(Vec& vec) {

    tmpM->setTo(*at);
    static_cast<Mat3*> (tmpM.get())->invert();

    tmpM->mult(vec);
}