#include "headers/collision/BoundingVolume.h"

BoundingVolume::BoundingVolume()
:localPos(new Vec3()),
 worldPos(new Vec3()),
 localExtent(new Vec3()),
 worldExtent(new Vec3()),
 vertices(0),
 vLength(0),
 type(VOLUME)
{}


BoundingVolume::BoundingVolume(const Vec3& pos)
:localPos(new Vec3(pos)),
 worldPos(new Vec3(pos)),
 localExtent(new Vec3()),
 worldExtent(new Vec3()),
 vertices(0),
 vLength(0),
 type(VOLUME)
{}


BoundingVolume::BoundingVolume(const BoundingVolume& rhs)
:localPos(new Vec3(*rhs.localPos)),
 worldPos(new Vec3(*rhs.worldPos)),
 localExtent(new Vec3(*rhs.localExtent)),
 worldExtent(new Vec3(*rhs.worldExtent)),
 vertices(new float[rhs.vLength]),
 vLength(rhs.vLength),
 type(VOLUME)
{
    for(int i = 0; i < rhs.vLength; i++) {
        vertices[i] = rhs.vertices[i];
    }
}


BoundingVolume& BoundingVolume::operator =(const BoundingVolume& rhs) {

    *localPos = *rhs.localPos;
    *worldPos = *rhs.worldPos;
    *localExtent = *rhs.localExtent;
    *worldExtent = *rhs.worldExtent;
    
    float* vsOrig = vertices;
    vertices = new float[rhs.vLength];
    for(int i = 0; i < rhs.vLength; i++) {
        vertices[i] = rhs.vertices[i];
    }
    vLength = rhs.vLength;
    type = VOLUME;
    delete [] vsOrig;

    return *this;
}


BoundingVolume::~BoundingVolume() {

    delete [] vertices;
}


Vec3& BoundingVolume::getWorldPos() const {

    return *worldPos;
}


Vec3& BoundingVolume::getLocalExtent() const {

    return *localExtent;
}


Vec3& BoundingVolume::getWorldExtent() const {

    return *worldExtent;
}

