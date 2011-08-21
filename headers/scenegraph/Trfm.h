#ifndef TRFM_H
#define	TRFM_H

#include "headers/utils/Object.h"
#include "headers/maths/Mat.h"
#include "headers/maths/Vec.h"

/**
 * The Trfm class is an abstract class that is implemented by Trfm2 and Trfm3.
 * It provides functionality to translate, scale and rotate objects in 2D and
 * 3D space. Every Spatial Node has a Trfm object.
 *
 * @see Trfm2
 * @see Trfm3
 * @see Spatial
 *
 * @author Ben Constable, original Java code by Oli Winks
 * @version 1.0
 *
 * @ingroup Scenegraph
 */
class Trfm: public Object {

public:

    SPtr<Mat> at; ///< affine transform matrix

    /**
     * Default constructor. All matrices set to null and scale set to 1.
     */
    Trfm();
    /**
     * Copy constructor. Does nothing, copying handled by implementing classes,
     * except for scale.
     *
     * @param rhs
     */
    Trfm(const Trfm& rhs);
    /**
     * Assignment operator.
     *
     * @param rhs Trfm to copy from
     * @return this
     */
    Trfm& operator=(const Trfm& rhs);
    /**
     * Destructor.
     */
    virtual ~Trfm();

    /**
     * Set the translation, rotation, scale and affine transformation data
     * from the parameter Trfm.
     *
     * @param trfm Trfm to get data from
     */
    inline void setTo(const Trfm& trfm);
    /**
     * Set all matrices to identity and scale to 1.
     */
    void toIdentity();
    /**
     * Store the position data of this Trfm in the paramter vector.
     *
     * @param store Vec to store data in
     */
    void getPos(Vec& store);
    /**
     * Get the scale of this transform.
     *
     * @return scale
     */
    inline float getScale();
    /**
     * Store the translation data of this Trfm in the parameter vector.
     *
     * @param store Vec to store data in
     */
    inline void getTranslation(Vec& store);
    /**
     * Set the scale of this Trfm to the given parameter.
     *
     * @param scale new scale
     */
    inline void scaleTo(float scale);
    /**
     * Translate this Trfm to the given position.
     *
     * @param pos new position
     */
    inline void translateTo(const Vec& pos);
    /**
     * Translate this Trfm by the given vector.
     *
     * @param dPos vector to add to the position
     */
    inline void translateBy(const Vec& dPos);
    /**
     * Add the affine transformation matrix of the given parameter Trfm to that
     * of this Trfm.
     *
     * @param local transformation data to add
     */
    inline void add(const Trfm& local);
    /**
     * Get the affine transformation matrix.
     *
     * @return affine trfm matrix
     */
    inline Mat& getAt();
    /**
     * Multiply the given Vec through the affine transformation matrix.
     *
     * @param vec Vec to multiply through
     */
    virtual void apply(Vec& vec);
    /**
     * Decompose the affine transformation matrix into its separate parts, and
     * store them in this Trfm.
     */
    virtual void decompose() = 0;
    /**
     * Update the affine transformation matrix based on the individual parts of
     * this Trfm.
     */
    virtual void update() = 0;
    /**
     * Apply the inverse of the affine transformation through the given vector.
     *
     * @param vec Vec to multiply through
     */
    virtual void applyInverse(Vec& vec) = 0;

protected:

    float sc; ///< scale ratio
    SPtr<Vec> tr; ///< translation vector
    SPtr<Mat> ro; ///< rotation matrix

    SPtr<Vec> pos; ///< position

    //Convenience variables, for speed.
    SPtr<Vec> tmpV;
    SPtr<Mat> tmpM;
    
};


inline void Trfm::setTo(const Trfm& trfm) {

    sc = trfm.sc;
    tr->setTo(*trfm.tr);
    ro->setTo(*trfm.ro);
    at->setTo(*trfm.at);
}


inline void Trfm::add(const Trfm& local) {

    at->mult(*local.at);
}


inline float Trfm::getScale() {

    return sc;
}


inline void Trfm::getTranslation(Vec& store) {

    store.setTo(*tr);
}


inline void Trfm::scaleTo(float scale) {

    sc = scale;
}


inline void Trfm::translateTo(const Vec& pos) {

    tr->setTo(pos);
}


inline void Trfm::translateBy(const Vec& dPos) {

    tr->add(dPos);
}


inline Mat& Trfm::getAt() {

    return *at;
}

#endif	/* TRFM_H */

