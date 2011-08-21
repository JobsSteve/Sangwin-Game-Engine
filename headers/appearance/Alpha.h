#ifndef ALPHA_H
#define	ALPHA_H

#include "headers/utils/Object.h"

/**
 * The Alpha class is used to set the alpha component of a material.
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
class Alpha: public Object {

public:

    /**
     * Default constructor. Set alpha value to 1.
     */
    Alpha();
    /**
     * Constructor that sets this Alpha object to the given value.
     *
     * @param alpha alpha value
     */
    Alpha(float alpha);
    /**
     * Copy constructor.
     * 
     * @param rhs Alpha to copy from
     */
    Alpha(const Alpha& rhs);
    /**
     * Assignment operator.
     *
     * @param rhs Alpha to copy from
     * @return this
     */
    Alpha& operator=(const Alpha& rhs);
    /**
     * Destructor.
     */
    ~Alpha();

    /**
     * Set the value of this Alpha to that of the given one.
     *
     * @param att Alpha to set the value from
     */
    inline void setTo(const Alpha& att);
    /**
     * Set the value of this Alpha to the given value.
     *
     * @param alpha alpha value
     */
    inline void setValue(float alpha);
    /**
     * Return the value of this Alpha.
     *
     * @return alpha value
     */
    inline float getValue();
    /**
     * Set the alpha value to one.
     */
    inline void toDefault();
    
private:
    float alpha; ///< Alpha value
};

//INLINE FUNCTION DECLARATIONS

inline void Alpha::setTo(const Alpha& att) {

    this->alpha = att.alpha;
}


inline void Alpha::setValue(float alpha) {

    this->alpha = alpha;
}


inline float Alpha::getValue() {

    return alpha;
}


inline void Alpha::toDefault() {

    alpha = 1;
}

#endif	/* ALPHA_H */

