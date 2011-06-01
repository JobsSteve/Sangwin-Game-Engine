#ifndef VEC3_H
#define	VEC3_H

#include "Vec.h"
#include <math.h>

/**
 * This class represents a Vector of size 3.
 *
 * @see Vec
 * @see Vec2
 * 
 * @author Ben Constable, original Java code by Oli Winks
 * @version 1.0
 *
 * @ingroup Math
 */
class Vec3: public Vec {

public:

    /**
     * Default constructor. Sets size to 3 and values to 0.
     */
    Vec3()
    :Vec(3)
    {}
    /**
     * Constructs this Vec3 to have values equal to the given parameters.
     *
     * @param x x value
     * @param y y value
     * @param z z value
     */
    Vec3(float x, float y, float z)
    :Vec(3)
    {
        v[0] = x;
        v[1] = y;
        v[2] = z;
    }
    /**
     * Copy constructor.
     *
     * @param rhs Vec3 to copy.
     */
    Vec3(const Vec3& rhs)
    :Vec(rhs)
    {}
    /**
     * Copy assignment operator.
     *
     * @param rhs Vec3 to assign.
     * @return this
     */
    Vec3& operator=(const Vec3& rhs);
    /**
     * Destructor.
     */
    ~Vec3(){}

    /**
     * The x co-ordinate of this Vec3.
     *
     * @return x
     */
    inline float x();
    /**
     * The y co-ordinate of this Vec3.
     *
     * @return y
     */
    inline float y();
    /**
     * The z co-ordinate of this Vec3.
     *
     * @return z
     */
    inline float z();
    inline Vec3& setTo(const Vec& vec);
    /**
     * Set the values of this Vec3 to the given parameters.
     *
     * @param x x value
     * @param y y value
     * @param z z value
     * @return this
     */
    Vec3& setTo(float x, float y, float z);
    Vec3& setTo(float s);
    Vec3& add(const Vec& vec);
    /**
     * Add the given parameters to this Vec3.
     *
     * @param x x value to add
     * @param y y value to add
     * @param z z value to add
     * @return this
     */
    Vec3& add(float x, float y, float z);
    Vec3& sub(const Vec& vec);
    /**
     * Subtract the given parameters from this Vec3.
     *
     * @param x x value to subtract
     * @param y y value to subtract
     * @param z z value to subtract
     * @return this
     */
    Vec3& sub(float x, float y, float z);
    Vec3& mult(float s);
    Vec3& mult(const Vec& vec);
    /**
     * Multiply this Vec3 by the given parameters.
     *
     * @param x x value to multiply by
     * @param y y value to multiply by
     * @param z z value to multiply by
     * @return this
     */
    Vec3& mult(float x, float y, float z);
    Vec3& div(float s);
    Vec3& div(const Vec& vec);
    /**
     * Divide this Vec3 by the given parameters.
     *
     * @param x x value to divide by
     * @param y y value to divide by
     * @param z z value to divide by
     * @return this
     */
    Vec3& div(float x, float y, float z);
    float dot(const Vec& vec);
    /**
     * Calculate the dot product of this Vec3 from the given parameters.
     *
     * @param x x value to dot
     * @param y y value to dot
     * @param z z value to dot
     * @return dot product
     */
    float dot(float x, float y, float z);
    /**
     * Calculate the cross product of this Vec3 against the given Vec3.
     * 
     * @param vec Vec3 to cross
     * @return cross product
     */
    Vec3& cross(const Vec3& vec);
    /**
     * Calculate the cross product of this Vec3 from the given parameters.
     *
     * @param x x value to cross
     * @param y y value to cross
     * @param z z value to cross
     * @return cross product
     */
    Vec3& cross(float x, float y, float z);
    float dist(const Vec& vec);
    /**
     * Calculate the distance of this Vec3 from the given parameters.
     * 
     * @param x x value
     * @param y y value
     * @param z z value
     * @return distance
     */
    float dist(float x, float y, float z);
    /**
     * Normalize this Vec3.
     *
     * @return this
     */
    Vec3& norm();
};

//INLINE FUNCTION DEFINITIONS

inline Vec3& Vec3::setTo(const Vec& vec){

    v[0] = vec.v[0];
    v[1] = vec.v[1];
    v[2] = vec.v[2];

    return *this;
}


inline float Vec3::x() {

    return v[0];
}


inline float Vec3::y() {

    return v[1];
}


inline float Vec3::z() {

    return v[2];
}


#endif	/* VEC3_H */

