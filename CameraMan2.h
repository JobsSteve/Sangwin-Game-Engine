#ifndef CAMERAMAN2_H
#define	CAMERAMAN2_H

#include "Spatial.h"
#include "Cam2.h"

/**
 * The CameraMan2 class allows a camera to be placed in a 2D scenegraph. It is
 * a leaf node that has spatial and bounding information.
 *
 * @see Cam2
 *
 * @author Ben Constable, original Java engine by Oli Winks
 * @version 1.0
 *
 * @ingroup Cameras
 */
class CameraMan2: public Spatial<Vec2,Trfm2> {

private:

    SPtr<Cam2> cam; ///< This CameraMan2's Cam2.

public:

    /**
     * Default construtor. Default Spatial information and Cam2 to set to the
     * paramter camera.
     *
     * @param name name of this node
     * @param cCam cam2
     */
    CameraMan2(const char* name, SPtr<Cam2>& cCam)
    :Spatial<Vec2,Trfm2>(name),
     cam(cCam)
    {}
    /**
     * Copy constructor.
     *
     * @param rhs CameraMan2 to copy from
     */
    CameraMan2(const CameraMan2& rhs)
    :Spatial<Vec2,Trfm2>(rhs),
     cam(new Cam2(*rhs.cam))
    {}
    /**
     * Assignment operator.
     *
     * @param rhs CameraMan2 to copy from
     * @return this
     */
    CameraMan2& operator=(const CameraMan2& rhs);
    ~CameraMan2(){}

    /**
     * Does nothing as CameraMan2 is a leaf node.
     * 
     * @param child
     */
    void attachChild(SPtr<Node>& child);
    /**
     * Does nothing as CameraMan2 is a leaf node.
     * 
     * @param child
     */
    void detachChild(const SPtr<Node>& child);
    /**
     * Does nothing as CameraMan2 is a leaf node.
     *
     * @param i
     * @return empty node
     */
    SPtr<Node> detachChild(int i);
    /**
     * Set the Cam2 associated with this CameraMan2. 
     * @param cam
     */
    inline void setCamera(SPtr<Cam2>& cam);
    /**
     * Return the Cam2 associated with this CameraMan2.
     * @return
     */
    inline SPtr<Cam2> getCamera();
    /**
     * Update this CameraMan2's BoundingVolume by applying the world transform
     * to it.
     * 
     * @param childBounds not used
     * @param from not used
     * @param to not used
     */
    void updateBounds(ArrayList<SPtr<BoundingVolume<Vec2> > >& childBounds, int from, int to);
    /**
     * Apply the given world transform to this node.
     * 
     * @param worldTransform world transform to apply
     */
    void applyTransform(Trfm2& worldTransform);
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

inline void CameraMan2::setCamera(SPtr<Cam2>& cam) {

    this->cam = cam;
}


inline SPtr<Cam2> CameraMan2::getCamera() {

    return cam;
}

#endif	/* CAMERAMAN2_H */

