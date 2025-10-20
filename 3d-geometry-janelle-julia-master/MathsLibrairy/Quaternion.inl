#pragma once
#include <cmath>

namespace ml {

    template<typename T>
	inline T clampValue(T v, T minVal, T maxVal) { // clamp v entre minVal et maxVal
        return (v < minVal) ? minVal : (v > maxVal ? maxVal : v);
    }

    template<typename T>
	inline T minValue(T a, T b) { // renvoie la plus petite des deux valeurs
        return (a < b) ? a : b;
    }

    template<typename T>
	inline T absValue(T v) { // renvoie la valeur absolue
        return (v < static_cast<T>(0)) ? -v : v;
    }

    template<typename T>
	constexpr Quaternion<T>::Quaternion() : x(0), y(0), z(0), w(1) {} // Constructeur par défaut

    template<typename T>
	constexpr Quaternion<T>::Quaternion(T x, T y, T z, T w) : x(x), y(y), z(z), w(w) {} // Constructeur avec paramètres

    template<typename T>
	Quaternion<T> Quaternion<T>::Identity() { // Renvoie le quaternion identité
        return Quaternion<T>(0, 0, 0, 1);
    }

    template<typename T>
	T Quaternion<T>::Length() const { // Renvoie la norme du quaternion
        return static_cast<T>(std::sqrt(x * x + y * y + z * z + w * w));
    }

    template<typename T>
    Quaternion<T> Quaternion<T>::Normalized() const {
        T len = Length();
        if (len < kEpsilon) return Quaternion<T>::Identity();
        return Quaternion<T>(x / len, y / len, z / len, w / len);
    }

    template<typename T>
	void Quaternion<T>::Normalize() { // Normalise le quaternion 
        T len = Length();
        if (len < kEpsilon) { *this = Identity(); return; }
        x /= len; y /= len; z /= len; w /= len;
    }

    template<typename T>
	Quaternion<T> Quaternion<T>::Conjugate() const { // Renvoie le conjugué du quaternion : negatif
        return Quaternion<T>(-x, -y, -z, w);
    }

    template<typename T>
	Quaternion<T> Quaternion<T>::Inverse() const { // Renvoie l'inverse du quaternion

        Quaternion<T> n = this->Normalized();
        return n.Conjugate();
    }

    template<typename T>
	T Quaternion<T>::Dot(const Quaternion<T>& a, const Quaternion<T>& b) { // Produit scalaire entre deux quaternions
        return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
    }

    template<typename T>
	T Quaternion<T>::Angle(const Quaternion<T>& a, const Quaternion<T>& b) { // Renvoie l'angle entre deux quaternions en radians
        T d = absValue(Dot(a.Normalized(), b.Normalized()));
        d = minValue(d, static_cast<T>(1));
        return static_cast<T>(2) * std::acos(d);
    }

    template<typename T>
	const Quaternion<T> Quaternion<T>::FromAxisAngle(Vector3<T>& axis, T angle) { // Renvoie un quaternion à partir d'un axe et d'un angle en radians
        Vector3<T> n = axis.Normalized();
        T half = angle / static_cast<T>(2);
        T s = std::sin(half);
        return Quaternion<T>(n.x * s, n.y * s, n.z * s, std::cos(half));
    }

    template<typename T>
	Quaternion<T> Quaternion<T>::AngleAxis(T angle, const Vector3<T>& axis) { // Renvoie un quaternion à partir d'un axe et d'un angle en radians
        return FromAxisAngle(axis, angle);
    }

    template<typename T>
	void Quaternion<T>::ToAxisAngle(Vector3<T>& outAxis, T& outAngle) const { // Renvoie un axe et un angle en radians à partir d'un quaternion
        Quaternion<T> qn = Normalized();
        outAngle = static_cast<T>(2) * std::acos(qn.w);
        T s = std::sqrt(1 - qn.w * qn.w);
        if (s < kEpsilon)
            outAxis = Vector3<T>(1, 0, 0);
        else
            outAxis = Vector3<T>(qn.x / s, qn.y / s, qn.z / s);
    }

    template<typename T>
	Quaternion<T> Quaternion<T>::FromEuler(const Vector3<T>& eulerRad) { // Renvoie un quaternion à partir d'angles d'Euler en radians
        T cx = std::cos(eulerRad.x / 2);
        T sx = std::sin(eulerRad.x / 2);
        T cy = std::cos(eulerRad.y / 2);
        T sy = std::sin(eulerRad.y / 2);
        T cz = std::cos(eulerRad.z / 2);
        T sz = std::sin(eulerRad.z / 2);

        T qw = cy * cz * cx + sy * sz * sx;
        T qx = cy * cz * sx - sy * sz * cx;
        T qy = sy * cz * sx + cy * sz * cx;
        T qz = sy * cz * cx - cy * sz * sx;

        return Quaternion<T>(qx, qy, qz, qw);
    }

    template<typename T>
	Vector3<T> Quaternion<T>::ToEuler() const { // Renvoie des angles d'Euler en radians à partir d'un quaternion
        Quaternion<T> qn = Normalized();

        T sinr_cosp = static_cast<T>(2) * (qn.w * qn.x + qn.y * qn.z);
        T cosr_cosp = static_cast<T>(1) - static_cast<T>(2) * (qn.x * qn.x + qn.y * qn.y);
        T roll = std::atan2(sinr_cosp, cosr_cosp);

        T sinp = static_cast<T>(2) * (qn.w * qn.y - qn.z * qn.x);
        T pitch = (absValue(sinp) >= 1)
            ? std::copysign(PI / 2, sinp)
            : std::asin(sinp);

        T siny_cosp = static_cast<T>(2) * (qn.w * qn.z + qn.x * qn.y);
        T cosy_cosp = static_cast<T>(1) - static_cast<T>(2) * (qn.y * qn.y + qn.z * qn.z);
        T yaw = std::atan2(siny_cosp, cosy_cosp);

        return Vector3<T>(pitch, yaw, roll);
    }


	/// //OPERATEUR  //////// OVERLOAD les operteurs existants pour les appliquer a nos quaternions

    template<typename T>
    Quaternion<T> Quaternion<T>::operator*(const Quaternion<T>& rhs) const {
        return Quaternion<T>(
            w * rhs.x + x * rhs.w + y * rhs.z - z * rhs.y,
            w * rhs.y - x * rhs.z + y * rhs.w + z * rhs.x,
            w * rhs.z + x * rhs.y - y * rhs.x + z * rhs.w,
            w * rhs.w - x * rhs.x - y * rhs.y - z * rhs.z
        );
    }

    template<typename T>
    Vector3<T> Quaternion<T>::operator*(const Vector3<T>& v) const {
        Vector3<T> qv(x, y, z);
        Vector3<T> t = qv.cross(v) * static_cast<T>(2);
        return v + t * w + qv.cross(t);
    }

    template<typename T>
    bool Quaternion<T>::operator==(const Quaternion<T>& q) const {
        return x == q.x && y == q.y && z == q.z && w == q.w;
    }

    template<typename T>
	Quaternion<T> Quaternion<T>::Lerp(const Quaternion<T>& a, const Quaternion<T>& b, T t) {  // Renvoie une interpolation linéaire entre deux quaternions
        t = clampValue(t, static_cast<T>(0), static_cast<T>(1));
        Quaternion<T> r(
            a.x + (b.x - a.x) * t,
            a.y + (b.y - a.y) * t,
            a.z + (b.z - a.z) * t,
            a.w + (b.w - a.w) * t
        );
        return r.Normalized();
    }

    template<typename T>
	Quaternion<T> Quaternion<T>::Slerp(const Quaternion<T>& a, const Quaternion<T>& b, T t) { // Renvoie une interpolation sphérique entre deux quaternions
        t = clampValue(t, static_cast<T>(0), static_cast<T>(1));
        T dot = Dot(a, b);
        dot = clampValue(dot, static_cast<T>(-1), static_cast<T>(1));

        const T DOT_THRESHOLD = static_cast<T>(0.9995);
        if (absValue(dot) > DOT_THRESHOLD)
            return Lerp(a, b, t);

        T theta_0 = std::acos(dot);
        T theta = theta_0 * t;

        T s0 = std::cos(theta) - dot * std::sin(theta) / std::sin(theta_0);
        T s1 = std::sin(theta) / std::sin(theta_0);

        Quaternion<T> result(
            a.x * s0 + b.x * s1,
            a.y * s0 + b.y * s1,
            a.z * s0 + b.z * s1,
            a.w * s0 + b.w * s1
        );
        return result.Normalized();
    };

}
