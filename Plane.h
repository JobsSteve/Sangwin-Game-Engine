#ifndef PLANE_H
#define	PLANE_H

#include "Object.h"
#include "Vec3.h"

/**
 * This class represents a Euclidean Plane, to be used in 2D or 3D Space. It is
 * used, for example, in the Cam3 class to find the clipping planes in all
 * directions.
 *
 * @see Cam3
 *
 * @author Ben Constable, original Java code by Oli Winks
 * @version 1.0
 *
 * @ingroup Math
 */
class Plane: public Object {

public:

    SPtr<Vec3> normal; ///< Normal vector of this Plane.
    float D; ///< Distance from the origin.

    /**
     * Default constructor. Defines the Plane to be on the origin, facing
     * up in the y-axis.
     */
    Plane();
    /**
     * Define this Plane from a normal vector and a distance from the origin.
     *
     * @param cNormal normal vector
     * @param cD distance from the origin
     */
    Plane(const Vec3& cNormal, float cD);
    /**
     * Define this plane from three different points in space.
     * 
     * @param a point 1
     * @param b point 2
     * @param c point 3
     */
    Plane(const Vec3& a, const Vec3& b, const Vec3& c);
    /**
     * Copy constructor.
     *
     * @param rhs Plane to copy from
     */
    Plane(const Plane& rhs);
    /**
     * Assignment operator.
     *
     * @param rhs Plane to copy from
     * @return this
     */
    Plane& operator=(const Plane& rhs);
    /**
     * Destructor.
     */
    ~Plane() {}

    /**
     * Set this Plane using the values in from the parameter Plane.
     *
     * @param plane Plane to get values from
     * @return this
     */
    Plane& setTo(const Plane& plane);
    /**
     * Set this Plane from the given normal vector and distance from the origin.
     *
     * @param vec normal vector
     * @param D distance from the origin
     * @return this
     */
    Plane& setTo(const Vec3& vec, float D);
    /**
     * Set this plane from the given 3 points in space.
     *
     * @param a point 1
     * @param b point 2
     * @param c point 3
     * @return this
     */
    Plane& setTo(const Vec3& a, const Vec3& b, const Vec3& c);
    /**
     * Find the distance between this Plane and the given point.
     *
     * @param pos Point to check distance from
     * @return this
     */
    inline float dist(const Vec& pos);
    /**
     * Check if the given ray intersects this Plane, and if so set the point of
     * intersection in the given parameter.
     *
     * @param rayPos Ray position vector
     * @param rayDir Ray direction vector
     * @param intersection Resultant intersection vector
     * @return true if ray intersects, false if not
     */
    bool findIntersection(const Vec3& rayPos,
                          const Vec3& rayDir,
                                Vec3& intersection);

private:

    SPtr<Vec3> temp1; ///< used for storing results of calculations
    SPtr<Vec3> temp2; ///< used for storing results of calculations
};


//INLINE FUNCTION DEFINITIONS

inline float Plane::dist(const Vec& pos) {

    return normal->dot(pos) + D;
}

#endif	/* PLANE_H */

