#ifndef TRIMESH_H
#define	TRIMESH_H

#include "headers/utils/Object.h"
#include "headers/utils/ArrayList.h"
#include "headers/maths/Vec2.h"
#include "headers/maths/Vec3.h"
#include "headers/scenegraph/TexCoord.h"

/**
 * The Trimesh class holds mesh data for 2D and 3D meshes. Meshes have vertex,
 * normal and texture information. The way in which each polygon is drawn can
 * also be set. Some primitive meshes can be created with static methods.
 *
 * Trimeshes are compatible with OpenGL.
 *
 * @see Geom
 *
 * @author Ben Constable, original Java code by Oli Winks
 * @version 1.0
 *
 * @ingroup Scenegraph
 */
class Trimesh: public Object {

public:

    /**
     * This Enum decides the method in which OpenGL draws polygons.
     */
    enum DrawMode {POINTS, LINES, LINE_STRIP, LINE_LOOP, TRIANGLES, TRIANGLE_STRIP, TRIANGLE_FAN};
    DrawMode drawMode; ///< Drawing method for this Trimesh

    /**
     * Default constructor. Sets arrays to size 1 and creates an empty list of
     * texture coordinates.
     */
    Trimesh();
    /**
     * Construct a Trimesh with the given vertices and DrawMode.
     *
     * @param cDrawMode DrawMode
     * @param vertexArray vertices to uses, in the form of a float array
     * @param length array length
     */
    Trimesh(DrawMode cDrawMode, float vertexArray[], int length);
    /**
     * Construct a Trimesh with the given vertices and DrawMode.
     *
     * @param cDrawMode DrawMode
     * @param vertexArray vertices to use, in the form of a vector array
     * @param length array length
     */
    Trimesh(DrawMode cDrawMode, Vec3 vertexArray[], int length);
    /**
     * Construct a Trimesh with the given vertices, normals and DrawMode.
     *
     * @param cDrawMode DrawMode
     * @param vertexArray vertices to use, in the form of a float array
     * @param normalArray normals to use, in the form of a float array
     * @param cVLength vertex array length
     * @param cNLength normal array length
     */
    Trimesh(DrawMode cDrawMode, float vertexArray[], float normalArray[], int cVLength, int cNLength);
    /**
     * Construct a Trimesh with the given vertices, normals and DrawMode.
     * 
     * @param cDrawMode DrawMode
     * @param vertexArray vertices to use, in the form of a vector array
     * @param normalArray normals to use, in the form of a vector array
     * @param cVLength vertex array length
     * @param cNLength normal array length
     */
    Trimesh(DrawMode cDrawMode, Vec3 vertexArray[], Vec3 normalArray[], int cVLength, int cNLength);
    /**
     * Copy constructor. TexCoord list is a SHALLOW copy.
     *
     * @param rhs Trimesh to copy from
     */
    Trimesh(const Trimesh& rhs);
    /**
     * Assignment operator. TexCoord list is a SHALLOW copy.
     *
     * @param rhs Trimesh to copy from
     *
     * @return this
     */
    Trimesh& operator=(const Trimesh& rhs);
    /**
     * Destructor.
     */
    ~Trimesh();

    /**
     * Create a Line Trimesh with the given points.
     * 
     * @param drawMode DrawMode
     * @param points points on the line
     * @param length lenght of array
     * @return Line Trimesh
     */
    static SPtr<Trimesh> Line(DrawMode drawMode, Vec3 points[], int length);
    /**
     * Create a Triangle Trimesh of the given width and height.
     *
     * @param width width of Triangle
     * @param height height of Triangle
     * @return Triangle Trimesh
     */
    static SPtr<Trimesh> Triangle(float width, float height);
    /**
     * Create a Quad Trimesh of the given width and height.
     *
     * @param width width of Quad
     * @param height height of Quad
     * @return Quad Trimesh
     */
    static SPtr<Trimesh> Quad(float width, float height);
    /**
     * Create an Ellipse Trimesh of the given width, height and number of edges.
     *
     * @param width width of Ellipse
     * @param height height of Ellipse
     * @param edges number of edges
     * @return Ellipse Trimesh
     */
    static SPtr<Trimesh> Ellipse(float width, float height, int edges);
    /**
     * Create a Cube Trimesh of the given dimension
     *
     * @param width dimensions
     * @return Cube Trimesh
     */
    static SPtr<Trimesh> Cube(float width);

    /**
     * Set this Trimesh to the given Trimesh. Clones all data.
     *
     * @param trimesh Trimesh to copy
     */
    void setTo(const Trimesh& trimesh);
    /**
     * Set the vertices of this Trimesh to those in the given float array.
     *
     * @param vertexArray vertices
     * @param length array length
     */
    void setVertices(float vertexArray[], int length);
    /**
     * Set the vertices of this Trimesh to those in the given vector array.
     *
     * @param vertexArray vertices
     * @param length array length
     */
    void setVertices(Vec3 vertexArray[], int length);
    /**
     * Return this Trimesh's vertices.
     *
     * @return vertices
     */
    inline float* getVertices();
    /**
     * Set the normals of this Trimesh to those in the given float array.
     *
     * @param normalArray normals
     * @param length array length
     */
    void setNormals(float normalArray[], int length);
    /**
     * Set the normals of this Trimesh to those in the given vector array.
     *
     * @param normalArray normals
     * @param length array length
     */
    void setNormals(Vec3 normalArray[], int length);
    /**
     * Return this Trimesh's normals.
     *
     * @return normals
     */
    inline float* getNormals();
    /**
     * Set the tex coords at the given index to the those given.
     *
     * @param i index
     * @param texCoord new tex coords
     */
    inline void setTexCoords(int i, TexCoord& texCoord);
    /**
     * Add the given set of tex coords to the list.
     *
     * @param texCoord tex coords to add
     */
    inline void addTexCoords(SPtr<TexCoord>& texCoord);
    /**
     * Remove the tex coords at the given index from the list.
     *
     * @param i index
     * @return removed tex coords
     */
    inline SPtr<TexCoord> removeTexCoords(int i);
    /**
     * Get this Trimesh's list of tex coords
     *
     * @return tex coords list
     */
    inline ArrayList<SPtr<TexCoord> >& getTexCoords();
    /**
     * Get the tex coords at the given index from the tex coord list.
     *
     * @param i index
     * @return tex coords
     */
    inline SPtr<TexCoord> getTexCoords(int i);
    /**
     * Get the number of vertices held by this Trimesh.
     *
     * @return number of vertices
     */
    inline int getVertexCount();
    /**
     * Get the number of vertices*3 held by this Trimesh (num of individual x y
     * z points).
     *
     * @return number of vertices*3
     */
    inline int getVLength();
    /**
     * Get the number of normals*3 held by this Trimesh (num of individual x y
     * z points).
     *
     * @return number of normals*3
     */
    inline int getNLength();
    


private:

    float* vertices; ///< This Trimesh's vertices
    int vLength; ///< Number of vertices x 3
    float* normals; ///< This Trimesh's normals
    int nLength; ///< Number of normals x 3
    ArrayList<SPtr<TexCoord> >* texCoords; ///< List of tex coords held by this Trimesh
};

//INLINE FUNCTION DEFINITIONS

inline float* Trimesh::getVertices() {

    return vertices;
}


inline float* Trimesh::getNormals() {

    return normals;
}


inline ArrayList<SPtr<TexCoord> >& Trimesh::getTexCoords() {

    return *texCoords;
}


inline SPtr<TexCoord> Trimesh::getTexCoords(int i) {

    return texCoords->get(i);
}


inline int Trimesh::getVertexCount() {

    return vLength/3;
}


inline void Trimesh::setTexCoords(int i, TexCoord& texCoord) {

    *texCoords->get(i) = texCoord;
}


inline void Trimesh::addTexCoords(SPtr<TexCoord>& texCoord) {

    texCoords->add(texCoord);
}


inline SPtr<TexCoord> Trimesh::removeTexCoords(int i) {

    return texCoords->remove(i);
}


inline int Trimesh::getVLength() {

    return vLength;
}


inline int Trimesh::getNLength() {

    return nLength;
}

#endif	/* TRIMESH_H */

