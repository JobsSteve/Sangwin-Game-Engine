#ifndef SPATIAL_H
#define	SPATIAL_H

#include "headers/scenegraph/Bound.h"
#include "headers/scenegraph/Trfm.h"

/**
 * The Spatial class extends the Bound class by adding spatial information. This
 * is in the form of local (related to parent) information and world
 * information.
 *
 * Spatial Nodes take advantage of the Trfm class to perform spatial functions.
 *
 * @author Ben Constable, original Java code by Oli Winks
 * @version 1.1
 *
 * @ingroup Scenegraph
 */
class Spatial: public Bound {

protected:

    bool hasTransformed; ///< used by the renderer to tell when a transformation has occured
    SPtr<Trfm> localTransform; ///< local spatial information
    SPtr<Trfm> worldTransform; ///< world spatial information

public:
    
    /**
     * Default constructor. Create default Trfm data and gives the Spatial a
     * name from the given parameter.
     *
     * @param name Name for this Node
     */
    Spatial(const char* name)
    :Bound(name),
     hasTransformed(true),
     localTransform(new Trfm()),
     worldTransform(new Trfm())
    {
        type = Node::SPATIAL;
    }
    /**
     * Copy constructor. See Node for more information.
     *
     * @param rhs Spatial to copy from
     */
    Spatial(const Spatial& rhs)
    :Bound(rhs),
     hasTransformed(true),
     localTransform(new Trfm(*rhs.localTransform)),
     worldTransform(new Trfm(*rhs.worldTransform))
    {
        type = Node::SPATIAL;
    }
    
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
    Trfm& getLocalTransform();
    /**
     * Get this Spatial's world transform.
     *
     * @return world transform
     */
    Trfm& getWorldTransform();
    /**
     * Whether or not this spatial has transformed.
     *
     * @return true if has transformed, false if not
     */
    bool transformed();
    /**
     * Set whether or not this Spatial has transformed.
     * 
     * @param transformed new hasTransformed value
     */
    void setTransformed(bool transformed);
    /**
     * Update the local transform of this Spatial.
     */
    void updateLocalTransform();
    /**
     * Apply the give transform to this Spatial's world transform.
     *
     * @param worldTransform world transform to apply
     */
    virtual void applyTransform(Trfm& worldTransform);
    virtual SPtr<Node> clone();
    virtual SPtr<Node> cloneTree(SPtr<Node>& parent);
    
};


#endif	/* SPATIAL_H */

