#include "headers/cameras/Viewport.h"

Viewport::Viewport()
:fixed(false),
 relativePos(new Vec2(0,0)),
 relativeDim(new Vec2(1,1)),
 pos(new Vec2()),
 dim(new Vec2())
{}


Viewport::Viewport(bool isFixed, const Vec2& cPos, const Vec2& cDim)
:fixed(false),
 relativePos(new Vec2(0,0)),
 relativeDim(new Vec2(1,1)),
 pos(new Vec2()),
 dim(new Vec2())
{
    setTo(isFixed,cPos,cDim);
}


Viewport::Viewport(const Viewport& rhs)
:fixed(rhs.fixed),
 relativePos(new Vec2(*rhs.relativePos)),
 relativeDim(new Vec2(*rhs.relativeDim)),
 pos(new Vec2(*rhs.pos)),
 dim(new Vec2(*rhs.dim))
{}


Viewport& Viewport::operator =(const Viewport& rhs) {

    fixed = rhs.fixed;
    *relativePos = *rhs.relativePos;
    *relativeDim = *rhs.relativeDim;
    *pos = *rhs.pos;
    *dim = *rhs.dim;

    return *this;
}


void Viewport::setTo(bool isFixed, const Vec2& pos, const Vec2& dim) {

    fixed = isFixed;
    if(fixed) {
        this->pos->setTo(pos);
        this->dim->setTo(dim);
    }
    else {
        relativePos->setTo(pos);
        relativeDim->setTo(dim);
    }
}


void Viewport::onCanvasChanged(int width, int height) {

    //Recalculate actual position based on relative positions and canvas
    //dimensions.
    if(!fixed) {
        pos->setTo(relativePos->v[0]*width, relativePos->v[1]*height);
        dim->setTo(relativeDim->v[0]*width, relativeDim->v[1]*height);
    }
}

