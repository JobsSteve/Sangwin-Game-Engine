#ifndef FASTMATH_H
#define	FASTMATH_H

/**
 * The FastMath class provides a number of trigonometrical operations with
 * reduced accuracy and greater speed than the math.h implementation. It should
 * be used when speed is important and accuracy can afford a reduction. The
 * class is a Singleton, and uses sin and cos tables built a single time,
 * at initial construction.
 *
 * @author Ben Constable, original Java code by Oli Winks
 * @version 1.0
 *
 * @ingroup Math
 */
class FastMath {

private:

    static FastMath* inst; ///< instance of this class
    static float sinTable[720]; ///< sin table
    static float cosTable[720]; ///< cos table
    static const float PI = 3.1415926f; ///< PI to 7dp
    static const float step = 2*3.1415926f/720; ///< step distance in tables
    static const float PI2 = 3.1415926f*2; ///< 2*PI, to 7dp
    static const float HALFPI = 3.1415926f/2; ///< 0.5*PI, to 7dp

    /**
     * Destructor.
     */
    ~FastMath();

    /**
     * Build sin and cos tables using step and math.h sin/cos functions.
     */
    void build();

    /**
     * Copy constructor. Not defined as this class is a Singleton.
     * @param rhs
     */
    FastMath(const FastMath& rhs);
    /**
     * Assignment operator. Not defined as this class is a Singleton.
     * 
     * @param rhs
     * @return
     */
    FastMath& operator=(const FastMath& rhs);
    
protected:

    /**
     * Default constructor. Does nothing.
     */
    FastMath();
    
public:

    /**
     * Return the instance of this class. If there isn't one, create one.
     *
     * @return instance
     */
    static FastMath* instance();
    /**
     * Convert the given angle to radians.
     *
     * @param a angle in degrees
     * @return angle in radians
     */
    inline float fmToRadians(float a);
    /**
     * Convert the given angle to degrees.
     *
     * @param a angle in radians
     * @return angle in degress
     */
    inline float fmToDegrees(float a);
    /**
     * Get the absolute value of the given value.
     *
     * @param a value
     * @return absolute value
     */
    float fmAbs(float a);
    /**
     * Calculate the sin of the given angle.
     *
     * @param a angle
     * @return sin of a
     */
    float fmSin(float a);
    /**
     * Calculate the cosine of the given angle.
     *
     * @param a angle
     * @return cosine of a
     */
    float fmCos(float a);
    /**
     * PI to 7dp.
     *
     * @return PI to 7dp
     */
    inline float fmPi();
    /**
     * 2*PI to 7dp.
     *
     * @return 2*PI to 7dp
     */
    inline float fm2Pi();
    /**
     * Half PI to 7dp.
     *
     * @return Half PI to 7dp
     */
    inline float fmHalfPi();
};

//INLINE FUNCTION DEFINITIONS

inline float FastMath::fmToRadians(float a) {

    return a*0.0174532925f;
}


inline float FastMath::fmToDegrees(float a) {

    return a*57.2957795f;
}


inline float FastMath::fmPi() {

    return PI;
}


inline float FastMath::fm2Pi() {

    return PI2;
}


inline float FastMath::fmHalfPi() {

    return HALFPI;
}


#endif	/* FASTMATH_H */

