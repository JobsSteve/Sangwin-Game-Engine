#ifndef VEC2_H
#define	VEC2_H

#include "Vec.h"
#include <math.h>

/**
 * This class represents a Vector of size 2.
 *
 * @see Vec
 * @see Vec3
 *
 * @author Ben Constable, original Java code by Oli Winks
 * @version 1.0
 *
 * @ingroup Math
 */
class Vec2: public Vec {

public:

    /**
     * Default constructor. Sets size to 2 and values to 0.
     */
    Vec2()
    :Vec(2)
    {}
    /**
     * Sets values to the given x and y parameters.
     *
     * @param x x value
     * @param y y value
     */
    Vec2(float x, float y)
    :Vec(2)
    {
        v[0]=x;
        v[1]=y;
    }
    /**
     * Copy constructor.
     *
     * @param rhs Vec2 to copy
     */
    Vec2(const Vec2& rhs)
    :Vec(rhs)
    {}
    /**
     * Assignment operator.
     *
     * @param rhs Vec2 to copy assign
     * @return this
     */
    Vec2& operator=(const Vec2& rhs);
    /**
     * Destructor
     */
    ~Vec2(){}

    /**
     * The x co-ordinate of this Vec2.
     *
     * @return x
     */
    inline float x();
    /**
     * The y co-ordinate of this Vec2.
     *
     * @return y
     */
    inline float y();
    Vec2& setTo(const Vec& vec);
    /**
     * Set the values of this Vec2 to the given parameters.
     *
     * @param x x value
     * @param y y value
     * @return this
     */
    Vec2& setTo(float x, float y);
    Vec2& setTo(float s);
    Vec2& add(const Vec& vec);
    /**
     * Add the given parameters to this Vec2.
     *
     * @param x x value to add
     * @param y y value to add
     * @return this
     */
    Vec2& add(float x, float y);
    Vec2& sub(const Vec& vec);
    /**
     * Subtract the given parameters from this Vec2.
     *
     * @param x x value to subtract
     * @param y y value to subtract
     * @return this
     */
    Vec2& sub(float x, float y);
    Vec2& mult(float s);
    Vec2& mult(const Vec& vec);
    /**
     * Multiply this Vec2 by the given parameters.
     *
     * @param x x value to multiply by
     * @param y y value to multiply by
     * @return this
     */
    Vec2& mult(float x, float y);
    Vec2& div(float s);
    Vec2& div(const Vec& vec);
    /**
     * Divide this Vec2 by the given parameters.
     *
     * @param x x value to divide by
     * @param y y value to divide by
     * @return this
     */
    Vec2& div(float x, float y);
    float dot(const Vec& vec);
    /**
     * Calculate the dot product of this Vec2 from the given parameters.
     *
     * @param x x value to dot
     * @param y y value to dot
     * @return dot product
     */
    float dot(float x, float y);
    float dist(const Vec& vec);
    /**
     * Calculate the distance of this Vec2 from the given coordinates.
     *
     * @param x x coord
     * @param y y coord
     * @return distance
     */
    float dist(float x, float y);
    /**
     * Normalise this vector.
     *
     * @return this
     */
    Vec2& norm();
};

//INLINE FUNCTION DEFINITIONS

float Vec2::x() {

    return v[0];
}


float Vec2::y() {

    return v[1];
}

#endif	/* VEC2_H */

