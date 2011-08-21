#ifndef OBJLOADER_H
#define	OBJLOADER_H

#include "headers/utils/GetNode.h"
#include "headers/utils/HashMap.h"
#include "headers/resource/OBJLexicalAnalyser.h"
#include "headers/resource/ResourceManager.h"

/**
 * The OBJLoader takes an .OBJ or .MTL file as input, and builds physical
 * geometry from the data.
 *
 * The OBJLoader makes some assumptions about how files should be loaded, so
 * that the resultant geometry is build correctly. First, all textures should
 * be loaded into the ResourceManager so they can be accessed by the OBJLoader.
 * Secondly, all .MTL files must be loaded prior to the .OBJ file so that the
 * material data can be used by the geometry.
 *
 * The above would not be neccessary in engines using solely native code, but as
 * this engine is intended to be used with Java, the class must take this format
 * to avoid having to make C++ to Java JNI calls.
 *
 * The class could easily be modified to include .MTL and texture loading
 * automatically.
 *
 * .OBJ files should be triangulated and be set to Group format in order to be
 * loaded correctly.
 * 
 * After an .OBJ has been fully loaded, reset() should be called before loading
 * the next file.
 *
 * OBJLoader is a Singleton, and can be accessed via OBJLoader\::instance()
 *
 * @see OBJLexicalAnalyser
 * @see Token
 * 
 * @author Ben Constable, original Java code by Oli Winks
 * @version 1.0
 *
 * @ingroup Resource
 */
class OBJLoader: public Object {

private:

    /**
     * Basic wrapper to allow STRING LITERALS to be managed by SPtrs.
     *
     * @author Ben Constable
     * @version 1.0
     *
     * @ingroup Resource
     */
    class OBJString: public Object {

    public:
        
        const char* str; ///< actual string

        /**
         * Default constructor. Takes an input string to wrap.
         * 
         * @param cStr
         */
        OBJString(const char* cStr)
        :str(cStr)
        {}

        /**
         * Copy constructor. Makes a SHALLOW copy of the string.
         *
         * @param rhs OBJString to copy from
         */
        OBJString(const OBJString& rhs)
        :str(rhs.str)
        {}

        /**
         * Assignment operator. Makes a SHALLOW copy of the string.
         *
         * @param rhs OBJString to copy from
         * @return this
         */
        OBJString& operator=(const OBJString& rhs) {

            str = rhs.str;
            return *this;
        }

        /**
         * Destructor.
         */
        ~OBJString() {}
    };

    /**
     * A Material class which is in the OBJ MTL format.
     *
     * @author Ben Constable, original Java code by Oli Winks
     * @version 1.0
     *
     * @ingroup Resource
     */
    class OBJMaterial: public Object {

    public:
        float shininess; ///< Shininess value
        float ambient[3]; ///< Ambient colour
        float diffuse[3]; ///< Diffuse colour
        float specular[3]; ///< Specular colour
        float alpha; ///< Alpha level
        SPtr<ArrayList<SPtr<OBJString> > > textures; ///< Texture list

        /**
         * Default constructor. No material and empty list of textures.
         */
        OBJMaterial()
        :textures(new ArrayList<SPtr<OBJString> >())
        {}

        /**
         * Destructor.
         */
        ~OBJMaterial(){}
    };

    /**
     * Small OBJFace class, created from .OBJ Face data. Includes indices for
     * vertices, normals and texture coordinates.
     *
     * @author Ben Constable, original Java code by Oli Winks
     * @version 1.0
     *
     * @ingroup Resource
     */
    class OBJFace: public Object {

    public:

        int vertexIndices[3]; ///< Vertex indices
        int normalIndices[3]; ///< Normal indices
        int texCoordIndices[3]; ///< Tex coord indices

        /**
         * Default constructor.
         */
        OBJFace(){}
        /**
         * Destructor.
         */
        ~OBJFace(){}
    };

    /**
     * The OBJGroup class works on the OBJ grouping principal, with each group
     * representing one section of the model.
     *
     * It takes a set of faces and a material and converts them into a Visual
     * Node compatible with this engine.
     *
     * @author Ben Constable, original Java code by Oli Winks
     * @version 1.0
     *
     * @ingroup Resource
     */
    class OBJGroup: public Object {

    public:

        char* name; ///< name of this Node
        int numOfFaces; ///< number of faces in the model
        SPtr<ArrayList<SPtr<OBJFace> > > faces; ///< faces to build the Visual Node from
        SPtr<OBJMaterial> mtl; ///< Material for this Visual Node

        /**
         * Default constructor. Creates an empty list of faces and no material.
         */
        OBJGroup()
        :numOfFaces(0),
         faces(new ArrayList<SPtr<OBJFace> >()),
         mtl(0)
        {}

        /**
         * Destructor.
         */
        ~OBJGroup(){}

        /**
         * Convert the list of faces and material stored in this class into a
         * Visual Node that can be used within the engine.
         *
         * @return Visual Node
         */
        SPtr<Visual<Vec3,Trfm3,App3> > convert() {
            //Create the geometry
            int tempSize = numOfFaces*3;
            Vec3 vertexArray[tempSize];
            Vec3 normalArray[tempSize];
            Vec2 texCoordArray[tempSize];
            for(int f=0; f<numOfFaces; f++) {
                SPtr<OBJFace> face(faces->get(f));

                for(int i=0; i<3; i++) {
                    vertexArray[(f*3)+i] = *vertices.get(face->vertexIndices[i]-1);

                    if(hasTexCoords) {
                        texCoordArray[(f*3)+i] = *texCoords.get(face->texCoordIndices[i]-1);
                    }
                    if(hasNormals) {
                        normalArray[(f*3)+i] = *normals.get(face->normalIndices[i]-1);
                    }
                }
            }
            
            SPtr<Geom<Vec3,Trfm3,App3> > model;
            if(hasTexCoords && hasNormals) {
                SPtr<Trimesh> t(new Trimesh(Trimesh::TRIANGLES,vertexArray,normalArray,tempSize,tempSize));
                SPtr<TexCoord> tc(new TexCoord(tempSize*2));
                for(int j=0; j<tempSize;j++) {
                    tc->addCoord(texCoordArray[j]);
                }
                t->addTexCoords(tc);
                model = GetNode::newGeom3D(name,t);
            }
            else if(hasNormals) {
                SPtr<Trimesh> t(new Trimesh(Trimesh::TRIANGLES,vertexArray,normalArray,tempSize,tempSize));
                model = GetNode::newGeom3D(name,t);
            }
            else {
                SPtr<Trimesh> t(new Trimesh(Trimesh::TRIANGLES,vertexArray,tempSize));
                model = GetNode::newGeom3D(name,t);
            }

            //Create the material
            if(mtl.get()) {
                model->getLocalAppearance().override(App::MATERIAL);
                
                SPtr<Material> newMat(new Material());
                newMat->setShininess(mtl->shininess);
                newMat->setAmbient(mtl->ambient);
                newMat->setDiffuse(mtl->diffuse);
                newMat->setSpecular(mtl->specular);

                model->getLocalAppearance().setMaterial(newMat);
                if(mtl->alpha < 1) {
                    model->getLocalAppearance().override(App::ALPHA);

                    SPtr<Alpha> tran(new Alpha(mtl->alpha));
                    model->getLocalAppearance().setAlpha(tran);
                }

                for(int i=0; i<mtl->textures->size(); i++) {
                    model->getLocalAppearance().addTexture(ResourceManager::instance()->getTexture(mtl->textures->get(i)->str));
                }
            }

            return model;
        }
    };

    static OBJLoader* inst; ///< instance of this OBJLoader

    //Non-static variables
    int numOfGroups; ///< num of groups for the current model
    SPtr<OBJGroup> currGroup; ///< current group being built
    ArrayList<SPtr<OBJGroup> > groups; ///< list of all groups
    SPtr<HashMap<SPtr<OBJMaterial> > > materials; ///< map of materials
    OBJLexicalAnalyser* la; ///< the lexical analyser to use with this loader

    //These are static so that they can be reached by the nested classes.
    static bool hasNormals; ///< whether or not the current group has normals
    static bool hasTexCoords; ///< whether or not the current group has tex coords
    static ArrayList<SPtr<Vec3> > vertices; ///< current group's vertices
    static ArrayList<SPtr<Vec3> > normals; ///< current group's normals
    static ArrayList<SPtr<Vec2> > texCoords; ///< current group's tex coords

    /**
     * Default constructor. Creates empty lists of groups and materials.
     */
    OBJLoader();
    
    /**
     * Copy not supported as this is a singleton.
     *
     * @param rhs
     */
    OBJLoader(const OBJLoader& rhs);
    /**
     * Copying not supported as this is a singleton.
     * 
     * @param rhs
     * @return
     */
    OBJLoader& operator=(const OBJLoader& rhs);
   
public:

    /**
     * Destructor.
     */
    ~OBJLoader();
    /**
     * Return the instance of this OBJLoader, and create one if it does not yet
     * exist.
     *
     * @return instance of this OBJLoader
     */
    static OBJLoader* instance();

    /**
     * Reset the OBJLoader to its start state, ready to load a new model.
     */
    void reset();

    /**
     * Load in a model from the given file data. Loaded model is stored directly
     * in the ResourceManager.
     * 
     * @param data Data to load model from
     * @param filesize Size of the data array
     * @param filename Filename, used as the name for the model
     */
    void loadModel(char* data, int filesize, const char* filename);
    /**
     * Create a new OBJMaterial from the given file data.
     *
     * @param data Data to load OBJMaterial from
     * @param filesize Size of the data array
     */
    void loadMTL(char* data, int filesize);
};

#endif

