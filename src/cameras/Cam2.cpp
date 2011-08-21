#include "headers/cameras/Cam2.h"
#include "headers/maths/FastMath.h"

int AbstractRenderer::canvasHeight;
int AbstractRenderer::canvasWidth;

Cam2& Cam2::operator =(const Cam2& rhs) {

    Cam<Vec2>::operator =(rhs);

    rot = rhs.rot;
    *bs = *rhs.bs;
    
    return *this;
}


void Cam2::onCanvasChanged(int width, int height) {

    //Update Viewport
    Cam<Vec2>::onCanvasChanged(width,height);

    //Update modelview matrix
    modelView->setTo(
            FastMath::instance()->fmCos(-rot), -FastMath::instance()->fmSin(-rot), 0.0f, -pos->v[0],
            FastMath::instance()->fmSin(-rot), -FastMath::instance()->fmCos(-rot), 0.0f, -pos->v[1],
            0.0f, 0.0f, 1.0f, 0.0f,
            0.0f, 0.0f, 0.0f, 1.0f);
}


bool Cam2::isVisible(const Vec2& pos) {

    if(pos.v[0] <= this->pos->v[0] || pos.v[0] >= this->pos->v[0] + AbstractRenderer::canvasWidth ||
       pos.v[1] <= this->pos->v[1] || pos.v[1] >= this->pos->v[1] + AbstractRenderer::canvasHeight) {

        return false;
    }
    return true;
}


bool Cam2::isVisible(const BoundingVolume<Vec2>& bounds) {

    //Check if Sphere is visible
    if(bounds.type == bounds.SPHERE) {
        *bs = static_cast<const BoundingSphere<Vec2>& > (bounds);
        float bs_x = bs->getWorldPos().v[0];
        float bs_y = bs->getWorldPos().v[1];
        float bs_rad = bs->getRadius();
        if(bs_x + bs_rad <= pos->v[0] || bs_x - bs_rad >= pos->v[0] + AbstractRenderer::canvasWidth ||
           bs_y + bs_rad <= pos->v[1] || bs_y - bs_rad >= pos->v[1] + AbstractRenderer::canvasHeight) {
            return false;
        }
    }
    return true;
}


void Cam2::update() {

    //Update the modelview matrix
    modelView->setTo(
             FastMath::instance()->fmCos(-rot), -FastMath::instance()->fmSin(-rot),  0.0f, -pos->v[0],
             FastMath::instance()->fmSin(-rot),  FastMath::instance()->fmCos(-rot),  0.0f, -pos->v[1],
             0.0f,  0.0f,  1.0f,  0.0f,
             0.0f,  0.0f,  0.0f,  1.0f);
}