#ifndef APP_H
#define	APP_H

#include "headers/appearance/Alpha.h"
#include "headers/appearance/Colour.h"
#include "headers/appearance/LineAtt.h"
#include "headers/appearance/PointAtt.h"
#include "headers/appearance/PolyAtt.h"
#include "headers/appearance/Texture.h"
#include "headers/appearance/Material.h"
#include "headers/lights/Light.h"
#include "headers/utils/ArrayList.h"

/**
 * This class holds appearance information for game objects. It encompasses all
 * individual appearance components into a single, highly configurable 
 * interface.
 *
 * @author Ben Constable, original Java code by Oli Winks
 * @version 1.1
 *
 * @ingroup Scenegraph
 */
class App: public Object {

public:

    static const int POINT_ATT = 1; ///< Bitwise value for PointAtt
    static const int LINE_ATT = 2; ///< Bitwise value for LineAtt;
    static const int POLY_ATT = 4; ///< Bitwise value for PolyAtt;
    static const int COLOUR = 8; ///< Bitwise value for Colour;
    static const int ALPHA = 16; ///< Bitwise value for Alpha;
    static const int MATERIAL = 32; ///< Bitwise value for Material;
    static const int LIGHTING = 64; ///< Bitwise value for Lighting;

    /**
     * Lighting policy.
     */
    enum LightingPolicy {GLOBAL_FIRST, LOCAL_FIRST};
    int inheritance; ///< Bitmask the defines what visual components should be inherited by child nodes of this App

    /**
     * Default constructor. Initialises all appearance information to default,
     * and inheritance to true for all components.
     */
    App();
    /**
     * Copy constructor. Creates a SHALLOW copy of all appearance information.
     *
     * @param rhs App to copy from
     */
    App(const App& rhs);
    /**
     * Assignment operator. Creates a SHALLOW copy of all appearance
     * information.
     *
     * @param rhs App to copy from
     * @return this
     */
    App& operator=(const App& rhs);
    /**
     * Destructor.
     */
    ~App();
    
    
    /**
     * Set the values of this App to those of another.
     *
     * @param app The App to set the values from
     */
    void setTo(const App& app);
    /**
     * Set the visual information to default (i.e no information).
     */
    void toDefault();
    /**
     * Get this App's PointAtt.
     *
     * @return This App's PointAtt
     */
    SPtr<PointAtt> getPointAtt();
    /**
     * Set this App's PointAtt to the given parameter.
     *
     * @param pointAtt PointAtt to set to
     */
    void setPointAtt(const SPtr<PointAtt>& pointAtt);
    /**
     * Get this App's LineAtt.
     *
     * @return This App's LineAtt
     */
    SPtr<LineAtt> getLineAtt();
    /**
     * Set this App's LineAtt to the given parameter.
     *
     * @param lineAtt LineAtt to set to
     */
    void setLineAtt(const SPtr<LineAtt>& lineAtt);
    /**
     * Get this App's PolyAtt.
     *
     * @return This App's PolyAtt
     */
    SPtr<PolyAtt> getPolyAtt();
    /**
     * Set this App's LineAtt to the given parameter.
     *
     * @param polyAtt PolyAtt to set to
     */
    void setPolyAtt(const SPtr<PolyAtt>& polyAtt);
    /**
     * Get this App's Colour.
     *
     * @return This App's Colour
     */
    SPtr<Colour> getColour();
    /**
     * Set this App's Colour to the given parameter.
     *
     * @param colourAtt Colour to set to
     */
    void setColour(const SPtr<Colour>& colouring);
    /**
     * Get this App's Alpha level.
     *
     * @return This App's Alpha level
     */
    SPtr<Alpha> getAlpha();
    /**
     * Set this App's Alpha to the given parameter.
     *
     * @param alpha A reference to the Alpha to set to
     */
    void setAlpha(const SPtr<Alpha>& alpha);
    /**
     * Add a texture to this App.
     *
     * @param texture texture to add
     */
    void addTexture(SPtr<Texture> texture);
    /**
     * Remove a texture from this App.
     *
     * @param texture texture to remove
     */
    void removeTexture(const SPtr<Texture>& texture);
    /**
     * Remove a texture from this App.
     *
     * @param i index of texture to remove
     * @return texture
     */
    SPtr<Texture> removeTexture(int i);
    /**
     * Get this App's textures.
     *
     * @return ArrayList of textures
     */
    ArrayList<SPtr<Texture> >& getTextures();
    /**
     * Get the texture at the given index from this App.
     * 
     * @param i index of texture to get
     * @return texture
     */
    SPtr<Texture> getTexture(int i);
    /**
     * Return this App's Material.
     *
     * @return material
     */
    SPtr<Material> getMaterial();
    /**
     * Set this App's material.
     *
     * @param material new material
     */
    void setMaterial(const SPtr<Material>& material);
    /**
     * Get this App's lighting policy.
     *
     * @return the lighting policy
     */
    LightingPolicy getLightingPolicy();
    /**
     * Add the given Light to this App's light list.
     * 
     * @param light light to add
     */
    void addLight(SPtr<Light> light);
    /**
     * Remove the given Light from this App's light list
     * 
     * @param light light to remove
     */
    void removeLight(const SPtr<Light>& light);
    /**
     * Remove the light at the given index from this App's light list.
     *
     * @param i index of the light to remove
     * @return removed light
     */
    SPtr<Light> removeLight(int i);
    /**
     * Get the list of Lights from this App.
     *
     * @return light list
     */
    ArrayList<SPtr<Light> >& getLights();
    /**
     * Add the given App's visual information to this App.
     *
     * @param app App tp get visual information from
     */
    void add(App& app);
    /**
     * Takes a number of bit visual component options to override. Options are
     * defined higher up in this header file. Overriding means that the App uses
     * its own visual state, rather than its parent's.
     * 
     * @param options list of options. Need to be 'or'd' e.g App::COLOUR || App::ALPHA ...
     */
    void override(int options);
    /**
     * Takes a number of bit visual component options to inherit. Options are
     * defined higher up in this header file. Inheriting means that the App uses
     * its parent's visual state, rather than its own. Apps inherit by default.
     *
     * @param options list of options. Need to be 'or'd' e.g App::COLOUR || App::ALPHA ...
     */
    void inherit(int options);

protected:

    SPtr<PointAtt> pointAtt; ///< The PointAtt for this App
    SPtr<LineAtt> lineAtt; ///< The LineAtt for this App
    SPtr<PolyAtt> polyAtt; ///< The PolyAtt for this App
    SPtr<Colour> colour; ///< The Colour of this App
    SPtr<Alpha> alpha; ///< The Alpha level of this App
    ArrayList<SPtr<Texture> >* textures; ///< List of textures held by this App
    
    SPtr<Material> material; ///< This App's Material
    LightingPolicy lightingPolicy; ///< whether this App should use global or local lighting first
    ArrayList<SPtr<Light> >* lights; ///< lights
};


#endif	/* APP_H */

