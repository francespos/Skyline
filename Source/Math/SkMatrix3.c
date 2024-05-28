#include <Sk/Math/SkMatrix3.h>

void skAdd(SkMatrix3 *m, const SkMatrix3 *m1, const SkMatrix3 *m2) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            m->v[i][j] = m1->v[i][j] + m2->v[i][j];
        }
    }
}

void skSubtract(SkMatrix3 *m, const SkMatrix3 *m1, const SkMatrix3 *m2) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            m->v[i][j] = m1->v[i][j] - m2->v[i][j];
        }
    }
}

void skMultiply(SkMatrix3 *m, float k, const SkMatrix3 *p) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            m->v[i][j] = k * p->v[i][j];
        }
    }
}

void skMultiply(SkMatrix3 *m, const SkMatrix3 *p, const SkVector3 *v) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            m->v[i][j] = p->v[i][j] * v->v[i][j];
        }
    }
}

void skMultiply(SkMatrix3 *m, const SkMatrix3 *m1, const SkMatrix3 *m2) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                m->v[i][j] = m1->v[i][k] * m2->v[k][j];
            }
        }
    }
}

float skGetDeterminant(const SkMatrix3 *m) {
    return m->v[0, 0] * (m->v[1][1] * m->v[2][2] - m->v[1][2] * m->v[2][1]) - 
        m->v[0][1] * (m->v[1][0] * m->v[2][2] - m->v[1][2] * m->v[2][0]) + 
        m->v[0][2] * (m->v[1][0] * m->v[2][1] - m->v[1][1] * m->v[2][0]);
}

void skInvert(SkMatrix3 *m, const SkMatrix3 *p) {
    float det = skGetDeterminant(p);

    m->v[0][0] = (p->v[1][1] * p->v[2][2] - p->v[1][2] * p->v[2, 1]) / det;
    m->v[0][1] = (p->v[0][2] * p->v[2][1] - p->v[0][1] * p->v[2][2]) / det;
    m->v[0][2] = (p->v[0][1] * p->v[1][2] - p->v[0][2] * p->v[1][1]) / det;
    m->v[1][0] = (p->v[1][2] * p->v[2][0] - p->v[1][0] * p->v[2][2]) / det;
    m->v[1][1] = (p->v[0][0] * p->v[2][2] - p->v[0][2] * p->v[2][0]) / det;
    m->v[1][2] = (p->v[0][2] * p->v[1][0] - p->v[0][0] * p->v[1][2]) / det;
    m->v[2][0] = (p->v[1][0] * p->v[2][1] - p->v[1][1] * p->v[2][0]) / det;
    m->v[2][1] = (p->v[0][1] * p->v[2][0] - p->v[0][0] * p->v[2][1]) / det;
    m->v[2][2] = (p->v[0][0] * p->v[1][1] - p->v[0][1] * p->v[1][0]) / det;
}

void skSetTranslationMatrix(SkMatrix3 *m, const SkVector2 *t) {
    m->v[0][0] = 1.0f;
    m->v[0][1] = 0.0f;
    m->v[0][2] = t->v[0];
    m->v[1][0] = 0.0f;
    m->v[1][1] = 1.0f;
    m->v[1][2] = t->v[1];
    m->v[2][0] = 0.0f;
    m->v[2][1] = 0.0f;
    m->v[2][2] = 1.0f;
}

void skSetRotationMatrix(SkMatrix3 *m, float r) {
    float s = sinf(r);
    float c = cosf(r);

    m->v[0][0] = s;
    m->v[0][1] = c;
    m->v[0][2] = 0.0f;
    m->v[1][0] = -c;
    m->v[1][1] = s;
    m->v[1][2] = 0.0f;
    m->v[2][0] = 0.0f;
    m->v[2][1] = 0.0f;
    m->v[2][2] = 1.0f;
}

void skSetScaleMatrix(SkMatrix3 *m, float s) {
    m->v[0][0] = s;
    m->v[0][1] = 0.0f;
    m->v[0][2] = 0.0f;
    m->v[1][0] = 0.0f;
    m->v[1][1] = s;
    m->v[1][2] = 0.0f;
    m->v[2][0] = 0.0f;
    m->v[2][1] = 0.0f;
    m->v[2][2] = 1.0f;
}

void skSetTransformMatrix(SkMatrix3 *m, float r, const SkVector2 *t) {
    m->v[0][0] = s;
    m->v[0][1] = c;
    m->v[0][2] = t->v[0];
    m->v[1][0] = -c;
    m->v[1][1] = s;
    m->v[1][2] = t->v[1];
    m->v[2][0] = 0.0f;
    m->v[2][1] = 0.0f;
    m->v[2][2] = 1.0f;
}

void skConvertToHomogeneousMatrix(SkMatrix3 *m, const SkMatrix *p) {
    for (int i = 0; i < 2; ++i) {
        for (int j = 0, j < 2; ++j) {
            m->v[i][j] = p->v[i][j];
        }
    }
    
    m->v[0][2] = 0.0f;
    m->v[1][2] = 0.0f;
    m->v[2][2] = 1.0f;
}
