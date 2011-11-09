#ifndef VISUAL_H
#define	VISUAL_H

#include "headers/scenegraph/Spatial.h"
#include "headers/scenegraph/App.h"

/**
 * The Visual class extends the Spatial class by adding visual information. This
 * is in the form of local (self) or world (related to root) information.
 *
 * Visual Nodes take advantage of the App class to add visual functionality.
 *
 * @author Ben Constable, original Java code by Oli Winks
 * @version 1.1
 * 
 * @ingroup Scenegraph
 */
class Visual: public Spatial {

    friend class GetNode; ///< friend so that GetNode can access protected constructors

protected:

    SPtr<App> worldAppearance; ///< local visual information
    SPtr<App> localAppearance; ///< world visual information

    /**
     * Default constructor. Gives default visual information and sets the name
     * to the given parameter.
     *
     * @param name Name of this Node
     */
    Visual(const char* name)
    :Spatial(name),
     worldAppearance(new App()),
     localAppearance(new App()),
     hasVisualStateChanged(true)
    {
        this->type = Node::VISUAL;
    }
    /**
     * Copy constructor. See Node for more information on copy behaviour.
     *
     * @param rhs Visual node to copy from
     */
    Visual(const Visual& rhs)
    :Spatial(rhs),
     worldAppearance(new App(*rhs.worldAppearance)),
     localAppearance(new App(*rhs.localAppearance)),
     hasVisualStateChanged(true)
    {
        this->type = Node::VISUAL;
    }
    
public:

    bool hasVisualStateChanged; ///< whether or not this Visual has changed in appearance

    /**
     * Assignment operator. See Node for more information on copy behaviour.
     *
     * @param rhs Visual node to copy from
     * @return this
     */
    Visual& operator=(const Visual& rhs);
    /**
     * Destructor.
     */
    ~Visual(){}

    /**
     * Return the local appearance of this Visual. It is assumed the calling
     * this is used to modify appearance, which means that the render updates
     * the appearance of this node and its subtree on the next draw.
     *
     * @return the local appearance
     */
    App& getLocalAppearance();
    /**
     * Get this Visual's world appearance. This should not be modified, as it
     * will affect all of the other Nodes in the scenegraph.
     * 
     * @return the world appearance
     */
    App& getWorldAppearance();
    /**
     * Apply the accumulated appearance of the scenegraph to this Visual.
     *
     * This function is called by the renderer, and should not be called
     * manually.
     * 
     * @param worldAppearance accumulated appearance of the scenegraph
     */
    void applyAppearance(const App& worldAppearance);
    virtual SPtr<Node> clone();
    virtual SPtr<Node> cloneTree(SPtr<Node>& parent);
};


#endif	/* VISUAL_H */

