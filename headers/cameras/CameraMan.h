#ifndef CAMERAMAN_H
#define	CAMERAMAN_H

#include "headers/scenegraph/Spatial.h"
#include "headers/cameras/Cam.h"

/**
 * The CameraMan3 class allows a Cam to be placed directly into a scenegraph.
 * This gives it world as well as local information.
 *
 * @see Cam
 *
 * @author Ben Constable, original Java code by Oli Winks
 * @version 1.1
 *
 * @ingroup Cameras
 */
class CameraMan: public Spatial {

protected:

    SPtr<Vec3> worldLookAt; ///< look at coordinates in the world system
    SPtr<Vec3> worldDir; ///< direction coordinates in the world system
    SPtr<Vec3> worldUp; ///< up coordinates in the world system

private:

    SPtr<Cam> cam; ///< Cam3 held by this CameraMan3

public:

    /**
     * Default constructor. Sets position information to default and the
     * camera to the given parameter.
     * 
     * @param name name of this node
     * @param cCam Cam3 to give to his CameraMan3
     */
    CameraMan(const char* name, SPtr<Cam>& cCam)
    :Spatial(name),
     worldLookAt(new Vec3()),
     worldDir(new Vec3(0,0,1)),
     worldUp(new Vec3(0,1,0)),
     cam(cCam)
    {}
    /**
     * Copy constructor.
     *
     * @param rhs CameraMan3 to copy from
     */
    CameraMan(const CameraMan& rhs)
    :Spatial(name),
     worldLookAt(new Vec3(*rhs.worldLookAt)),
     worldDir(new Vec3(*rhs.worldDir)),
     worldUp(new Vec3(*rhs.worldUp)),
     cam(new Cam(*rhs.cam))
    {}
    /**
     * Assignment operator.
     *
     * @param rhs CameraMan3 to copy from
     * @return this
     */
    CameraMan& operator=(const CameraMan& rhs);
    /**
     * Destructor.
     */
    ~CameraMan(){}

    /**
     * Does nothing as CameraMan3 is a leaf node.
     *
     * @param child
     */
    void attachChild(SPtr<Node>& child);
    /**
     * Does nothing as CameraMan3 is a leaf node.
     * @param child
     */
    void detachChild(SPtr<Node>& child);
    /**
     * Does nothing as CameraMan3 is a lead node.
     *
     * @param i
     * @return empty node
     */
    SPtr<Node> detachChild(int i);
    /**
     * Get the world look at.
     * 
     * @return world look at coordinates
     */
    inline Vec3& getWorldLookAt();
    /**
     * Get the world direction.
     *
     * @return world direction at coordinates
     */
    inline Vec3& getWorldDir();
    /**
     * Get the world up.
     *
     * @return world up at coordinates
     */
    inline Vec3& getWorldUp();
    /**
     * Set the Cam3 held by this CameraMan 3.
     *
     * @param camera Cam3 to give to this CameraMan3
     */
    inline void setCamera(SPtr<Cam>& camera);
    /**
     * Return the Cam3 associated with this CameraMan3.
     * 
     * @return Cam3
     */
    inline SPtr<Cam> getCamera();
    /**
     * Update this CameraMan3's BoundingVolume by applying the world transform
     * to it.
     *
     * @param childBounds not used
     * @param from not used
     * @param to not used
     */
    void updateBounds(ArrayList<SPtr<BoundingVolume> >& childBounds, int from, int to);
    /**
     * Apply the given world transform to this node.
     *
     * @param worldTransform world transform to apply
     */
    void applyTransform(Trfm& worldTransform);
    /**
     * Not supported yet.
     *
     * @return empty node
     */
    SPtr<Node> clone();
    /**
     * Not supported yet.
     * 
     * @param parent
     * @return empty node
     */
    SPtr<Node> cloneTree(SPtr<Node>& parent);

};

#endif	/* CAMERAMAN_H */

