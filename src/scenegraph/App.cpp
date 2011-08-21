#include "headers/scenegraph/App.h"

App::App()
:inheritance(0),
 pointAtt(new PointAtt()),
 lineAtt(new LineAtt()),
 polyAtt(new PolyAtt()),
 colour(new Colour()),
 alpha(new Alpha()),
 textures(new ArrayList<SPtr<Texture> >())
{}


App::App(const App& rhs)
:inheritance(rhs.inheritance),
 pointAtt(rhs.pointAtt),
 lineAtt(rhs.lineAtt),
 polyAtt(rhs.polyAtt),
 colour(rhs.colour),
 alpha(rhs.alpha),
 textures(rhs.textures)
{}


App& App::operator =(const App& rhs) {

    inheritance = rhs.inheritance;
    pointAtt = rhs.pointAtt;
    lineAtt = rhs.lineAtt;
    polyAtt = rhs.polyAtt;
    colour = rhs.colour;
    alpha = rhs.alpha;
    textures = rhs.textures;

    return *this;
}


void App::setTo(const App& app) {

    inheritance = app.inheritance;
    pointAtt = app.pointAtt;
    lineAtt = app.lineAtt;
    polyAtt = app.polyAtt;
    colour = app.colour;
    alpha = app.alpha;

    textures->clear();
    for(int i=0; i<app.textures->size(); i++) {
        textures->add(app.textures->get(i));
    }
}


void App::toDefault() {

    inheritance = 0;
    pointAtt = SPtr<PointAtt>();
    lineAtt = SPtr<LineAtt>();
    polyAtt = SPtr<PolyAtt>();
    colour = SPtr<Colour>();
    alpha = SPtr<Alpha>();
    textures->clear();
}


SPtr<Texture> App::getTexture(int i) {

    if(i>=0 && i<textures->size()) {
        return textures->get(i);
    }
    return SPtr<Texture>();
}
