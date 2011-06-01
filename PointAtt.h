#ifndef POINTATT_H
#define	POINTATT_H

#include "Object.h"

/**
 * This class represents the point attribute of a 2D or 3D object. This is the
 * width of each point, and whether or not they are antialiased.
 *
 * @see App
 * @see App2
 * @see App3
 * 
 * @author Ben Constable, original Java code by Oli Winks
 * @version 1.0
 *
 * @ingroup Appearance
 */
class PointAtt: public Object {

public:

    bool isAntialiased; ///< Whether or not the points are antialiased

    /**
     * Default constructor. Sets point size to 1, and antialias to off.
     */
    PointAtt();
    /**
     * Copy constructor.
     *
     * @param rhs PointAtt to copy from
     */
    PointAtt(const PointAtt& rhs);
    /**
     * Assignment operator.
     *
     * @param rhs PointAtt to copy from
     * @return this
     */
    PointAtt& operator=(const PointAtt& rhs);
    /**
     * Destructor.
     */
    ~PointAtt();

    /**
     * Set the values of this PointAtt to those of the given parameter.
     *
     * @param att PointAtt to set from
     */
    void setTo(const PointAtt& att);
    /**
     * Set the pointsize.
     *
     * @param pointSize new pointsize
     */
    inline void setPointSize(float pointSize);
    /**
     * Get the pointsize.
     *
     * @return pointsize
     */
    inline float getPointSize();
    /**
     * Set this PointAtt to default. Width 1, antialias off.
     */
    void toDefault();

private:

    float pointSize; ///< Point size value
};

//INLINE FUNCTION DECLARATIONS

inline void PointAtt::setPointSize(float pointSize) {

    this->pointSize = pointSize;
}


inline float PointAtt::getPointSize() {

    return pointSize;
}

#endif	/* POINTATT_H */

