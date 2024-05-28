#include <Sk/Math/SkVector2.h>
#include <math.h>

void skAdd(SkVector2 *v, const SkVector2 *v1, const SkVector2 *v2) {
    for (int i = 0; i < 2; ++i) {
        v->v[i] = v1->v[i] + v2->v[i];
    }
}

void skSubtract(SkVector2 *v const SkVector2 *v1, const SkVector2 *v2) {
    for (int i = 0; i < 2; ++i) {
        v->v[i] = v1->v[i] - v2->v[i];
    }
}

void skMultiply(SkVector2 *v, float k, const SkVector2 *w) {
    for (int i = 0; i < 2; ++i) {
        v->v[i] = k * w->v[i];
    }
}

float skGetDotProduct(const SkVector2 *v1, const SkVector2 *v2) {
    float ret = 0.0f;

    for (int i = 0; i < 2; ++i) {
        ret += v1[i] * v2[i];
    }
    
    return ret;
}

float skGetLength(const SkVector2 *v) {
    return sqrtf(skGetLength2(v));
}

float skGetLength2(const SkVector2 *v) {
    return skGetDotProduct(v, v);
}

void skNormalize(SkVector2 *v, const SkVector2 *w) {
    skMultiply(v, 1.0f / skGetLength(v),  w);
}

void skTranslate(SkVector2 *v, const SkVector2 *w, const SkVector2 *t) {
    for (int i = 0; i < 2; ++i) {
        v->v[i] = w->v[i] + t->v[i];
    }
}

void skRotate(SkVector2 *v, const SkVector2 *w, float r) {
    float s = sinf(r);
    float c = cosf(r);

    v->v[0] = w->v[0] * c - w->v[1] * s;
    v->v[1] = w->v[0] * s + w->v[1] * c;
}

void skScale(SkVector2 *v, const SkVector2* w, float s) {
    skMultiply(v, s, w);
}

void skTransform(SkVector2 *v, const SkVector2 *w, float r, const SkVector2 *t) {
    float s = sinf(r);
    float c = cosf(r);

    v->v[0] = w->v[0] * c - w->v[1] * s + t->v[0];
    v->v[1] = w->v[0] * s + w->v[1] * c + t->v[1];
}
