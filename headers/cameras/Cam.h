#ifndef CAM_H
#define	CAM_H

#include "headers/collision/BoundingVolume.h"
#include "headers/collision/BoundingSphere.h"
#include "headers/maths/Vec3.h"
#include "headers/maths/Mat4.h"
#include "headers/maths/Plane.h"
#include "headers/cameras/Viewport.h"

/**
 * The Cam class is the root subclass for all cameras.
 *
 * A Cam has a Viewport, through which it sees the scene. It also has a
 * position and a modelview, which makes it compatible with OpenGL.
 *
 * @author Ben Constable, original Java code by Oli Winks
 * @version 1.1
 *
 * @ingroup Cameras
 */
class Cam: public Object {

public:

    bool viewportChanged; ///< Set to true when the viewport has been updated
    bool frustumChanged; ///< Used by the renderer, should not be modified.

    /**
     * Default constructor. Default Viewport positioning and position at the
     * origin.
     */
    Cam();
    /**
     * Constructor which sets the Viewport, field of view and clipping
     * distances.
     * 
     * @param viewport Thie Cam3's Viewport
     * @param cFov field of view
     * @param cNearClip near clipping plane
     * @param cFarClip far clipping plane
     */
    Cam(SPtr<Viewport>& aViewport, float cFov, float cNearClip, float cFarClip);
    /**
     * Copy constructor.
     *
     * @param rhs Cam to copy from
     */
    Cam(const Cam& rhs);
    /**
     * Assignment operator.
     *
     * @param rhs Cam to copy from
     * @return this
     */
    Cam& operator=(const Cam& rhs);
    /**
     * Destructor.
     */
    virtual ~Cam(){}

    /**
     * Set the Viewport to the given parameter.
     * 
     * @param viewport new viewport
     */
    void setViewport(SPtr<Viewport>& viewport);
    /**
     * Return the Viewport associated with this Cam.
     *
     * @return the viewport
     */
    Viewport& getViewport();
    /**
     * Set the position of this Cam.
     *
     * @param pos new pos
     */
    void setPos(const Vec3& pos);
    /**
     * Get the position of this Cam.
     *
     * @return position Vec
     */
    Vec3& getPos();
    /**
     * Return the modelview of this Cam.
     *
     * @return modelview matrix
     */
    Mat4& getModelView();
    
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
    float getFOV();
    /**
     * Get the aspect ratio of this Cam3.
     *
     * @return aspect ratio
     */
    float getAspectRatio();
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
    float getNearClip();
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
    float getFarClip();
    /**
     * Set the position of this Cam3.
     *
     * @param x x position
     * @param y y position
     * @param z z position
     */
    void setPos(float x, float y, float z);
    /**
     * Set the up vector of this Cam3.
     *
     * @param up up vector
     */
    void setUp(const Vec3& up);
    /**
     * Set the up vector of this Cam3.
     *
     * @param x x position
     * @param y y position
     * @param z z position
     */
    void setUp(float x, float y, float z);
    /**
     * Get the up vector of this Cam3.
     *
     * @return up vector
     */
    Vec3& getUp();
    /**
     * Set the look at vector of this Cam3.
     *
     * @param lookAt look at vector
     */
    void setLookAt(const Vec3& lookAt);
    /**
     * Set the look at vector of this Cam3.
     *
     * @param x x position
     * @param y y position
     * @param z z position
     */
    void setLookAt(float x, float y, float z);
    /**
     * Return the look at vector of this Cam3.
     *
     * @return look at vector
     */
    Vec3& getLookAt();
    /**
     * Get the x axis of this Cam3.
     *
     * @return x axis
     */
    Vec3& getXAxis();
    /**
     * Get the y axis of this Cam3.
     *
     * @return y axis
     */
    Vec3& getYAxis();
    /**
     * Get the z axis of this Cam3.
     *
     * @return z axis
     */
    Vec3& getZAxis();
    /**
     * Check if the given point is visible to this Cam.
     *
     * @param pos point to check
     * @return true if point is visible, false if not
     */
    bool isVisible(const Vec3& pos);
    /**
     * Check if the given BoundingVolume is visible to this Cam.
     *
     * @param bounds BoundingVolume to check
     * @return true if BoundingVolume is visible, false if not
     */
    bool isVisible(const BoundingVolume& bounds);
    /**
     * Update this Cam's data. Must be called when this Cam is transformed in
     * any way.
     */
    void update();
    /**
     * Called when the canvas this Cam's Viewport is attached to changes size.
     *
     * @param width new canvas width
     * @param height new canvas height
     */
    void onCanvasChanged(int width, int height);
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

protected:

    SPtr<Viewport> viewport; ///< This Cam's Viewport
    SPtr<Vec3> pos; ///< Position of this Cam
    SPtr<Mat4> modelView; ///< Modelview matrix
    SPtr<Mat4> modelViewInv; ///< Inverse of modelview matrix
    
    //Camera
    SPtr<Vec3> x ///< x axis
              ,y ///< y axis
              ,z; ///< z axis
    SPtr<Vec3> up; ///< The up direction for this Cam3
    SPtr<Vec3> lookAt; ///< Look at coordinates for this Cam3
    
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
    bool isVisible(const BoundingSphere& bounds);
    /**
     * Calculate the clipping planes in each direction to find the new frustum.
     */
    void calculatePlanes();
        
};

#endif	/* CAM_H */

