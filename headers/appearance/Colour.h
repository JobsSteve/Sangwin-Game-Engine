#ifndef COLOUR_H
#define	COLOUR_H

#include "headers/utils/Object.h"

/**
 * This class represents the colour component of a material. It is used when no
 * material is set.
 *
 * @see App
 * @see App2
 * @see App3
 *
 * @author Ben Constable, original Java code by Oli Winks
 * @version 1.0
 *
 * @ingroup Appearance
 */
class Colour: public Object {

public:

    /**
     * Default constructor. Set all RGB values to 1 (white).
     */
    Colour();
    /**
     * Constructor that sets the colour component to that of the given RGB
     * array.
     * 
     * @param rgbArray array to set from
     */
    Colour(float* rgbArray);
    /**
     * Copy constructor.
     * 
     * @param rhs Colour to copy from
     */
    Colour(const Colour& rhs);
    /**
     * Assignment operator.
     *
     * @param rhs Colour to copy from.
     * @return this
     */
    Colour& operator=(const Colour& rhs);
    /**
     * Destructor.
     */
    ~Colour();

    /**
     * Set the colour value to that of the given Colour object.
     *
     * @param att Colour to set from
     */
    void setTo(const Colour& att);
    /**
     * Set the colour value to that of the given RGB array.
     *
     * @param rgbArray array to set from
     */
    void setColour(float* rgbArray);
    /**
     * Return the colour value (RGB) from this Colour object.
     *
     * @return RGB array
     */
    inline float* getColour();
    /**
     * Set this colour to default (1,1,1 white).
     */
    void toDefault();
    
private:

    float* colour; ///< Colour RBG array
};

//INLINE FUNCTION DEFINITIONS

inline float* Colour::getColour() {

    return colour;
}

#endif	/* COLOUR_H */

