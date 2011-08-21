#include "headers/scenegraph/App3.h"

App3& App3::operator =(const App3& rhs) {

    App::operator =(rhs);
    material = rhs.material;
    lightingPolicy = rhs.lightingPolicy;
    lights->clear();
    int nLights = rhs.lights->size();
    for(int i=0; i<nLights; i++) {
        lights->add(rhs.lights->get(i));
    }

    return *this;
}


App3::~App3() {

    delete lights;
}


void App3::setTo(const App& app) {

    App::setTo(app);

    material = static_cast<const App3&> (app).material;
    lightingPolicy = static_cast<const App3&> (app).lightingPolicy;
    lights->clear();
    int nLights = static_cast<const App3&> (app).lights->size();
    for(int i=0; i<nLights; i++) {
        lights->add(static_cast<const App3&> (app).lights->get(i));
    }
}


void App3::toDefault() {

    App::toDefault();

    inheritance = 64;
    material = SPtr<Material>();
    lights->clear();
}


void App3::add(App& app) {

    if( (app.inheritance & POINT_ATT) != 0 ) {
        inheritance |= POINT_ATT;
        pointAtt = static_cast<App3&> (app).pointAtt;
    }

    if( (app.inheritance & LINE_ATT) != 0 ) {
        inheritance |= LINE_ATT;
        lineAtt = static_cast<App3&> (app).lineAtt;
    }

    if( (app.inheritance & POLY_ATT) != 0 ) {
        inheritance |= POLY_ATT;
        polyAtt = static_cast<App3&> (app).polyAtt;
    }

    if( (app.inheritance & COLOUR) != 0 ) {
        inheritance |= COLOUR;
        colour = static_cast<App3&> (app).colour;
    }

    if( (app.inheritance & MATERIAL) != 0 ) {
        inheritance |= MATERIAL;
        material = static_cast<App3&> (app).material;
    }

    if( (app.inheritance & ALPHA) != 0 ) {
        inheritance |= ALPHA;
        alpha = static_cast<App3&> (app).alpha;
    }

    textures->clear();
    int nTextures = static_cast<App3&>(app).textures->size();
    for(int i=0; i<nTextures; i++) {
        textures->add(static_cast<App3&>(app).textures->get(i));
    }

    int nLights = static_cast<App3&> (app).lights->size();
    if( (app.inheritance & LIGHTING) != 0 ) {
        inheritance |= LIGHTING;
        for(int i=0; i<(static_cast<App3&> (app).lights->size()); i++) {
            if(!lights->contains(static_cast<App3&>(app).lights->get(i))) {
                lights->add(static_cast<App3&> (app).lights->get(i));
            }
        }
    }
    else{
        lights->clear();
        for(int i=0; i<nLights; i++) {
                lights->add(static_cast<App3&>(app).lights->get(i));
        }
    }
}


