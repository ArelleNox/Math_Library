#pragma once
#include <iostream>
#include <string>
#include "Vector3.h"

namespace ml {

	template <typename T>
	class Vector2{
	private:
		T x;
		T y;

	public:
		/// CONSTRUCTOR
		Vector2();
		Vector2(T x, T y);

		/// STATIC_PORPRETIES
		Vector2 Down();
		Vector2 Up();
		Vector2 Left();
		Vector2 Right();
		Vector2 One();
		Vector2 Zero();
		Vector2 PositiveInfinity();
		Vector2 NegativeInfinity();

		///PROPERTIES
		T Magnitude(); // UT
		Vector2 Normalized(); // UT
		T SqrtMagnitude(); // UT
		T This(int i); // UT
		T X() const; // UT
		T Y() const; // UT

		///PUBLIC METHODS
		bool Equal(Vector2 other); // UT
		void Normalize(); // UT
		void Set(T newX, T newY); // UT
		std::string ToString(); // UT

		/// STATIC METHODS
		static T Angle(Vector2 a, Vector2 b); // UT
		static Vector2 ClampMagnitude(Vector2& a, T MaxLenght); // UT
		static T Distance(Vector2& a, Vector2& b); // UT
		static T Dot(Vector2& a, Vector2& b); // UT
		static Vector2 Lerp(Vector2 a, Vector2 b, T t); // UT
		static Vector2 LerpUnclamped(Vector2 a, Vector2 b, T t); // UT
		static Vector2 Min(Vector2& a, Vector2& b); // UT
		static Vector2 Max(Vector2& a, Vector2& b); // UT
		static Vector2 MoveTowards(Vector2 current, Vector2 target, T maxDistanceDelta); // UT
		static Vector2 Perpendicular(Vector2 inDirection); // UT
		static Vector2 Scale(Vector2& a, Vector2& b);// UT
		static T SignedAngle(Vector2 from, Vector2 to); // UT
		
		// CONVERSIONS

		Vector3<T> ToVector3() const;
		static Vector2<T> ToVector2(Vector3<T>& vec);

		///OPERATOR

		Vector2 operator-(const Vector2& other) const;
		Vector2 operator+(const Vector2& other) const;
		Vector2 operator*(const Vector2& other) const;
		Vector2 operator*(T scalar) const;
		Vector2 operator/(const Vector2& other) const;
		Vector2 operator/(T scalar) const;

		bool operator==(const Vector2& other) const;
		bool operator!=(const Vector2& other) const;

		template<typename TypeToCastTo>
		explicit operator TypeToCastTo()
		{
			return TypeToCastTo{ x, y };
		}
	};

	typedef Vector2<float> Vector2f;
}

#include "Vector2.inl"