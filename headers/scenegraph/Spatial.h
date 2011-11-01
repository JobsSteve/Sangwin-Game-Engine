#ifndef SPATIAL_H
#define	SPATIAL_H


////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//                                 DEFINITION                                 //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////


#include "headers/scenegraph/Bound.h"
#include "headers/scenegraph/Trfm.h"

/**
 * The Spatial class extends the Bound class by adding spatial information. This
 * is in the form of local (related to parent) information and world
 * information.
 *
 * Spatial Nodes take advantage of the Trfm class to perform spatial functions.
 * They can be both 2D and 3D, and should therefore use Vec2/Vec3 and
 * Trfm2/Trfm3 as their template parameters. Any other template parameter will
 * cause an error on compilation.
 *
 * @author Ben Constable, original Java code by Oli Winks
 * @version 1.0
 *
 * @ingroup Scenegraph
 */
template<class V, class T>
class Spatial: public Bound<V> {

    friend class GetNode; ///< friend so that GetNode can access protected constructors

protected:

    bool hasTransformed; ///< used by the renderer to tell when a transformation has occured
    SPtr<T> localTransform; ///< local spatial information
    SPtr<T> worldTransform; ///< world spatial information

    /**
     * Default constructor. Create default Trfm data and gives the Spatial a
     * name from the given parameter.
     *
     * @param name Name for this Node
     */
    Spatial(const char* name)
    :Bound<V>(name),
     hasTransformed(true),
     localTransform(new T()),
     worldTransform(new T())
    {
        this->type = Node::SPATIAL;
    }
    /**
     * Copy constructor. See Node for more information.
     *
     * @param rhs Spatial to copy from
     */
    Spatial(const Spatial& rhs)
    :Bound<V>(rhs),
     hasTransformed(true),
     localTransform(new T(*rhs.localTransform)),
     worldTransform(new T(*rhs.worldTransform))
    {
        this->type = Node::SPATIAL;
    }

public:

    /**
     * Assignment operator. See Node for more information.
     * 
     * @param rhs Spatial to copy from
     * @return this
     */
    Spatial& operator=(const Spatial& rhs);
    /**
     * Destructor.
     */
    ~Spatial(){}

    /**
     * Get this Spatial's local transform.
     *
     * @return local transform
     */
    inline T& getLocalTransform();
    /**
     * Get this Spatial's world transform.
     *
     * @return world transform
     */
    inline T& getWorldTransform();
    /**
     * Whether or not this spatial has transformed.
     *
     * @return true if has transformed, false if not
     */
    inline bool transformed();
    /**
     * Set whether or not this Spatial has transformed.
     * 
     * @param transformed new hasTransformed value
     */
    inline void setTransformed(bool transformed);
    /**
     * Update the local transform of this Spatial.
     */
    inline void updateLocalTransform();
    /**
     * Apply the give transform to this Spatial's world transform.
     *
     * @param worldTransform world transform to apply
     */
    virtual void applyTransform(T& worldTransform);
    virtual SPtr<Node> clone();
    virtual SPtr<Node> cloneTree(SPtr<Node>& parent);
    
};


////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//                               IMPLEMENTATION                               //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////


template<class V, class T>
Spatial<V,T>& Spatial<V,T>::operator =(const Spatial& rhs) {

    Bound<V>::operator =(rhs);

    hasTransformed = rhs.hasTransformed;
    *localTransform = *rhs.localTransform;
    *worldTransform = *rhs.worldTransform;

    return *this;
}


template<class V, class T>
inline T& Spatial<V,T>::getLocalTransform() {

    return *localTransform;
}


template<class V, class T>
inline T& Spatial<V,T>::getWorldTransform() {

    return *worldTransform;
}


template<class V, class T>
inline bool Spatial<V,T>::transformed() {

    return hasTransformed;
}


template<class V, class T>
inline void Spatial<V,T>::setTransformed(bool transformed) {

    hasTransformed = transformed;
}


template<class V, class T>
inline void Spatial<V,T>::updateLocalTransform() {

    localTransform->update();
    hasTransformed = true;
}


template<class V, class T>
void Spatial<V,T>::applyTransform(T& worldTransform) {

    this->worldTransform->setTo(worldTransform);
    hasTransformed = true;
}


template<class V, class T>
SPtr<Node> Spatial<V,T>::clone() {

    SPtr<Node> clone(new Spatial<V,T>(this->name));
    clone.smart_static_cast(SPtr<Spatial<V,T> >())->localTransform->setTo(*localTransform);

    if(this->bounds.get()) {
        SPtr<BoundingVolume<V> > boundsClone(this->bounds->clone());
        clone.smart_static_cast(SPtr<Spatial<V,T> >())->setBounds(boundsClone);
    }

    return clone;
}


template<class V, class T>
SPtr<Node> Spatial<V,T>::cloneTree(SPtr<Node>& parent) {
    
    SPtr<Node> clone(this->clone());

    //reparent clone
    if(parent.get()) {
        parent->attachChild(clone);
    }

    //recursively clone children
    for(int i=0; i<this->children->size(); i++) {
        this->children->get(i)->cloneTree(clone);
    }

    return clone;
}

#endif	/* SPATIAL_H */

