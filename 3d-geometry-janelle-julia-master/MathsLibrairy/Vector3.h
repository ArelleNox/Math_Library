#pragma once

#include <iostream>
#include <string>

namespace ml{

	template <typename T>

	class Vector3 {
	public:

		T x;
		T y;
		T z;

	public:
		Vector3();

		Vector3(T x, T y, T z);

		///// STATIC_PORPRETIES

		static Vector3 Down();
		static Vector3 Up();
		static Vector3 Right();
		static Vector3 Left();
		static Vector3 Back();
		static Vector3 Foward();
		static Vector3 One();
		static Vector3 Zero();
		static Vector3 negativeInfinity();
		static Vector3 positiveInfinity();

		/////PORPRETIES

		Vector3 Normalized(); // UT
		T Magnitude(); // UT
		T SqrMagnitude(); // UT
		T This(int i); // UT
		T X(); // UT
		T Y(); // UT
		T Z(); // UT

		///// PUBLIC METHODS

		bool Equals(Vector3& other); // UT
		void Set(T newX, T newY, T newZ); // UT
		std::string ToString(); // UT
		void Normalize(); // UT

		/////// STATIC METHODS

		static T Angle(Vector3 a, Vector3 b); // UT
		static Vector3 ClampMagnitude(Vector3& a, T MaxLenght); // UT
		static Vector3 Cross(Vector3& a, Vector3& b); // UT
		static T Distance(Vector3& a, Vector3& b); // UT
		static T Dot(Vector3& a, Vector3& b); // UT
		static Vector3 Lerp(Vector3 a, Vector3 b, T t); // UT
		static Vector3 LerpUnclamped(Vector3 a, Vector3 b, T t); // UT
		static Vector3 Min(Vector3& a, Vector3& b); // UT
		static Vector3 Max(Vector3& a, Vector3& b); // UT
		static Vector3 MoveTowards(Vector3 current, Vector3 target, T maxDistanceDelta); // UT
		static void OrthoNormalize(Vector3& normal, Vector3& tangent); // UT
		static Vector3 Project(Vector3 vector, Vector3 onNormal); // UT
		static Vector3 ProjectOnPlane(Vector3 vector, Vector3 planeNormal); // UT
		static Vector3 Reflect(Vector3 inDirection, Vector3 inNormal);	// UT
		static Vector3 RotateTowards(Vector3 current, Vector3 target, T maxRadiansDelta, T maxMagnitudeDelta); // UT
		static Vector3 Scale(Vector3& a, Vector3& b); // UT
		static T SignedAngle(Vector3 from, Vector3 to, Vector3 axis); // UT
		static Vector3 Slerp(Vector3 a, Vector3 b, T t); // UT
		static Vector3 SlerpUnclamped(Vector3 a, Vector3 b, T t); // UT


		/////////OPERATOR

		Vector3 operator-(const Vector3& other) const;
		Vector3 operator+(const Vector3& other) const;
		Vector3 operator*(const Vector3& other) const;
		Vector3 operator*(T scalar) const;
		Vector3 operator/(const Vector3& other) const;
		Vector3 operator/(T scalar) const;
		bool operator==(const Vector3& other) const;
		bool operator!=(const Vector3& other) const;

		template<typename TypeToCastTo>
		explicit operator TypeToCastTo()
		{
			return TypeToCastTo{x, y, z};
		}
	};
}

#include "Vector3.inl"
