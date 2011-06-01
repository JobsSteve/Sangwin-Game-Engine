#ifndef DIRLIGHT_H
#define	DIRLIGHT_H

#include "Light.h"
#include "Vec3.h"

/**
 * This class represents a directed Light, which has a direction along a given
 * vector. Can be used as an OpenGL directed light.
 *
 * @see Light
 *
 * @author Ben Constable, original Java code by Oli Winks
 * @version 1.0
 *
 * @ingroup Lights
 */
class DirLight: public Light {

public:

    /**
     * Default constructor. Sets the colour to Light default and direction to
     * straight down.
     */
    DirLight()
    :Light(),
     dir(new Vec3(0,-1,0))
    {
        type = DIRLIGHT;
    }
    /**
     * Constructor for DirLight. Sets the colour and direction to the given
     * parameters.
     *
     * @param rgbArray RGB array to set the colour of this DirLight to
     * @param cDir Vector to set the direction of this DirLight to
     */
    DirLight(float rgbArray[], Vec3& cDir)
    :Light(rgbArray),
     dir(new Vec3(cDir))
    {
        type = DIRLIGHT;
    }
    /**
     * Copy constructor.
     *
     * @param rhs rhs to copy from
     */
    DirLight(const DirLight& rhs)
    :Light(rhs),
     dir(new Vec3(*rhs.dir))
    {
        type = DIRLIGHT;
    }
    /**
     * Assignment operator.
     *
     * @param rhs DirLight to copy from.
     */
    DirLight& operator=(const DirLight& rhs);
    /**
     * Destructor.
     */
    ~DirLight();

    /**
     * Sets the direction of this DirLight to the given vector.
     *
     * @param dir The Vector to set the direction to
     */
    inline void setDir(const Vec3& dir);
    /**
     * Sets the direction of this DirLight to the given x,y,z values.
     *
     * @param x The new x direction
     * @param y The new y direction
     * @param z The new z direction
     */
    inline void setDir(float x, float y, float z);
    /**
     * Get the direction of this DirLight.
     *
     * @return The direction vecotr
     */
    inline Vec3& getDir();
    /**
     * Return a clone of this DirLight wrapped in a SPtr.
     *
     * @return A clone of this DirLight
     */
    SPtr<Light> clone();
    
private:

    SPtr<Vec3> dir; ///< Direction vector of this DirLight
};

//INLINE FUNCTION DEFINITIONS

inline void DirLight::setDir(const Vec3& dir) {

    this->dir->setTo(dir);
}


inline void DirLight::setDir(float x, float y, float z) {

    dir->setTo(x,y,z);
}


inline Vec3& DirLight::getDir() {

    return *dir;
}

#endif	/* DIRLIGHT_H */

