#include "headers/resource/ResourceManager.h"

ResourceManager* ResourceManager::inst;

ResourceManager::ResourceManager()
:textures(new HashMap<SPtr<Texture> >()),
 models(new HashMap<SPtr<Visual> >())
{}


ResourceManager::~ResourceManager() {}


ResourceManager* ResourceManager::instance() {

    if(!inst) {
        inst = new ResourceManager();
    }
    return inst;
}


void ResourceManager::addTexture(const char* filename, SPtr<Texture>& tex) {

    if(!textures->containsKey(filename)) {
        textures->put(filename,tex);
    }
}


void ResourceManager::createTexture(const char* filename, int* width, int* height, void** data, int numOfBitmaps) {

    SPtr<Texture> newTex(new Texture(width,height,data,numOfBitmaps));

    addTexture(filename,newTex);
}


SPtr<Texture> ResourceManager::getTexture(const char* filename) {

    if(textures->containsKey(filename)) {
        return textures->get(filename);
    }
    else {
        return SPtr<Texture>();
    }
}


SPtr<ArrayList<SPtr<Texture> > > ResourceManager::getTextures() {

    return textures->values();
}


void ResourceManager::addModel(const char* filename, SPtr<Visual> mod) {

    if(!models->containsKey(filename)) {
        models->put(filename, mod);
    }
}


SPtr<Visual> ResourceManager::getModel(const char* filename) {

    if(models->containsKey(filename)) {
        SPtr<Node> n(0);
        return models->get(filename)->cloneTree(n).smart_static_cast(SPtr<Visual>());
    }
    else {
        return SPtr<Visual>();
    }
}


SPtr<Visual> ResourceManager::getModelActual(const char* filename) {

    if(models->containsKey(filename)) {
        return models->get(filename);
        }
    else {
        return SPtr<Visual>();
    }
}


SPtr<ArrayList<SPtr<Visual> > > ResourceManager::getModels() {

    return models->values();
}