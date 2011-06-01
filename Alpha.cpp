#include "Alpha.h"

Alpha::Alpha() {
    toDefault();
}


Alpha::Alpha(float alpha) {
    setValue(alpha);
}


Alpha::Alpha(const Alpha& rhs)
:alpha(rhs.alpha)
{}


Alpha& Alpha::operator =(const Alpha& rhs) {

    alpha = rhs.alpha;

    return *this;
}


Alpha::~Alpha() {}
