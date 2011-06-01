#ifndef LINEATT_H
#define	LINEATT_H

#include "Object.h"

/**
 * This class represents the line attribute of 2D or 3D object. It decides the
 * width of each and line and whether or not they are antialiased.
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
class LineAtt: public Object {

public:

    bool isAntialiased; ///< Whether or not the line is antialiased

    /**
     * Default constructor. Sets line width to 1, and antialiased to off.
     */
    LineAtt();
    /**
     * Copy constructor.
     *
     * @param rhs LineAtt to copy from
     */
    LineAtt(const LineAtt& rhs);
    /**
     * Assignment operator.
     *
     * @param rhs LineAtt to copy from
     * @return this
     */
    LineAtt& operator=(const LineAtt& rhs);
    /**
     * Destructor
     */
    ~LineAtt();

    /**
     * Set the values of this LineAtt to those of the given one.
     *
     * @param att LineAtt to copy from
     */
    void setTo(const LineAtt& att);
    /**
     * Se the linewidth of this LineAtt to the given parameter.
     *
     * @param lineWidth new line width
     */
    inline void setLineWidth(float lineWidth);
    /**
     * Return the linewidth.
     *
     * @return line width
     */
    inline float getLineWidth();
    /**
     * Set this LineAtt to default. Width 1, antialias off.
     */
    void toDefault();
    
private:

    float lineWidth; ///< Line width
};

//INLINE FUNCTIONS

inline void LineAtt::setLineWidth(float lineWidth) {

    this->lineWidth = lineWidth;
}


inline float LineAtt::getLineWidth() {

    return lineWidth;
}


#endif	/* LINEATT_H */

