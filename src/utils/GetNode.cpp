#include "headers/utils/GetNode.h"

Bound2D GetNode::newBound2D() {

    return Bound2D(new Bound<Vec2>());
}


Bound2D GetNode::newBound2D(const char* name) {

    return Bound2D(new Bound<Vec2>(name));
}


Bound3D GetNode::newBound3D() {

    return Bound3D(new Bound<Vec3>());
}


Bound3D GetNode::newBound3D(const char* name) {

    return Bound3D(new Bound<Vec3>(name));
}


Bound2D GetNode::copyBound2D(const Bound<Vec2>& rhs) {

    return Bound2D(new Bound<Vec2>(rhs));
}


Bound3D GetNode::copyBound3D(const Bound<Vec3>& rhs) {

    return Bound3D(new Bound<Vec3>(rhs));
}


Spatial2D GetNode::newSpatial2D(const char* name) {

    return Spatial2D(new Spatial<Vec2,Trfm2>(name));
}


Spatial3D GetNode::newSpatial3D(const char* name) {

    return Spatial3D(new Spatial<Vec3,Trfm3>(name));
}


Spatial2D GetNode::copySpatial2D(const Spatial<Vec2,Trfm2>& rhs) {

    return Spatial2D(new Spatial<Vec2,Trfm2>(rhs));
}


Spatial3D GetNode::copySpatial3D(const Spatial<Vec3,Trfm3>& rhs) {

    return Spatial3D(new Spatial<Vec3,Trfm3>(rhs));
}


Collider2D GetNode::newCollider2D(const char* name) {

    return Collider2D(new Collider<Vec2,Trfm2>(name));
}


Collider3D GetNode::newCollider3D(const char* name) {

    return Collider3D(new Collider<Vec3,Trfm3>(name));
}


Collider2D GetNode::copyCollider2D(const Collider<Vec2,Trfm2>& rhs) {

    return Collider2D(new Collider<Vec2,Trfm2>(rhs));
}


Collider3D GetNode::copyCollider3D(const Collider<Vec3,Trfm3>& rhs) {

    return Collider3D(new Collider<Vec3,Trfm3>(rhs));
}


Visual2D GetNode::newVisual2D(const char* name) {

    return Visual2D(new Visual<Vec2,Trfm2,App2>(name));
}


Visual3D GetNode::newVisual3D(const char* name) {

    return Visual3D(new Visual<Vec3,Trfm3,App3>(name));
}


Visual2D GetNode::copyVisual2D(const Visual<Vec2,Trfm2,App2>& rhs) {

    return Visual2D(new Visual<Vec2,Trfm2,App2>(rhs));
}


Visual3D GetNode::copyVisual3D(const Visual<Vec3,Trfm3,App3>& rhs) {

    return Visual3D(new Visual<Vec3,Trfm3,App3>(rhs));
}


Geom2D GetNode::newGeom2D(const char* name, SPtr<Trimesh> trimesh) {

    return Geom2D(new Geom<Vec2,Trfm2,App2>(name,trimesh));
}


Geom3D GetNode::newGeom3D(const char* name, SPtr<Trimesh> trimesh) {

    return Geom3D(new Geom<Vec3,Trfm3,App3>(name,trimesh));
}


Geom2D GetNode::copyGeom2D(const Geom<Vec2,Trfm2,App2>& rhs) {

    return Geom2D(new Geom<Vec2,Trfm2,App2>(rhs));
}


Geom3D GetNode::copyGeom3D(const Geom<Vec3,Trfm3,App3>& rhs) {

    return Geom3D(new Geom<Vec3,Trfm3,App3>(rhs));
}


BoundingSphere2D GetNode::newBoundingSphere2D() {

    return BoundingSphere2D(new BoundingSphere<Vec2>());
}


BoundingSphere2D GetNode::newBoundingSphere2D(const Vec2& pos, float rad) {

    return BoundingSphere2D(new BoundingSphere<Vec2>(pos,rad));
}


BoundingSphere3D GetNode::newBoundingSphere3D() {

    return BoundingSphere3D(new BoundingSphere<Vec3>());
}


BoundingSphere3D GetNode::newBoundingSphere3D(const Vec3& pos, float rad) {

    return BoundingSphere3D(new BoundingSphere<Vec3>(pos,rad));
}


BoundingSphere2D GetNode::copyBoundingSphere2D(const BoundingSphere<Vec2>& rhs) {

    return BoundingSphere2D(new BoundingSphere<Vec2>(rhs));
}


BoundingSphere3D GetNode::copyBoundingSphere3D(const BoundingSphere<Vec3>& rhs) {

    return BoundingSphere3D(new BoundingSphere<Vec3>(rhs));
}