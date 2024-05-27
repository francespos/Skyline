#pragma once

#include "SkCommons.h"

typedef struct {
    float v[3];
} SkVector3;

/// @brief Adds two vectors.
SK_API void skAdd(SkVector3 *v, const SkVector3 *v1, const SkVector3 *v2);

/// @brief Subtracts two vectors.
SK_API void skSubtract(SkVector3 *v const SkVector3 *v1, const SkVector3 *v2);

/// @brief Multiplies a scalar and a vector.
SK_API void skMultiply(SkVector3 *v, float k, const SkVector3 *w);

/// @brief Computes dot product of two vectors.
SK_API float skGetDotProduct(const SkVector3 *v1, const SkVector3 *v2);

/// @bried Sets cross product of two vectors
SK_API void skSetCrossProduct(const SkVector3 *v, const SkVector3 *v1, const SkVector3 *v2);

/// @brief Computes vector's length.
SK_API float skGetLength(const SkVector3 *v);

/// @brief Computes vector's squared length.
SK_API float skGetLength2(const SkVector3 *v);

/// @brief Normalizes a vector.
SK_API void skNormalize(SkVector3 *v, const SkVector3 *w);

/// @brief Converts vector's coordinate to homogeneous coordinates.
SK_API void skConvertToHomogeneousCoordinates(SkVector3 *v, const SkVector2 *w);
