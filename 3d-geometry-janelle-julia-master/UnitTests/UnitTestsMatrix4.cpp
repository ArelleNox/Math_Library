#include "pch.h"
#include "CppUnitTest.h"
#include "Matrix4x4.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(UnitTests)
	{
	public:

		float const epsilon = 1e-6f; // tolérance
		TEST_METHOD(TEST_CONSTRUCTEUR)
		{
			ml::Matrix4x4<float> m = ml::Matrix4x4<float>::Identity();
			Assert::AreEqual(1.0f, m(0, 0), epsilon);
			Assert::AreEqual(0.0f, m(0, 1), epsilon);
			Assert::AreEqual(0.0f, m(0, 2), epsilon);
			Assert::AreEqual(0.0f, m(0, 3), epsilon);
			Assert::AreEqual(0.0f, m(1, 0), epsilon);
			Assert::AreEqual(1.0f, m(1, 1), epsilon);
			Assert::AreEqual(0.0f, m(1, 2), epsilon);
			Assert::AreEqual(0.0f, m(1, 3), epsilon);
			Assert::AreEqual(0.0f, m(2, 0), epsilon);
			Assert::AreEqual(0.0f, m(2, 1), epsilon);
			Assert::AreEqual(1.0f, m(2, 2), epsilon);
			Assert::AreEqual(0.0f, m(2, 3), epsilon);
			Assert::AreEqual(0.0f, m(3, 0), epsilon);
			Assert::AreEqual(0.0f, m(3, 1), epsilon);
			Assert::AreEqual(0.0f, m(3, 2), epsilon);
			Assert::AreEqual(1.0f, m(3, 3), epsilon);
		}

		TEST_METHOD(TEST_TRANSLATE)
		{
			ml::Vector3<float> translation(1.0f, 2.0f, 3.0f);
			ml::Matrix4x4<float> m = ml::Matrix4x4<float>::Identity();
			m = ml::Matrix4x4<float>::Translate(translation);
			Assert::AreEqual(1.0f, m(0, 0), epsilon);
			Assert::AreEqual(0.0f, m(0, 1), epsilon);
			Assert::AreEqual(0.0f, m(0, 2), epsilon);
			Assert::AreEqual(1.0f, m(0, 3), epsilon);
			Assert::AreEqual(0.0f, m(1, 0), epsilon);
			Assert::AreEqual(1.0f, m(1, 1), epsilon);
			Assert::AreEqual(0.0f, m(1, 2), epsilon);
			Assert::AreEqual(2.0f, m(1, 3), epsilon);
			Assert::AreEqual(0.0f, m(2, 0), epsilon);
			Assert::AreEqual(0.0f, m(2, 1), epsilon);
			Assert::AreEqual(1.0f, m(2, 2), epsilon);
			Assert::AreEqual(3.0f, m(2, 3), epsilon);
			Assert::AreEqual(0.0f, m(3, 0), epsilon);
			Assert::AreEqual(0.0f, m(3, 1), epsilon);
			Assert::AreEqual(0.0f, m(3, 2), epsilon);
			Assert::AreEqual(1.0f, m(3, 3), epsilon);
		}

		TEST_METHOD(TEST_SCALE)
		{
			ml::Vector3<float> scale(2.0f, 3.0f, 4.0f);
			ml::Matrix4x4<float> m = ml::Matrix4x4<float>::Identity();
			m = ml::Matrix4x4<float>::Scale(scale);
			Assert::AreEqual(2.0f, m(0, 0), epsilon);
			Assert::AreEqual(0.0f, m(0, 1), epsilon);
			Assert::AreEqual(0.0f, m(0, 2), epsilon);
			Assert::AreEqual(0.0f, m(0, 3), epsilon);
			Assert::AreEqual(0.0f, m(1, 0), epsilon);
			Assert::AreEqual(3.0f, m(1, 1), epsilon);
			Assert::AreEqual(0.0f, m(1, 2), epsilon);
			Assert::AreEqual(0.0f, m(1, 3), epsilon);
			Assert::AreEqual(0.0f, m(2, 0), epsilon);
			Assert::AreEqual(0.0f, m(2, 1), epsilon);
			Assert::AreEqual(4.0f, m(2, 2), epsilon);
			Assert::AreEqual(0.0f, m(2, 3), epsilon);
			Assert::AreEqual(0.0f, m(3, 0), epsilon);
			Assert::AreEqual(0.0f, m(3, 1), epsilon);
			Assert::AreEqual(0.0f, m(3, 2), epsilon);
			Assert::AreEqual(1.0f, m(3, 3), epsilon);
		}

		TEST_METHOD(TEST_INVERSE) {
			ml::Matrix4x4<float> m = ml::Matrix4x4<float>::Identity();
			m = ml::Matrix4x4<float>::Translate(ml::Vector3<float>(1.0f, 2.0f, 3.0f));
			ml::Matrix4x4<float> inv = m.Inverse();
			Assert::AreEqual(1.0f, inv(0, 0), epsilon);
			Assert::AreEqual(0.0f, inv(0, 1), epsilon);
			Assert::AreEqual(0.0f, inv(0, 2), epsilon);
			Assert::AreEqual(-1.0f, inv(0, 3), epsilon);
			Assert::AreEqual(0.0f, inv(1, 0), epsilon);
			Assert::AreEqual(1.0f, inv(1, 1), epsilon);
			Assert::AreEqual(0.0f, inv(1, 2), epsilon);
			Assert::AreEqual(-2.0f, inv(1, 3), epsilon);
			Assert::AreEqual(0.0f, inv(2, 0), epsilon);
			Assert::AreEqual(0.0f, inv(2, 1), epsilon);
			Assert::AreEqual(1.0f, inv(2, 2), epsilon);
			Assert::AreEqual(-3.0f, inv(2, 3), epsilon);
			Assert::AreEqual(0.0f, inv(3, 0), epsilon);
			Assert::AreEqual(0.0f, inv(3, 1), epsilon);
			Assert::AreEqual(0.0f, inv(3, 2), epsilon);
			Assert::AreEqual(1.0f, inv(3, 3), epsilon);
		}

		TEST_METHOD(TEST_ORTHO) {
			ml::Matrix4x4<float> m = ml::Matrix4x4<float>::Identity();
			m = ml::Matrix4x4<float>::Ortho(-1.0f, 1.0f, -1.0f, 1.0f, 0.1f, 100.0f);
			Assert::AreEqual(1.0f, m(0, 0), epsilon);
			Assert::AreEqual(0.0f, m(0, 1), epsilon);
			Assert::AreEqual(0.0f, m(0, 2), epsilon);
			Assert::AreEqual(0.0f, m(0, 3), epsilon);
			Assert::AreEqual(0.0f, m(1, 0), epsilon);
			Assert::AreEqual(1.0f, m(1, 1), epsilon);
			Assert::AreEqual(0.0f, m(1, 2), epsilon);
			Assert::AreEqual(0.0f, m(1, 3), epsilon);
			Assert::AreEqual(0.0f, m(2, 0), epsilon);
			Assert::AreEqual(0.0f, m(2, 1), epsilon);
			Assert::AreEqual(-0.02002002f, m(2, 2), epsilon);
			Assert::AreEqual(-1.002002f, m(2, 3), epsilon);
			Assert::AreEqual(0.0f, m(3, 0), epsilon);
			Assert::AreEqual(0.0f, m(3, 1), epsilon);
			Assert::AreEqual(0.0f, m(3, 2), epsilon);
			Assert::AreEqual(1.0f, m(3, 3), epsilon);
		}

		TEST_METHOD(TEST_COFACTEUR) {
			ml::Matrix4x4<float> m({ 1, 2, 3, 4,
									 5, 6, 7, 8,
									 9,10,11,12,
									 13,14,15,16 });
			float cofactor = m.Cofactor(0, 0);
			Assert::AreEqual(0.0f, cofactor, epsilon);
			cofactor = m.Cofactor(1, 1);
			Assert::AreEqual(0.0f, cofactor, epsilon);
			cofactor = m.Cofactor(2, 2);
			Assert::AreEqual(0.0f, cofactor, epsilon);
			cofactor = m.Cofactor(3, 3);
			Assert::AreEqual(0.0f, cofactor, epsilon);
		}

		TEST_METHOD(TEST_DETERMINANT) {
			ml::Matrix4x4<float> m({ 1, 2, 3, 4,
									 5, 6, 7, 8,
									 9,10,11,12,
									 13,14,15,16 });
			float det = m.Determinant();
			Assert::AreEqual(0.0f, det, epsilon);
		}

		TEST_METHOD(TEST_LOSSYSCALE) {
			ml::Matrix4x4<float> m = ml::Matrix4x4<float>::Identity();
			m = ml::Matrix4x4<float>::Scale(ml::Vector3<float>(2.0f, 3.0f, 4.0f));
			ml::Vector3<float> scale = m.lossyScale();
			Assert::AreEqual(2.0f, scale.x, epsilon);
			Assert::AreEqual(3.0f, scale.y, epsilon);
			Assert::AreEqual(4.0f, scale.z, epsilon);
		}

		TEST_METHOD(TEST_ROTATION) {
			ml::Quaternion<float> q(0.0f, 0.0f, std::sin(3.14159265f / 4), std::cos(3.14159265f / 4)); // 90 degrees around Z
			ml::Matrix4x4<float> m = ml::Matrix4x4<float>::Rotate(q);
			ml::Quaternion<float> q2 = m.rotation();
			Assert::AreEqual(q.x, q2.x, epsilon);
			Assert::AreEqual(q.y, q2.y, epsilon);
			Assert::AreEqual(q.z, q2.z, epsilon);
			Assert::AreEqual(q.w, q2.w, epsilon);
		}

		TEST_METHOD(TEST_ROTATE) {
			ml::Quaternion<float> q(0.0f, 0.0f, std::sin(3.14159265f / 4), std::cos(3.14159265f / 4)); // 90 degrees around Z
			ml::Matrix4x4<float> m = ml::Matrix4x4<float>::Rotate(q);
			Assert::AreEqual(0.0f, m(0, 0), epsilon);
			Assert::AreEqual(-1.0f, m(0, 1), epsilon);
			Assert::AreEqual(0.0f, m(0, 2), epsilon);
			Assert::AreEqual(0.0f, m(0, 3), epsilon);
			Assert::AreEqual(1.0f, m(1, 0), epsilon);
			Assert::AreEqual(0.0f, m(1, 1), epsilon);
			Assert::AreEqual(0.0f, m(1, 2), epsilon);
			Assert::AreEqual(0.0f, m(1, 3), epsilon);
			Assert::AreEqual(0.0f, m(2, 0), epsilon);
			Assert::AreEqual(0.0f, m(2, 1), epsilon);
			Assert::AreEqual(1.0f, m(2, 2), epsilon);
			Assert::AreEqual(0.0f, m(2, 3), epsilon);
			Assert::AreEqual(0.0f, m(3, 0), epsilon);
			Assert::AreEqual(0.0f, m(3, 1), epsilon);
			Assert::AreEqual(0.0f, m(3, 2), epsilon);
			Assert::AreEqual(1.0f, m(3, 3), epsilon);
		}

		TEST_METHOD(TEST_FRUSTRUM) {
			ml::Matrix4x4<float> m = ml::Matrix4x4<float>::Frustum(-1.0f, 1.0f, -1.0f, 1.0f, 0.1f, 100.0f);
			Assert::AreEqual(0.1f, m(0, 0), epsilon);
			Assert::AreEqual(0.0f, m(0, 1), epsilon);
			Assert::AreEqual(0.0f, m(0, 2), epsilon);
			Assert::AreEqual(0.0f, m(0, 3), epsilon);
			Assert::AreEqual(0.0f, m(1, 0), epsilon);
			Assert::AreEqual(0.1f, m(1, 1), epsilon);
			Assert::AreEqual(0.0f, m(1, 2), epsilon);
			Assert::AreEqual(0.0f, m(1, 3), epsilon);
			Assert::AreEqual(0.0f, m(2, 0), epsilon);
			Assert::AreEqual(0.0f, m(2, 1), epsilon);
			Assert::AreEqual(-1.002002f, m(2, 2), epsilon);
			Assert::AreEqual(-0.2002002f, m(2, 3), epsilon);
			Assert::AreEqual(0.0f, m(3, 0), epsilon);
			Assert::AreEqual(0.0f, m(3, 1), epsilon);
			Assert::AreEqual(-1.0f, m(3, 2), epsilon);
			Assert::AreEqual(0.0f, m(3, 3), epsilon);
		}

		TEST_METHOD(TEST_TRS) {
			ml::Vector3<float> position(1.0f, 2.0f, 3.0f);
			ml::Quaternion<float> rotation(0.0f, 0.0f, std::sin(3.14159265f / 4), std::cos(3.14159265f / 4)); // 90 degrees around Z
			ml::Vector3<float> scale(2.0f, 3.0f, 4.0f);
			ml::Matrix4x4<float> m = ml::Matrix4x4<float>::TRS(position, rotation, scale);
			Assert::AreEqual(0.0f, m(0, 0), epsilon);
			Assert::AreEqual(-3.0f, m(0, 1), epsilon);
			Assert::AreEqual(0.0f, m(0, 2), epsilon);
			Assert::AreEqual(1.0f, m(0, 3), epsilon);
			Assert::AreEqual(2.0f, m(1, 0), epsilon);
			Assert::AreEqual(0.0f, m(1, 1), epsilon);
			Assert::AreEqual(0.0f, m(1, 2), epsilon);
			Assert::AreEqual(2.0f, m(1, 3), epsilon);
			Assert::AreEqual(0.0f, m(2, 0), epsilon);
			Assert::AreEqual(0.0f, m(2, 1), epsilon);
			Assert::AreEqual(4.0f, m(2, 2), epsilon);
			Assert::AreEqual(3.0f, m(2, 3), epsilon);
		}

		TEST_METHOD(TEST_LOOKAT) {
			ml::Vector3<float> eye(0.0f, 0.0f, 0.0f);
			ml::Vector3<float> center(0.0f, 0.0f, -1.0f);
			ml::Vector3<float> up(0.0f, 1.0f, 0.0f);
			ml::Matrix4x4<float> m = ml::Matrix4x4<float>::LookAt(eye, center, up);
			Assert::AreEqual(1.0f, m(0, 0), epsilon);
			Assert::AreEqual(0.0f, m(0, 1), epsilon);
			Assert::AreEqual(0.0f, m(0, 2), epsilon);
			Assert::AreEqual(0.0f, m(0, 3), epsilon);
			Assert::AreEqual(0.0f, m(1, 0), epsilon);
			Assert::AreEqual(1.0f, m(1, 1), epsilon);
			Assert::AreEqual(0.0f, m(1, 2), epsilon);
			Assert::AreEqual(0.0f, m(1, 3), epsilon);
			Assert::AreEqual(0.0f, m(2, 0), epsilon);
			Assert::AreEqual(0.0f, m(2, 1), epsilon);
			Assert::AreEqual(1.0f, m(2, 2), epsilon);
			Assert::AreEqual(0.0f, m(2, 3), epsilon);
			Assert::AreEqual(0.0f, m(3, 0), epsilon);
			Assert::AreEqual(0.0f, m(3, 1), epsilon);
			Assert::AreEqual(0.0f, m(3, 2), epsilon);
			Assert::AreEqual(1.0f, m(3, 3), epsilon);
		}

		TEST_METHOD(TEST_PERSPECTIVE) { ///////// franchement j'ai pas d'explication
			ml::Matrix4x4<float> m = ml::Matrix4x4<float>::Perspective(90.0f, 1.0f, 0.1f, 100.0f);
			Assert::AreEqual(1.0f, m(0, 0), epsilon);
			Assert::AreEqual(0.0f, m(0, 1), epsilon);
			Assert::AreEqual(0.0f, m(0, 2), epsilon);
			Assert::AreEqual(0.0f, m(0, 3), epsilon);
			Assert::AreEqual(0.0f, m(1, 0), epsilon);
			Assert::AreEqual(1.0f, m(1, 1), epsilon);
			Assert::AreEqual(0.0f, m(1, 2), epsilon);
			Assert::AreEqual(0.0f, m(1, 3), epsilon);
			Assert::AreEqual(0.0f, m(2, 0), epsilon);
			Assert::AreEqual(0.0f, m(2, 1), epsilon);
			Assert::AreEqual(-1.002002f, m(2, 2), epsilon);
			Assert::AreEqual(-0.2002002f, m(2, 3), epsilon);
			Assert::AreEqual(0.0f, m(3, 0), epsilon);
			Assert::AreEqual(0.0f, m(3, 1), epsilon);
			Assert::AreEqual(-1.0f, m(3, 2), epsilon);
			Assert::AreEqual(0.0f, m(3, 3), epsilon);
		}

		TEST_METHOD(TEST_MULTIPLYPOINT) {
			ml::Matrix4x4<float> m = ml::Matrix4x4<float>::Identity();
			m = ml::Matrix4x4<float>::Translate(ml::Vector3<float>(1.0f, 2.0f, 3.0f));
			ml::Vector3<float> v(1.0f, 1.0f, 1.0f);
			ml::Vector3<float> result = m.MultiplyPoint(v);
			Assert::AreEqual(2.0f, result.x, epsilon);
			Assert::AreEqual(3.0f, result.y, epsilon);
			Assert::AreEqual(4.0f, result.z, epsilon);
		}

		TEST_METHOD(TEST_MULTYPOINT3x4) {
			ml::Matrix4x4<float> m = ml::Matrix4x4<float>::Identity();
			m = ml::Matrix4x4<float>::Translate(ml::Vector3<float>(1.0f, 2.0f, 3.0f));
			ml::Vector3<float> v(1.0f, 1.0f, 1.0f);
			ml::Vector3<float> result = m.MultiplyPoint3x4(v);
			Assert::AreEqual(2.0f, result.x, epsilon);
			Assert::AreEqual(3.0f, result.y, epsilon);
			Assert::AreEqual(4.0f, result.z, epsilon);
		}

		TEST_METHOD(TEST_MULTIPLYVECTOR) {
			ml::Matrix4x4<float> m = ml::Matrix4x4<float>::Identity();
			m = ml::Matrix4x4<float>::Scale(ml::Vector3<float>(2.0f, 3.0f, 4.0f));
			ml::Vector3<float> v(1.0f, 1.0f, 1.0f);
			ml::Vector3<float> result = m.MultiplyVector(v);
			Assert::AreEqual(2.0f, result.x, epsilon);
			Assert::AreEqual(3.0f, result.y, epsilon);
			Assert::AreEqual(4.0f, result.z, epsilon);
		}

	};
}