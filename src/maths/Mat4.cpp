#include "headers/maths/Mat4.h"

Mat4& Mat4::operator =(const Mat4& rhs) {

    Mat::operator =(rhs);

    return *this;
}


Mat4& Mat4::setTo(const Mat& mat) {

    Mat::setTo(mat);

    return *this;
}


Mat4& Mat4::setTo(float** m) {

    Mat::setTo(m);

    return *this;
}


Mat4& Mat4::setTo(float m00, float m01, float m02, float m03,
                  float m10, float m11, float m12, float m13,
                  float m20, float m21, float m22, float m23,
                  float m30, float m31, float m32, float m33) {

    m[0][0]=m00; m[0][1]=m01; m[0][2]=m02; m[0][3]=m03;
    m[1][0]=m10; m[1][1]=m11; m[1][2]=m12; m[1][3]=m13;
    m[2][0]=m20; m[2][1]=m21; m[2][2]=m22; m[2][3]=m23;
    m[3][0]=m30; m[3][1]=m31; m[3][2]=m32; m[3][3]=m33;

    return *this;
}


Mat4& Mat4::toZeros() {

    Mat::toZeros();

    return *this;
}


Mat4& Mat4::toOnes() {

    Mat::toOnes();

    return *this;
}


Mat4& Mat4::toIdentity() {

    Mat::toIdentity();

    return *this;
}


Mat4& Mat4::add(const Mat& mat) {

    Mat::add(mat);

    return *this;
}


Mat4& Mat4::add(float** m) {

    Mat::add(m);

    return *this;
}


Mat4& Mat4::add(float m00, float m01, float m02, float m03,
                float m10, float m11, float m12, float m13,
                float m20, float m21, float m22, float m23,
                float m30, float m31, float m32, float m33) {

    m[0][0]+=m00; m[0][1]+=m01; m[0][2]+=m02; m[0][3]+=m03;
    m[1][0]+=m10; m[1][1]+=m11; m[1][2]+=m12; m[1][3]+=m13;
    m[2][0]+=m20; m[2][1]+=m21; m[2][2]+=m22; m[2][3]+=m23;
    m[3][0]+=m30; m[3][1]+=m31; m[3][2]+=m32; m[3][3]+=m33;

    return *this;
}


Mat4& Mat4::sub(const Mat& mat) {

    Mat::sub(mat);

    return *this;
}


Mat4& Mat4::sub(float** m) {

    Mat::sub(m);

    return *this;
}


Mat4& Mat4::sub(float m00, float m01, float m02, float m03,
                float m10, float m11, float m12, float m13,
                float m20, float m21, float m22, float m23, float m30,
                float m31, float m32, float m33) {

    m[0][0]-=m00; m[0][1]-=m01; m[0][2]-=m02; m[0][3]-=m03;
    m[1][0]-=m10; m[1][1]-=m11; m[1][2]-=m12; m[1][3]-=m13;
    m[2][0]-=m20; m[2][1]-=m21; m[2][2]-=m22; m[2][3]-=m23;
    m[3][0]-=m30; m[3][1]-=m31; m[3][2]-=m32; m[3][3]-=m33;

    return *this;
}


Mat4& Mat4::mult(float s) {

    Mat::mult(s);

    return *this;
}


Mat4& Mat4::mult(const Mat& mat) {

    Mat::mult(mat);

    return *this;
}


Mat4& Mat4::mult(float** m) {

    Mat::mult(m);

    return *this;
}


Mat4& Mat4::mult(float m00, float m01, float m02, float m03,
                 float m10, float m11, float m12, float m13,
                 float m20, float m21, float m22, float m23,
                 float m30, float m31, float m32, float m33) {

    tmpM[0][0] = m[0][0]*m00 + m[0][1]*m10 + m[0][2]*m20 + m[0][3]*m30;
    tmpM[0][1] = m[0][0]*m01 + m[0][1]*m11 + m[0][2]*m21 + m[0][3]*m31;
    tmpM[0][2] = m[0][0]*m02 + m[0][1]*m12 + m[0][2]*m22 + m[0][3]*m32;
    tmpM[0][3] = m[0][0]*m03 + m[0][1]*m13 + m[0][2]*m23 + m[0][3]*m33;

    tmpM[1][0] = m[1][0]*m00 + m[1][1]*m10 + m[1][2]*m20 + m[1][3]*m30;
    tmpM[1][1] = m[1][0]*m01 + m[1][1]*m11 + m[1][2]*m21 + m[1][3]*m31;
    tmpM[1][2] = m[1][0]*m02 + m[1][1]*m12 + m[1][2]*m22 + m[1][3]*m32;
    tmpM[1][3] = m[1][0]*m03 + m[1][1]*m13 + m[1][2]*m23 + m[1][3]*m33;

    tmpM[2][0] = m[2][0]*m00 + m[2][1]*m10 + m[2][2]*m20 + m[2][3]*m30;
    tmpM[2][1] = m[2][0]*m01 + m[2][1]*m11 + m[2][2]*m21 + m[2][3]*m31;
    tmpM[2][2] = m[2][0]*m02 + m[2][1]*m12 + m[2][2]*m22 + m[2][3]*m32;
    tmpM[2][3] = m[2][0]*m03 + m[2][1]*m13 + m[2][2]*m23 + m[2][3]*m33;

    tmpM[3][0] = m[3][0]*m00 + m[3][1]*m10 + m[3][2]*m20 + m[3][3]*m30;
    tmpM[3][1] = m[3][0]*m01 + m[3][1]*m11 + m[3][2]*m21 + m[3][3]*m31;
    tmpM[3][2] = m[3][0]*m02 + m[3][1]*m12 + m[3][2]*m22 + m[3][3]*m32;
    tmpM[3][3] = m[3][0]*m03 + m[3][1]*m13 + m[3][2]*m23 + m[3][3]*m33;

    Mat::setTo(tmpM);

    return *this;
}


void Mat4::mult(Vec& vec) {

    if(vec.l == 3) {
        float mx = m[0][0]*vec.v[0] + m[0][1]*vec.v[1] + m[0][2]*vec.v[2] + m[0][3];
        float my = m[1][0]*vec.v[0] + m[1][1]*vec.v[1] + m[1][2]*vec.v[2] + m[1][3];
        float mz = m[2][0]*vec.v[0] + m[2][1]*vec.v[1] + m[2][2]*vec.v[2] + m[2][3];

        vec.v[0] = mx;
        vec.v[1] = my;
        vec.v[2] = mz;
    }
}


Mat4& Mat4::div(float s) {

    Mat::div(s);

    return *this;
}


float Mat4::determinant() {

    float a0 = m[0][0]*m[1][1] - m[0][1]*m[1][0];
    float a1 = m[0][0]*m[1][2] - m[0][2]*m[1][0];
    float a2 = m[0][0]*m[1][3] - m[0][3]*m[1][0];
    float a3 = m[0][1]*m[1][2] - m[0][2]*m[1][1];
    float a4 = m[0][1]*m[1][3] - m[0][3]*m[1][1];
    float a5 = m[0][2]*m[1][3] - m[0][3]*m[1][2];
    float b0 = m[2][0]*m[3][1] - m[2][1]*m[3][0];
    float b1 = m[2][0]*m[3][2] - m[2][2]*m[3][0];
    float b2 = m[2][0]*m[3][3] - m[2][3]*m[3][0];
    float b3 = m[2][1]*m[3][2] - m[2][2]*m[3][1];
    float b4 = m[2][1]*m[3][3] - m[2][3]*m[3][1];
    float b5 = m[2][2]*m[3][3] - m[2][3]*m[3][2];

    return a0*b5 - a1*b4 + a2*b3 + a3*b2 - a4*b1 + a5*b0;
}


Mat4& Mat4::invert() {

    float a0 = m[0][0]*m[1][1] - m[0][1]*m[1][0];
    float a1 = m[0][0]*m[1][2] - m[0][2]*m[1][0];
    float a2 = m[0][0]*m[1][3] - m[0][3]*m[1][0];
    float a3 = m[0][1]*m[1][2] - m[0][2]*m[1][1];
    float a4 = m[0][1]*m[1][3] - m[0][3]*m[1][1];
    float a5 = m[0][2]*m[1][3] - m[0][3]*m[1][2];
    float b0 = m[2][0]*m[3][1] - m[2][1]*m[3][0];
    float b1 = m[2][0]*m[3][2] - m[2][2]*m[3][0];
    float b2 = m[2][0]*m[3][3] - m[2][3]*m[3][0];
    float b3 = m[2][1]*m[3][2] - m[2][2]*m[3][1];
    float b4 = m[2][1]*m[3][3] - m[2][3]*m[3][1];
    float b5 = m[2][2]*m[3][3] - m[2][3]*m[3][2];
    float det = a0*b5 - a1*b4 + a2*b3 + a3*b2 - a4*b1 + a5*b0;

    if(fabs(det) <=0) {

        Mat::toZeros();

        return *this;
    }

    tmpM[0][0] = + m[1][1]*b5 - m[1][2]*b4 + m[1][3]*b3;
    tmpM[1][0] = - m[1][0]*b5 + m[1][2]*b2 - m[1][3]*b1;
    tmpM[2][0] = + m[1][0]*b4 - m[1][1]*b2 + m[1][3]*b0;
    tmpM[3][0] = - m[1][0]*b3 + m[1][1]*b1 - m[1][2]*b0;
    tmpM[0][1] = - m[0][1]*b5 + m[0][2]*b4 - m[0][3]*b3;
    tmpM[1][1] = + m[0][0]*b5 - m[0][2]*b2 + m[0][3]*b1;
    tmpM[2][1] = - m[0][0]*b4 + m[0][1]*b2 - m[0][3]*b0;
    tmpM[3][1] = + m[0][0]*b3 - m[0][1]*b1 + m[0][2]*b0;
    tmpM[0][2] = + m[3][1]*a5 - m[3][2]*a4 + m[3][3]*a3;
    tmpM[1][2] = - m[3][0]*a5 + m[3][2]*a2 - m[3][3]*a1;
    tmpM[2][2] = + m[3][0]*a4 - m[3][1]*a2 + m[3][3]*a0;
    tmpM[3][2] = - m[3][0]*a3 + m[3][1]*a1 - m[3][2]*a0;
    tmpM[0][3] = - m[2][1]*a5 + m[2][2]*a4 - m[2][3]*a3;
    tmpM[1][3] = + m[2][0]*a5 - m[2][2]*a2 + m[2][3]*a1;
    tmpM[2][3] = - m[2][0]*a4 + m[2][1]*a2 - m[2][3]*a0;
    tmpM[3][3] = + m[2][0]*a3 - m[2][1]*a1 + m[2][2]*a0;

    float one_over_det = 1.0f/det;
    for(int i=0; i<dim; i++) {
        for(int j=0; j<dim; j++) {
            m[i][j] = tmpM[i][j]*one_over_det;
        }
    }

    return *this;
}


void Mat4::toOpenGL(float* M) {

    M[ 0]=m[0][0]; M[ 1]=m[1][0]; M[ 2]=m[2][0]; M[ 3]=m[3][0];
    M[ 4]=m[0][1]; M[ 5]=m[1][1]; M[ 6]=m[2][1]; M[ 7]=m[3][1];
    M[ 8]=m[0][2]; M[ 9]=m[1][2]; M[10]=m[2][2]; M[11]=m[3][2];
    M[12]=m[0][3]; M[13]=m[1][3]; M[14]=m[2][3]; M[15]=m[3][3];
}