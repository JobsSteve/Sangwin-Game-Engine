#ifndef GETNODE_H
#define	GETNODE_H

#include "headers/scenegraph/Geom.h"
#include "headers/scenegraph/Collider.h"

//TYPEDEFS FOR SCENEGRAPH NODES AND BOUNDING VOLUMES

/**
 * @typdef Bound2D
 */
typedef SPtr<Bound<Vec2> > Bound2D; ///< Bound typedef
typedef SPtr<Bound<Vec3> > Bound3D;
typedef SPtr<Spatial<Vec2,Trfm2> > Spatial2D;
typedef SPtr<Spatial<Vec3,Trfm3> > Spatial3D;
typedef SPtr<Collider<Vec2,Trfm2> > Collider2D;
typedef SPtr<Collider<Vec3,Trfm3> > Collider3D;
typedef SPtr<Visual<Vec2,Trfm2,App2> > Visual2D;
typedef SPtr<Visual<Vec3,Trfm3,App3> > Visual3D;
typedef SPtr<Geom<Vec2,Trfm2,App2> > Geom2D;
typedef SPtr<Geom<Vec3,Trfm3,App3> > Geom3D;
typedef SPtr<BoundingSphere<Vec2> > BoundingSphere2D;
typedef SPtr<BoundingSphere<Vec3> > BoundingSphere3D;

/**
 * The GetNode class provides an interface for creating all types of Node and
 * BoundingVolume. It includes static functions which make it easy to get Nodes
 * without having to use long winded template syntax.
 *
 * This header file also defines a number of typedefs which make creating SPtrs
 * to each Node type easier. Nodes are normally handled in SPtr form, so these
 * typedefs should be able to define Nodes game-wide.
 *
 * Every Node and BoundingVolume returned is a SPtr.
 *
 * @author Ben Constable
 * @version 1.0
 *
 * @ingroup Utilities
 */
class GetNode: public Object {

public:

    /**
     * Create a new 2D Bound.
     *
     * @return 2D Bound
     */
    static Bound2D newBound2D();
    /**
     * Create a new 2D Bound with the given name.
     *
     * @param name name for the 2D Bound
     * @return 2D Bound
     */
    static Bound2D newBound2D(const char* name);
    /**
     * Create a new 3D Bound.
     *
     * @return 3D Bound
     */
    static Bound3D newBound3D();
    /**
     * Create a new 3D Bound with the given name.
     *
     * @param name name for the 3D Bound
     * @return 3D Bound
     */
    static Bound3D newBound3D(const char* name);
    /**
     * Copy the given 2D Bound into a new 2D Bound.
     *
     * @param rhs 2D Bound to copy from
     * @return 2D Bound
     */
    static Bound2D copyBound2D(const Bound<Vec2>& rhs);
    /**
     * Copy the given 3D Bound into a new 3D Bound.
     *
     * @param rhs 3D Bound to copy from
     * @return 3D Bound
     */
    static Bound3D copyBound3D(const Bound<Vec3>& rhs);

    /**
     * Create a new 2D Spatial with the given name.
     *
     * @param name name for the 2D Spatial
     * @return 2D Spatial
     */
    static Spatial2D newSpatial2D(const char* name);
    /**
     * Create a new 3D Spatial with the given name.
     *
     * @param name name for the 3D Spatial
     * @return 3D Spatial
     */
    static Spatial3D newSpatial3D(const char* name);
    /**
     * Copy the given 2D Spatial into a new 2D Spatial.
     *
     * @param rhs 2D Spatial to copy from
     * @return 2D Spatial
     */
    static Spatial2D copySpatial2D(const Spatial<Vec2,Trfm2>& rhs);
    /**
     * Copy the given 3D Spatial into a new 3D Spatial.
     *
     * @param rhs 3D Spatial to copy from
     * @return 3D Spatial
     */
    static Spatial3D copySpatial3D(const Spatial<Vec3,Trfm3>& rhs);

    /**
     * Create a new 2D Collider with the given name.
     *
     * @param name name for the 2D Collider
     * @return 2D Collider
     */
    static Collider2D newCollider2D(const char* name);
    /**
     * Create a new 3D Collider with the given name.
     *
     * @param name name for the 3D Collider
     * @return 3D Collider
     */
    static Collider3D newCollider3D(const char* name);
    /**
     * Copy the given 2D Collider into a new 2D Collider.
     *
     * @param rhs 2D Collider to copy from
     * @return 2D Collider
     */
    static Collider2D copyCollider2D(const Collider<Vec2,Trfm2>& rhs);
    /**
     * Copy the given 3D Collider into a new 3D Collider.
     *
     * @param rhs 3D Collider to copy from
     * @return 3D Collider
     */
    static Collider3D copyCollider3D(const Collider<Vec3,Trfm3>& rhs);

    /**
     * Create a new 2D Visual with the given name.
     *
     * @param name name for the 2D Visual
     * @return 2D Visual
     */
    static Visual2D newVisual2D(const char* name);
    /**
     * Create a new 3D Visual with the given name.
     *
     * @param name name for the 3D Visual
     * @return 3D Visual
     */
    static Visual3D newVisual3D(const char* name);
    /**
     * Copy the given 2D Visual into a new 2D Visual.
     *
     * @param rhs 2D Visual to copy from
     * @return 2D Visual
     */
    static Visual2D copyVisual2D(const Visual<Vec2,Trfm2,App2>& rhs);
    /**
     * Copy the given 3D Visual into a new 3D Visual.
     *
     * @param rhs 3D Visual to copy from
     * @return 3D Visual
     */
    static Visual3D copyVisual3D(const Visual<Vec3,Trfm3,App3>& rhs);

    /**
     * Create a new 2D Geom with the given name.
     *
     * @param name name for the 2D Geom
     * @return 2D Geom
     */
    static Geom2D newGeom2D(const char* name, SPtr<Trimesh> trimesh);
    /**
     * Create a new 3D Geom with the given name.
     *
     * @param name name for the 3D Geom
     * @return 3D Geom
     */
    static Geom3D newGeom3D(const char* name, SPtr<Trimesh> trimesh);
    /**
     * Copy the given 2D Geom into a new 2D Geom.
     *
     * @param rhs 2D Geom to copy from
     * @return 2D Geom
     */
    static Geom2D copyGeom2D(const Geom<Vec2,Trfm2,App2>& rhs);
    /**
     * Copy the given 3D Geom into a new 3D Geom.
     *
     * @param rhs 3D Geom to copy from
     * @return 3D Geom
     */
    static Geom3D copyGeom3D(const Geom<Vec3,Trfm3,App3>& rhs);

    /**
     * Create a new 2D BoundingSphere.
     *
     * @return 2D BoundingSphere
     */
    static BoundingSphere2D newBoundingSphere2D();
    /**
     * Create a new 2D BoundingSphere from the given parameters.
     *
     * @param pos position
     * @param rad radius
     * @return 2D BoundingSphere
     */
    static BoundingSphere2D newBoundingSphere2D(const Vec2& pos, float rad);
    /**
     * Create a new 3D BoundingSphere.
     *
     * @return 3D BoundingSphere
     */
    static BoundingSphere3D newBoundingSphere3D();
    /**
     * Create a new 3D BoundingSphere from the given parameters.
     *
     * @param pos position
     * @param rad radius
     * @return 3D BoundingSphere
     */
    static BoundingSphere3D newBoundingSphere3D(const Vec3& pos, float rad);
    /**
     * Copy the given 2D BoundingSphere into a new 2D BoundingSphere.
     *
     * @param rhs 2D BoundingSphere to copy from
     * @return 2D BoundingSphere
     */
    static BoundingSphere2D copyBoundingSphere2D(const BoundingSphere<Vec2>& rhs);
    /**
     * Copy the given 3D BoundingSphere into a new 3D BoundingSphere.
     *
     * @param rhs 3D BoundingSphere to copy from
     * @return 3D BoundingSphere
     */
    static BoundingSphere3D copyBoundingSphere3D(const BoundingSphere<Vec3>& rhs);
};

#endif	/* GETNODE_H */

