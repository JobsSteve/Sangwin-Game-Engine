#ifndef GEOM_H
#define	GEOM_H

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//                                 DEFINITION                                 //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////
#include "Visual.h"
#include "Trimesh.h"
#include "BoundingSphere.h"

/**
 * The Geom class extends the Visual class by adding a mesh data. This in the
 * form of a Trimesh that can be rendered by the renderer.
 *
 * Geoms can be used in both 2D and 3D scenegraph. They should take Vec2/Vec3,
 * Trfm2/Trfm3 and App2/App3 as template parameters to compile correctly.
 *
 * @author Ben Constable, original Java code by Oli Winks
 * @version 1.0
 *
 * @ingroup Scenegraph
 */
template<class V, class T, class A>
class Geom: public Visual<V,T,A> {

    friend class GetNode; ///< friend so that GetNode can access protected constructors
    
protected:

    SPtr<Trimesh> trimesh; ///< This Geom's mesh data

    /**
     * Default constructor. Takes a mesh and a name for this Geom as parameters.
     *
     * @param name Name of this Geom
     * @param mesh Trimesh to be held by this Geom
     */
    Geom(const char* name, SPtr<Trimesh> mesh)
    :Visual<V,T,A>(name),
     trimesh(mesh)
    {
        this->type = Node::GEOM;
    }
    /**
     * Copy constructor. Trimesh is an instance (SHALLOW copy) of the given
     * Geom's Trimesh. See Node for more information on copy behaviour.
     * 
     * @param rhs Geom to copy from
     */
    Geom(const Geom& rhs)
    :Visual<V,T,A>(rhs),
     trimesh(rhs.trimesh)
    {
        this->type = Node::GEOM;
    }

public:

    /**
     * Assignment operator. Trimesh is an instance (SHALLOW copy) of the given
     * Geom's Trimesh. See Node for more information on copy behaviour.
     *
     * @param rhs Geom to copy from
     * @return this
     */
    Geom& operator=(const Geom& rhs);
    /**
     * Destructor.
     */
    ~Geom(){}

    /**
     * This does nothing as Geom is a leaf Node.
     * 
     * @param child
     */
    void attachChild(SPtr<Node> child);
    /**
     * This does nothing as Geom is a leaf Node.
     * 
     * @param child
     */
    void detachChild(const SPtr<Node>& child);
    /**
     * This does nothing as Geom is a leaf Node.
     *
     * @param i
     * @return null pointer to Node
     */
    SPtr<Node> detachChild(int i);
    /**
     * Sets this Geom's BoundingVolume.
     *
     * DO NOT call this AFTER this Geom has been scaled. New bounds assume that
     * the model has a scale of 1!
     *
     * @param bounds BoundingVolume to give to this Geom
     */
    void setBounds(SPtr<BoundingVolume<V> >& bounds);
    /**
     * Return this Geom's BoundingVolume.
     *
     * @return the BoundingVolume
     */
   SPtr<BoundingVolume<V> > getBounds();
    /**
     * Update this Geom's BoundingVolume. Geom's are leaf nodes, so childBounds
     * will be empty.
     *
     * @param childBounds empty as Geom's have no children
     * @param from not used
     * @param to not used
     */
    void updateBounds(ArrayList<SPtr<BoundingVolume<V> > >& childBounds, int from, int to);
    /**
     * Return this Geom's Trimesh.
     *
     * @return this Geom's Trimesh
     */
    inline SPtr<Trimesh> getTrimesh();
    SPtr<Node> clone();
    SPtr<Node> cloneTree(SPtr<Node>& parent);
    
};


////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//                               IMPLEMENTATION                               //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////


template<class V, class T, class A>
Geom<V,T,A>& Geom<V,T,A>::operator=(const Geom& rhs) {

    Visual<V,T,A>::operator =(rhs);

    trimesh = rhs.trimesh;

    return *this;
}


template<class V, class T, class A>
void Geom<V,T,A>::attachChild(SPtr<Node> child) {}


template<class V, class T, class A>
void Geom<V,T,A>::detachChild(const SPtr<Node>& child) {}


template<class V, class T, class A>
SPtr<Node> Geom<V,T,A>::detachChild(int i) {

    return SPtr<Node>();
}


template<class V, class T, class A>
void Geom<V,T,A>::setBounds(SPtr<BoundingVolume<V> >& bounds) {

    this->bounds = bounds;
    this->bounds->wrap(trimesh->getVertices(), trimesh->getVLength());
}


template<class V, class T, class A>
SPtr<BoundingVolume<V> > Geom<V,T,A>::getBounds() {

    return this->bounds;
}


template<class V, class T, class A>
void Geom<V,T,A>::updateBounds(ArrayList<SPtr<BoundingVolume<V> > >& childBounds, int from, int to) {

    if(this->bounds.get() && this->hasTransformed) {
        this->bounds->applyTransform(*(this->worldTransform));
    }
}


template<class V, class T, class A>
inline SPtr<Trimesh> Geom<V,T,A>::getTrimesh() {

    return trimesh;
}


template<class V, class T, class A>
SPtr<Node> Geom<V,T,A>::clone() {

    SPtr<Node> clone(new Geom(this->name, trimesh));
    clone.smart_static_cast(SPtr<Geom<V,T,A> >())->localTransform->setTo(*(this->localTransform));
    clone.smart_static_cast(SPtr<Geom<V,T,A> >())->localAppearance->setTo(*(this->localAppearance));

    if(this->bounds.get()) {
        SPtr<BoundingVolume<V> > boundsClone(this->bounds->clone());
        clone.smart_static_cast(SPtr<Geom<V,T,A> >())->setBounds(boundsClone);
    }

    return clone;
}


template<class V, class T, class A>
SPtr<Node> Geom<V,T,A>::cloneTree(SPtr<Node>& parent) {

    return clone();
}


#endif	/* GEOM_H */

