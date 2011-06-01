#ifndef LIGHTBULB_H
#define	LIGHTBULB_H

#include "Light.h"
#include "Vec3.h"

/**
 * This class represents a LightBulb. The bulb has a position and a number of
 * variables representing the intensity of the light. Used an OpenGL positional
 * light.
 *
 * @see Light
 *
 * @author Ben Constable, original Java code by Oli Winks
 * @version 1.0
 *
 * @ingroup Lights
 */
class LightBulb: public Light {

public:

    bool hasAmbience; ///< Used to show if the LightBulb has ambience.


    /**
     * Default constructor for LightBulb. Initialises variables to default -
     * position at origin, const attenuation to 1.
     */
    LightBulb()
    :Light(),
     pos(new Vec3(0,0,0)),
     constAttenuation(1),
     linearAttenuation(0),
     quadAttenuation(0)
    {
        type = LIGHTBULB;
    }
    /**
     * Constructor for LightBulb. Initialises default values and colour to the
     * given RGB array.
     *
     * @param rgbArray RGB array to set the colour to
     */
    LightBulb(float rgbArray[])
    :Light(rgbArray),
     pos(new Vec3()),
     constAttenuation(1),
     linearAttenuation(0),
     quadAttenuation(0)
    {
        type = LIGHTBULB;
    }
    /**
     * Constructor for LightBulb. Initialises default values and colour to the
     * given float values.
     *
     * @param r Red RGB value
     * @param g Green RGB value
     * @param b Blue RGB value
     */
    LightBulb(float r, float g, float b)
    :Light(r,g,b),
     pos(new Vec3()),
     constAttenuation(1),
     linearAttenuation(0),
     quadAttenuation(0)
    {
        type = LIGHTBULB;
    }
    /**
     * Copy constructor.
     *
     * @param rhs LightBulb to copy from
     */
    LightBulb(const LightBulb& rhs)
    :Light(rhs),
     hasAmbience(rhs.hasAmbience),
     pos(new Vec3(*rhs.pos)),
     constAttenuation(rhs.constAttenuation),
     linearAttenuation(rhs.linearAttenuation),
     quadAttenuation(rhs.quadAttenuation)
    {
        type = LIGHTBULB;
    }
    /**
     * Assignment operator.
     *
     * @param rhs LightBulb to copy from
     */
    LightBulb& operator =(const LightBulb& rhs);
    /**
     * Destructor.
     */
    ~LightBulb();

    /**
     * Get this LightBulb's position.
     *
     * @return The position vector of this LightBulb
     */
    inline Vec3& getPos();
    /**
     * Set the attenuation of this LightBulb.
     *
     * @param constant The new constant attenuation
     * @param linear The new linear attenuation
     * @param quadratic The new quadratic new attenuation
     */
    void setAttenuation(float constant, float linear, float quadratic);
    /**
     * Get this LightBulb's constant attenuation.
     *
     * @return The constant attenuation
     */
    inline float getConstAttenuation();
    /**
     * Get this LightBulb's linear attenuation.
     *
     * @return The linear attenuation
     */
    inline float getLinearAttenuation();
    /**
     * Get this LightBulb's quadratic attenuation.
     *
     * @return The quadratic attenuation
     */
    inline float getQuadAttenuation();
    /**
     * Return a clone of this LightBulb, wrapped in a SPtr.
     *
     * @return The clone
     */
    virtual SPtr<Light> clone();
    
protected:

    SPtr<Vec3> pos; ///< The position of this LightBulb.
    float constAttenuation; ///< The constant attenuation of this LightBulb.
    float linearAttenuation; ///< The linear attenuation of this LightBulb.
    float quadAttenuation; ///< The quadratic attenuation of this LightBulb.
};

//INLINE FUNCTION DEFINITIONS

inline Vec3& LightBulb::getPos() {

    return *pos;
}


inline float LightBulb::getConstAttenuation() {

    return constAttenuation;
}


inline float LightBulb::getLinearAttenuation() {

    return linearAttenuation;
}


inline float LightBulb::getQuadAttenuation() {

    return quadAttenuation;
}


#endif	/* LIGHTBULB_H */

