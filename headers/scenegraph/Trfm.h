#ifndef TRFM_H
#define	TRFM_H

#include "headers/utils/Object.h"
#include "headers/maths/Mat3.h"
#include "headers/maths/Mat4.h"
#include "headers/maths/FastMath.h"

/**
 * The Trfm class provides functionality to translate, scale and rotate objects in space. 
 * Every Spatial Node has a Trfm object.
 *
 * @see Spatial
 *
 * @author Ben Constable, original Java code by Oli Winks
 * @version 1.1
 *
 * @ingroup Scenegraph
 */
class Trfm: public Object {

public:

    SPtr<Mat4> at; ///< affine transform matrix

    /**
     * Default constructor. Sets up all matrices and vectors, and scale set to 
     * 1.
     */
    Trfm();
    /**
     * Copy constructor. Copies this transform.
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
    void setTo(const Trfm& trfm);
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
    float getScale();
    /**
     * Store the translation data of this Trfm in the parameter vector.
     *
     * @param store Vec to store data in
     */
    void getTranslation(Vec& store);
    /**
     * Return the rotation angle of this Trfm in the given axis.
     *
     * @param axis Axis to check rotation in
     * @return angle
     */
    float getRotation(Vec3& axis);
    /**
     * Store the rotation in each axis in the given Vec3. X,Y,Z order.
     *
     * @param store Vec3 to store rotation in
     */
    void getRotationXYZ(const Vec3& store);
    /**
     * Store the rotation in each axis in the given Vec3. Y,X,Z order.
     *
     * @param store Vec3 to store rotation in
     */
    void getRotationYXZ(const Vec3& store);
    /**
     * Set the scale of this Trfm to the given parameter.
     *
     * @param scale new scale
     */
    void scaleTo(float scale);
    /**
     * Translate this Trfm to the given position.
     *
     * @param pos new position
     */
    void translateTo(const Vec& pos);
    /**
     * Translate this Trfm to the given x,y,z position.
     * 
     * @param x new x pos
     * @param y new y pos
     * @param z new z pos
     */
    void translateTo(float x, float y, float z);
    /**
     * Translate this Trfm by the given vector.
     *
     * @param dPos vector to add to the position
     */
    void translateBy(const Vec& dPos);
    /**
     * Translate this Trfm by the given x,y,z values.
     *
     * @param dx x difference
     * @param dy y difference
     * @param dz z difference
     */
    void translateBy(float dx, float dy, float dz);
    /**
     * Rotate this Trfm to the given angle in the given axis.
     * 
     * @param angle rotation angle
     * @param x x axis
     * @param y y axis
     * @param z z axis
     */
    void rotateTo(float angle, float x, float y, float z);
    /**
     * Rotate this Trfm to the given angle in the given axis.
     * 
     * @param angle rotation
     * @param axis angle
     */
    void rotateTo(float angle, const Vec3& axis);
    /**
     * Rotate this Trfm by the given amount in each axis. X,Y,Z order.
     *
     * @param pitch pitch amount
     * @param yaw yaw amount
     * @param roll roll amount
     */
    void rotateToXYZ(float pitch, float yaw, float roll);
    /**
     * Rotate this Trfm by the given amount in each axis. X,Y,Z order.
     * 
     * @param rot Rotation amount in each axis
     */
    void rotateToXYZ(const Vec3& rot);
    /**
     * Rotate this Trfm by the given amount in each axis. Y,X,Z order.
     *
     * @param pitch pitch amount
     * @param yaw yaw amount
     * @param roll roll amount
     */
    void rotateToYXZ(float pitch, float yaw, float roll);
    /**
     * Rotate this Trfm by the given amount in each axis. Y,X,Z order.
     *
     * @param rot Rotation amount in each axis
     */
    void rotateToYXZ(const Vec3& rot);
    /**
     * Add the affine transformation matrix of the given parameter Trfm to that
     * of this Trfm.
     *
     * @param local transformation data to add
     */
    void add(const Trfm& local);
    /**
     * Get the affine transformation matrix.
     *
     * @return affine trfm matrix
     */
    Mat& getAt();
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
    void decompose();
    /**
     * Update the affine transformation matrix based on the individual parts of
     * this Trfm.
     */
    void update();
    /**
     * Apply the inverse of the affine transformation through the given vector.
     *
     * @param vec Vec to multiply through
     */
    void applyInverse(Vec& vec);

protected:

    float sc; ///< scale ratio
    SPtr<Vec3> tr; ///< translation vector
    SPtr<Mat3> ro; ///< rotation matrix

    SPtr<Vec> pos; ///< position

    //Convenience variables, for speed.
    SPtr<Vec3> tmpV;
    SPtr<Mat4> tmpM;
};

#endif	/* TRFM_H */

