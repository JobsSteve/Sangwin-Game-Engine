#ifndef CAM_H
#define	CAM_H

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//                                 DEFINITION                                 //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

#include "BoundingVolume.h"
#include "Mat4.h"
#include "Viewport.h"

/**
 * The Cam class is the root subclass for all cameras.
 *
 * A Cam has a Viewport, through which it sees the scene. It also has a
 * position and a modelview, which makes it compatible with OpenGL.
 *
 * @see Cam2
 * @see Cam3
 *
 * @author Ben Constable, original Java code by Oli Winks
 * @version 1.0
 *
 * @ingroup Cameras
 */
template<class V>
class Cam: public Object {

public:

    bool viewportChanged; ///< Set to true when the viewport has been updated

    /**
     * Default constructor. Default Viewport positioning and position at the
     * origin.
     */
    Cam();
    /**
     * Constructor that sets the Cam to be at the origin and the Viewport to
     * the given parameter.
     * 
     * @param viewport viewport of this Cam
     */
    Cam(SPtr<Viewport>& viewport);
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
    Cam<V>& operator=(const Cam<V>& rhs);
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
    inline Viewport& getViewport();
    /**
     * Set the position of this Cam.
     *
     * @param pos new pos
     */
    inline void setPos(const V& pos);
    /**
     * Set the position of this Cam.
     *
     * @param pos float array containing position data
     */
    inline void setPos(const float pos[]);
    /**
     * Get the position of this Cam.
     *
     * @return position Vec
     */
    inline V& getPos();
    /**
     * Return the modelview of this Cam.
     *
     * @return modelview matrix
     */
    inline Mat4& getModelView();
    /**
     * Check if the given point is visible to this Cam.
     *
     * @param pos point to check
     * @return true if point is visible, false if not
     */
    virtual bool isVisible(const V& pos) = 0;
    /**
     * Check if the given BoundingVolume is visible to this Cam.
     *
     * @param bounds BoundingVolume to check
     * @return true if BoundingVolume is visible, false if not
     */
    virtual bool isVisible(const BoundingVolume<V>& bounds) = 0;
    /**
     * Update this Cam's data. Must be called when this Cam is transformed in
     * any way.
     */
    virtual void update() = 0;
    /**
     * Called when the canvas this Cam's Viewport is attached to changes size.
     *
     * @param width new canvas width
     * @param height new canvas height
     */
    virtual void onCanvasChanged(int width, int height);

protected:

    SPtr<Viewport> viewport; ///< This Cam's Viewport
    SPtr<V> pos; ///< Position of this Cam
    SPtr<Mat4> modelView; ///< Modelview matrix
    SPtr<Mat4> modelViewInv; ///< Inverse of modelview matrix
};


////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//                               IMPLEMENTATION                               //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////


template<class V>
Cam<V>::Cam()
:viewportChanged(true),
 viewport(new Viewport()),
 pos(new V()),
 modelView(new Mat4()),
 modelViewInv(new Mat4())
{}


template<class V>
Cam<V>::Cam(SPtr<Viewport>& aViewport)
:viewportChanged(true),
 viewport(aViewport),
 pos(new V()),
 modelView(new Mat4()),
 modelViewInv(new Mat4())
{}


template<class V>
Cam<V>::Cam(const Cam& rhs)
:viewportChanged(rhs.viewportChanged),
 viewport(new Viewport(*rhs.viewport)),
 pos(new V(*rhs.pos)),
 modelView(new Mat4(*rhs.modelView)),
 modelViewInv(new Mat4(*rhs.modelViewInv))
{}


template<class V>
Cam<V>& Cam<V>::operator =(const Cam<V>& rhs) {

    viewportChanged = rhs.viewportChanged;
    *viewport = *rhs.viewport;
    *pos = *rhs.pos;
    *modelView = *rhs.modelView;
    *modelViewInv = *rhs.modelViewInv;
    
    return *this;
}


template<class V>
void Cam<V>::setViewport(SPtr<Viewport>& viewport) {

    viewportChanged = true;
    this->viewport = viewport;
}


template<class V>
inline Viewport& Cam<V>::getViewport() {

    return *viewport;
}


template<class V>
inline void Cam<V>::setPos(const V& pos) {

    this->pos->setTo(pos);
}


template<class V>
inline void Cam<V>::setPos(const float pos[]) {

    this->pos->setTo(pos);
}


template<class V>
inline V& Cam<V>::getPos() {

    return *pos;
}


template<class V>
inline Mat4& Cam<V>::getModelView() {

    return *modelView;
}


template<class V>
void Cam<V>::onCanvasChanged(int width, int height) {

    viewport->onCanvasChanged(width,height);
    viewportChanged = true;
}


#endif	/* CAM_H */

