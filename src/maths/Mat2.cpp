#include "headers/maths/Mat2.h"

Mat2& Mat2::operator =(const Mat2& rhs) {

    Mat::operator =(rhs);

    return *this;
}


Mat2& Mat2::setTo(const Mat& mat) {

    Mat::setTo(mat);

    return *this;
}


Mat2& Mat2::setTo(float** m) {

    Mat::setTo(m);

    return *this;
}


Mat2& Mat2::setTo(float m00, float m01,
                   float m10, float m11) {

    m[0][0] = m00; m[0][1] = m01;
    m[1][0] = m10; m[1][1] = m11;

    return *this;
}


Mat2& Mat2::toZeros() {

    Mat::toZeros();

    return *this;
}


Mat2& Mat2::toOnes() {

    Mat::toOnes();

    return *this;
}


Mat2& Mat2::toIdentity() {

    Mat::toIdentity();

    return *this;
}


Mat2& Mat2::add(const Mat& mat) {

    Mat::add(mat);

    return *this;
}


Mat2& Mat2::add(float** m) {

    Mat::add(m);

    return *this;
}


Mat2& Mat2::add(float m00, float m01,
                 float m10, float m11) {

    m[0][0] += m00; m[0][1] += m01;
    m[1][0] += m10; m[1][1] += m11;

    return *this;
}


Mat2& Mat2::sub(const Mat& mat) {

    Mat::sub(mat);

    return *this;
}


Mat2& Mat2::sub(float** m) {

    Mat::sub(m);

    return *this;
}


Mat2& Mat2::sub(float m00, float m01,
                 float m10, float m11) {

    m[0][0] -= m00; m[0][1] -= m01;
    m[1][0] -= m10; m[1][1] -= m11;

    return *this;
}


Mat2& Mat2::mult(float s) {

    Mat::mult(s);

    return *this;
}


Mat2& Mat2::mult(const Mat& mat) {

    Mat::mult(mat);

    return *this;
}


Mat2& Mat2::mult(float** m) {

    Mat::mult(m);

    return *this;
}


Mat2& Mat2::mult(float m00, float m01,
                  float m10, float m11) {

    tmpM[0][0] = m[0][0]*m00 + m[0][1]*m10;
    tmpM[0][1] = m[0][0]*m01 + m[0][1]*m11;

    tmpM[1][0] = m[1][0]*m00 + m[1][1]*m10;
    tmpM[1][1] = m[1][0]*m01 + m[1][1]*m11;

    Mat::setTo(tmpM);

    return *this;
}


void Mat2::mult(Vec& vec) {

    if(vec.l == 2) {
        float x = m[0][0]*vec.v[0] + m[0][1]*vec.v[1];
        float y = m[1][0]*vec.v[0] + m[1][1]*vec.v[1];

        vec.v[0] = x;
        vec.v[1] = y;
    }
}


Mat2& Mat2::div(float s) {

    Mat::div(s);

    return *this;
}


Mat2& Mat2::invert() {

    float det = m[0][0]*m[1][1] - m[0][1]*m[1][0];

    if(fabs(det) <= 0) {

        Mat::toZeros();

        return *this;
    }

    tmpM[0][0] = m[1][1];
    tmpM[0][1] = m[0][1];
    tmpM[1][0] = m[1][0];
    tmpM[1][1] = m[0][0];
    
    float oneOverDet = 1.0f/det;
    for(int i=0; i < dim; i++) {
        for(int j=0; j < dim; j++) {
            m[i][j] = tmpM[i][j]*oneOverDet;
        }
    }
    return *this;
}

