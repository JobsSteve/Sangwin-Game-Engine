#ifndef RESOURCEMANAGER_H
#define	RESOURCEMANAGER_H

#include "headers/utils/HashMap.h"
#include "headers/appearance/Texture.h"
#include "headers/scenegraph/Visual.h"

/**
 * The ResourceManager class handles all of the resources used throughout the
 * duration of a game. Resources include textures and models.
 *
 * ResourceManager is a singleton, and can be accessed by
 * ResourceManager\::instance()
 *
 * @author Ben Constable, original Java code by Oli Winks
 * @version 1.0
 *
 * @ingroup Resource
 */
class ResourceManager: public Object {

private:

    static ResourceManager* inst; ///< instance of this ResourceManager

    SPtr<HashMap<SPtr<Texture> > > textures; ///< map of textures
    SPtr<HashMap<SPtr<Visual> > > models; ///< map of models

    /**
     * Default constructor. Creates empty maps of textures and models.
     */
    ResourceManager();
    /**
     * Copying is not supported as this is a singleton.
     *
     * @param rhs
     */
    ResourceManager(const ResourceManager& rhs);
    /**
     * Copying is not supported as this is a singleton.
     * 
     * @param rhs
     * @return
     */
    ResourceManager& operator=(const ResourceManager& rhs);
    
public:

    /**
     * Destructor.
     */
    ~ResourceManager();

    static ResourceManager* instance(); ///< get the instance of this ResourceManager

    /**
     * Add a Texture to the ResourceManager. Retrievable by the given filename.
     *
     * Texture does not get added if the key already exists in the map.
     *
     * @param filename filename to associate this Texture with
     * @param tex Texture to add
     */
    void addTexture(const char* filename, SPtr<Texture>& tex);
    /**
     * Creates and adds a Texture to the ResourceManager. This function can be
     * used to make Texture loading easier.
     *
     * @param filename name of Texture
     * @param width array of widths for each image
     * @param height array of heights for each image
     * @param data 2D data array, each row is one image
     * @param numOfBitmaps number of bitmaps composing this Texture
     */
    void createTexture(const char* filename, int* width, int* height, void** data, int numOfBitmaps);
    /**
     * Retrieve the Texture with the given filename from the ResourceManager.
     *
     * If the Texture doesn't exist, a null pointer is returned.
     * 
     * @param filename filename of Texture to get
     * @return Texture
     */
    SPtr<Texture> getTexture(const char* filename);
    /**
     * Return all of the Textures in the ResourceManager in an ArrayList.
     *
     * <strong>NOTE: This list does not support element removal!</strong>
     *
     * @return Textures in an ArrayList
     */
    SPtr<ArrayList<SPtr<Texture> > > getTextures();
    /**
     * Add the given model to the ResourceManager. If a model with the given
     * filename already exists in the ResourceManager, this model is not
     * added.
     *
     * @param filename filename of model to add
     * @param mod Model to add
     */
    void addModel(const char* filename, SPtr<Visual> mod);
    /**
     * Retrieve a clone of the model with the given filename from the list.
     *
     * This means that visual and transformation data can be modified without
     * affecting other instances of the model.
     *
     * If a model with the given filename does not exist in the ResourceManager,
     * a null pointer is returned.
     *
     * @param filename filename of model to retrieve
     * @return Model clone
     */
    SPtr<Visual> getModel(const char* filename);
    /**
     * Return the actual model with the given filename, so that it's visual
     * and transformation data can be modified directly.
     *
     * If a model with the given filename does not exist in the ResourceManager,
     * a null pointer is returned.
     * 
     * @param filename filename of model to retrieve
     * @return Model
     */
    SPtr<Visual> getModelActual(const char* filename);
    /**
     * Return all of the models in the ResourceMananger in an ArrayList.
     *
     * <strong>NOTE: This list does not support element removal!</strong>
     *
     * @return Models in an ArrayList
     */
    SPtr<ArrayList<SPtr<Visual> > > getModels();
};

#endif	/* RESOURCEMANAGER_H */

