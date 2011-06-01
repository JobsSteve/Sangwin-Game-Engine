#ifndef TRFM2_H
#define	TRFM2_H

#include "Trfm.h"
#include "Vec2.h"
#include "Mat2.h"
#include "Mat3.h"
#include "FastMath.h"
#include <math.h>

/**
 * The Trfm2 class implements the Trfm class to be used in 2 dimensions.
 *
 * @see Trfm
 *
 * @author Ben Constable, original Java code by Oli Winks
 * @version 1.0
 *
 * @ingroup Scenegraph
 */
class Trfm2: public Trfm {

public:

    /**
     * Default constructor. Sets all vectors and matrices to default.
     */
    Trfm2()
    :Trfm()
    {
        tr = SPtr<Vec>(new Vec2());
        ro = SPtr<Mat>(new Mat2());
        at = SPtr<Mat>(new Mat3());
        tmpV = SPtr<Vec>(new Vec2());
        tmpM = SPtr<Mat>(new Mat3());
    }
    /**
     * Copy constructor.
     * 
     * @param rhs Trfm2 to copy from
     */
    Trfm2(const Trfm2& rhs)
    :Trfm(rhs)
    {
        tr = SPtr<Vec>(new Vec2(static_cast<Vec2&>(*rhs.tr)));
        ro = SPtr<Mat>(new Mat2(static_cast<Mat2&>(*rhs.ro)));
        at = SPtr<Mat>(new Mat3(static_cast<Mat3&>(*rhs.at)));
        tmpV = SPtr<Vec>(new Vec2(static_cast<Vec2&>(*rhs.tmpV)));
        tmpM = SPtr<Mat>(new Mat3(static_cast<Mat3&>(*rhs.tmpM)));
    }
    /**
     * Assignment operator.
     * 
     * @param rhs Trfm2 to copy from.
     * @return
     */
    Trfm2& operator=(const Trfm2& rhs);
    /**
     * Destructor.
     */
    ~Trfm2(){}

    void decompose();
    /**
     * Get the angle of rotation of this Trfm2.
     *
     * @return angle of rotation
     */
    inline float getRotation();
    /**
     * Translate this Trfm2 to the given point.
     * 
     * @param x new x pos
     * @param y new y pos
     */
    void translateTo(float x, float y);
    /**
     * Translate this Trfm2 by the given point.
     *
     * @param dx x pos to add
     * @param dy y pos to add
     */
    void translateBy(float dx, float dy);
    /**
     * Rotate this Trfm2 to the given angle.
     *
     * @param angle angle to rotate to
     */
    void rotateTo(float angle);
    void update();
    void apply(Vec& vec);
    void applyInverse(Vec& vec);
};

//INLINE FUNCTION DEFINITIONS


inline float Trfm2::getRotation() {

    return acos(ro->m[0][0]);
}

#endif	/* TRFM2_H */

