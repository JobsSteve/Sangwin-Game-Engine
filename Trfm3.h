#ifndef TRFM3_H
#define	TRFM3_H

#include "Trfm.h"
#include "Mat3.h"
#include "Mat4.h"
#include "FastMath.h"

/**
 * The Trfm3 class extends the Trfm class to be used in 3D space.
 *
 * @see Trfm
 * @see Spatial
 *
 * @author Ben Constable, original Java code by Oli Winks
 * @version 1.0
 *
 * @ingroup Scenegraph
 */
class Trfm3: public Trfm {

public:

    /**
     * Default constructor. Initialises all vectors and matrices to default
     * values.
     */
    Trfm3()
    :Trfm()
    {
        tr = SPtr<Vec>(new Vec3());
        ro = SPtr<Mat>(new Mat3());
        at = SPtr<Mat>(new Mat4());
        tmpV = SPtr<Vec>(new Vec3());
        tmpM = SPtr<Mat>(new Mat4());
    }
    /**
     * Copy constructor.
     * 
     * @param rhs Trfm3 to copy from
     */
    Trfm3(const Trfm3& rhs)
    :Trfm(rhs)
    {
        tr = SPtr<Vec>(new Vec3(static_cast<Vec3&>(*rhs.tr)));
        ro = SPtr<Mat>(new Mat3(static_cast<Mat3&>(*rhs.ro)));
        at = SPtr<Mat>(new Mat4(static_cast<Mat4&>(*rhs.at)));
        tmpV = SPtr<Vec>(new Vec3(static_cast<Vec3&>(*rhs.tmpV)));
        tmpM = SPtr<Mat>(new Mat4(static_cast<Mat4&>(*rhs.tmpM)));
    }
    /**
     * Assignment operator.
     *
     * @param rhs Trfm3 to copy from
     * @return this
     */
    Trfm3& operator=(const Trfm3& rhs);
    /**
     * Destructor.
     */
    ~Trfm3() {}
    
    void decompose();
    /**
     * Return the rotation angle of this Trfm3 in the given axis.
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
     * Translate this Trfm3 to the given x,y,z position.
     * 
     * @param x new x pos
     * @param y new y pos
     * @param z new z pos
     */
    void translateTo(float x, float y, float z);
    /**
     * Translate this Trfm3 by the given x,y,z values.
     *
     * @param dx x difference
     * @param dy y difference
     * @param dz z difference
     */
    void translateBy(float dx, float dy, float dz);
    /**
     * Rotate this Trfm3 to the given angle in the given axis.
     * 
     * @param angle rotation angle
     * @param x x axis
     * @param y y axis
     * @param z z axis
     */
    void rotateTo(float angle, float x, float y, float z);
    /**
     * Rotate this Trfm3 to the given angle in the given axis.
     * 
     * @param angle rotation
     * @param axis angle
     */
    void rotateTo(float angle, const Vec3& axis);
    /**
     * Rotate this Trfm3 by the given amount in each axis. X,Y,Z order.
     *
     * @param pitch pitch amount
     * @param yaw yaw amount
     * @param roll roll amount
     */
    void rotateToXYZ(float pitch, float yaw, float roll);
    /**
     * Rotate this Trfm3 by the given amount in each axis. X,Y,Z order.
     * 
     * @param rot Rotation amount in each axis
     */
    void rotateToXYZ(const Vec3& rot);
    /**
     * Rotate this Trfm3 by the given amount in each axis. Y,X,Z order.
     *
     * @param pitch pitch amount
     * @param yaw yaw amount
     * @param roll roll amount
     */
    void rotateToYXZ(float pitch, float yaw, float roll);
    /**
     * Rotate this Trfm3 by the given amount in each axis. Y,X,Z order.
     *
     * @param rot Rotation amount in each axis
     */
    void rotateToYXZ(const Vec3& rot);
    void update();
    void applyInverse(Vec& vec);
};

#endif	/* TRFM3_H */

