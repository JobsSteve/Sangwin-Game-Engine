#ifndef MAT2_H
#define	MAT2_H

#include "headers/maths/Mat.h"
#include "headers/maths/Vec2.h"
#include <math.h>

/**
 * The Mat2 class extends the Mat class with a fixed 2x2 dimension.
 *
 * @see Mat
 * @see Mat3
 * @see Mat4
 *
 * @author Ben Constable, original Java code by Oli Winks
 * @version 1.0
 *
 * @ingroup Math
 */
class Mat2: public Mat {

public:

    /**
     * Default constructor. Sets dimension to 2 to and initialises arrays to 
     * hold 0 values.
     */
    Mat2()
    :Mat(2)
    {}
    /**
     * Construct a Mat2 with the values from the given 2D array.
     *
     * @param cM Values to use
     */
    Mat2(float** cM)
    :Mat(cM,2)
    {}
    /**
     * Copy constructor.
     *
     * @param rhs Mat2 to copy from
     */
    Mat2(const Mat2& rhs)
    :Mat(rhs)
    {}
    /**
     * Assignment operator.
     *
     * @param rhs Mat2 to copy from
     * @return this
     */
    Mat2& operator=(const Mat2& rhs);
    /**
     * Destructor.
     */
    ~Mat2(){}

    Mat2& setTo(const Mat& mat);
    Mat2& setTo(float** m);
    /**
     * Set the values of this Mat2 to the given values. Parameters are ordered
     * in a row by row format.
     *
     * @param m00 [0][0]
     * @param m01 [0][1]
     * @param m10 [1][0]
     * @param m11 [1][1]
     * @return this
     */
    Mat2& setTo(float m00, float m01,
                float m10, float m11);
    Mat2& toZeros();
    Mat2& toOnes();
    Mat2& toIdentity();
    Mat2& add(const Mat& mat);
    Mat2& add(float** m);
    /**
     * Add the given values to those of this Mat2. Parameters are ordered in a
     * row by row format.
     * 
     * @param m00 [0][0]
     * @param m01 [0][1]
     * @param m10 [1][0]
     * @param m11 [1][1]
     * @return this
     */
    Mat2& add(float m00, float m01,
              float m10, float m11);
    Mat2& sub(const Mat& mat);
    Mat2& sub(float **m);
    /**
     * Subtract the given values from those of this Mat2. Parameters are ordered
     * in a row by row format.
     *
     * @param m00 [0][0]
     * @param m01 [0][1]
     * @param m10 [1][0]
     * @param m11 [1][1]
     * @return this
     */
    Mat2& sub(float m00, float m01,
              float m10, float m11);
    Mat2& mult(float s);
    Mat2& mult(const Mat& mat);
    Mat2& mult(float **m);
    /**
     * Multiply the given values through those of this Mat2. Parameters are
     * ordered in a row by row format.
     *
     * @param m00 [0][0]
     * @param m01 [0][1]
     * @param m10 [1][0]
     * @param m11 [1][1]
     * @return this
     */
    Mat2& mult(float m00, float m01,
               float m10, float m11);
    /**
     * Multiply the values given through this Vec. Vec must have a dim of 2.
     *
     * @param vec Vec to multiply
     */
    void mult(Vec& vec);
    Mat2& div(float s);
    /**
     * Invert this Mat2 i.e 1 over each of its values.
     *
     * @return this
     */
    Mat2& invert();
};

#endif	/* MAT2_H */

