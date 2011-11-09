#ifndef GEOM_H
#define	GEOM_H

#include "headers/scenegraph/Visual.h"
#include "headers/scenegraph/Trimesh.h"
#include "headers/collision/BoundingSphere.h"

/**
 * The Geom class extends the Visual class by adding a mesh data. This in the
 * form of a Trimesh that can be rendered by the renderer.
 *
 *
 * @author Ben Constable, original Java code by Oli Winks
 * @version 1.1
 *
 * @ingroup Scenegraph
 */
class Geom: public Visual {

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
    :Visual(name),
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
    :Visual(rhs),
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
    void setBounds(SPtr<BoundingVolume>& bounds);
    /**
     * Return this Geom's BoundingVolume.
     *
     * @return the BoundingVolume
     */
   SPtr<BoundingVolume> getBounds();
    /**
     * Update this Geom's BoundingVolume. Geom's are leaf nodes, so childBounds
     * will be empty.
     *
     * @param childBounds empty as Geom's have no children
     * @param from not used
     * @param to not used
     */
    void updateBounds(ArrayList<SPtr<BoundingVolume> >& childBounds, int from, int to);
    /**
     * Return this Geom's Trimesh.
     *
     * @return this Geom's Trimesh
     */
    SPtr<Trimesh> getTrimesh();
    SPtr<Node> clone();
    SPtr<Node> cloneTree(SPtr<Node>& parent);
    
};


#endif	/* GEOM_H */

