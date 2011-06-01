#ifndef APP3_H
#define	APP3_H

#include "App.h"
#include "Light.h"
#include "Material.h"

/**
 * The App3 class provides visual information for 3D objects. As well as all the
 * visual information provided in the App class, the App3 class adds materials
 * and lighting.
 *
 * @see App
 * @see Visual
 *
 * @author Ben Constable, original Java code by Oli Winks
 * @version 1.0
 *
 * @ingroup Scenegraph
 */
class App3: public App {

protected:

    SPtr<Material> material; ///< This App3's Material
    LightingPolicy lightingPolicy; ///< whether this App3 should use global or local lighting first
    ArrayList<SPtr<Light> >* lights; ///< lights

public:

    /**
     * Default constructor. Default material, local lighting and empty list of
     * lights. Inherit lights by default.
     */
    App3()
    :App(),
     material(new Material()),
     lightingPolicy(LOCAL_FIRST),
     lights(new ArrayList<SPtr<Light> >())
    {
        inheritance = LIGHTING;
    }
    /**
     * Copy constructor. Creates a SHALLOW copy of this App3.
     * 
     * @param rhs App3 to copy from
     */
    App3(const App3& rhs)
    :App(rhs),
     material(rhs.material),
     lightingPolicy(rhs.lightingPolicy),
     lights(rhs.lights)
    {}
    /**
     * Assignment operator. Creates a SHALLOW copy of this App3.
     * 
     * @param rhs App3 to copy from
     * @return this
     */
    App3& operator=(const App3& rhs);
    /**
     * Destructor.
     */
    ~App3();

    /**
     * Set this App3 to take the visual information of the given one.
     * 
     * @param app
     */
    void setTo(const App& app);
    void toDefault();
    /**
     * Return this App3's Material.
     *
     * @return material
     */
    inline SPtr<Material> getMaterial();
    /**
     * Set this App3's material.
     *
     * @param material new material
     */
    inline void setMaterial(const SPtr<Material>& material);
    /**
     * Get this App3's lighting policy.
     *
     * @return the lighting policy
     */
    inline LightingPolicy getLightingPolicy();
    /**
     * Add the given Light to this App3's light list.
     * 
     * @param light light to add
     */
    inline void addLight(SPtr<Light> light);
    /**
     * Remove the given Light from this App3's light list
     * 
     * @param light light to remove
     */
    inline void removeLight(const SPtr<Light>& light);
    /**
     * Remove the light at the given index from this App3's light list.
     *
     * @param i index of the light to remove
     * @return removed light
     */
    inline SPtr<Light> removeLight(int i);
    /**
     * Get the list of Lights from this App3.
     *
     * @return light list
     */
    inline ArrayList<SPtr<Light> >& getLights();
    /**
     * Add the given App3's visual information to this App3.
     *
     * @param app App3 to get the visual information from
     */
    void add(App& app);
};

//INLINE FUNCTION DEFINITIONS

inline SPtr<Material> App3::getMaterial() {

    return material;
}


inline void App3::setMaterial(const SPtr<Material>& material) {

    this->material = material;
}


inline App::LightingPolicy App3::getLightingPolicy() {

    return lightingPolicy;
}


inline void App3::addLight(SPtr<Light> light) {

    lights->add(light);
}


inline void App3::removeLight(const SPtr<Light>& light) {

    lights->remove(light);
}


inline SPtr<Light> App3::removeLight(int i) {

    return lights->remove(i);
}


inline ArrayList<SPtr<Light> >& App3::getLights() {

    return *lights;
}

#endif	/* APP3_H */

