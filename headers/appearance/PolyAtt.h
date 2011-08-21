#ifndef POLYATT_H
#define	POLYATT_H

#include "headers/utils/Object.h"

/**
 * This class represents the poly attribute of a 2d or 3d object. This is
 * whether or not certain faces are culled.
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
class PolyAtt: public Object {

public:

    /**
     * Enum of the culling type.
     */
    enum CullFace {
        FRONT, ///< Front face culling on
        BACK, ///< Back face culling on
        NONE //< No face culling on
    };

    CullFace cullFace; ///< Cullface value

    /**
     * Default constructor. Sets culling to back.
     */
    PolyAtt();
    /**
     * Copy constructor.
     * 
     * @param rhs PolyAtt to copy from
     */
    PolyAtt(const PolyAtt& rhs);
    /**
     * Assignment operator.
     *
     * @param rhs PolyAtt to copy from
     * @return this
     */
    PolyAtt& operator=(const PolyAtt& rhs);
    /**
     * Destructor.
     */
    ~PolyAtt();

    /**
     * Set the culling value to that of the given PolyAtt.
     * 
     * @param att PolyAtt to set from
     */
    inline void setTo(const PolyAtt& att);
    /**
     * Set this PolyAtt to default, back face culling.
     */
    inline void toDefault();
};

//INLINE FUNCTION DECLARATIONS

inline void PolyAtt::setTo(const PolyAtt& att) {

    this->cullFace = att.cullFace;
}


inline void PolyAtt::toDefault() {

    cullFace = BACK;
}

#endif	/* POLYATT_H */

