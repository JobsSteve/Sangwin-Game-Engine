#ifndef BOUNDINGVOLUME_H
#define	BOUNDINGVOLUME_H


////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//                                 DEFINITION                                 //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////


#include "ArrayList.h"
#include "Trfm.h"

/**
 * The BoundingVolume class is an abstract class which can be used to wrap any
 * Bound node in a scenegraph. BoundingVolumes also wrap around any children
 * the node has. This makes collision detection simple, as the collision
 * detector can simply check for collisions between BoundingVolumes. which are
 * usually of primitive shape. 
 * 
 * A BoundingVolume can be both 2D and 3D, and can only accept a Vec2 or Vec3
 * as its template parameter.
 *
 * @see Bound
 * @see BoundingSphere
 *
 * @author Ben Constable, original Java code by Oli Winks
 * @version 1.0
 *
 * @ingroup Collision
 */
template<class V>
class BoundingVolume: public Object {

protected:

    SPtr<V> localPos; ///< The local position (relative to the attached node)
    SPtr<V> worldPos; ///< The world position
    SPtr<V> localExtent; ///< The local size
    SPtr<V> worldExtent; ///< The world size
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
    BoundingVolume(const V& pos);

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
    inline V& getWorldPos() const;
    /**
     * Get the local extent of this BoundingVolume. This is the distance from
     * its centre to its edge, along its local axis.
     *
     * @return local extent
     */
    inline V& getLocalExtent() const;
    /**
     * Get the world extend of this BoundingVolume. This is the distance from
     * its centre to its edge, along the world axis.
     *
     * @return world extent
     */
    inline V& getWorldExtent() const;
    /**
     * Set the size of this BoundingVolume. (width,height) or (width,height,
     * depth).
     *
     * @param dim new size
     */
    virtual void setSize(const V& dim) = 0;
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
    virtual void wrap(ArrayList<SPtr<BoundingVolume<V> > >& bounds, int to, int from) = 0;
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
    virtual bool collides(const BoundingVolume<V>& bounds) = 0;
    /**
     * Create a clone of this BoundingVolume.
     * 
     * @return a clone of this BoundingVolume
     */
    virtual SPtr<BoundingVolume<V> > clone() = 0;
};


////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//                               IMPLEMENTATION                               //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////


template<class V>
BoundingVolume<V>::BoundingVolume()
:localPos(new V()),
 worldPos(new V()),
 localExtent(new V()),
 worldExtent(new V()),
 vertices(0),
 vLength(0),
 type(VOLUME)
{}


template<class V>
BoundingVolume<V>::BoundingVolume(const V& pos)
:localPos(new V(pos)),
 worldPos(new V(pos)),
 localExtent(new V()),
 worldExtent(new V()),
 vertices(0),
 vLength(0),
 type(VOLUME)
{}


template<class V>
BoundingVolume<V>::BoundingVolume(const BoundingVolume& rhs)
:localPos(new V(*rhs.localPos)),
 worldPos(new V(*rhs.worldPos)),
 localExtent(new V(*rhs.localExtent)),
 worldExtent(new V(*rhs.worldExtent)),
 vertices(new float[rhs.vLength]),
 vLength(rhs.vLength),
 type(VOLUME)
{
    for(int i = 0; i < rhs.vLength; i++) {
        vertices[i] = rhs.vertices[i];
    }
}


template<class V>
BoundingVolume<V>& BoundingVolume<V>::operator =(const BoundingVolume& rhs) {

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


template<class V>
BoundingVolume<V>::~BoundingVolume() {

    delete [] vertices;
}


template<class V>
inline V& BoundingVolume<V>::getWorldPos() const {

    return *worldPos;
}


template<class V>
inline V& BoundingVolume<V>::getLocalExtent() const {

    return *localExtent;
}


template<class V>
inline V& BoundingVolume<V>::getWorldExtent() const {

    return *worldExtent;
}

#endif	/* BOUNDINGVOLUME_H */



