#ifndef BOUNDINGSPHERE_H
#define	BOUNDINGSPHERE_H


////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//                                 DEFINITION                                 //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////


#include "BoundingVolume.h"
#include "Vec2.h"
#include "Vec3.h"
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
 * @version 1.0
 *
 * @ingroup Collision
 */
template<class V>
class BoundingSphere: public BoundingVolume<V> {

    friend class GetNode; ///< So GetNode can access protected constructors.
    
private:

    float normalRadius; ///< pre-scale radius
    float radius; ///< current radius

    SPtr<V> tmpV0; ///< temp, used for speed
    SPtr<V> tmpV1; ///< temp, used for speed
    SPtr<Vec2> tmpV2; ///< temp, used for speed

public:

    /**
     * Copy constructor.
     *
     * @param rhs BoundingSphere to copy from
     */
    BoundingSphere(const BoundingSphere& rhs)
    :BoundingVolume<V>(rhs),
     normalRadius(rhs.normalRadius),
     radius(rhs.radius),
     tmpV0(new V(*rhs.tmpV0)),
     tmpV1(new V(*rhs.tmpV1)),
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
    void setSize(const V& dim);
    /**
     * Return the current radius of this BoundinSphere.
     *
     * @return radius
     */
    inline float getRadius();
    void wrap(float* vertices, int vLength);
    void wrap(ArrayList<SPtr<BoundingVolume<V> > >& bounds, int to, int from);
    void applyTransform(Trfm& worldTransform);
    bool collides(const BoundingVolume<V>& bounds);
    SPtr<BoundingVolume<V> > clone();

protected:

    /**
     * Default constructor. Initialises BoundingSphere to size and position 0.
     */
    BoundingSphere()
    :BoundingVolume<V>(),
     tmpV0(new V()),
     tmpV1(new V()),
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
    BoundingSphere(const V& pos, float rad)
    :BoundingVolume<V>(pos),
     normalRadius(rad),
     radius(rad),
     tmpV0(new V()),
     tmpV1(new V()),
     tmpV2(new Vec2())
    {
        type = SPHERE;
    }

    using BoundingVolume<V>::localExtent;
    using BoundingVolume<V>::worldExtent;
    using BoundingVolume<V>::localPos;
    using BoundingVolume<V>::worldPos;
    using BoundingVolume<V>::type;
    using BoundingVolume<V>::SPHERE;
};


////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//                               IMPLEMENTATION                               //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////


template<class V>
BoundingSphere<V>& BoundingSphere<V>::operator =(const BoundingSphere& rhs) {

    BoundingVolume<V>::operator =(rhs);

    type = SPHERE;
    normalRadius = rhs.normalRadius;
    radius = rhs.radius;
    *tmpV0 = *rhs.tmpV0;
    *tmpV1 = *rhs.tmpV1;
    *tmpV2 = *rhs.tmpV2;

    return *this;
}


template<class V>
void BoundingSphere<V>::setSize(const V& dim) {

    normalRadius = dim.v[0]/2;
    radius = normalRadius;
    localExtent->setTo(dim);
    worldExtent->setTo(dim);
}


template<class V>
inline float BoundingSphere<V>::getRadius() {

    return radius;
}


template<class V>
void BoundingSphere<V>::wrap(float* vertices, int vLength) {

    //Initialise the min and max of the box that encompasses this sphere
    for(int i=0; i<tmpV0->l; i++) {
        tmpV0->v[i] = FLT_MAX;
        tmpV1->v[i] = -FLT_MAX;
    }

    //Find the min and max extents of each dimension, and store in temps
    float v;
    for(int vert=0; vert<vLength; vert+=3) {
        for(int i=0; i<localExtent->l; i++) {
            v = vertices[vert];
            if(v < tmpV0->v[i]) {
                tmpV0->v[i] = v;
            }
            if(v > tmpV1->v[i]) {
                tmpV1->v[i] = v;
            }
        }
    }

    //Calculate the centre, localPos, of this BoundingSphere
    for(int i=0; i<localPos->l; i++) {
        localPos->v[i] = tmpV0->v[i] + (tmpV1->v[i] - tmpV0->v[i])/2;
    }

    //find the radius
    float dist2 = 0;
    for(int i=0; i<tmpV0->l; i++) {
        dist2 += (tmpV1->v[i] - tmpV0->v[i])*(tmpV1->v[i] - tmpV0->v[i]);
    }

    //Update size data
    normalRadius = sqrt(dist2)/2;
    radius = normalRadius;
    localExtent->setTo(radius);
    worldExtent->setTo(radius);
}


template<class V>
void BoundingSphere<V>::wrap(ArrayList<SPtr<BoundingVolume<V> > >& bounds, int to, int from) {

    //Initialise the min and max of the box that encompasses this sphere
    for(int i=0; i<tmpV0->l; i++) {
        tmpV0->v[i] = FLT_MAX;
        tmpV1->v[i] = -FLT_MAX;
    }

    //Find the min and max extents of each dimensions, and store in temps
    float v = 0;
    for(int count=from; count<to; count++) {
        tmpV2->setTo(bounds.get(count)->getWorldExtent());

        for(int i=0; i<tmpV2->l; i++) {
            v = bounds.get(count)->getWorldPos().v[i];
            if(v - tmpV2->v[i] < tmpV0->v[i]) {
                tmpV0->v[i] = v - tmpV2->v[0];
            }
            if(v + tmpV2->v[0] > tmpV1->v[i]) {
                tmpV1->v[1] = v + tmpV2->v[0];
            }
        }
    }

     //Calculate the centre, localPos, of this BoundingSphere
    for(int i=0; i<localPos->l; i++) {
        localPos->v[i] = tmpV0->v[i] + (tmpV1->v[i] - tmpV0->v[i])/2;
    }

    //find the radius
    float max = tmpV1->v[0] - tmpV0->v[0];
    for(int i=1; i<tmpV0->l; i++)
        max = (max>(tmpV1->v[i] - tmpV0->v[i]))?max:(tmpV1->v[i] - tmpV0->v[i]);

    //update size data
    normalRadius = max/2;
    radius = normalRadius;
    localExtent->setTo(radius);
    worldExtent->setTo(radius);
}


template<class V>
void BoundingSphere<V>::applyTransform(Trfm& worldTransform) {

    //apply the position transform
    worldPos->setTo(*localPos);
    worldTransform.apply(*worldPos);

    //apply the size transform
    radius = normalRadius*worldTransform.getScale();
    localExtent->setTo(radius);
    worldExtent->setTo(radius);
}


template<class V>
bool BoundingSphere<V>::collides(const BoundingVolume<V>& bounds) {

    //If the given volume is a sphere, check for collisions based on distance
    //and size of radius
    if(bounds.type == SPHERE) {
        if(worldPos->dist(bounds.getWorldPos()) <= radius + static_cast<const BoundingSphere<V>& > (bounds).radius) {
            return true;
        }
    }
    return false;
}


template<class V>
SPtr<BoundingVolume<V> > BoundingSphere<V>::clone() {

    return SPtr<BoundingVolume<V> >(new BoundingSphere<V>(*this));
}


#endif	/* BOUNDINGSPHERE_H */





