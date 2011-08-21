#ifndef TEXTURE_H
#define	TEXTURE_H

#include "headers/utils/Object.h"

/**
 * This class holds texture information. Texture data is stored as a 2D array of
 * void pointers. Each row is one texture. Void pointers are accepted by OpenGL,
 *  and so this class complies with OpenGL. Multiple textures are used in
 * OpenGL mipmapping.
 *
 * Textures can be created from any acceptable image format.
 *
 * @see App
 * @see App2
 * @see App3
 * 
 * @author Ben Constable, original Java code by Oli Winks.
 * @version 1.0
 *
 * @ingroup Appearance
 */
class Texture: public Object {

protected:

    int* width; ///< Array of widths for each texture
    int* height; ///< Array of heights for each texture
    void** data; ///< Texture data, each row is one texture
    int numOfTextures; ///< Number of textures stored in this object
    bool alpha; ///< Alpha component of the textures

public:

    unsigned int* texPtr; ///< Pointer to textures, needed by OpenGL

    /**
     * Default constructor. Does nothing (should not be used).
     */
    Texture();
    /**
     * Create a Texture object. Takes widths, heights, data and number of 
     * textures. Alpha is set to false.
     *
     * @param cWidth width array
     * @param cHeight height array
     * @param cData texture data
     * @param cNumOfTextures number of textures
     */
    Texture(int* cWidth, int* cHeight, void** cData, int cNumOfTextures);
    /**
     * Copy constructor. Creates a SHALLOW copy of the given parameter.
     * 
     * @param rhs Texture to copy from
     */
    Texture(const Texture& rhs);
    /**
     * Assignment operator. Creates a SHALLOW copy of the given parameter.
     *
     * @param rhs Texture to copy from
     * @return this
     */
    Texture& operator=(const Texture& rhs);
    /**
     * Destructor.
     */
    ~Texture();

    /**
     * Set the texture data.
     *
     * @param data texture data
     */
    void setData(void** data);
    /**
     * 
     * @param width
     * @param height
     */
    /**
     * Set the dimensions.
     *
     * @param width width dimensions
     * @param height height dimensions
     */
    void setDimensions(int* width, int*height);
    /**
     * Return image data for the specific texture in the data array.
     *
     * @param img index number in the array
     * @return image data
     */
    inline void* getData(int img);
    /**
     * Get the width of the image at the given index.
     *
     * @param img index
     * @return image width
     */
    inline int getWidth(int img);
    /**
     * Get the height of the image at the given index.
     *
     * @param img index
     * @return image height
     */
    inline int getHeight(int img);
    /**
     * Get the number of textures in this Texture object.
     *
     * @return number of textures
     */
    inline int getNumOfTextures();
    /**
     * Whether or not this Texture has alpha.
     *
     * @return true if has alpha, false if not
     */
    inline bool hasAlpha();

};

//INLINE FUNCTION DECLARATIONS

inline void* Texture::getData(int img) {

    return data[img];
}


inline int Texture::getWidth(int img) {

    return width[img];
}


inline int Texture::getHeight(int img) {

    return height[img];
}


inline int Texture::getNumOfTextures() {

    return numOfTextures;
}


inline bool Texture::hasAlpha() {

    return alpha;
}

#endif	/* TEXTURE_H */

