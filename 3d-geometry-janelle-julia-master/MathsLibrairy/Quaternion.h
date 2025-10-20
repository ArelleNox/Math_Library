#pragma once
#include <iostream>
#include <cmath>
#include "Vector3.h"

namespace ml {

    template<typename T = float>
    class Quaternion
    {
    public:
        T x, y, z, w;

        constexpr Quaternion();
        constexpr Quaternion(T x, T y, T z, T w);

        static Quaternion Identity();
        static T Dot(const Quaternion& a, const Quaternion& b);
        static T Angle(const Quaternion& a, const Quaternion& b);
        static Quaternion Lerp(const Quaternion& a, const Quaternion& b, T t);
        static Quaternion Slerp(const Quaternion& a, const Quaternion& b, T t);
        const static Quaternion FromAxisAngle( Vector3<T>& axis, T angle);
        static Quaternion AngleAxis(T angle, const Vector3<T>& axis);
        static Quaternion FromEuler(const Vector3<T>& eulerRad);

        void ToAxisAngle(Vector3<T>& outAxis, T& outAngle) const;
        Vector3<T> ToEuler() const;

        T Length() const;
        Quaternion Normalized() const;
        void Normalize();
        Quaternion Conjugate() const;
        Quaternion Inverse() const;

        Quaternion operator*(const Quaternion& rhs) const;
        Vector3<T> operator*(const Vector3<T>& v) const;
        bool operator==(const Quaternion& q) const;

        template<typename TypeToCastTo>
        explicit operator TypeToCastTo()
        {
            return TypeToCastTo{x, y, z, w};
        }

    public:
        static constexpr T kEpsilon = static_cast<T>(1e-6);
        static constexpr T PI = static_cast<T>(3.14159265358979323846);
    };

    using Quat = Quaternion<float>;

}

#include "Quaternion.inl"