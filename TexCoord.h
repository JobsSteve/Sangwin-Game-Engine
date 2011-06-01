#ifndef TEXCOORD_H
#define	TEXCOORD_H

#include "Object.h"
#include "Vec2.h"

/**
 * This is a simple wrapper class that allows texture coordinate arrays to be
 * held by SPtrs, and therfore have them delete correctly when used in an
 * ArrayList.
 *
 * @see Trimesh
 * @see ArrayList
 *
 * @author Ben Constable
 * @version 1.0
 *
 * @ingroup Scenegraph
 */
class TexCoord: public Object {

private:

    int size; ///< the number of individual points in the tex coord array
    float* coords; ///< tex coord array
    int pos; ///< current position in the array

public:

    /**
     * Default constructor. Create a new array of tex coords of the given size.
     * The size is the number of INDIVIDUAL COORDINATES in the array. So for 4
     * tex coords, each consisting of a u and v position, the size will be 8.
     *
     * @param cSize size of array
     */
    TexCoord(int cSize);
    /**
     * Copy constructor.
     *
     * @param rhs TexCoord to copy from
     */
    TexCoord(const TexCoord& rhs);
    /**
     * Assignment operator.
     *
     * @param rhs TexCoord to copy from
     * @return this
     */
    TexCoord& operator=(const TexCoord& rhs);
    /**
     * Destructor.
     */
    ~TexCoord();

    /**
     * Return the size of this tex coord array.
     *
     * @return size
     */
    inline int getSize();
    /**
     * Get the tex coords array from this TexCoord.
     *
     * @return tex coords
     */
    inline float* getCoords();
    /**
     * Add a pair of tex coords to the array.
     *
     * @param vec Vec2 containing tex coords
     */
    void addCoord(const Vec2& vec);
    /**
     * Add an individual tex coord to the array.
     *
     * @param c single tex coord
     */
    void addCoord(float c);
};

//INLINE FUNCTION DEFINITIONS

inline int TexCoord::getSize() {

    return size;
}


inline float* TexCoord::getCoords() {

    return coords;
}

#endif	/* TEXCOORD_H */

