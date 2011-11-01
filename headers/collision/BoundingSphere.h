#ifndef BOUNDINGSPHERE_H
#define	BOUNDINGSPHERE_H


#include "headers/collision/BoundingVolume.h"
#include "headers/maths/Vec2.h"
#include "headers/maths/Vec3.h"
#include <float.h>

/**
 * This class implements the BoundingVolume class. It is a BoundingVolume with
 * spherical shape.
 *
 * Due to the nature of a sphere, the local and world extents
 * are the same, as the sphere remains the same no matter how it is aligned.
 *
 * @see Bound
 * @see BoundingVolume
 *
 * @author Ben Constable, original Java code by Oli Winks
 * @version 1.1
 *
 * @ingroup Collision
 */
class BoundingSphere: public BoundingVolume {

    friend class GetNode; ///< So GetNode can access protected constructors.
    
private:

    float normalRadius; ///< pre-scale radius
    float radius; ///< current radius

    SPtr<Vec3> tmpV0; ///< temp, used for speed
    SPtr<Vec3> tmpV1; ///< temp, used for speed
    SPtr<Vec2> tmpV2; ///< temp, used for speed

public:

    /**
     * Copy constructor.
     *
     * @param rhs BoundingSphere to copy from
     */
    BoundingSphere(const BoundingSphere& rhs)
    :BoundingVolume(rhs),
     normalRadius(rhs.normalRadius),
     radius(rhs.radius),
     tmpV0(new Vec3(*rhs.tmpV0)),
     tmpV1(new Vec3(*rhs.tmpV1)),
     tmpV2(new Vec2(*rhs.tmpV2))
    {
        type = SPHERE;
    }
    /**
     * Assignment operator.
     *
     * @param rhs BoundingSphere to copy from
     * @return this
     */
    BoundingSphere& operator=(const BoundingSphere& rhs);
    /**
     * Destructor.
     */
    ~BoundingSphere(){}

    /**
     * Set the size of this BoundingSphere. The size vector must contain
     * identical values, as this is a sphere.
     * 
     * @param dim new size
     */
    void setSize(const Vec3& dim);
    /**
     * Return the current radius of this BoundinSphere.
     *
     * @return radius
     */
    float getRadius();
    void wrap(float* vertices, int vLength);
    void wrap(ArrayList<SPtr<BoundingVolume> >& bounds, int to, int from);
    void applyTransform(Trfm& worldTransform);
    bool collides(const BoundingVolume& bounds);
    SPtr<BoundingVolume> clone();

protected:

    /**
     * Default constructor. Initialises BoundingSphere to size and position 0.
     */
    BoundingSphere()
    :BoundingVolume(),
     tmpV0(new Vec3()),
     tmpV1(new Vec3()),
     tmpV2(new Vec2())
    {
        type = SPHERE;
    }
    /**
     * Constructor which sets the initial position and radius of this
     * BoundingSphere.
     *
     * @param pos initial position
     * @param rad initial radius
     */
    BoundingSphere(const Vec3& pos, float rad)
    :BoundingVolume(pos),
     normalRadius(rad),
     radius(rad),
     tmpV0(new Vec3()),
     tmpV1(new Vec3()),
     tmpV2(new Vec2())
    {
        type = SPHERE;
    }
};


#endif	/* BOUNDINGSPHERE_H */





