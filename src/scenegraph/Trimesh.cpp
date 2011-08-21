#include "headers/scenegraph/Trimesh.h"

Trimesh::Trimesh()
:vertices(new float[1]),
 vLength(1),
 normals(new float[1]),
 nLength(1),
 texCoords(new ArrayList<SPtr<TexCoord> >())
{}


Trimesh::Trimesh(DrawMode cDrawMode, float vertexArray[], int length)
:drawMode(cDrawMode),
 vertices(new float[length]),
 vLength(length),
 normals(new float[1]),
 nLength(1),
 texCoords(new ArrayList<SPtr<TexCoord> >())
{
    for(int i=0; i < length; i++) {
        vertices[i] = vertexArray[i];
    }
}


Trimesh::Trimesh(DrawMode cDrawMode, Vec3 vertexArray[], int length)
:drawMode(cDrawMode),
 vertices(new float[length*3]),
 vLength(length*3),
 normals(new float[1]),
 nLength(1),
 texCoords(new ArrayList<SPtr<TexCoord> >())
{
    int j = 0;
    for(int i=0; i < length*3; i=i+3) {
        vertices[i] = vertexArray[j].v[0];
        vertices[i+1] = vertexArray[j].v[1];
        vertices[i+2] = vertexArray[j].v[2];
        j++;
    }
}


Trimesh::Trimesh(DrawMode cDrawMode, float vertexArray[], float normalArray[], int cVLength, int cNLength)
:drawMode(cDrawMode),
 vertices(new float[cVLength]),
 vLength(cVLength),
 normals(new float[cNLength]),
 nLength(cNLength),
 texCoords(new ArrayList<SPtr<TexCoord> >())
{
    for(int i=0; i < cVLength; i++) {
        vertices[i] = vertexArray[i];
    }
    
    for(int i=0; i < cNLength; i++) {
        normals[i] = normalArray[i];
    }
}


Trimesh::Trimesh(DrawMode cDrawMode, Vec3 vertexArray[], Vec3 normalArray[], int cVLength, int cNLength)
:drawMode(cDrawMode),
 vertices(new float[cVLength*3]),
 vLength(cVLength*3),
 normals(new float[cNLength*3]),
 nLength(cVLength*3),
 texCoords(new ArrayList<SPtr<TexCoord> >())
{
    int j = 0;
    for(int i=0; i < cVLength*3; i=i+3) {
        vertices[i] = vertexArray[j].v[0];
        vertices[i+1] = vertexArray[j].v[1];
        vertices[i+2] = vertexArray[j].v[2];
        j++;
    }

    j = 0;
    for(int i=0; i < cNLength*3; i=i+3) {
        normals[i] = normalArray[j].v[0];
        normals[i+1] = normalArray[j].v[1];
        normals[i+2] = normalArray[j].v[2];
        j++;
    }
}


Trimesh::Trimesh(const Trimesh& rhs)
:drawMode(rhs.drawMode),
 vertices(new float[rhs.vLength]),
 vLength(rhs.vLength),
 normals(new float[rhs.nLength]),
 nLength(rhs.nLength),
 texCoords(new ArrayList<SPtr<TexCoord> >(*rhs.texCoords))
{
    for(int i=0; i < rhs.vLength; i++) {
        vertices[i] = rhs.vertices[i];
    }

    for(int i=0; i < rhs.nLength; i++) {
        normals[i] = rhs.normals[i];
    }
}


Trimesh& Trimesh::operator =(const Trimesh& rhs) {

    drawMode = rhs.drawMode;
    float* verticesOrig = vertices;
    vertices = new float[rhs.vLength];
    for(int i=0; i < rhs.vLength; i++) {
        vertices[i] = rhs.vertices[i];
    }
    vLength = rhs.vLength;
    delete [] verticesOrig;
    float* normalsOrig = normals;
    normals = new float[rhs.nLength];
    for(int i=0; i < rhs.nLength; i++) {
        normals[i] = rhs.normals[i];
    }
    nLength = rhs.nLength;
    delete [] normalsOrig;
    *texCoords = *rhs.texCoords;

    return *this;
}


Trimesh::~Trimesh() {

    delete [] vertices;
    delete [] normals;
    delete texCoords;
}


SPtr<Trimesh> Trimesh::Line(DrawMode drawMode, Vec3 points[], int length) {

    return SPtr<Trimesh>(new Trimesh(drawMode, points, length));
}


SPtr<Trimesh> Trimesh::Triangle(float width, float height) {

    float halfWidth = width/2;
    float halfHeight = height/2;

    Vec3 vertexArray[3];
    vertexArray[0] = Vec3( 0,            1*halfHeight, 0);
    vertexArray[1] = Vec3(-1*halfWidth, -1*halfHeight, 0);
    vertexArray[2] = Vec3( 1*halfWidth, -1*halfHeight, 0);

    Vec3 normalArray[3];
    normalArray[0] = Vec3(0,0,1);
    normalArray[1] = Vec3(0,0,1);
    normalArray[2] = Vec3(0,0,1);
    
    SPtr<TexCoord> texCoord(new TexCoord(6));
    texCoord->addCoord(Vec2(0.5f, 1.0f));
    texCoord->addCoord(Vec2(0.0f, 0.0f));
    texCoord->addCoord(Vec2(1.0f, 0.0f));
    
    SPtr<Trimesh> tri(new Trimesh(TRIANGLES, vertexArray, normalArray, 3, 3));
    tri->addTexCoords(texCoord);

    return tri;
}


SPtr<Trimesh> Trimesh::Quad(float width, float height) {

    float halfWidth = width/2;
    float halfHeight = height/2;

    Vec3 vertexArray[4];
    vertexArray[0] = Vec3( halfWidth,  halfHeight, 0);
    vertexArray[1] = Vec3(-halfWidth,  halfHeight, 0);
    vertexArray[2] = Vec3( halfWidth, -halfHeight, 0);
    vertexArray[3] = Vec3(-halfWidth, -halfHeight, 0);

    Vec3 normalArray[4];
    normalArray[0] = Vec3(0,0,1);
    normalArray[1] = Vec3(0,0,1);
    normalArray[2] = Vec3(0,0,1);
    normalArray[3] = Vec3(0,0,1);
    
    SPtr<TexCoord> texCoord(new TexCoord(8));
    texCoord->addCoord(Vec2(1.0f, 1.0f));
    texCoord->addCoord(Vec2(0.0f, 1.0f));
    texCoord->addCoord(Vec2(1.0f, 0.0f));
    texCoord->addCoord(Vec2(0.0f, 0.0f));

    SPtr<Trimesh> quad(new Trimesh(TRIANGLE_STRIP, vertexArray, normalArray, 4, 4));
    quad->addTexCoords(texCoord);
    
    return quad;
}


SPtr<Trimesh> Trimesh::Ellipse(float width, float height, int edges) {

    float radw = width/2;
    float radh = height/2;

    if(edges > 2) {
        int vertices = edges + 2;
        Vec3 vertexArray[vertices];
        SPtr<TexCoord> texCoord(new TexCoord(vertices*2));

        // add central vertex
        vertexArray[0] = Vec3(0, 0, 0);
        texCoord->addCoord(Vec2(0.5, 0.5));

        int count = 1;
        float angle = 0;
        for(float i=0; i<vertices-1; i++) {
            angle += 360.0/edges;
            float x = radw*cos(angle*0.0174532925);
            float y = radh*sin(angle*0.0174532925);

            vertexArray[count] = Vec3(x, y, 0);
            texCoord->addCoord(Vec2( (x + radw)/width, (y + radh)/height ));
            count++;
        }

        SPtr<Trimesh> ellipse(new Trimesh(TRIANGLE_FAN, vertexArray, vertices));
        ellipse->addTexCoords(texCoord);
        return ellipse;
    }
    return SPtr<Trimesh>();
}


SPtr<Trimesh> Trimesh::Cube(float width) {

    float halfWidth = width/2;

    Vec3 vertexArray[36];
    Vec3 normalArray[36];
    SPtr<TexCoord> texCoordArray(new TexCoord(72));

    //front
    vertexArray[0] = Vec3( halfWidth,  halfWidth, halfWidth);//0
    vertexArray[1] = Vec3(-halfWidth,  halfWidth, halfWidth);//1
    vertexArray[2] = Vec3( halfWidth, -halfWidth, halfWidth);//2
    vertexArray[3] = Vec3(-halfWidth,  halfWidth, halfWidth);//1
    vertexArray[4] = Vec3(-halfWidth, -halfWidth, halfWidth);//3
    vertexArray[5] = Vec3( halfWidth, -halfWidth, halfWidth);//2
    normalArray[0] = Vec3(0,0,1);
    normalArray[1] = Vec3(0,0,1);
    normalArray[2] = Vec3(0,0,1);
    normalArray[3] = Vec3(0,0,1);
    normalArray[4] = Vec3(0,0,1);
    normalArray[5] = Vec3(0,0,1);
    texCoordArray->addCoord(Vec2(1,1));
    texCoordArray->addCoord(Vec2(0,1));
    texCoordArray->addCoord(Vec2(1,0));
    texCoordArray->addCoord(Vec2(0,1));
    texCoordArray->addCoord(Vec2(0,0));
    texCoordArray->addCoord(Vec2(1,0));
    //back
    vertexArray[6] = Vec3(-halfWidth,  halfWidth, -halfWidth);//1
    vertexArray[7] = Vec3( halfWidth,  halfWidth, -halfWidth);//0
    vertexArray[8] = Vec3(-halfWidth, -halfWidth, -halfWidth);//3
    vertexArray[9] = Vec3( halfWidth,  halfWidth, -halfWidth);//0
    vertexArray[10] = Vec3( halfWidth, -halfWidth, -halfWidth);//2
    vertexArray[11] = Vec3(-halfWidth, -halfWidth, -halfWidth);//3
    normalArray[6] = Vec3(0,0,-1);
    normalArray[7] = Vec3(0,0,-1);
    normalArray[8] = Vec3(0,0,-1);
    normalArray[9] = Vec3(0,0,-1);
    normalArray[10] = Vec3(0,0,-1);
    normalArray[11] = Vec3(0,0,-1);
    texCoordArray->addCoord(Vec2(1,1));
    texCoordArray->addCoord(Vec2(0,1));
    texCoordArray->addCoord(Vec2(1,0));
    texCoordArray->addCoord(Vec2(0,1));
    texCoordArray->addCoord(Vec2(0,0));
    texCoordArray->addCoord(Vec2(1,0));
    //right
    vertexArray[12] = Vec3( halfWidth,  halfWidth, -halfWidth);//0
    vertexArray[13] = Vec3( halfWidth,  halfWidth, halfWidth);//1
    vertexArray[14] = Vec3( halfWidth, -halfWidth, -halfWidth);//2
    vertexArray[15] = Vec3( halfWidth,  halfWidth, halfWidth);//1
    vertexArray[16] = Vec3( halfWidth, -halfWidth, halfWidth);//3
    vertexArray[17] = Vec3( halfWidth, -halfWidth, -halfWidth);//2
    normalArray[12] = Vec3(1,0,0);
    normalArray[13] = Vec3(1,0,0);
    normalArray[14] = Vec3(1,0,0);
    normalArray[15] = Vec3(1,0,0);
    normalArray[16] = Vec3(1,0,0);
    normalArray[17] = Vec3(1,0,0);
    texCoordArray->addCoord(Vec2(1,1));
    texCoordArray->addCoord(Vec2(0,1));
    texCoordArray->addCoord(Vec2(1,0));
    texCoordArray->addCoord(Vec2(0,1));
    texCoordArray->addCoord(Vec2(0,0));
    texCoordArray->addCoord(Vec2(1,0));
    //left
    vertexArray[18] = Vec3( -halfWidth,  halfWidth, halfWidth);//1
    vertexArray[19] = Vec3( -halfWidth,  halfWidth, -halfWidth);//0
    vertexArray[20] = Vec3( -halfWidth, -halfWidth, halfWidth);//3
    vertexArray[21] = Vec3( -halfWidth,  halfWidth, -halfWidth);//0
    vertexArray[22] = Vec3( -halfWidth, -halfWidth, -halfWidth);//2
    vertexArray[23] = Vec3( -halfWidth, -halfWidth, halfWidth);//3
    normalArray[18] = Vec3(-1,0,0);
    normalArray[19] = Vec3(-1,0,0);
    normalArray[20] = Vec3(-1,0,0);
    normalArray[21] = Vec3(-1,0,0);
    normalArray[22] = Vec3(-1,0,0);
    normalArray[23] = Vec3(-1,0,0);
    texCoordArray->addCoord(Vec2(1,1));
    texCoordArray->addCoord(Vec2(0,1));
    texCoordArray->addCoord(Vec2(1,0));
    texCoordArray->addCoord(Vec2(0,1));
    texCoordArray->addCoord(Vec2(0,0));
    texCoordArray->addCoord(Vec2(1,0));
    //top
    vertexArray[24] = Vec3( halfWidth,  halfWidth, -halfWidth);//0
    vertexArray[25] = Vec3(-halfWidth,  halfWidth, -halfWidth);//1
    vertexArray[26] = Vec3( halfWidth,  halfWidth,  halfWidth);//2
    vertexArray[27] = Vec3(-halfWidth,  halfWidth, -halfWidth);//1
    vertexArray[28] = Vec3(-halfWidth,  halfWidth,  halfWidth);//3
    vertexArray[29] = Vec3( halfWidth,  halfWidth,  halfWidth);//2
    normalArray[24] = Vec3(0,1,0);
    normalArray[25] = Vec3(0,1,0);
    normalArray[26] = Vec3(0,1,0);
    normalArray[27] = Vec3(0,1,0);
    normalArray[28] = Vec3(0,1,0);
    normalArray[29] = Vec3(0,1,0);
    texCoordArray->addCoord(Vec2(1,1));
    texCoordArray->addCoord(Vec2(0,1));
    texCoordArray->addCoord(Vec2(1,0));
    texCoordArray->addCoord(Vec2(0,1));
    texCoordArray->addCoord(Vec2(0,0));
    texCoordArray->addCoord(Vec2(1,0));
    //bottom
    vertexArray[30] = Vec3(-halfWidth,  -halfWidth, -halfWidth);//1
    vertexArray[31] = Vec3( halfWidth,  -halfWidth, -halfWidth);//0
    vertexArray[32] = Vec3(-halfWidth,  -halfWidth,  halfWidth);//3
    vertexArray[33] = Vec3( halfWidth,  -halfWidth, -halfWidth);//0
    vertexArray[34] = Vec3( halfWidth,  -halfWidth,  halfWidth);//2
    vertexArray[35] = Vec3(-halfWidth,  -halfWidth,  halfWidth);//3
    normalArray[30] = Vec3(0,-1,0);
    normalArray[31] = Vec3(0,-1,0);
    normalArray[32] = Vec3(0,-1,0);
    normalArray[33] = Vec3(0,-1,0);
    normalArray[34] = Vec3(0,-1,0);
    normalArray[35] = Vec3(0,-1,0);
    texCoordArray->addCoord(Vec2(1,1));
    texCoordArray->addCoord(Vec2(0,1));
    texCoordArray->addCoord(Vec2(1,0));
    texCoordArray->addCoord(Vec2(0,1));
    texCoordArray->addCoord(Vec2(0,0));
    texCoordArray->addCoord(Vec2(1,0));


    SPtr<Trimesh> cube(new Trimesh(TRIANGLES, vertexArray, normalArray,36,36));
    cube->addTexCoords(texCoordArray);

    return cube;
}


void Trimesh::setTo(const Trimesh& trimesh) {

    drawMode = trimesh.drawMode;

    delete [] vertices;

    vertices = new float[trimesh.vLength];
    for(int i=0; i < trimesh.vLength; i++) {
        vertices[i] = trimesh.vertices[i];
    }

    vLength = trimesh.vLength;

    delete [] normals;

    normals = new float[trimesh.nLength];
    for(int i=0; i < trimesh.nLength; i++) {
        normals[i] = trimesh.normals[i];
    }

    nLength = trimesh.nLength;

    *texCoords = *trimesh.texCoords;
}


void Trimesh::setVertices(float vertexArray[], int length) {

    delete [] vertices;
    vertices = new float[length];
    for(int i=0; i < length; i++) {
        vertices[i] = vertexArray[i];
    }
    vLength = length;
}


void Trimesh::setVertices(Vec3 vertexArray[], int length) {

    delete [] vertices;
    vertices = new float[length*3];
    int j = 0;
    for(int i=0; i < length*3; i=i+3) {
        vertices[i] = vertexArray[j].v[0];
        vertices[i+1] = vertexArray[j].v[1];
        vertices[i+2] = vertexArray[j].v[2];
        j++;
    }
    vLength = length*3;
}


void Trimesh::setNormals(float normalArray[], int length) {

    delete [] normals;
    normals = new float[length];
    for(int i=0; i < length; i++) {
        normals[i] = normalArray[i];
    }
    nLength = length;
}


void Trimesh::setNormals(Vec3 normalArray[], int length) {

    delete [] normals;
    normals = new float[length*3];
    int j = 0;
    for(int i=0; i < length*3; i=i+3) {
        normals[i] = normalArray[j].v[0];
        normals[i+1] = normalArray[j].v[1];
        normals[i+2] = normalArray[j].v[2];
        j++;
    }
    nLength = length*3;
}