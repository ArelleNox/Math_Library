#pragma once
#include <array>
#include "Vector3.h"
#include "Quaternion.h"

namespace ml
{
	template <typename T>
	class Matrix4x4{
	private:
		std::array<T, 16> m;
		
	public:
		Matrix4x4();
		Matrix4x4(const std::array<T, 16>& m);

		T& operator()(int row, int col);
		T  operator()(int row, int col) const;

		////// STATIC PROPRETIES

		static Matrix4x4 Identity(); // UT
		static Matrix4x4 Zero(); // UT


		/////PROPRETIES

		T Cofactor(int row, int col) const;
		T Determinant() const;
		Matrix4x4 Inverse() const; // UT
		Vector3<T> lossyScale();
		Quaternion<T> rotation();
		bool isIdentity() const; // UT
		T This(int i, int j) const;
		Matrix4x4 Transpose() const; // UT

		//////PUBLIC METHODS

		Vector3<T> GetColumn(int index) const;
		Vector3<T> GetRow(int index) const;
		void SetColumn(int index, const Vector3<T>& column);
		void SetRow(int index, const Vector3<T>& row);
		Vector3<T> GetPosition() const;
		Vector3<T> MultiplyPoint(const Vector3<T>& point) const;
		Vector3<T> MultiplyPoint3x4(const Vector3<T>& point) const;
		Vector3<T> MultiplyVector(const Vector3<T>& vec) const;
		void SetTRS(const Vector3<T>& position, const Quaternion<T>& rotation, const Vector3<T>& scale);
		bool ValidTRS() const;
		std::string ToString() const;

		////// STATIC METHODS
		static Matrix4x4<T> Frustum(T left, T right, T bottom, T top, T near, T far);
		static Matrix4x4<T> Inverse3DAffine(const Matrix4x4<T>& m);
		static Matrix4x4<T> LookAt(const Vector3<T>& eye, const Vector3<T>& center, const Vector3<T>& up);
		static Matrix4x4<T> Ortho(T left, T right, T bottom, T top, T near, T far); // UT
		static Matrix4x4<T> Perspective(T fovY, T aspect, T near, T far);
		static Matrix4x4<T> Rotate(const Quaternion<T>& q);
		static Matrix4x4<T> Scale(const Vector3<T>& scale); // UT
		static Matrix4x4<T> Translate(const Vector3<T>& translation); // UT
		static Matrix4x4<T> TRS(const Vector3<T>& position, const Quaternion<T>& rotation, const Vector3<T>& scale);

		///// OPERATOR
		std::array<T, 4>& operator[](int row);
		const std::array<T, 4>& operator[](int row) const;
		Matrix4x4 operator*(const Matrix4x4& rhs) const;
		bool operator==(const Matrix4x4& rhs) const;
		bool operator!=(const Matrix4x4& rhs) const;

	};
}

#include "Matrix4x4.inl"

