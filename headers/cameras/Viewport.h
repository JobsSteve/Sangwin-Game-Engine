#ifndef VIEWPORT_H
#define	VIEWPORT_H

#include "headers/maths/Vec2.h"

/**
 * A Viewport is the view through which a camera sees a scene. It can have a
 * fixed position and dimension, or can change its position and dimension when
 * the size of the canvas using it changes. It is compatible with OpenGL.
 *
 * @see Cam
 *
 * @author Ben Constable, original Java code by Oli Winks
 * @version 1.0
 *
 * @ingroup Cameras
 */
class Viewport: public Object {

private:

    bool fixed; ///< Whether or not this Viewport is fixed, relative to canvas size
    SPtr<Vec2> relativePos; ///< The position of this Viewport, relative to the canvas size
    SPtr<Vec2> relativeDim; ///< The dimensions of this Viewport, relative to the canvas size
    SPtr<Vec2> pos; ///< The actual position of this Viewport
    SPtr<Vec2> dim; ///< The actual dimensions of this Viewport
    
public:

    /**
     * Default constructor. Creates a 1x1 viewport at the origin, without fixed
     * position.
     */
    Viewport();
    /**
     * Constructor which sets the position and dimensions of this Viewport, and
     * sets it to be fixed or unfixed.
     *
     * @param isFixed fixed or not
     * @param cPos position
     * @param cDim dimensions
     */
    Viewport(bool isFixed, const Vec2& cPos, const Vec2& cDim);
    /**
     * Copy constructor.
     *
     * @param rhs Viewport to copy from
     */
    Viewport(const Viewport& rhs);
    /**
     * Assignment operator.
     *
     * @param rhs Viewport to copy from
     * @return this
     */
    Viewport& operator=(const Viewport& rhs);
    /**
     * Destructor.
     */
    ~Viewport(){}

    /**
     * Sets this Viewport to the given parameters. 
     * 
     * If fixed is false, the Viewport will resize itself as the canvas resizes,
     * and the parameters will be used as percentages of the canvas parameters.
     * This means that they must be between 0 and 1. onCanvasChanged must also
     * be called straight after this in order to recalculate the position and
     * dimensions.
     * 
     * @param fixed whether or not this Viewport has fixed dimensions/position
     * @param pos position (% relative to canvas if fixed = false)
     * @param dim dimension (% relative to canvas if fixed = false)
     */
    void setTo(bool fixed, const Vec2& pos, const Vec2& dim);
    /**
     * Whether or not this Viewport resizes with the canvas.
     * @return
     */
    inline bool isFixed();
    /**
     * Get the position of this Viewport.
     * @return position
     */
    inline Vec2& getPos();
    /**
     * Get the dimensions of this Viewport.
     * @return dimensions
     */
    inline Vec2& getDimensions();
    /**
     * Called when the canvas changes size/position. If this Viewport is not
     * fixes, the change in the canvas will affect the position/dimensions of
     * this Viewport.
     * 
     * @param width canvas width
     * @param height canvas height
     */
    void onCanvasChanged(int width, int height);
};

//INLINE FUNCTION DEFINITIONS

inline bool Viewport::isFixed() {

    return fixed;
}


inline Vec2& Viewport::getPos() {

    return *pos;
}


inline Vec2& Viewport::getDimensions() {

    return *dim;
}

#endif	/* VIEWPORT_H */

