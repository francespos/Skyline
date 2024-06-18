#include <Sk/Math/Transform.hpp>

namespace Sk {
    Translation::Translation(float x, float y)
        : Matrix3{1.0f, 0.0f, x
        , 0.0f, 1.0f, y
        , 0.0f, 0.0f, 1.0f} {}

    Translation::Translation(const Vector2& t)
        : Translation{t(0), t(1)} {}

    Translation operator*(const Translation& lhs, const Translation& rhs) {
        return Translation{getTranslationVector(lhs) + getTranslationVector(rhs)};
    }

    Vector2 getTranslationVector(const Translation& t) {
        return Vector2{t(0, 2), t(1, 2)};
    }

    Translation invert(const Translation& t) {
        Translation ret{t};

        ret(0, 2) = -ret(0, 2);
        ret(1, 2) = -ret(1, 2);

        return ret;
    }

    Rotation::Rotation(float angle)
        : Matrix3{std::cos(angle), -std::sin(angle), 0.0f
        , std::sin(angle), std::cos(angle), 0.0f
        , 0.0f, 0.0f, 1.0f} {}

    Rotation operator*(const Rotation& lhs, const Rotation& rhs) {
        return Rotation{getAngle(lhs) + getAngle(rhs)};
    }

    float getAngle(const Rotation& r) {
        return std::atan2(r(1, 1), r(1, 2));
    }

    Rotation invert(const Rotation& r) {
        Rotation ret{r};

        ret(0, 1) = -ret(0, 1);
        ret(1, 0) = -ret(1, 0);

        return ret;
    }

    Scaling::Scaling(float sx, float sy) 
        : Matrix3{sx, 0.0f, 0.0f
        , 0.0f, sy, 0.0f
        , 0.0f, 0.0f, 1.0f} {}

    Scaling::Scaling(const Vector2& s) 
        : Scaling{s(0), s(1)} {}

    Scaling operator*(const Scaling& lhs, const Scaling& rhs) {
        return Scaling{lhs(0, 0) * rhs(0, 0), lhs(1, 1) * rhs(1, 1)};
    }

    Vector2 getScalingVector(const Scaling& s) {
        return Vector2{s(0, 0), s(1, 1)};
    }

    Scaling invert(const Scaling& s) {
        return Scaling{1.0f / s(0, 0), 1.0f / s(1, 1)};
    }

    TransformA::TransformA(float tx, float ty, float angle) 
        : Matrix3{std::cos(angle), -std::sin(angle), tx
        , std::sin(angle), std::cos(angle), ty
        , 0.0f, 0.0f, 1.0f} {}
    
    TransformA::TransformA(const Vector2& t, float angle)
        : TransformA{t(0), t(1), angle} {}

    TransformA operator*(const Translation& lhs, const Rotation& rhs) {
        const auto translationVector{ getTranslationVector(lhs) };
        const auto angle = getAngle(rhs);

        return TransformA(translationVector, angle);
    }

    TransformA operator*(const TransformA& lhs, const Rotation& rhs) {
        const auto translationVector{getTranslationVector(lhs)};

        const auto angle1 = getAngle(lhs);
        const auto angle2 = getAngle(rhs);

        return TransformA{translationVector, angle1 + angle2};
    }

    TransformA operator*(const Translation& lhs, const TransformA& rhs) {
        const auto translationVector1{getTranslationVector(lhs)};
        const auto translationVector2{getTranslationVector(rhs)};

        const auto angle = getAngle(rhs);

        return TransformA{translationVector1 + translationVector2, angle};
    }

    Vector2 getTranslationVector(const TransformA& tA) {
        return Vector2{tA(0, 2), tA(1, 2)};
    }

    float getAngle(const TransformA& tA) {
        return std::atan2(tA(1, 1), tA(1, 2));
    }

    TransformA invert(const TransformA& tA) {
        const auto translationVector{getTranslationVector(tA)};
        const auto angle = getAngle(tA);

        const auto tx = translationVector(0);
        const auto ty = translationVector(1);

        return TransformA{-angle, 
            -tx * std::cos(angle) - ty * std::sin(angle),
            tx * std::sin(angle) - ty * std::cos(angle)};
    }

    TransformB::TransformB(float tx, float ty, float sx, float sy)
        : Matrix3{sx, 0.0f, tx
        , 0.0f, sy, ty
        , 0.0f, 0.0f, 1.0f} {}

    TransformB::TransformB(const Vector2& t, const Vector2& s)
        : TransformB{t(0), t(1), s(0), s(1)} {}

    TransformB operator*(const Translation& lhs, const Scaling& rhs) {
        const auto translationVector{getTranslationVector(lhs)};
        const auto scalingVector{getScalingVector(rhs)};

        return TransformB{translationVector, scalingVector};
    }

    TransformB operator*(const TransformB& lhs, const Scaling& rhs) {
        const auto translationVector{getTranslationVector(lhs)};
        const auto scalingVector1{getScalingVector(lhs)};
        const auto scalingVector2{getScalingVector(rhs)};

        const auto tx = translationVector(0);
        const auto ty = translationVector(1);

        const auto sx = scalingVector1(0) * scalingVector2(0);
        const auto sy = scalingVector1(1) * scalingVector2(1);
        
        return TransformB{tx, ty, sx, sy};
    }

    TransformB operator*(const Translation& lhs, const TransformB& rhs) {
        const auto translationVector1{getTranslationVector(lhs)};
        const auto translationVector2{getTranslationVector(rhs)};
        const auto ScalingVector{getScalingVector(rhs)};

        return TransformB(translationVector1 + translationVector2, ScalingVector);
    }

    Vector2 getTranslationVector(const TransformB& tB) {
        return Vector2{tB(0, 2), tB(1, 2)};
    }

    Vector2 getScalingVector(const TransformB& tB) {
        return Vector2{tB(0, 0), tB(1, 1)};
    }

    TransformB invert(const TransformB& tB) {
        const auto translationVector{getTranslationVector(tB)};
        const auto scalingVector{getScalingVector(tB)};

        const auto tx = translationVector(0);
        const auto ty = translationVector(1);

        const auto sx = scalingVector(0);
        const auto sy = scalingVector(1);

        return TransformB{-tx / sx, -ty / sy, 1.0f / sx, 1.0f / sy};
    }
}
