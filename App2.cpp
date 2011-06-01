#include "App2.h"

App2& App2::operator =(const App2& rhs) {

    App::operator =(rhs);

    return *this;
}


void App2::add(App& app) {

    if( (app.inheritance & POINT_ATT) != 0) {
        inheritance |= POINT_ATT;
        pointAtt = static_cast<App2&>(app).pointAtt;
    }

    if((app.inheritance & LINE_ATT) != 0) {
        inheritance |= LINE_ATT;
        lineAtt = static_cast<App2&>(app).lineAtt;
    }

    if( (app.inheritance & POLY_ATT) != 0 ) {
        inheritance |= POLY_ATT;
        polyAtt = static_cast<App2&>(app).polyAtt;
    }

    if( (app.inheritance & COLOUR) != 0 ) {
        inheritance |= COLOUR;
        colour = static_cast<App2&>(app).colour;
    }

    if( (app.inheritance & ALPHA) != 0 ) {
        inheritance |= ALPHA;
        alpha = static_cast<App2&>(app).alpha;
    }

    textures->clear();
    int nTextures = static_cast<App2&>(app).textures->size();
    for(int i=0; i<nTextures; i++) {
        textures->add(static_cast<App2&>(app).textures->get(i));
    }
}
