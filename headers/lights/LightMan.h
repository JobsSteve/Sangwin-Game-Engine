#ifndef LIGHTMAN_H
#define	LIGHTMAN_H

#include "headers/scenegraph/Spatial.h"
#include "headers/lights/SpotLight.h"

/**
 * A LightMan is a positional Light that can be placed in a 3D scenegraph. This
 * makes it easy to position the light using coordinates local to other
 * scenegraph objects.
 *
 * A LightMan is a leaf node, and so children cannot be added to it.
 *
 * @see Spatial
 *
 * @author Ben Constable, original Java code by Oli Winks
 * @version 1.0
 *
 * @ingroup Lights
 */
class LightMan: public Spatial<Vec3,Trfm3> {

private:

    SPtr<Vec3> worldDir; ///< Direction of this light, relative to the world
    SPtr<LightBulb> light; ///< Light held by this LightMan

public:

    /**
     * Constructor that sets light direction to be into the screen, and light
     * held to be a null pointer.
     *
     * @param name Name of this node
     */
    LightMan(const char* name)
    :Spatial<Vec3,Trfm3>(name),
     worldDir(new Vec3(0,0,1)),
     light()
    {}
    /**
     * Constructor that gives the LightMan a light, facing into the screen.
     *
     * @param name Name of this node
     * @param aLight Light
     */
    LightMan(const char* name, SPtr<LightBulb>& aLight)
    :Spatial<Vec3,Trfm3>(name),
     worldDir(new Vec3(0,0,1)),
     light(aLight)
    {}
    /**
     * Copy constructor.
     *
     * @param rhs LightMan to copy from.
     */
    LightMan(const LightMan& rhs)
    :Spatial<Vec3,Trfm3>(rhs),
     worldDir(new Vec3(*rhs.worldDir)),
     light(rhs.light->clone().smart_static_cast(SPtr<LightBulb>()))
    {}
    /**
     * Assignment operator.
     *
     * @param rhs LightMan to copy from.
     * @return this
     */
    LightMan& operator=(const LightMan& rhs);
    /**
     * Destructor.
     */
    ~LightMan(){}

    /**
     * Attach child does nothing, as this is a leaf node.
     *
     * @param child
     */
    void attachChild(SPtr<Node> child);
    /**
     * Detach child does nothing, as this is a leaf node.
     *
     * @param child
     */
    void detachChild(const SPtr<Node>& child);
    /**
     * Detach child does nothing, as this is a leaf node.
     *
     * @param i
     * @return Empty SPtr to Node
     */
    SPtr<Node> detachChild(int i);

    /**
     * Return the world direction of this node.
     *
     * @return world direction
     */
    inline Vec3& getWorldDir();
    /**

     * Set the Light held by this LightMan to the given parameter.
     *
     * @param light new light
     */
    inline void setLight(SPtr<LightBulb>& light);
    /**
     * Return the Light held by this LightMan.
     *
     * @return light
     */
    inline SPtr<LightBulb> getLight();
    /**
     * Update the Bounding Volume of this LightMan, if it has one.

     *
     * @param childBounds not used
     * @param from not used
     * @param to not used
     */
    void updateBounds(ArrayList<SPtr<BoundingVolume<Vec3> > >& childBounds, int from, int to);
    /**
     * Apply the given transform to this LightMan.
     * @param worldTransform
     */
    void applyTransform(Trfm3& worldTransform);
    /**
     * Return a clone of this LightMan.
     *
     * @return Clone of this LightMan.
     */
    SPtr<Node> clone();
    /**
     * Calls clone, as LightMan is a lead node.
     *
     * @param parent not used
     * @return Clone of this LightMan
     */
    inline SPtr<Node> cloneTree(SPtr<Node>& parent);
    
};

//INLINE FUNCTION DEFINITIONS

inline Vec3& LightMan::getWorldDir() {

    return *worldDir;
}


inline void LightMan::setLight(SPtr<LightBulb>& light) {

    this->light = light;
}


inline SPtr<LightBulb> LightMan::getLight() {

    return light;
}

inline SPtr<Node> LightMan::cloneTree(SPtr<Node>& parent) {

    return clone();
}

#endif	/* LIGHTMAN_H */

