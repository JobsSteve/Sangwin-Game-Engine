#ifndef BOUNDINGVOLUME_H
#define	BOUNDINGVOLUME_H

#include "headers/utils/ArrayList.h"
#include "headers/scenegraph/Trfm.h"

/**
 * The BoundingVolume class is an abstract class which can be used to wrap any
 * Bound node in a scenegraph. BoundingVolumes also wrap around any children
 * the node has. This makes collision detection simple, as the collision
 * detector can simply check for collisions between BoundingVolumes, which are
 * usually of primitive shape. 
 *
 * @see Bound
 *
 * @author Ben Constable, original Java code by Oli Winks
 * @version 1.1
 *
 * @ingroup Collision
 */
class BoundingVolume: public Object {

protected:

    SPtr<Vec3> localPos; ///< The local position (relative to the attached node)
    SPtr<Vec3> worldPos; ///< The world position
    SPtr<Vec3> localExtent; ///< The local size
    SPtr<Vec3> worldExtent; ///< The world size
    float* vertices;
    int vLength;

    /**
     * Default constructor. Sets the size and position of this BoundingVolume
     * to 0.
     */
    BoundingVolume();
    /**
     * Constructor which gives the BoundingVolume an initial position.
     *
     * @param pos initial position
     */
    BoundingVolume(const Vec3& pos);

public:

    /**
     * The type of the BoundingVolume. Used to tell the type at runtime.
     */
    enum ShapeType {
        VOLUME, ///< Default type
        SPHERE ///< BoundingSphere
    };
    ShapeType type; ///< The type of this BoundingVolume

    /**
     * Copy constructor.
     *
     * @param rhs BoundingVolume to copy from
     */
    BoundingVolume(const BoundingVolume& rhs);
    /**
     * Assignment operator.
     *
     * @param rhs BoundingVolume to copy from
     * @return this
     */
    BoundingVolume& operator=(const BoundingVolume& rhs);
    /**
     * Destructor.
     */
    virtual ~BoundingVolume();

    /**
     * Get the world position of this BoundingVolume.
     *
     * @return world position
     */
    Vec3& getWorldPos() const;
    /**
     * Get the local extent of this BoundingVolume. This is the distance from
     * its centre to its edge, along its local axis.
     *
     * @return local extent
     */
    Vec3& getLocalExtent() const;
    /**
     * Get the world extend of this BoundingVolume. This is the distance from
     * its centre to its edge, along the world axis.
     *
     * @return world extent
     */
    Vec3& getWorldExtent() const;
    /**
     * Set the size of this BoundingVolume. (width,height) or (width,height,
     * depth).
     *
     * @param dim new size
     */
    virtual void setSize(const Vec3& dim) = 0;
    /**
     * Wraps the model (specified by the list of vertices) in this
     * BoundingVolume.
     *
     * @param vertices model data
     * @param vLength number of vertices
     */
    virtual void wrap(float* vertices, int vLength) = 0;
    /**
     * Wrap all of the given BoundingVolumes from the start to end position in
     * the list inside this BoundingVolume.
     * 
     * @param bounds BoundingVolumes to wrap in this BoundingVolume
     * @param to start index in the list
     * @param from end index in the list
     */
    virtual void wrap(ArrayList<SPtr<BoundingVolume> >& bounds, int to, int from) = 0;
    /**
     * Transform the world position of this BoundingVolume by the given Trfm.
     *
     * @param worldTransform Trfm to transform by
     */
    virtual void applyTransform(Trfm& worldTransform) = 0;
    /**
     * Check if this BoundingVolume collides with the given one.
     *
     * @param bounds Volume to check collisions with
     * @return true of there is a collision, false if not
     */
    virtual bool collides(const BoundingVolume& bounds) = 0;
    /**
     * Create a clone of this BoundingVolume.
     * 
     * @return a clone of this BoundingVolume
     */
    virtual SPtr<BoundingVolume> clone() = 0;
};

#endif	/* BOUNDINGVOLUME_H */



