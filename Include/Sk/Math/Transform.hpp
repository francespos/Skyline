#pragma once

#include <Sk/Math/Matrix.hpp>

namespace Sk {
    struct Translation final : public Matrix3 {
        explicit Translation(float x, float y);
        explicit Translation(const Vector2& t);
    };

    Translation operator*(const Translation& lhs, const Translation& rhs);

    Vector2 getTranslationVector(const Translation& t);
    Translation invert(const Translation& t);

    struct Rotation final : public Matrix3 {
        explicit Rotation(float angle);
    };

    Rotation operator*(const Rotation& lhs, const Rotation& rhs);

    float getAngle(const Rotation& r);
    Rotation invert(const Rotation& r);

    struct Scaling final : public Matrix3 {
        Scaling(float sx, float sy);
        Scaling(const Vector2& s);
    };

    Scaling operator*(const Scaling& lhs, const Scaling& rhs);

    Vector2 getScalingVector(const Scaling& s);
    Scaling invert(const Scaling& s);

    struct TransformA final : public Matrix3 {
        TransformA(float tx, float ty, float angle);
        TransformA(const Vector2& t, float angle);
    };
    
    TransformA operator*(const Translation& lhs, const Rotation& rhs);
    TransformA operator*(const TransformA& lhs, const Rotation& rhs);
    TransformA operator*(const Translation& lhs, const TransformA& rhs);

    Vector2 getTranslationVector(const TransformA& tA);
    float getAngle(const TransformA& tA);

    TransformA invert(const TransformA& tA);

    struct TransformB final : public Matrix3 {
        TransformB(float tx, float ty, float sx, float sy);
        TransformB(const Vector2& t, const Vector2& r);
    };

    TransformB operator*(const Translation& lhs, const Scaling& rhs);
    TransformB operator*(const TransformB& lhs, const Scaling& rhs);
    TransformB operator*(const Translation& lhs, const TransformB& rhs);

    Vector2 getTranslationVector(const TransformB& tB);
    Vector2 getScalingVector(const TransformB& tB);

    TransformB invert(const TransformB& tB);
}