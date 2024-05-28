#pragma once 

#include <Sk/Math/SkVector2.h>

typedef struct {
    float v[4];
} SkMatrix2;

/// @brief Adds two matrices.
SK_API void skAdd(SkMatrix2 *m, const SkMatrix2 *m1, const SkMatrix2 *m2);

/// @brief Subtracts two matrices.
SK_API void skSubtract(SkMatrix2 *m, const SkMatrix2 *m1, const SkMatrix2 *m2);

/// @brief Multiplies a scalar and a matrix.
SK_API void skMultiply(SkMatrix2 *m, float k, const SkMatrix2 *p);

/// @brief Multiplies a matrix and a vector.
SK_API void skMultiply(SVector2 *v, const SkMatrix2 *p, const SkVector2* w);

/// @brief Multiplies two matrices.
SK_API void skMultiply(SkMatrix2 *m, const SkMatrix2 *m1, const SkMatrix2 *m2);

/// @brief Computes matrix's determinant
SK_API float skGetDeterminant(SkMatrix2 *m);

/// @brief Inverts a matrix
SK_API void skInvert(SkMatrix2 *m, const SkMatrix2 *p);

/// @brief Sets rotation matrix
SK_API void skSetRotationMatrix(SkMatrix2 *m, float r);

/// @brief Sets scale matrix
SK_API void skSetScaleMatrix(SkMatrix2 *m, float s);
