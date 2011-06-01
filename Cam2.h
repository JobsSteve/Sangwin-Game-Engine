#ifndef CAM2_H
#define	CAM2_H

#include "Cam.h"
#include "AbstractRenderer.h"
#include "Vec2.h"
#include "BoundingSphere.h"
#include "GetNode.h"

/**
 * The Cam2 class is a camera which can be used in 2D i.e it has an x and y
 * position.
 *
 * @see Cam
 *
 * @author Ben Constable, original Java code by Oli Winks
 * @version 1.0
 *
 * @ingroup Cameras
 */
class Cam2: public Cam<Vec2> {
    
protected:

    using Cam<Vec2>::pos;

private:

    SPtr<BoundingSphere<Vec2> > bs; ///< Temp, used for speed

public:

    float rot; ///< Rotation of this Cam2

    /**
     * Default constructor. Default position (origin) and rotation (0).
     */
    Cam2()
    :Cam<Vec2>(),
     bs(GetNode::newBoundingSphere2D()),
     rot(0)
    {
        pos->setTo(0,0);
    }
    /**
     * Constructor that gives this Cam2 a Viewport from the given parameter.
     * Default position and rotation.
     *
     * @param viewport This Cam2's Viewport
     */
    Cam2(SPtr<Viewport>& viewport)
    :Cam<Vec2>(viewport),
     bs(GetNode::newBoundingSphere2D()),
     rot(0)
    {
        pos->setTo(0,0);
    }
    /**
     * Copy constructor.
     *
     * @param rhs Cam2 to copy from.
     */
    Cam2(const Cam2& rhs)
    :Cam<Vec2>(rhs),
     bs(GetNode::copyBoundingSphere2D(*rhs.bs)),
     rot(rhs.rot)
    {}
    /**
     * Assignment operator.
     *
     * @param rhs Cam2 to copy from
     * @return this
     */
    Cam2& operator=(const Cam2& rhs);
    /**
     * Destructor.
     */
    ~Cam2(){}

    /**
     * Set the position of this Cam2.
     *
     * @param x new x position
     * @param y new y position
     */
    inline void setPos(float x, float y);
    void onCanvasChanged(int width, int height);
    bool isVisible(const Vec2& pos);
    bool isVisible(const BoundingVolume<Vec2>& bounds);
    void update();
};

//INLINE FUNCTION DEFINITIONS

inline void Cam2::setPos(float x, float y) {

    pos->setTo(x,y);
}

#endif	/* CAM2_H */

