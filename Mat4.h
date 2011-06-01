#ifndef MAT4_H
#define	MAT4_H

#include "Mat.h"
#include "Vec3.h"

/**
 * The Mat3 class extends the Mat clas with a fixed 4x4 dimension.
 *
 * @see Mat
 * @see Mat2
 * @see Mat3
 *
 * @author Ben Constable, original Java code by Oli Winks
 * @version 1.0
 *
 * @ingroup Math
 */
class Mat4: public Mat {

public:

    /**
     * Default constructor. Sets dimension to 4 and initialises arrrays to hold
     * 0 values.
     */
    Mat4()
    :Mat(4)
    {}
    /**
     * Construct this Mat4 using the values in the given 2D array.
     *
     * @param cM Values to use
     */
    Mat4(float** cM)
    :Mat(cM,4)
    {}
    /**
     * Copy constructor.
     *
     * @param rhs Mat4 to copy from
     */
    Mat4(const Mat4& rhs)
    :Mat(rhs)
    {}
    /**
     * Assignment operator.
     *
     * @param rhs Mat4 to copy from
     * @return this
     */
    Mat4& operator=(const Mat4& rhs);
    /**
     * Destructor.
     */
    ~Mat4(){}

    Mat4& setTo(const Mat& mat);
    Mat4& setTo(float** m);
    /**
     * Set the values of this Mat4 to those given. Parameters are ordered in a
     * row by row format.
     *
     * @param m00 [0][0]
     * @param m01 [0][1]
     * @param m02 [0][2]
     * @param m03 [0][3]
     * @param m10 [1][0]
     * @param m11 [1][1]
     * @param m12 [1][2]
     * @param m13 [1][3]
     * @param m20 [2][0]
     * @param m21 [2][1]
     * @param m22 [2][2]
     * @param m23 [2][3]
     * @param m30 [3][0]
     * @param m31 [3][1]
     * @param m32 [3][2]
     * @param m33 [3][3]
     * @return this
     */
    Mat4& setTo(float m00, float m01, float m02, float m03,
                float m10, float m11, float m12, float m13,
                float m20, float m21, float m22, float m23,
                float m30, float m31, float m32, float m33);
    Mat4& toZeros();
    Mat4& toOnes();
    Mat4& toIdentity();
    Mat4& add(const Mat& mat);
    Mat4& add(float** m);
    /**
     * Add the values given to this Mat4. Parameters are ordered in a
     * row by row format.
     *
     * @param m00 [0][0]
     * @param m01 [0][1]
     * @param m02 [0][2]
     * @param m03 [0][3]
     * @param m10 [1][0]
     * @param m11 [1][1]
     * @param m12 [1][2]
     * @param m13 [1][3]
     * @param m20 [2][0]
     * @param m21 [2][1]
     * @param m22 [2][2]
     * @param m23 [2][3]
     * @param m30 [3][0]
     * @param m31 [3][1]
     * @param m32 [3][2]
     * @param m33 [3][3]
     * @return this
     */
    Mat4& add(float m00, float m01, float m02, float m03,
              float m10, float m11, float m12, float m13,
              float m20, float m21, float m22, float m23,
              float m30, float m31, float m32, float m33);
    Mat4& sub(const Mat& mat);
    Mat4& sub(float** m);
    /**
     * Subtract the values given from this Mat4. Parameters are ordered in a
     * row by row format.
     *
     * @param m00 [0][0]
     * @param m01 [0][1]
     * @param m02 [0][2]
     * @param m03 [0][3]
     * @param m10 [1][0]
     * @param m11 [1][1]
     * @param m12 [1][2]
     * @param m13 [1][3]
     * @param m20 [2][0]
     * @param m21 [2][1]
     * @param m22 [2][2]
     * @param m23 [2][3]
     * @param m30 [3][0]
     * @param m31 [3][1]
     * @param m32 [3][2]
     * @param m33 [3][3]
     * @return this
     */
    Mat4& sub(float m00, float m01, float m02, float m03,
              float m10, float m11, float m12, float m13,
              float m20, float m21, float m22, float m23,
              float m30, float m31, float m32, float m33);
    Mat4& mult(float s);
    Mat4& mult(const Mat& mat);
    Mat4& mult(float** m);
    /**
     * Multiply the values given through this Mat4. Parameters are ordered in a
     * row by row format.
     *
     * @param m00 [0][0]
     * @param m01 [0][1]
     * @param m02 [0][2]
     * @param m03 [0][3]
     * @param m10 [1][0]
     * @param m11 [1][1]
     * @param m12 [1][2]
     * @param m13 [1][3]
     * @param m20 [2][0]
     * @param m21 [2][1]
     * @param m22 [2][2]
     * @param m23 [2][3]
     * @param m30 [3][0]
     * @param m31 [3][1]
     * @param m32 [3][2]
     * @param m33 [3][3]
     * @return this
     */
    Mat4& mult(float m00, float m01, float m02, float m03,
               float m10, float m11, float m12, float m13,
               float m20, float m21, float m22, float m23,
               float m30, float m31, float m32, float m33);
    /**
     * Multiply the values given through this Vec. Vec must have a dim of 3 or
     * 4.
     *
     * @param vec Vec to multiply
     */
    void mult(Vec& vec);
    Mat4& div(float s);
    /**
     * Calculate the determinant of this Mat4.
     *
     * @return determinant
     */
    float determinant();
    /**
     * Invert this Mat4 i.e one over all of its values.
     * 
     * @return this
     */
    Mat4& invert();
    /**
     * Convert this Mat3 to a format which can be used by OpenGL. This is a one
     * dimensional array of 16 values, in column by column order.
     *
     * @param M OpenGL array to populate with the values of this Mat4.
     */
    void toOpenGL(float* M);
};



#endif	/* MAT4_H */

