#include "headers/scenegraph/App.h"

App::App()
:inheritance(0),
 pointAtt(new PointAtt()),
 lineAtt(new LineAtt()),
 polyAtt(new PolyAtt()),
 colour(new Colour()),
 alpha(new Alpha()),
 textures(new ArrayList<SPtr<Texture> >()),
 material(new Material()),
 lightingPolicy(LOCAL_FIRST),
 lights(new ArrayList<SPtr<Light> >())
{
    inheritance = LIGHTING;
}


App::App(const App& rhs)
:inheritance(rhs.inheritance),
 pointAtt(rhs.pointAtt),
 lineAtt(rhs.lineAtt),
 polyAtt(rhs.polyAtt),
 colour(rhs.colour),
 alpha(rhs.alpha),
 textures(rhs.textures),
 material(rhs.material),
 lightingPolicy(rhs.lightingPolicy),
 lights(rhs.lights)
{}


App& App::operator =(const App& rhs) {

    inheritance = rhs.inheritance;
    pointAtt = rhs.pointAtt;
    lineAtt = rhs.lineAtt;
    polyAtt = rhs.polyAtt;
    colour = rhs.colour;
    alpha = rhs.alpha;
    textures = rhs.textures;
    
    material = rhs.material;
    lightingPolicy = rhs.lightingPolicy;
    lights->clear();
    int nLights = rhs.lights->size();
    for(int i=0; i<nLights; i++) {
        lights->add(rhs.lights->get(i));
    }
    
    return *this;
}


App::~App() {
    
    delete lights;
}


void App::setTo(const App& app) {
    
    //basic attributes
    inheritance = app.inheritance;
    pointAtt = app.pointAtt;
    lineAtt = app.lineAtt;
    polyAtt = app.polyAtt;
    colour = app.colour;
    alpha = app.alpha;

    //textures
    textures->clear();
    for(int i=0; i<app.textures->size(); i++) {
        textures->add(app.textures->get(i));
    }
    
    //material
    material = app.material;
    
    //lights
    lightingPolicy = app.lightingPolicy;
    lights->clear();
    int nLights = app.lights->size();
    for(int i=0; i<nLights; i++) {
        lights->add(app.lights->get(i));
    }
}


void App::toDefault() {

    pointAtt = SPtr<PointAtt>();
    lineAtt = SPtr<LineAtt>();
    polyAtt = SPtr<PolyAtt>();
    colour = SPtr<Colour>();
    alpha = SPtr<Alpha>();
    textures->clear();
    
    inheritance = 64;
    material = SPtr<Material>();
    lights->clear();
}


SPtr<PointAtt> App::getPointAtt() {

    return pointAtt;
}


void App::setPointAtt(const SPtr<PointAtt>& pointAtt) {

    this->pointAtt = pointAtt;
}


SPtr<LineAtt> App::getLineAtt() {

    return lineAtt;
}


void App::setLineAtt(const SPtr<LineAtt>& lineAtt) {

    this->lineAtt = lineAtt;
}


SPtr<PolyAtt> App::getPolyAtt() {

    return polyAtt;
}


void App::setPolyAtt(const SPtr<PolyAtt>& polyAtt) {

    this->polyAtt = polyAtt;
}


SPtr<Colour> App::getColour() {

    return colour;
}


void App::setColour(const SPtr<Colour>& colouring) {

    this->colour = colouring;
}


SPtr<Alpha> App::getAlpha() {

    return alpha;
}


void App::setAlpha(const SPtr<Alpha>& alpha) {

    this->alpha = alpha;
}


void App::addTexture(SPtr<Texture> texture) {

    textures->add(texture);
}


void App::removeTexture(const SPtr<Texture>& texture) {

    textures->remove(texture);
}


SPtr<Texture> App::removeTexture(int i) {

    return textures->remove(i);
}


ArrayList<SPtr<Texture> >& App::getTextures() {

    return *textures;
}


SPtr<Texture> App::getTexture(int i) {

    if(i>=0 && i<textures->size()) {
        return textures->get(i);
    }
    return SPtr<Texture>();
}


SPtr<Material> App::getMaterial() {

    return material;
}


void App::setMaterial(const SPtr<Material>& material) {

    this->material = material;
}


App::LightingPolicy App::getLightingPolicy() {

    return lightingPolicy;
}


void App::addLight(SPtr<Light> light) {

    lights->add(light);
}


void App::removeLight(const SPtr<Light>& light) {

    lights->remove(light);
}


SPtr<Light> App::removeLight(int i) {

    return lights->remove(i);
}


ArrayList<SPtr<Light> >& App::getLights() {

    return *lights;
}


void App::add(App& app) {

    if( (app.inheritance & POINT_ATT) != 0 ) {
        inheritance |= POINT_ATT;
        pointAtt = app.pointAtt;
    }

    if( (app.inheritance & LINE_ATT) != 0 ) {
        inheritance |= LINE_ATT;
        lineAtt = app.lineAtt;
    }

    if( (app.inheritance & POLY_ATT) != 0 ) {
        inheritance |= POLY_ATT;
        polyAtt = app.polyAtt;
    }

    if( (app.inheritance & COLOUR) != 0 ) {
        inheritance |= COLOUR;
        colour = app.colour;
    }

    if( (app.inheritance & MATERIAL) != 0 ) {
        inheritance |= MATERIAL;
        material = app.material;
    }

    if( (app.inheritance & ALPHA) != 0 ) {
        inheritance |= ALPHA;
        alpha = app.alpha;
    }

    textures->clear();
    int nTextures = app.textures->size();
    for(int i=0; i<nTextures; i++) {
        textures->add(app.textures->get(i));
    }

    int nLights = app.lights->size();
    if( (app.inheritance & LIGHTING) != 0 ) {
        inheritance |= LIGHTING;
        for(int i=0; i<(app.lights->size()); i++) {
            if(!lights->contains(app.lights->get(i))) {
                lights->add(app.lights->get(i));
            }
        }
    }
    else{
        lights->clear();
        for(int i=0; i<nLights; i++) {
                lights->add(app.lights->get(i));
        }
    }
}


void App::override(int options) {

    inheritance = (inheritance | options);
}


void App::inherit(int options) {

    inheritance = inheritance & ~options;
}
