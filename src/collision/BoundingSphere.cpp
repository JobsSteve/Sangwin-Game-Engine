#include "headers/collision/BoundingSphere.h"

BoundingSphere& BoundingSphere::operator =(const BoundingSphere& rhs) {

    BoundingVolume::operator =(rhs);

    type = SPHERE;
    normalRadius = rhs.normalRadius;
    radius = rhs.radius;
    *tmpV0 = *rhs.tmpV0;
    *tmpV1 = *rhs.tmpV1;
    *tmpV2 = *rhs.tmpV2;

    return *this;
}


void BoundingSphere::setSize(const Vec3& dim) {

    normalRadius = dim.v[0]/2;
    radius = normalRadius;
    localExtent->setTo(dim);
    worldExtent->setTo(dim);
}


float BoundingSphere::getRadius() {

    return radius;
}


void BoundingSphere::wrap(float* vertices, int vLength) {

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


void BoundingSphere::wrap(ArrayList<SPtr<BoundingVolume> >& bounds, int to, int from) {

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


void BoundingSphere::applyTransform(Trfm& worldTransform) {

    //apply the position transform
    worldPos->setTo(*localPos);
    worldTransform.apply(*worldPos);

    //apply the size transform
    radius = normalRadius*worldTransform.getScale();
    localExtent->setTo(radius);
    worldExtent->setTo(radius);
}


bool BoundingSphere::collides(const BoundingVolume& bounds) {

    //If the given volume is a sphere, check for collisions based on distance
    //and size of radius
    if(bounds.type == SPHERE) {
        if(worldPos->dist(bounds.getWorldPos()) <= radius + static_cast<const BoundingSphere&> (bounds).radius) {
            return true;
        }
    }
    return false;
}


SPtr<BoundingVolume> BoundingSphere::clone() {

    return SPtr<BoundingVolume>(new BoundingSphere(*this));
}

