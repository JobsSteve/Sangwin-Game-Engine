#include "Mat3.h"

Mat3& Mat3::operator =(const Mat3& rhs) {

    Mat::operator =(rhs);

    return *this;
}


Mat3& Mat3::setTo(const Mat& mat) {

    Mat::setTo(mat);

    return *this;
}


Mat3& Mat3::setTo(float** m) {

    Mat::setTo(m);

    return *this;
}


Mat3& Mat3::setTo(float m00, float m01, float m02,
                  float m10, float m11, float m12,
                  float m20, float m21, float m22) {

    m[0][0] = m00; m[0][1] = m01; m[0][2] = m02;
    m[1][0] = m10; m[1][1] = m11; m[1][2] = m12;
    m[2][0] = m20; m[2][1] = m21; m[2][2] = m22;

    return *this;
}


Mat3& Mat3::toZeros() {

    Mat::toZeros();

    return *this;
}


Mat3& Mat3::toOnes() {

    Mat::toOnes();

    return *this;
}


Mat3& Mat3::toIdentity() {

    Mat::toIdentity();

    return *this;
}


Mat3& Mat3::fromAxes(const Vec3& uAxis, const Vec3& vAxis, const Vec3& wAxis) {

    m[0][0] = uAxis.v[0];
    m[1][0] = uAxis.v[1];
    m[2][0] = uAxis.v[2];

    m[0][1] = vAxis.v[0];
    m[1][1] = vAxis.v[1];
    m[2][1] = vAxis.v[2];

    m[0][2] = wAxis.v[0];
    m[1][2] = wAxis.v[1];
    m[2][2] = wAxis.v[2];

    return *this;
}


Mat3& Mat3::add(const Mat& mat) {

    Mat::add(mat);

    return *this;
}


Mat3& Mat3::add(float** m) {

    Mat::add(m);

    return *this;
}


Mat3& Mat3::add(float m00, float m01, float m02,
                float m10, float m11, float m12,
                float m20, float m21, float m22) {

    m[0][0]+=m00; m[0][1]+=m01; m[0][2]+=m02;
    m[1][0]+=m10; m[1][1]+=m11; m[1][2]+=m12;
    m[2][0]+=m20; m[2][1]+=m21; m[2][2]+=m22;

    return *this;
}


Mat3& Mat3::sub(const Mat& mat) {

    Mat::sub(mat);

    return *this;
}


Mat3& Mat3::sub(float** m) {

    Mat::sub(m);

    return *this;
}


Mat3& Mat3::sub(float m00, float m01, float m02,
                float m10, float m11, float m12,
                float m20, float m21, float m22) {

    m[0][0]-=m00; m[0][1]-=m01; m[0][2]-=m02;
    m[1][0]-=m10; m[1][1]-=m11; m[1][2]-=m12;
    m[2][0]-=m20; m[2][1]-=m21; m[2][2]-=m22;

    return *this;
}


Mat3& Mat3::mult(float s) {

    Mat::mult(s);

    return *this;
}


Mat3& Mat3::mult(const Mat& mat) {

    Mat::mult(mat);

    return *this;
}


Mat3& Mat3::mult(float** m) {

    Mat::mult(m);

    return *this;
}


Mat3& Mat3::mult(float m00, float m01, float m02,
                 float m10, float m11, float m12,
                 float m20, float m21, float m22) {

    tmpM[0][0] = m[0][0]*m00 + m[0][1]*m10 + m[0][2]*m20;
    tmpM[0][1] = m[0][0]*m01 + m[0][1]*m11 + m[0][2]*m21;
    tmpM[0][2] = m[0][0]*m02 + m[0][1]*m12 + m[0][2]*m22;

    tmpM[1][0] = m[1][0]*m00 + m[1][1]*m10 + m[1][2]*m20;
    tmpM[1][1] = m[1][0]*m01 + m[1][1]*m11 + m[1][2]*m21;
    tmpM[1][2] = m[1][0]*m02 + m[1][1]*m12 + m[1][2]*m22;

    tmpM[2][0] = m[2][0]*m00 + m[2][1]*m10 + m[2][2]*m20;
    tmpM[2][1] = m[2][0]*m01 + m[2][1]*m11 + m[2][2]*m21;
    tmpM[2][2] = m[2][0]*m02 + m[2][1]*m12 + m[2][2]*m22;

    Mat::setTo(tmpM);

    return *this;
}


void Mat3::mult(Vec& vec) {

    if(vec.l == 2) {
        float x = m[0][0]*vec.v[0] + m[0][1]*vec.v[1] + m[0][2];
        float y = m[1][0]*vec.v[0] + m[1][1]*vec.v[1] + m[1][2];

        vec.v[0] = x;
        vec.v[1] = y;
    }
    else if(vec.l == 3) {
        float x = m[0][0]*vec.v[0] + m[0][1]*vec.v[1] + m[0][2]*vec.v[2];
        float y = m[1][0]*vec.v[0] + m[1][1]*vec.v[1] + m[1][2]*vec.v[2];
        float z = m[2][0]*vec.v[0] + m[2][1]*vec.v[1] + m[2][2]*vec.v[2];

        vec.v[0] = x;
        vec.v[1] = y;
        vec.v[2] = z;
    }
}


Mat3& Mat3::div(float s) {

    Mat::div(s);

    return *this;
}


float Mat3::determinant() {

    float t00 = m[0][0]*((m[1][1]*m[2][2])-(m[2][1]*m[1][2]));
    float t10 = m[1][0]*((m[0][1]*m[2][2])-(m[2][1]*m[0][2]));
    float t20 = m[2][0]*((m[0][1]*m[1][2])-(m[1][1]*m[0][2]));

    return t00 - t10 + t20;
}


Mat3& Mat3::invert() {

    float t00 = m[1][1]*m[2][2] - m[1][2]*m[2][1];
    float t10 = m[2][1]*m[2][0] - m[1][0]*m[2][2];
    float t20 = m[1][0]*m[2][1] - m[1][1]*m[2][0];
    float det = m[0][0]*t00 + m[0][1]*t10 + m[0][2]*t20;

    if(fabs(det) <= 0) {

        Mat::toZeros();

        return *this;
    }

    tmpM[0][0] = m[1][1]*m[2][2] - m[1][2]*m[2][1];
    tmpM[0][1] = m[0][2]*m[2][1] - m[0][1]*m[2][2];
    tmpM[0][2] = m[0][1]*m[1][2] - m[0][2]*m[1][1];
    tmpM[1][0] = m[1][2]*m[2][0] - m[1][0]*m[2][2];
    tmpM[1][1] = m[0][0]*m[2][2] - m[0][2]*m[2][0];
    tmpM[1][2] = m[0][2]*m[1][0] - m[0][0]*m[1][2];
    tmpM[2][0] = m[1][0]*m[2][1] - m[1][1]*m[2][0];
    tmpM[2][1] = m[0][1]*m[2][0] - m[0][0]*m[2][1];
    tmpM[2][2] = m[0][0]*m[1][1] - m[0][1]*m[1][0];

    float one_over_det = 1.0f/det;
    for(int i=0; i<dim; i++) {
        for(int j=0; j<dim; j++) {
            m[i][j] = tmpM[i][j]*one_over_det;
        }
    }

    return *this;
}


void Mat3::toOpenGL(float* M) {

    M[ 0]=m[0][0]; M[ 1]=m[1][0]; M[ 2]=0.0f; M[ 3]=0.0f;
    M[ 4]=m[0][1]; M[ 5]=m[1][1]; M[ 6]=0.0f; M[ 7]=0.0f;
    M[ 8]=0.0f;    M[ 9]=0.0f;    M[10]=1.0f; M[11]=0.0f;
    M[12]=m[0][2]; M[13]=m[1][2]; M[14]=0.0f; M[15]=1.0f;
}