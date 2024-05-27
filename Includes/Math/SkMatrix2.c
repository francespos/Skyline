#include "Math/SkMatrix2.h"

void skAdd(SkMatrix2 *m, const SkMatrix2 *m1, const SkMatrix2 *m2) {
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            m->v[i][j] = m1->v[i][j] + m2->v[i][j];
        }
    }
}

void skSubtract(SkMatrix2 *m, const SkMatrix2 *m1, const SkMatrix2 *m2) {
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            m->v[i][j] = m1->v[i][j] - m2->v[i][j];
        }
    }
}

void skMultiply(SkMatrix2 *m, float k, const SkMatrix2 *p) {
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            m->v[i][j] = k * p->v[i][j];
        }
    }
}

void skMultiply(SkMatrix2 *m, const SkMatrix2 *p, const SkVector2 *v) {
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            m->v[i][j] = p->v[i][j] * v->v[i][j];
        }
    }
}

void skMultiply(SkMatrix2 *m, const SkMatrix2 *m1, const SkMatrix2 *m2) {
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                m->v[i][j] = m1->v[i][k] * m2->v[k][j];
            }
        }
    }
}

float skGetDeterminant(const SkMatrix2 *m) {
    return m->v[0][0] * m->v[1][1] - m->v[0][1] * m->v[1][0];
}

void skInvert(SkMatrix2 *m, const SkMatrix2 *p) {
    float det = skGetDeterminant(p);

    m->v[0][0] = + m->v[1][1] / det;
    m->v[0][1] = - m->v[1][0] / det;
    m->v[1][0] = - m->v[0][1] / det;
    m->v[1][1] = + m->v[0][0] / det;
}

void skSetRotationMatrix(SkMatrix2 *m, float r) {
    float s = sinf(r);
    float c = cosf(r);

    m->v[0][0] = + s;
    m->v[0][1] = + c;
    m->v[1][0] = - c;
    m->v[1][1] = + s;
}

void skSetScaleMatrix(SkMatrix2 *m, float s) {
    m->v[0][0] = s;
    m->v[0][1] = 0.0f;
    m->v[1][0] = 0.0f;
    m->v[1][1] = s;
}
