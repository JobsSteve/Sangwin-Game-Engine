#include "headers/resource/OBJLoader.h"

//Static inclusions
OBJLoader* OBJLoader::inst;
bool OBJLoader::hasNormals = false;
bool OBJLoader::hasTexCoords = false;
ArrayList<SPtr<Vec3> > OBJLoader::vertices = ArrayList<SPtr<Vec3> >();
ArrayList<SPtr<Vec3> > OBJLoader::normals = ArrayList<SPtr<Vec3> >();
ArrayList<SPtr<Vec2> > OBJLoader::texCoords = ArrayList<SPtr<Vec2> >();


OBJLoader::OBJLoader()
:numOfGroups(0),
 currGroup(new OBJGroup()),
 groups(ArrayList<SPtr<OBJGroup> >()),
 materials(new HashMap<SPtr<OBJMaterial> >()),
 la(0)
{}


OBJLoader::~OBJLoader() {}


OBJLoader* OBJLoader::instance() {

    if(!inst) {
        inst = new OBJLoader();
    }
    return inst;
}


void OBJLoader::reset() {

    numOfGroups = 0;
    hasNormals = false;
    hasTexCoords = false;
    currGroup = SPtr<OBJGroup>(new OBJGroup());
    groups.clear();
    vertices.clear();
    normals.clear();
    texCoords.clear();
    materials->clear();
    if(la) {
        delete la;
    }
}


void OBJLoader::loadModel(char* data, int filesize, const char* filename) {

    //Create a new lexical analyser with the file data.
    if(la) {
        delete la;
    }
    la = new OBJLexicalAnalyser(data);

    //Iterate over every token in the file, creating geometry.
    while(la->getPos() < filesize) {

        switch (la->getNextTokenOBJ().type) {

            //Vertex
            case 0: {
                float x = la->getNextTokenOBJ().toFloat();
                float y = la->getNextTokenOBJ().toFloat();
                float z = la->getNextTokenOBJ().toFloat();
                vertices.add(SPtr<Vec3>(new Vec3(x,y,z)));
            } break;

            //Texture Coordinate
            case 1: {
                float u = la->getNextTokenOBJ().toFloat();
                float v = la->getNextTokenOBJ().toFloat();
                texCoords.add(SPtr<Vec2>(new Vec2(u,v)));
                hasTexCoords = true;
            } break;

            //Normal
            case 2: {
                float x = la->getNextTokenOBJ().toFloat();
                float y = la->getNextTokenOBJ().toFloat();
                float z = la->getNextTokenOBJ().toFloat();
                normals.add(SPtr<Vec3>(new Vec3(x,y,z)));
                hasNormals = true;
            } break;

            //Face
            case 3: {
                SPtr<OBJFace> face(new OBJFace());
                for(int p=0; p<3; p++) {
                    //Get Vertex
                    face->vertexIndices[p] = la->getNextTokenOBJ().toInt();
                    //Get Texture Coordinate
                    if(hasTexCoords) {
                        face->texCoordIndices[p] = la->getNextTokenOBJ().toInt();
                    }
                    //Get Normal
                    if(hasNormals) {
                        face->normalIndices[p] = la->getNextTokenOBJ().toInt();
                    }
                }
                currGroup->faces->add(face);
                currGroup->numOfFaces++;
            } break;

            //Group
            case 4: {
                if(numOfGroups != 0) {
                    currGroup = (SPtr<OBJGroup>(new OBJGroup()));
                }
                currGroup->name = la->getNextTokenOBJ().data;
                numOfGroups++;
                groups.add(currGroup);
            } break;

            //Use Material
            case 5: {
                currGroup->mtl = materials->get(la->getNextTokenOBJ().data);
            } break;

            //Load Material (Done elsewhere)
            case 6: {
                la->getNextTokenOBJ();
            } break;
        }
    }

    //Case where Group command was not used, and only one group exists
    if(numOfGroups == 0) {
        groups.add(currGroup);
    }

    //If there is more than one group:
    if(numOfGroups > 1) {
        //Create the group root node
        SPtr<Visual<Vec3,Trfm3,App3> > nodeGroup(GetNode::newVisual3D(" "));
        //Create individual nodes for each group, and attach them to the root
        for(int i=0; i<groups.size(); i++) {
            SPtr<Node> node(groups.get(i)->convert());
            nodeGroup->attachChild(node);
        }
        //Add the model to the ResourceManager
        ResourceManager::instance()->addModel(filename,nodeGroup);
        reset();
    }
    //If there was only one group, convert and add to the ResourceManager.
    else {
        SPtr<Visual<Vec3,Trfm3,App3> > node(groups.get(0)->convert());
        ResourceManager::instance()->addModel(filename,node);
        reset();
    }
}


void OBJLoader::loadMTL(char* data, int filesize) {

    //Create a new lexical analyser with the file data.
    if(la) {
        delete la;
    }
    la = new OBJLexicalAnalyser(data);

    //Create a material
    SPtr<OBJMaterial> mat(new OBJMaterial());
    mat->alpha = 1;
    
    //Iterate over every token in the file, creating material data.
    while(la->getPos() < filesize) {

        switch(la->getNextTokenMTL().type) {

            //Texture map (all kinds of map are used as an ambient map)
            case 10: {
                SPtr<OBJString> name(new OBJString(la->getNextTokenMTL().copyData()));
                mat->textures->add(name);
            } break;

            //New Material
            case 11: {
                const char* name = la->getNextTokenMTL().copyData();
                materials->put(name,mat);
            } break;

            //Shininess
            case 12: {
                mat->shininess = la->getNextTokenMTL().toFloat();
            } break;

            //Ambient
            case 14: {
                mat->ambient[0] = la->getNextTokenMTL().toFloat();
                mat->ambient[1] = la->getNextTokenMTL().toFloat();
                mat->ambient[2] = la->getNextTokenMTL().toFloat();
            } break;

            //Diffuse
            case 15: {
                mat->diffuse[0] = la->getNextTokenMTL().toFloat();
                mat->diffuse[1] = la->getNextTokenMTL().toFloat();
                mat->diffuse[2] = la->getNextTokenMTL().toFloat();
            } break;

            //Specular
            case 16: {
                mat->specular[0] = la->getNextTokenMTL().toFloat();
                mat->specular[1] = la->getNextTokenMTL().toFloat();
                mat->specular[2] = la->getNextTokenMTL().toFloat();
            } break;

            //Alpha
            case 17: {
                mat->alpha = la->getNextTokenMTL().toFloat();
            } break;

            //Alpha
            case 18: {
                mat->alpha = la->getNextTokenMTL().toFloat();
            } break;
        }
    }
}
