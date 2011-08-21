#ifndef CAM3_H
#define	CAM3_H

#include "headers/cameras/Cam.h"
#include "headers/maths/Vec3.h"
#include "headers/maths/Plane.h"
#include "headers/collision/BoundingSphere.h"

/**
 * A Cam3 is a camera that can be used in 3D space. It has clipping planes in
 * each dimension, calculated using field of view and near/far clipping
 * distance. This in turn produces the viewing frustum. The Cam3 is comaptible
 * with OpenGL.
 *
 * @see Cam
 *
 * @author Ben Constable, original Java code by Oli Winks
 * @version 1.0
 *
 * @ingroup Cameras
 */
class Cam3: public Cam<Vec3> {

    using Cam<Vec3>::pos;
    
private:

    //frustum
    float fov; ///< viewing angle
    float halfFOV; ///< half viewing angle
    float ratio; ///< ratio between width and height of this Cam3's Viewport
    float nearClip; ///< near clipping distance
    float farClip; ///< far clipping distance
    Plane* planes; ///< Array of clipping planes: F,B,L,R,T,B

    //convenience variables, for speed
    float nh, nw, fh, fw;
    float tanFOV;
    SPtr<Vec3> tmp1, tmp2, tmp3, tmp4;
    SPtr<Vec3> ntl, ntr, nbl, nbr;
    SPtr<Vec3> ftl, ftr, fbl, fbr;

    /**
     * Check if the given BoundingSphere is visible.
     * 
     * @param bounds BoundingSphere to check
     * @return true if is visinle, false if not
     */
    bool isVisible(const BoundingSphere<Vec3>& bounds);
    /**
     * Calculate the clipping planes in each direction to find the new frustum.
     */
    void calculatePlanes();

protected:

    //Camera
    SPtr<Vec3> x /// x axis
              ,y /// y axis
              ,z; ///< z axis
    SPtr<Vec3> up; ///< The up direction for this Cam3
    SPtr<Vec3> lookAt; ///< Look at coordinates for this Cam3

public:

    bool frustumChanged; ///< Used by the renderer, should not be modified.

    /**
     * Default constructor. Default position (0,0,1). Field of view is 45 
     * degrees, near clipping plane is 1 and far clipping plane is 100.
     */
    Cam3()
    :Cam<Vec3>(),
     fov(45.0f),
     halfFOV(22.5f),
     nearClip(1),
     farClip(100),
     planes(new Plane[6]),
     tmp1(new Vec3()),
     tmp2(new Vec3()),
     tmp3(new Vec3()),
     tmp4(new Vec3()),
     ntl(new Vec3()),
     ntr(new Vec3()),
     nbl(new Vec3()),
     nbr(new Vec3()),
     ftl(new Vec3()),
     ftr(new Vec3()),
     fbl(new Vec3()),
     fbr(new Vec3()),
     x(new Vec3()),
     y(new Vec3()),
     z(new Vec3()),
     up(new Vec3(0,1,0)),
     lookAt(new Vec3(0,0,0)),
     frustumChanged(true)
    {
        for(int i=0; i<6; i++) {
            planes[i] = Plane();
        }
        pos->setTo(0,0,1);
    }

    /**
     * Constructor which sets the Viewport, field of view and clipping
     * distances.
     * 
     * @param viewport Thie Cam3's Viewport
     * @param cFov field of view
     * @param cNearClip near clipping plane
     * @param cFarClip far clipping plane
     */
    Cam3(SPtr<Viewport>& viewport, float cFov, float cNearClip, float cFarClip)
    :Cam<Vec3>(viewport),
     fov(cFov),
     halfFOV(cFov/2),
     nearClip(cNearClip),
     farClip(cFarClip),
     planes(new Plane[6]),
     tmp1(new Vec3()),
     tmp2(new Vec3()),
     tmp3(new Vec3()),
     tmp4(new Vec3()),
     ntl(new Vec3()),
     ntr(new Vec3()),
     nbl(new Vec3()),
     nbr(new Vec3()),
     ftl(new Vec3()),
     ftr(new Vec3()),
     fbl(new Vec3()),
     fbr(new Vec3()),
     x(new Vec3()),
     y(new Vec3()),
     z(new Vec3()),
     up(new Vec3(0,1,0)),
     lookAt(new Vec3(0,0,0)),
     frustumChanged(true)
    {
        for(int i=0; i<6; i++) {
            planes[i] = Plane();
        }
        pos->setTo(0,0,1);
    }

    /**
     * Copy constructor.
     * 
     * @param rhs Cam3 to copy from
     */
    Cam3(const Cam3& rhs)
    :Cam<Vec3>(rhs),
     fov(rhs.fov),
     halfFOV(rhs.halfFOV),
     ratio(rhs.ratio),
     nearClip(rhs.nearClip),
     farClip(rhs.farClip),
     planes(new Plane[6]),
     nh(rhs.nh),
     nw(rhs.nw),
     fh(rhs.fh),
     fw(rhs.fw),
     tanFOV(rhs.tanFOV),
     tmp1(new Vec3(*rhs.tmp1)),
     tmp2(new Vec3(*rhs.tmp2)),
     tmp3(new Vec3(*rhs.tmp3)),
     tmp4(new Vec3(*rhs.tmp4)),
     ntl(new Vec3(*rhs.ntl)),
     ntr(new Vec3(*rhs.ntr)),
     nbl(new Vec3(*rhs.nbl)),
     nbr(new Vec3(*rhs.nbr)),
     ftl(new Vec3(*rhs.ftl)),
     ftr(new Vec3(*rhs.ftr)),
     fbl(new Vec3(*rhs.fbl)),
     fbr(new Vec3(*rhs.fbr)),
     x(new Vec3(*rhs.x)),
     y(new Vec3(*rhs.y)),
     z(new Vec3(*rhs.z)),
     up(new Vec3(*rhs.up)),
     lookAt(new Vec3(*rhs.lookAt)),
     frustumChanged(rhs.frustumChanged)
    {
        for(int i=0; i<6; i++) {
            planes[i] = rhs.planes[i];
        }
    }

    /**
     * Assignment operator.
     *
     * @param rhs Cam3 to copy from
     * @return this
     */
    Cam3& operator=(const Cam3& rhs);
    /**
     * Destructor.
     */
    ~Cam3(){};

    /**
     * Set the field of view of this Cam3.
     *
     * @param fov new field of view
     */
    void setFOV(float fov);
    /**
     * Get the field of view of this Cam3.
     *
     * @return the field of view
     */
    inline float getFOV();
    /**
     * Get the aspect ratio of this Cam3.
     *
     * @return aspect ratio
     */
    inline float getAspectRatio();
    /**
     * Set the near clipping plane of this Cam3.
     * 
     * @param nearClip near clipping plane
     */
    void setNearClip(float nearClip);
    /**
     * Get the near clipping plane of this Cam3.
     * 
     * @return near clipping plane
     */
    inline float getNearClip();
    /**
     * Set the far clipping plane of this Cam3.
     *
     * @param farClip far clipping plane
     */
    void setFarClip(float farClip);
    /**
     * Get the far clipping plane of this Cam3.
     *
     * @return far clipping plane
     */
    inline float getFarClip();
    /**
     * Set the position of this Cam3.
     *
     * @param x x position
     * @param y y position
     * @param z z position
     */
    inline void setPos(float x, float y, float z);
    /**
     * Set the up vector of this Cam3.
     *
     * @param up up vector
     */
    inline void setUp(const Vec3& up);
    /**
     * Set the up vector of this Cam3.
     *
     * @param x x position
     * @param y y position
     * @param z z position
     */
    inline void setUp(float x, float y, float z);
    /**
     * Get the up vector of this Cam3.
     *
     * @return up vector
     */
    inline Vec3& getUp();
    /**
     * Set the look at vector of this Cam3.
     *
     * @param lookAt look at vector
     */
    inline void setLookAt(const Vec3& lookAt);
    /**
     * Set the look at vector of this Cam3.
     *
     * @param x x position
     * @param y y position
     * @param z z position
     */
    inline void setLookAt(float x, float y, float z);
    /**
     * Return the look at vector of this Cam3.
     *
     * @return look at vector
     */
    inline Vec3& getLookAt();
    /**
     * Get the x axis of this Cam3.
     *
     * @return x axis
     */
    inline Vec3& getXAxis();
    /**
     * Get the y axis of this Cam3.
     *
     * @return y axis
     */
    inline Vec3& getYAxis();
    /**
     * Get the z axis of this Cam3.
     *
     * @return z axis
     */
    Vec3& getZAxis();
    bool isVisible(const Vec3& pos);
    bool isVisible(const BoundingVolume<Vec3>& bounds);
    /**
     * Generate a pick ray for the given parameters. A pick ray allows checking
     * for contact between a point on the physical screen and a point somewhere
     * in 3D space.
     * 
     * @param screenX screen x coordinate
     * @param screenY screen y coordinate
     * @param pickPos pick position
     * @param pickDir direction of screen coordinate to pick position
     */
    void generatePickRay(float screenX, float screenY, Vec3& pickPos, Vec3& pickDir);
    void update();
    void onCanvasChanged(int width, int height);
};

//INLINE FUNCTION DEFINITIONS

inline float Cam3::getFOV() {

    return fov;
}


inline float Cam3::getAspectRatio() {

    return ratio;
}


inline float Cam3::getNearClip() {

    return nearClip;
}


inline float Cam3::getFarClip() {

    return farClip;
}


inline void Cam3::setPos(float x, float y, float z) {

    pos->setTo(x,y,z);
}


inline void Cam3::setUp(const Vec3& up) {

    this->up->setTo(up);
}


inline void Cam3::setUp(float x, float y, float z) {

    this->up->setTo(x,y,z);
}


inline Vec3& Cam3::getUp() {

    return *up;
}


inline void Cam3::setLookAt(const Vec3& lookAt) {

    this->lookAt->setTo(lookAt);
}


inline void Cam3::setLookAt(float x, float y, float z) {

    this->lookAt->setTo(x,y,z);
}


inline Vec3& Cam3::getLookAt() {

    return *lookAt;
}


inline Vec3& Cam3::getXAxis() {

    return *x;
}


inline Vec3& Cam3::getYAxis() {

    return *y;
}


inline Vec3& Cam3::getZAxis() {

    return *z;
}

#endif	/* CAM3_H */

