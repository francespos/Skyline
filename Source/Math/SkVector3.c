#include <Sk/Math/SkVector3.h>
#include <math.h>

void skAdd(SkVector3 *v, const SkVector3 *v1, const SkVector3 *v2) {
    for (int i = 0; i < 3; ++i) {
        v->v[i] = v1->v[i] + v2->v[i];
    }
}

void skSubtract(SkVector3 *v const SkVector3 *v1, const SkVector3 *v2) {
    for (int i = 0; i < 3; ++i) {
        v->v[i] = v1->v[i] - v2->v[i];
    }
}

void skMultiply(SkVector3 *v, float k, const SkVector3 *w) {
    for (int i = 0; i < 3; ++i) {
        v->v[i] = k * v1->v[i];
    }
}

float skGetDotProduct(const SkVector3 *v1, const SkVector3 *v2) {
    float ret = 0.0f;

    for (int i = 0; i < 3; ++i) {
        ret += v1->v[i] * v2->v[i];
    }
    
    return ret;
}

void skSetCrossProduct(const SkVector3 *v, const SkVector3 *v1, const SkVector3 *v2) {
    v->v[0] = v1->v[1] * v2->v[2] - v1->v[2] * v2->v[1];
    v->v[1] = v1->v[0] * v2->v[2] - v1->v[2] * v2->v[0];
    v->v[2] = v1->v[0] * v2->v[1] - v1->v[1] * v2->v[0];
}

float skGetLength(const SkVector3 *v) {
    return sqrtf(skGetLength2(v));
}

float skGetLength2(const SkVector3 *v) {
    return skGetDotProduct(v, v);
}

void skNormalize(SkVector3 *v, const SkVector3 *w) {
    skMultiply(v, 1.0f / skGetLength(v),  w);
}

void skTranslate(SkVector3 *v, const SkVector3 *w, const SkVector3 *t) {
    for (int i = 0; i < 3; ++i) {
        v->v[i] = w->v[i] + t->v[i];
    }
}

void skConvertToHomogeneousCoordinates(SkVector3 *v, const SkVector2 *w) {
    v->v[0] = w->v[0];
    v->v[1] = w->v[1];
    v->v[2] = 1.0f;
}
