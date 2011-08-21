#ifndef CAMERAMAN3_H
#define	CAMERAMAN3_H

#include "headers/scenegraph/Spatial.h"
#include "headers/cameras/Cam3.h"

/**
 * The CameraMan3 class allows a Cam3 to be placed directly into a scenegraph.
 * This gives it world as well as local information.
 *
 * @see Cam3
 *
 * @author Ben Constable, original Java code by Oli Winks
 * @version 1.0
 *
 * @ingroup Cameras
 */
class CameraMan3: public Spatial<Vec3,Trfm3> {

protected:

    SPtr<Vec3> worldLookAt; ///< look at coordinates in the world system
    SPtr<Vec3> worldDir; ///< direction coordinates in the world system
    SPtr<Vec3> worldUp; ///< up coordinates in the world system

private:

    SPtr<Cam3> cam; ///< Cam3 held by this CameraMan3

public:

    /**
     * Default constructor. Sets position information to default and the
     * camera to the given parameter.
     * 
     * @param name name of this node
     * @param cCam Cam3 to give to his CameraMan3
     */
    CameraMan3(const char* name, SPtr<Cam3>& cCam)
    :Spatial<Vec3,Trfm3>(name),
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
    CameraMan3(const CameraMan3& rhs)
    :Spatial<Vec3,Trfm3>(name),
     worldLookAt(new Vec3(*rhs.worldLookAt)),
     worldDir(new Vec3(*rhs.worldDir)),
     worldUp(new Vec3(*rhs.worldUp)),
     cam(new Cam3(*rhs.cam))
    {}
    /**
     * Assignment operator.
     *
     * @param rhs CameraMan3 to copy from
     * @return this
     */
    CameraMan3& operator=(const CameraMan3& rhs);
    /**
     * Destructor.
     */
    ~CameraMan3(){}

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
    inline void setCamera(SPtr<Cam3>& camera);
    /**
     * Return the Cam3 associated with this CameraMan3.
     * 
     * @return Cam3
     */
    inline SPtr<Cam3> getCamera();
    /**
     * Update this CameraMan3's BoundingVolume by applying the world transform
     * to it.
     *
     * @param childBounds not used
     * @param from not used
     * @param to not used
     */
    void updateBounds(ArrayList<SPtr<BoundingVolume<Vec3> > >& childBounds, int from, int to);
    /**
     * Apply the given world transform to this node.
     *
     * @param worldTransform world transform to apply
     */
    void applyTransform(Trfm3& worldTransform);
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

//INLINE FUNCTION DEFINITIONS

inline Vec3& CameraMan3::getWorldLookAt() {

    return *worldLookAt;
}


inline Vec3& CameraMan3::getWorldDir() {

    return *worldDir;
}


inline Vec3& CameraMan3::getWorldUp() {

    return *worldUp;
}


inline void CameraMan3::setCamera(SPtr<Cam3>& camera) {

    this->cam = camera;
}


inline SPtr<Cam3> CameraMan3::getCamera() {

    return cam;
}

#endif	/* CAMERAMAN3_H */

