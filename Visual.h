#ifndef VISUAL_H
#define	VISUAL_H

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//                                 DEFINITION                                 //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

#include "Spatial.h"
#include "App2.h"
#include "App3.h"

/**
 * The Visual class extends the Spatial class by adding visual information. This
 * is in the form of local (self) or world (related to root) information.
 *
 * Visual Nodes take advantage of the App class to add visual functionality.
 * They can be both 2D and 3D, and should therefore use Vec2/Vec3, Trfm2/Trfm3
 * and App2/App3 as their template parameters. Any other template parameter will
 * cause an error on compilation.
 *
 * @author Ben Constable, original Java code by Oli Winks
 * @version 1.0
 * 
 * @ingroup Scenegraph
 */
template<class V, class T, class A>
class Visual: public Spatial<V,T> {

    friend class GetNode; ///< friend so that GetNode can access protected constructors

protected:

    SPtr<A> worldAppearance; ///< local visual information
    SPtr<A> localAppearance; ///< world visual information

    /**
     * Default constructor. Gives default visual information and sets the name
     * to the given parameter.
     *
     * @param name Name of this Node
     */
    Visual(const char* name)
    :Spatial<V,T>(name),
     worldAppearance(new A()),
     localAppearance(new A()),
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
    :Spatial<V,T>(rhs),
     worldAppearance(new A(*rhs.worldAppearance)),
     localAppearance(new A(*rhs.localAppearance)),
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
    A& getLocalAppearance();
    /**
     * Get this Visual's world appearance. This should not be modified, as it
     * will affect all of the other Nodes in the scenegraph.
     * 
     * @return the world appearance
     */
    inline A& getWorldAppearance();
    /**
     * Apply the accumulated appearance of the scenegraph to this Visual.
     *
     * This function is called by the renderer, and should not be called
     * manually.
     * 
     * @param worldAppearance accumulated appearance of the scenegraph
     */
    void applyAppearance(const A& worldAppearance);
    virtual SPtr<Node> clone();
    virtual SPtr<Node> cloneTree(SPtr<Node>& parent);


};


////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//                               IMPLEMENTATION                               //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////


template<class V,class T,class A>
Visual<V,T,A>& Visual<V,T,A>::operator =(const Visual& rhs) {

    Spatial<V,T>::operator =(rhs);

    *worldAppearance = *rhs.worldAppearance;
    *localAppearance = *rhs.localAppearance;
    hasVisualStateChanged = rhs.hasVisualStateChanged;

    return *this;
}


template<class V,class T,class A>
A& Visual<V,T,A>::getLocalAppearance() {

    hasVisualStateChanged = true;
    return *localAppearance;
}


template<class V,class T,class A>
inline A& Visual<V,T,A>::getWorldAppearance() {

    return *worldAppearance;
}


template<class V,class T,class A>
void Visual<V,T,A>::applyAppearance(const A& worldAppearance) {

    this->worldAppearance->setTo(worldAppearance);
    hasVisualStateChanged = true;
}


template<class V,class T,class A>
SPtr<Node> Visual<V,T,A>::clone() {

    SPtr<Node> clone(new Visual<V,T,A>(this->name));
    clone.smart_static_cast(SPtr<Visual<V,T,A> >())->localTransform->setTo(*(this->localTransform));
    clone.smart_static_cast(SPtr<Visual<V,T,A> >())->localAppearance->setTo(*localAppearance);

    if(this->bounds.get()) {
        SPtr<BoundingVolume<V> > boundsClone(this->bounds->clone());
        clone.smart_static_cast(SPtr<Visual<V,T,A> >())->setBounds(boundsClone);
    }

    return clone;
}


template<class V,class T,class A>
SPtr<Node> Visual<V,T,A>::cloneTree(SPtr<Node>& parent) {

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


#endif	/* VISUAL_H */

