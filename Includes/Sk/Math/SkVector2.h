#pragma once

#include <Sk/SkCommons.h>

typedef struct {
    float v[2];
} SkVector2;

/// @brief Adds two vectors.
SK_API void skAdd(SkVector2 *v, const SkVector2 *v1, const SkVector2 *v2);

/// @brief Subtracts two vectors.
SK_API void skSubtract(SkVector2 *v const SkVector2 *v1, const SkVector2 *v2);

/// @brief Multiplies a scalar and a vector.
SK_API void skMultiply(SkVector2 *v, float k, const SkVector2 *w);

/// @brief Computes dot product of two vectors.
SK_API float skGetDotProduct(const SkVector2 *v1, const SkVector2 *v2);

/// @brief Computes vector's length.
SK_API float skGetLength(const SkVector2 *v);

/// @brief Computes vector's squared length.
SK_API float skGetLength2(const SkVector2 *v);

/// @brief Normalizes a vector.
SK_API void skNormalize(SkVector2* v, const SkVector2 *w);

/// @brief Translates a vector.
SK_API void skTranslate(SkVector2 *v, const SkVector2 *w, const SkVector2 *t);

/// @brief Rotates a vector.
SK_API void skRotate(SkVector2 *v, const SkVector2 *w, float r);

/// @brief Scales a vector.
SK_API void skScale(SkVector2 *v, const SkVector2* w, float s);

/// @brief Rotates then translates a vector.
SK_API void skTransform(SkVector2 *v, const SkVector2 *w, float r, const SkVector2 *t);
