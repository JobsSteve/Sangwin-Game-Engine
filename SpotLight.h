#ifndef SPOTLIGHT_H
#define	SPOTLIGHT_H

#include "LightBulb.h"

/**
 * This class represents a SpotLight. As well as having a position, this light
 * also has a direction, cutoff and exponent. Can be used as an OpenGL
 * spotlight.
 *
 * @see Light
 * @see LightBulb
 *
 * @author Ben Constable, original Java code by Oli Winks
 * @version 1.0
 *
 * @ingroup Lights
 */
class SpotLight: public LightBulb {

public:

    /**
     * Default constructor for SpotLight. Initialises variables to default.
     * Facing into the screen, angle 40.0 and focus 30.0
     */
    SpotLight()
    :LightBulb(),
     dir(new Vec3(0,0,1)),
     angle(40.0f),
     focus(30.0f)
    {
        type = SPOTLIGHT;
    }
    /**
     * Constructor for SpotLight. Sets the angle and focus to the given
     * parameters.
     *
     * @param angle The angle parameter to set to
     * @param focus The focus parameter to set to
     */
    SpotLight(float cAngle, float cFocus)
    :LightBulb(),
     dir(new Vec3(0,0,1)),
     angle(cAngle),
     focus(cFocus)
    {
        type = SPOTLIGHT;
    }
    /**
     * Constructor for SpotLight. Sets the colour, angle and focus to the given
     * parameters.
     *
     * @param rgbArray The colour parameter to set to
     * @param angle The angle paramter to set to
     * @param focus The focus paramter to set to
     */
    SpotLight(float rgbArray[], float cAngle, float cFocus)
    :LightBulb(rgbArray),
     dir(new Vec3(0,0,1)),
     angle(cAngle),
     focus(cFocus)
    {
        type = SPOTLIGHT;
    }
    /**
     * Constructor for SpotLight. Sets the colour, angle and focus to the given
     * parameters.
     *
     * @param r The red RGB value
     * @param g The green RGB value
     * @param b The blue RGB value
     * @param angle The angle parameter to set to
     * @param focus The focus parameter to set to
     */
    SpotLight(float r, float g, float b, float cAngle, float cFocus)
    :LightBulb(r,g,b),
     dir(new Vec3(0,0,1)),
     angle(cAngle),
     focus(cFocus)
    {
        type = SPOTLIGHT;
    }
    /**
     * Copy constructor.
     *
     * @param rhs SpotLight to copy from
     */
    SpotLight(const SpotLight& rhs)
    :LightBulb(rhs),
     dir(new Vec3(*rhs.dir)),
     angle(rhs.angle),
     focus(rhs.focus)
    {
        type = SPOTLIGHT;
    }
    /**
     * Assignment operator.
     * 
     * @param rhs Spotlight to copy from
     * @return this
     */
    SpotLight& operator =(const SpotLight& rhs);
    /**
     * Destructor.
     */
    ~SpotLight();
    
    /**
     * Get the direction this SpotLight is facing.
     *
     * @return The direction vector
     */
    inline Vec3& getDir();
    /**
     * Set the angle of this SpotLight.
     *
     * @param angle The new angle
     */
    void setAngle(float angle);
    /**
     * Get the angle of this SpotLight.
     *
     * @return The angle value
     */
    inline float getAngle();
    /**
     * Set the focus of this SpotLight.
     *
     * @param focus The new focus
     */
    inline void setFocus(float focus);
    /**
     * Get the focus of this SpotLight.
     *
     * @return The focus value
     */
    inline float getFocus();
    /**
     * Create and return a copy of this SpotLight, wrapped in a SPtr.
     *
     * @return Copy of this SpotLight
     */
    SPtr<Light> clone();


protected:

    SPtr<Vec3> dir; ///< The direction the SpotLight is facing.

private:

    float angle; ///< Spread angle of this SpotLight
    float focus; ///< Intensity distribution of this SpotLight
};

//INLINE FUNCTION DEFINITIONS

inline Vec3& SpotLight::getDir() {

    return *dir;
}


inline float SpotLight::getAngle() {

    return angle;
}


inline void SpotLight::setFocus(float focus) {

    this->focus = focus;
}


inline float SpotLight::getFocus() {

    return focus;
}

#endif	/* SPOTLIGHT_H */

