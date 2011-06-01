#ifndef MAT_H
#define	MAT_H

#include "Vec.h"

/**
 * This class represents a Matrix of any size. It is extended by other classes
 * that build matrices of fixed sizes. The class provides a number of functions
 * that perform all of the typical calculations needed in both 2D and 3D game
 * engines. The Matrix is always sqaure.
 *
 * @see Mat2
 * @see Mat3
 * @see Mat4
 *
 * @author Ben Constable
 * @version 1.0
 *
 * @ingroup Math
 */
class Mat: public Object {

protected:

    int dim; ///< The dimensions of this Mat

public:

    float** m; ///< 2D dynamic array to hold the values of this Mat.
    float** tmpM; ///< temp values array, used in some functions.

    /**
     * Default constructor. Sets all values (including dim) to 0. Arrays are NOT
     * initialised.
     */
    Mat();
    /**
     * Initialises both arrays to to the given dimension, and sets their values
     * to 0.
     * 
     * @param cDim dimension
     */
    Mat(int cDim);
    /**
     * Sets dimension to the given parameter, and copies parameter array values
     * into this Mat.
     *
     * @param cM array to copy
     * @param cDim dimension
     */
    Mat(float** cM, int cDim);
    /**
     * Copy constructor.
     *
     * @param rhs Mat to copy
     */
    Mat(const Mat& rhs);
    /**
     * Assigment operator.
     * 
     * @param rhs Mat to copy
     * @return this
     */
    Mat& operator=(const Mat& rhs);
    /**
     * Destructor.
     */
    virtual ~Mat();

    /**
     * Set the values of this Mat to those of the given parameter Mat.
     *
     * @param mat The Mat to set the values from
     * @return this
     */
    virtual Mat& setTo(const Mat& mat);
    /**
     * Set that values of this Mat to those of the given 2D array.
     *
     * @param m The 2D array to set the values from
     * @return this
     */
    virtual Mat& setTo(float** m);
    /**
     * Set all of the values of this Mat to 0.
     *
     * @return this
     */
    virtual Mat& toZeros();
    /**
     * Set all of the values of this Mat to 1.
     *
     * @return this
     */
    virtual Mat& toOnes();
    /**
     * Set this Mat to the identity matrix.
     *
     * @return this
     */
    virtual Mat& toIdentity();
    /**
     * Add the values of the given Mat to this one.
     *
     * @param mat Mat to add the values from
     * @return this
     */
    virtual Mat& add(const Mat& mat);
    /**
     * Add the values of the given 2D array to those of this Mat.
     *
     * @param m 2D array to add the values from
     * @return this
     */
    virtual Mat& add(float** m);
    /**
     * Subtract the values of the given Mat from those of this Mat.
     *
     * @param mat Mat to subtract the values from
     * @return this
     */
    virtual Mat& sub(const Mat& mat);
    /**
     * Subtract the values of the given 2D array from those of this Mat.
     *
     * @param m 2D array to subtract the values from
     * @return this
     */
    virtual Mat& sub(float** m);
    /**
     * Multiply all of the values of this Mat by the given value.
     *
     * @param s Value to multiply by
     * @return this
     */
    virtual Mat& mult(float s);
    /**
     * Multiply this Mat by the given one.
     *
     * @param mat Mat to multiply by
     * @return this
     */
    virtual Mat& mult(const Mat& mat);
    /**
     * Mulptiply the values of this Mat by the given 2D array.
     *
     * @param m 2D array to multiply by
     * @return this
     */
    virtual Mat& mult(float** m);
    /**
     * Multiply the given Vec throught this Mat.
     *
     * @param vec Vec to multiply through this Mat
     */
    virtual void mult(Vec& vec);
    /**
     * Divide all of the values of this Mat by the given value.
     *
     * @param s Value to divide by
     * @return this
     */
    virtual Mat& div(float s);
    /**
     * Get the dimensions of this Mat.
     *
     * @return dimensions of this Mat
     */
    int getDim();
    /**
     * Transpose this Mat i.e swap its values by i and j coordinates.
     *
     * @return this
     */
    Mat& transpose();
    /**
     * Check if this Mat equals the given Mat by comparing their values.
     *
     * @param mat Mat to compare
     * @return true if Mats are equal, false if not
     */
    bool equals(const Mat& mat);
};

#endif	/* MAT_H */

