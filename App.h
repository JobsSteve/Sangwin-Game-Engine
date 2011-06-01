#ifndef APP_H
#define	APP_H

#include "Alpha.h"
#include "Colour.h"
#include "LineAtt.h"
#include "PointAtt.h"
#include "PolyAtt.h"
#include "Texture.h"
#include "ArrayList.h"

/**
 * This is an abstract class which is instantiated using the App2 and App3
 * classes. The class holds appearence information for Nodes, and can be
 * used for both 2D and 3D objects.
 *
 * @see App2
 * @see App2
 *
 * @author Ben Constable, original Java code by Oli Winks
 * @version 1.0
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
     * Set the values of this App to those of another.
     *
     * @param app The App to set the values from
     */
    virtual void setTo(const App& app);
    /**
     * Set the visual information to default (i.e no information).
     */
    virtual void toDefault();
    /**
     * Get this App's PointAtt.
     *
     * @return This App's PointAtt
     */
    inline SPtr<PointAtt> getPointAtt();
    /**
     * Set this App's PointAtt to the given parameter.
     *
     * @param pointAtt PointAtt to set to
     */
    inline void setPointAtt(const SPtr<PointAtt>& pointAtt);
    /**
     * Get this App's LineAtt.
     *
     * @return This App's LineAtt
     */
    inline SPtr<LineAtt> getLineAtt();
    /**
     * Set this App's LineAtt to the given parameter.
     *
     * @param lineAtt LineAtt to set to
     */
    inline void setLineAtt(const SPtr<LineAtt>& lineAtt);
    /**
     * Get this App's PolyAtt.
     *
     * @return This App's PolyAtt
     */
    inline SPtr<PolyAtt> getPolyAtt();
    /**
     * Set this App's LineAtt to the given parameter.
     *
     * @param polyAtt PolyAtt to set to
     */
    inline void setPolyAtt(const SPtr<PolyAtt>& polyAtt);
    /**
     * Get this App's Colour.
     *
     * @return This App's Colour
     */
    inline SPtr<Colour> getColour();
    /**
     * Set this App's Colour to the given parameter.
     *
     * @param colourAtt Colour to set to
     */
    inline void setColour(const SPtr<Colour>& colouring);
    /**
     * Get this App's Alpha level.
     *
     * @return This App's Alpha level
     */
    inline SPtr<Alpha> getAlpha();
    /**
     * Set this App's Alpha to the given parameter.
     *
     * @param alpha A reference to the Alpha to set to
     */
    inline void setAlpha(const SPtr<Alpha>& alpha);
    /**
     * Add a texture to this App.
     *
     * @param texture texture to add
     */
    inline void addTexture(SPtr<Texture> texture);
    /**
     * Remove a texture from this App.
     *
     * @param texture texture to remove
     */
    inline void removeTexture(const SPtr<Texture>& texture);
    /**
     * Remove a texture from this App.
     *
     * @param i index of texture to remove
     * @return texture
     */
    inline SPtr<Texture> removeTexture(int i);
    /**
     * Get this App's textures.
     *
     * @return ArrayList of textures
     */
    inline ArrayList<SPtr<Texture> >& getTextures();
    /**
     * Get the texture at the given index from this App.
     * 
     * @param i index of texture to get
     * @return texture
     */
    SPtr<Texture> getTexture(int i);
    /**
     * Add the given App's visual information to this App.
     *
     * @param app App tp get visual information from
     */
    virtual void add(App& app) = 0;
    /**
     * Takes a number of bit visual component options to override. Options are
     * defined higher up in this header file. Overriding means that the App uses
     * its own visual state, rather than its parent's.
     * 
     * @param options list of options. Need to be 'or'd' e.g App::COLOUR || App::ALPHA ...
     */
    inline void override(int options);
    /**
     * Takes a number of bit visual component options to inherit. Options are
     * defined higher up in this header file. Inheriting means that the App uses
     * its parent's visual state, rather than its own. Apps inherit by default.
     *
     * @param options list of options. Need to be 'or'd' e.g App::COLOUR || App::ALPHA ...
     */
    inline void inherit(int options);

protected:

    SPtr<PointAtt> pointAtt; ///< The PointAtt for this App
    SPtr<LineAtt> lineAtt; ///< The LineAtt for this App
    SPtr<PolyAtt> polyAtt; ///< The PolyAtt for this App
    SPtr<Colour> colour; ///< The Colour of this App
    SPtr<Alpha> alpha; ///< The Alpha level of this App
    ArrayList<SPtr<Texture> >* textures; ///< List of textures held by this App
};

//INLINE FUNCTION DEFINITIONS

inline SPtr<PointAtt> App::getPointAtt() {

    return pointAtt;
}


inline void App::setPointAtt(const SPtr<PointAtt>& pointAtt) {

    this->pointAtt = pointAtt;
}


inline SPtr<LineAtt> App::getLineAtt() {

    return lineAtt;
}


inline void App::setLineAtt(const SPtr<LineAtt>& lineAtt) {

    this->lineAtt = lineAtt;
}


inline SPtr<PolyAtt> App::getPolyAtt() {

    return polyAtt;
}


inline void App::setPolyAtt(const SPtr<PolyAtt>& polyAtt) {

    this->polyAtt = polyAtt;
}


inline SPtr<Colour> App::getColour() {

    return colour;
}


inline void App::setColour(const SPtr<Colour>& colouring) {

    this->colour = colouring;
}


inline SPtr<Alpha> App::getAlpha() {

    return alpha;
}


inline void App::setAlpha(const SPtr<Alpha>& alpha) {

    this->alpha = alpha;
}


inline void App::addTexture(SPtr<Texture> texture) {

    textures->add(texture);
}


inline void App::removeTexture(const SPtr<Texture>& texture) {

    textures->remove(texture);
}


inline SPtr<Texture> App::removeTexture(int i) {

    return textures->remove(i);
}


inline ArrayList<SPtr<Texture> >& App::getTextures() {

    return *textures;
}


inline void App::override(int options) {

    inheritance = (inheritance | options);
}


inline void App::inherit(int options) {

    inheritance = inheritance & ~options;
}

#endif	/* APP_H */

