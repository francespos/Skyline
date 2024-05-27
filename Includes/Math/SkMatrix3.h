#pragma once 

#include "Math/SkVector3.h"

typedef struct {
    float v[9];
} SkMatrix3;

/// @brief Adds two matrices.
SK_API void skAdd(SkMatrix3 *m, const SkMatrix3 *m1, const SkMatrix3 *m2);

/// @brief Subtracts two matrices.
SK_API void skSubtract(SkMatrix3 *m, const SkMatrix3 *m1, const SkMatrix3 *m2);

/// @brief Multiplies a scalar and a matrix.
SK_API void skMultiply(SkMatrix3 *m, float k, const SkMatrix3 *p);

/// @brief Multiplies a matrix and a vector.
SK_API void skMultiply(SVector3 *v, const SkMatrix3 *p, const SkVector3* w);

/// @brief Multiplies two matrices.
SK_API void skMultiply(SkMatrix3 *m, const SkMatrix3 *m1, const SkMatrix3 *m2);

/// @brief Computes matrix's determinant
SK_API float skGetDeterminant(SkMatrix3 *m);

/// @brief Inverts a matrix
SK_API void skInvert(SkMatrix3 *m, const SkMatrix3 *p);

/// @brief Sets translation matrix
SK_API void skSetTranslationMatrix(SkMatrix3 *m, SkVector2 *t);

/// @brief Sets rotation matrix
SK_API void skSetRotationMatrix(SkMatrix3 *m, float r);

/// @brief Sets scale matrix
SK_API void skSetScaleMatrix(SkMatrix3 *m, float s);

/// @brief Sets transform matrix
SK_API void skSetTransformMatrix(SkMatrix3 *m, float r, const SkVector2 *t);
