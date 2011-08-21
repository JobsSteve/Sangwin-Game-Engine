#include "headers/maths/Mat.h"

Mat::Mat()
:dim(0),
 m(0),
 tmpM(0)
{}


Mat::Mat(int cDim)
:dim(cDim),
 m(new float*[cDim]),
 tmpM(new float*[cDim])
{

    for(int i=0; i < cDim; i++) {
        m[i] = new float[cDim];
    }

    for(int i=0; i < cDim; i++) {
        for(int j=0; j < cDim; j++) {
            m[i][j] = 0;
        }
    }
    
    for(int i=0; i < cDim; i++) {
        tmpM[i] = new float[cDim];
    }

    toIdentity();
}


Mat::Mat(float** cM, int cDim)
:dim(cDim),
 m(new float*[cDim]),
 tmpM(new float*[cDim])
{

    for(int i=0; i < cDim; i++) {
        m[i] = new float[cDim];
    }
    
    for(int i=0; i < cDim; i++) {
        for(int j=0; j < cDim; j++) {
            m[i][j] = cM[i][j];
        }
    }

    for(int i=0; i < cDim; i++) {
        tmpM[i] = new float[cDim];
    }
}


Mat::Mat(const Mat& rhs)
:dim(rhs.dim), 
 m(new float*[rhs.dim]),
 tmpM(new float*[rhs.dim])
{

    for(int i=0; i < rhs.dim; i++) {
        m[i] = new float[rhs.dim];
    }

    for(int i=0; i < rhs.dim; i++) {
        for(int j=0; j < rhs.dim; j++) {
            m[i][j] = rhs.m[i][j];
        }
    }

    for(int i=0; i < rhs.dim; i++) {
        tmpM[i] = new float[rhs.dim];
    }
}


Mat& Mat::operator =(const Mat& rhs) {

    float** mOrig = m;
    float** tmpMOrig = tmpM;

    m = new float*[rhs.dim];
    for(int i=0; i < rhs.dim; i++) {
        m[i] = new float[rhs.dim];
    }

    for(int i=0; i < rhs.dim; i++) {
        for(int j=0; j < rhs.dim; j++) {
            m[i][j] = rhs.m[i][j];
        }
    }

    tmpM = new float*[rhs.dim];
    for(int i=0; i < rhs.dim; i++) {
        tmpM[i] = new float[rhs.dim];
    }

    for(int i=0; i < rhs.dim; i++) {
        delete [] mOrig[i];
        delete [] tmpMOrig[i];
    }
    delete [] mOrig;
    delete [] tmpMOrig;

    dim = rhs.dim;

    return *this;
}


Mat::~Mat() {

    for(int i=0; i < dim; i++) {
        delete [] m[i];
        delete [] tmpM[i];
    }
    delete [] m;
    delete [] tmpM;
}


Mat& Mat::setTo(const Mat& mat) {

    for(int i=0; i < dim; i++) {
        for(int j=0; j < dim; j++) {
            m[i][j] = mat.m[i][j];
        }
    }
    return *this;
}


Mat& Mat::setTo(float** m) {

    for(int i=0; i < dim; i++) {
        for(int j=0; j < dim; j++) {
            this->m[i][j] = m[i][j];
        }
    }
    return *this;
}


Mat& Mat::toZeros() {

    for(int i=0; i < dim; i++) {
        for(int j=0; j < dim; j++) {
            m[i][j] = 0;
        }
    }
    return *this;
}


Mat& Mat::toOnes() {

    for(int i=0; i < dim; i++) {
        for(int j=0; j < dim; j++) {
            m[i][j] = 1;
        }
    }
    return *this;
}


Mat& Mat::toIdentity() {

    for(int i=0; i < dim; i++) {
        for(int j=0; j < dim; j++) {
            if(i == j) {
                m[i][j] = 1;
            }
            else {
                m[i][j] = 0;
            }
        }
    }
    return *this;
}


Mat& Mat::add(const Mat& mat) {

    for(int i=0; i < dim; i++) {
        for(int j=0; j < dim; j++) {
            m[i][j] += mat.m[i][j];
        }
    }
    return *this;
}


Mat& Mat::add(float** m) {

    for(int i=0; i < dim; i++) {
        for(int j=0; j < dim; j++) {
            this->m[i][j] += m[i][j];
        }
    }
    return *this;
}


Mat& Mat::sub(const Mat& mat) {

    for(int i=0; i < dim; i++) {
        for(int j=0; j < dim; j++) {
            m[i][j] -= mat.m[i][j];
        }
    }
    return *this;
}


Mat& Mat::sub(float** m) {

    for(int i=0; i < dim; i++) {
        for(int j=0; j < dim; j++) {
            this->m[i][j] -= m[i][j];
        }
    }
    return *this;
}


Mat& Mat::mult(float s) {

    for(int i=0; i < dim; i++) {
        for(int j=0; j < dim; j++) {
            m[i][j] *= s;
        }
    }
    return *this;
}


Mat& Mat::mult(const Mat& mat) {

    for(int i=0; i < dim; i++) {
        for(int j=0; j < dim; j++) {
            tmpM[i][j] = 0;
            for(int k=0; k < dim; k++) {
                tmpM[i][j] += m[i][k]*mat.m[k][j];
            }
        }
        for(int j=0; j < dim; j++) {
            m[i][j] = tmpM[i][j];
        }
    }
    return *this;
}


Mat& Mat::mult(float** m) {

    for(int i=0; i < dim; i++) {
        for(int j=0; j < dim; j++) {
            tmpM[i][j] = 0;
            for(int k=0; k < dim; k++) {
                tmpM[i][j] += this->m[i][k]*m[k][j];
            }
        }
        for(int j=0; j < dim; j++) {
            this->m[i][j] = tmpM[i][j];
        }
    }
    return *this;
}


void Mat::mult(Vec& vec) {

    for(int i=0; i < dim; i++) {
        float v = 0;
        for(int j=0; j < dim; j++) {
            v += m[i][j]*vec.v[j];
        }
        vec.v[i] = v;
    }
}


Mat& Mat::div(float s) {

    for(int i=0; i < dim; i++) {
        for(int j=0; j < dim; j++) {
            m[i][j] /= s;
        }
    }
    return *this;
}


Mat& Mat::transpose() {

    for(int i=0; i<dim; i++) {
        for(int j=0; j<dim; j++) {
            tmpM[i][j] = m[j][i];
        }
    }

    for(int i=0; i<dim; i++) {
        for(int j=0; j<dim; j++) {
            m[i][j] = tmpM[i][j];
        }
    }

    return *this;
}


int Mat::getDim() {

    return dim;
}


bool Mat::equals(const Mat& mat) {

    for(int i=0; i < dim; i++) {
        for(int j=0; j < dim; j++) {
            if(m[i][j] != mat.m[i][j]) {
                return false;
            }
        }
    }
    return true;
}
