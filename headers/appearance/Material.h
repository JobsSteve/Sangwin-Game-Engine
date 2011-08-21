#ifndef MATERIAL_H
#define	MATERIAL_H

#include "headers/utils/Object.h"

/**
 * A Material is a complete material compatible with OpenGL. This includes
 * alpha, shininess, ambient, diffuse, specular and emissive components.
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
class Material: public Object {

public:

    static float* defaultAmbient; ///< Default ambient, all values 0.5
    static float* defaultDiffuse; ///< Default diffuse, all values 0.5
    static float* defaultSpecular; ///< Default specular, all values 0.0
    static float* defaultEmissive; ///< Default emissive, all values 0.0

    /**
     * Default constructor. Set up default arrays, and set all regular arrays
     * to default values.
     */
    Material();
    /**
     * Create Material with the given ambient array.
     *
     * @param cAmbient ambient array
     */
    Material(float* cAmbient);
    /**
     * Create Material with the given ambient and diffuse arrays.
     *
     * @param cAmbient ambient array
     * @param cDiffuse diffuse array
     */
    Material(float* cAmbient, float* cDiffuse);
    /**
     * Create Material with the given ambient, diffuse and specular arrays.
     *
     * @param cAmbient ambient array
     * @param cDiffuse diffuse array
     * @param cSpecular specular array
     */
    Material(float* cAmbient, float* cDiffuse, float* cSpecular);
    /**
     * Create Material with the given ambient, diffuse, specular and emissive
     * arrays.
     *
     * @param cAmbient ambient array
     * @param cDiffuse diffuse array
     * @param cSpecular specular array
     * @param cEmissive emissive array
     */
    Material(float* cAmbient, float* cDiffuse, float* cSpecular, float* cEmissive);
    /**
     * Copy constructor.
     *
     * @param rhs Material to copy from.
     */
    Material(const Material& rhs);
    /**
     * Assignment operator.
     *
     * @param rhs Material to copy from
     * @return this
     */
    Material& operator=(const Material& rhs);
    /**
     * Destructor.
     */
    ~Material();

    /**
     * Set the values of this Material to those of the given Material.
     *
     * @param material Material to set values from
     */
    void setTo(const Material& material);
    /**
     * Set the shininess component of this Material.
     * 
     * @param shininess new shiniess
     */
    void setShininess(float shininess);
    /**
     * Get the shininess component of this Material.
     *
     * @return shininess
     */
    inline float getShininess();
    /**
     * Set the ambient component of this Material.
     *
     * @param rgbArray new ambient
     */
    void setAmbient(float* rgbArray);
    /**
     * Get the ambient component of this Material, without alpha.
     *
     * @return ambient component
     */
    inline float* getAmbient();
    /**
     * Get the ambient component of this Material, with the given alpha.
     *
     * @param alpha to add to the ambient component
     * @return ambient component
     */
    float* getAmbient(float alpha);
    /**
     * Set the diffuse component of this Material.
     *
     * @param rgbArray new diffuse
     */
    void setDiffuse(float* rgbArray);
    /**
     * Get the diffuse component of this Material, without alpha.
     *
     * @return diffuse component
     */
    inline float* getDiffuse();
    /**
     * Get the diffuse component of this Material, with the given alpha.
     *
     * @param alpha to add to the diffuse component
     * @return diffuse component
     */
    float* getDiffuse(float alpha);
    /**
     * Set the specular component of this Material.
     *
     * @param rgbArray new ambient
     */
    void setSpecular(float* rgbArray);
    /**
     * Get the specular component of this Material, without alpha.
     *
     * @return specular component
     */
    inline float* getSpecular();
    /**
     * Get the specular component of this Material, with the given alpha.
     *
     * @param alpha to add to the specular component
     * @return specular component
     */
    float* getSpecular(float alpha);
    /**
     * Set the emissive component of this Material.
     *
     * @param rgbArray new ambient
     */
    void setEmissive(float* rgbArray);
    /**
     * Get the emissive component of this Material, without alpha.
     *
     * @return emissive component
     */
    inline float* getEmissive();
    /**
     * Get the emissive component of this Material, with the given alpha.
     *
     * @param alpha to add to the emissive component
     * @return emissive component
     */
    float* getEmissive(float alpha);
    /**
     * Set this material to default values. As in static default arrays.
     */
    void toDefault();

private:

    float* ambientBuf; ///< Array to store ambient component with alpha
    float* diffuseBuf; ///< Array to store diffuse component with alpha
    float* specularBuf; ///< Array to store specular component with alpha
    float* emissiveBuf; ///< Array to store emissive component with alpha

    float shininess; ///< Shininess component
    float* ambient; ///< Ambient component
    float* diffuse; ///< Diffuse component
    float* specular; ///< Specular component
    float* emissive; ///< Emissive component

    /**
     * Set up static default arrays to default values.
     */
    void init();
};

//INLINE FUNCTION DEFINITIONS

inline float Material::getShininess() {

    return shininess;
}


inline float* Material::getAmbient() {

    return ambient;
}


inline float* Material::getDiffuse() {

    return diffuse;
}


inline float* Material::getSpecular() {

    return specular;
}


inline float* Material::getEmissive() {

    return emissive;
}

#endif	/* MATERIAL_H */

