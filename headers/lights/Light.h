#ifndef LIGHT_H
#define	LIGHT_H

#include "headers/utils/Object.h"

/**
 * This class represents a basic Light object. Other types of Light are
 * inherited from this Light. Used as a standard, ambient light in OpenGL.
 *
 * @ingroup sgLights
 * 
 * @author Ben Constable, original Java code by Oli Winks
 * @version 1.0
 *
 * @ingroup Lights
 */
class Light: public Object {

public:

    static int activeLights; ///< Number of active lights in the scene
    /**
     * Type of Light, used to check type at runtime. One for each in the
     * inheritance heirarchy.
     */
    enum Type {LIGHT,LIGHTBULB,SPOTLIGHT,DIRLIGHT};
    bool on; ///< Light on or off
    Type type; ///< Type of this light


    /**
     * Default constructor for Light. Light is on and has RGBA 1,1,1,1 (white)
     */
    Light();
    /**
     * Construct this light from the given RGB array, with alpha 1.
     *
     * @param rgbArray RGB values
     */
    Light(float rgbArray[]);
    /**
     * Constructor this Light from the given RGB values. Sets alpha to 1.
     *
     * @param red Red RGB value
     * @param green Green RGB value
     * @param blue Blue RGB value
     */
    Light(float red, float green, float blue);
    /**
     * Copy constructor.
     *
     * @param rhs Light to copy from
     */
    Light(const Light& rhs);
    /**
     * Assignment operator.
     * 
     * @param rhs Light to copy from
     * @return this
     */
    Light& operator =(const Light& rhs);
    /**
     * Destructor.
     */
    virtual ~Light();

    /**
     * Set the colour of the light to that of the given RGB array.
     *
     * @param rgbArray The colour to set the light to
     */
    void setColour(float rgbArray[]);
    /**
     * Set the colour of the Light to that of the given RGB values.
     *
     * @param r Red RGB value.
     * @param g Green RGB value.
     * @param b Blue RGB value.
     */
    void setColour(float r, float g, float b);
    /**
     * Get the colour of the Light.
     *
     * @return The Light's colour
     */
    inline float* getColour();
    /**
     * Return a copy of the Light, wrapped in a SPtr.
     *
     * @return A copy of the Light
     */
    virtual SPtr<Light> clone();


protected:

    float* colour; ///< RGB array holding the colour of the light.

};

//INLINE FUNCTION DEFINITIONS

inline float* Light::getColour() {

    return colour;
}

#endif	/* LIGHT_H */

