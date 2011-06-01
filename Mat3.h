#ifndef MAT3_H
#define	MAT3_H

#include "Mat.h"
#include "Vec2.h"
#include "Vec3.h"

/**
 * The Mat3 class extends the Mat clas with a fixed 3x3 dimension.
 *
 * @see Mat
 * @see Mat2
 * @see Mat4
 * 
 * @author Ben Constable, original Java code by Oli Winks
 * @version 1.0
 *
 * @ingroup Math
 */
class Mat3: public Mat {

public:

    /**
     * Default constructor. Sets dimension to 3 and initialises arrrays to hold
     * 0 values.
     */
    Mat3()
    :Mat(3)
    {}
    /**
     * Construct this Mat3 using the values in the given 2D array.
     *
     * @param cM Values to use
     */
    Mat3(float** cM)
    :Mat(cM,3)
    {}
    /**
     * Copy constructor.
     * 
     * @param rhs Mat3 to copy from
     */
    Mat3(const Mat3& rhs)
    :Mat(rhs)
    {}
    /**
     * Assignment operator.
     *
     * @param rhs Mat3 to copy from
     * @return this
     */
    Mat3& operator=(const Mat3& rhs);
    /**
     * Destructor.
     */
    ~Mat3(){}

    Mat3& setTo(const Mat& mat);
    Mat3& setTo(float** m);
    /**
     * Set the values of this Mat3 to those given. Parameters are ordered in a
     * row by row format.
     *
     * @param m00 [0][0]
     * @param m01 [0][1]
     * @param m02 [0][2]
     * @param m10 [1][0]
     * @param m11 [1][1]
     * @param m12 [1][2]
     * @param m20 [2][0]
     * @param m21 [2][1]
     * @param m22 [2][2]
     * @return this
     */
    Mat3& setTo(float m00, float m01, float m02,
                float m10, float m11, float m12,
                float m20, float m21, float m22);
    Mat3& toZeros();
    Mat3& toOnes();
    Mat3& toIdentity();
    /**
     * Copy the values from the given Vec axis into this Mat3.
     *
     * @param uAxis top row
     * @param vAxis middle row
     * @param wAxis bottom row
     * @return this
     */
    Mat3& fromAxes(const Vec3& uAxis, const Vec3& vAxis, const Vec3& wAxis);
    Mat3& add(const Mat& mat);
    Mat3& add(float** m);
    /**
     * Add the values given to this Mat3. Parameters are ordered in a row by row
     * format.
     *
     * @param m00 [0][0]
     * @param m01 [0][1]
     * @param m02 [0][2]
     * @param m10 [1][0]
     * @param m11 [1][1]
     * @param m12 [1][2]
     * @param m20 [2][0]
     * @param m21 [2][1]
     * @param m22 [2][2]
     * @return this
     */
    Mat3& add(float m00, float m01, float m02,
              float m10, float m11, float m12,
              float m20, float m21, float m22);
    Mat3& sub(const Mat& mat);
    Mat3& sub(float** m);
    /**
     * Subtract the values given from this Mat3. Parameters are ordered in a row
     * by row format.
     *
     * @param m00 [0][0]
     * @param m01 [0][1]
     * @param m02 [0][2]
     * @param m10 [1][0]
     * @param m11 [1][1]
     * @param m12 [1][2]
     * @param m20 [2][0]
     * @param m21 [2][1]
     * @param m22 [2][2]
     * @return this
     */
    Mat3& sub(float m00, float m01, float m02,
              float m10, float m11, float m12,
              float m20, float m21, float m22);
    Mat3& mult(float s);
    Mat3& mult(const Mat& mat);
    Mat3& mult(float** m);
    /**
     * Multiply the values given through this Mat3. Parameters are ordered in a
     * row by row format.
     *
     * @param m00 [0][0]
     * @param m01 [0][1]
     * @param m02 [0][2]
     * @param m10 [1][0]
     * @param m11 [1][1]
     * @param m12 [1][2]
     * @param m20 [2][0]
     * @param m21 [2][1]
     * @param m22 [2][2]
     * @return this
     */
    Mat3& mult(float m00, float m01, float m02,
               float m10, float m11, float m12,
               float m20, float m21, float m22);
    /**
     * Multiply the values given through this Vec. Vec must have a dim of 3.
     *
     * @param vec Vec to multiply
     */
    void mult(Vec& vec);
    Mat3& div(float s);
    /**
     * Calculate the determinant of this Mat3.
     *
     * @return determinant
     */
    float determinant();
    /**
     * Invert this Mat3 i.e one over each of its values.
     *
     * @return this
     */
    Mat3& invert();
    /**
     * Convert this Mat3 to a format which can be used by OpenGL. This is a one
     * dimensional array of 16 values, in column by column order. Extra values
     * are populated as the identity matrix (1s and 0s).
     * 
     * @param M OpenGL array to populate with the values of this Mat3.
     */
    void toOpenGL(float* M);
};

#endif	/* MAT3_H */

