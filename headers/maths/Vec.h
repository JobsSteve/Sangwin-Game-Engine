#ifndef VEC_H
#define	VEC_H

#include "headers/utils/Object.h"

/**
 * This class represents a Vector of any size. Various functions can be
 * performed on the Vector. Vectors of specific dimensions inherit from it.
 * 
 * @see Vec2
 * @see Vec3.
 *
 * @author Ben Constable, original Java code by Oli Winks
 * @version 1.0
 *
 * @ingroup Math
 */
class Vec: public Object {

public:

    int l; ///< The size of this Vec.
    float* v; ///< Represents the values of the Vector.


    /**
     * Basic constructor for Vec. Initialises values to default (0).
     */
    Vec();
    /**
     * Constructor for Vec. Initialises it to a given size with default values.
     *
     * @param dim Size of the Vec
     */
    Vec(int dim);
    /**
     * Constructor for Vec. Initialises size and values to those given.
     *
     * @param vec Array of values to give to this Vec
     * @param dim Size to give to this Vec
     */
    Vec(float vec[], int dim);
    /**
     * Copy constructor for Vec.
     *
     * @param vec The Vec to copy
     */
    Vec(const Vec& rhs);
    /**
     * Assignment operator for Vec.
     * 
     * @param rhs Vec to copy into this one
     * @return A reference to this Vec
     */
    Vec& operator=(const Vec& rhs);
    /**
     * Destructor for Vec.
     */
    virtual ~Vec();


    /**
     * Sets the values of this Vec to those of the given one.
     *
     * @param vec The Vec to get the values from
     * @return A reference to this Vec
     */
    virtual Vec& setTo(const Vec& vec);
    /**
     * Sets the values of this Vec to those in the given float array.
     *
     * @param v The array of floats
     * @return A reference to this Vec
     */
    virtual Vec& setTo(float v[]);
    /**
     * Sets all the values of this Vec to that of the given float.
     *
     * @param s The float
     * @return A reference to this Vec
     */
    virtual Vec& setTo(float s);
    /**
     * Sets all the values of this Vec to 0.
     *
     * @return A reference to this Vec
     */
    Vec& toZeros();
    /**
     * Sets all the values of the Vec to 1.
     *
     * @return A reference to this Vec
     */
    Vec& toOnes();
    /**
     * Adds the values of the given Vec to this one.
     *
     * @param vec The Vec to add
     * @return A reference to this Vec
     */
    virtual Vec& add(const Vec& vec);
    /**
     * Adds the values of the given float array to this Vec.
     *
     * @param v The float array to add
     * @return A reference to this Vec
     */
    Vec& add(float v[]);
    /**
     * Subtracts the values of the given Vec from this one.
     *
     * @param vec The Vec to subtract
     * @return A reference to this Vec
     */
    virtual Vec& sub(const Vec& vec);
    /**
     * Subtracts the values of the given float array from this Vec.
     *
     * @param v The float array to subtract
     * @return A reference to this Vec
     */
    Vec& sub(float v[]);
    /**
     * Multiplies the values of this Vec by a float value.
     *
     * @param s The float to multiply by
     * @return A reference to this Vec
     */
    virtual Vec& mult(float s);
    /**
     * Multiplies the values of this Vec by those of the given one.
     *
     * @param vec The Vec to multiply by
     * @return A reference to this Vec
     */
    virtual Vec& mult(const Vec& vec);
    /**
     * Multiplies the values of this Vec by those of the given float array.
     *
     * @param v The float array to multiply by
     * @return A reference to thie Vec
     */
    Vec& mult(float v[]);
    /**
     * Divides the values of this Vec by a float value.
     *
     * @param s The float to divide by
     * @return A reference to this Vec
     */
    virtual Vec& div(float s);
    /**
     * Divides the values of this Vec by those of the given one.
     *
     * @param vec The Vec to divide by
     * @return A reference to this Vec
     */
    virtual Vec& div(const Vec& vec);
    /**
     * Divides the values of this Vec by those of the given float array.
     *
     * @param v The float array to divide by
     * @return A reference to this Vec
     */
    Vec& div(float v[]);
    /**
     * Calculates the dot product between this Vec and the given one.
     *
     * @param vec The Vec to perform the dot product with
     * @return The resulting dot product
     */
    virtual float dot(const Vec& vec);
    /**
     * Calculates the dot product between this Vec and the given float array.
     *
     * @param v The float array to perfrom the dot product with
     * @return The resulting dot product
     */
    float dot(float v[]);
    /**
     * Calculates the euclidian distance between the Vec and the given one.
     *
     * @param vec The Vec to calculate the distance between
     * @return The euclidian distance
     */
    virtual float dist(const Vec& vec);
    /**
     * Calculates the euclidian distance between the Vec and the given float
     * array.
     *
     * @param v The float array to calculate the distance between
     * @return The euclidian distance
     */
    float dist(float v[]);
    /**
     * Return the length (magnitude) of this Vec.
     *
     * @return The length (magnitude) of this Vec
     */
    float length();
    /**
     * Return the length (magnitude) squared of this Vec.
     *
     * @return The length (magnitude) squared of this Vec
     */
    float lengthSquared();
    /**
     * Normalises this Vec.
     *
     * @return A reference to this Vec
     */
    Vec& norm();
    /**
     * Checks to see if this Vec is equal to the given one. Compares the
     * dimensions of each.
     *
     * @param vec The Vec to check equality against
     * @return True if the Vecs are equal, false if not
     */
    bool equals(const Vec& vec);
};

#endif /* VEC_H */

