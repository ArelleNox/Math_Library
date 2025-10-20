#include "pch.h"
#include "CppUnitTest.h"
#include "Vector3.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(UnitTests)
	{
	public:
		const float epsilon = 1e-6f; // tolérance
		TEST_METHOD(TEST_CONSTRUCTEUR)
		{
			ml::Vector3<float> Vec3(1.0f, 2.0f, 3.0f);
			Assert::AreEqual(Vec3.X(), 1.0f);
			Assert::AreEqual(Vec3.Y(), 2.0f);
			Assert::AreEqual(Vec3.Z(), 3.0f);
		}
		TEST_METHOD(TEST_ADD)
		{
			ml::Vector3<float> Vec3A(1.0f, 2.0f, 3.0f);
			ml::Vector3<float> Vec3B(4.0f, 5.0f, 6.0f);
			ml::Vector3<float> Vec3C = Vec3A + Vec3B;
			Assert::AreEqual(Vec3C.X(), 5.0f);
			Assert::AreEqual(Vec3C.Y(), 7.0f);
			Assert::AreEqual(Vec3C.Z(), 9.0f);
		}
		TEST_METHOD(TEST_SUB)
		{
			ml::Vector3<float> Vec3A(1.0f, 2.0f, 3.0f);
			ml::Vector3<float> Vec3B(4.0f, 5.0f, 6.0f);
			ml::Vector3<float> Vec3C = Vec3A - Vec3B;
			Assert::AreEqual(Vec3C.X(), -3.0f);
			Assert::AreEqual(Vec3C.Y(), -3.0f);
			Assert::AreEqual(Vec3C.Z(), -3.0f);
		}
		TEST_METHOD(TEST_MUL)
		{
			ml::Vector3<float> Vec3A(1.0f, 2.0f, 3.0f);
			ml::Vector3<float> Vec3B(4.0f, 5.0f, 6.0f);
			ml::Vector3<float> Vec3C = Vec3A * Vec3B;
			Assert::AreEqual(Vec3C.X(), 4.0f);
			Assert::AreEqual(Vec3C.Y(), 10.0f);
			Assert::AreEqual(Vec3C.Z(), 18.0f);
		}

		TEST_METHOD(TEST_DIV)
		{
			ml::Vector3<float> Vec3A(1.0f, 2.0f, 3.0f);
			ml::Vector3<float> Vec3B(4.0f, 5.0f, 6.0f);
			ml::Vector3<float> Vec3C = Vec3A / Vec3B;
			Assert::AreEqual(Vec3C.X(), 1.0f / 4.0f);
			Assert::AreEqual(Vec3C.Y(), 2.0f / 5.0f);
			Assert::AreEqual(Vec3C.Z(), 0.5f);
		}

		TEST_METHOD(TEST_DOT)
		{
			ml::Vector3<float> Vec3A(1.0f, 2.0f, 3.0f);
			ml::Vector3<float> Vec3B(4.0f, 5.0f, 6.0f);
			float Dot = ml::Vector3<float>::Dot(Vec3A, Vec3B);
			Assert::AreEqual(Dot, 32.0f);
		}

		TEST_METHOD(TEST_MAGNITUDE)
		{
			ml::Vector3<float> Vec3A(1.0f, 2.0f, 2.0f);
			float Magnitude = Vec3A.Magnitude();
			Assert::AreEqual(Magnitude, 3.0f);
		}

		TEST_METHOD(TEST_SQRMAGNITUDE)
		{
			ml::Vector3<float> Vec3A(1.0f, 2.0f, 2.0f);
			float SqrMagnitude = Vec3A.SqrMagnitude();
			Assert::AreEqual(SqrMagnitude, 9.0f);
		}

		TEST_METHOD(TEST_ANGLE)
		{
			ml::Vector3<float> Vec3A(1.0f, 0.0f, 0.0f);
			ml::Vector3<float> Vec3B(0.0f, 1.0f, 0.0f);
			float Angle = ml::Vector3<float>::Angle(Vec3A, Vec3B);
			Assert::AreEqual(Angle, 1.570796f, epsilon); // Pi/2
		}

		TEST_METHOD(TEST_CROSS)
		{
			ml::Vector3<float> Vec3A(1.0f, 0.0f, 0.0f);
			ml::Vector3<float> Vec3B(0.0f, 1.0f, 0.0f);
			ml::Vector3<float> Vec3C = ml::Vector3<float>::Cross(Vec3A, Vec3B);
			Assert::AreEqual(Vec3C.X(), 0.0f);
			Assert::AreEqual(Vec3C.Y(), 0.0f);
			Assert::AreEqual(Vec3C.Z(), 1.0f);
		}

		TEST_METHOD(TEST_NORMALIZEZ)
		{
			ml::Vector3<float> Vec3A(1.0f, 2.0f, 2.0f);
			ml::Vector3<float> Vec3B = Vec3A.Normalized();
			Assert::AreEqual(Vec3B.X(), 1.0f / 3.0f);
			Assert::AreEqual(Vec3B.Y(), 2.0f / 3.0f);
			Assert::AreEqual(Vec3B.Z(), 2.0f / 3.0f);
		}

		TEST_METHOD(TEST_EQUAL)
		{
			ml::Vector3<float> Vec3A(1.0f, 2.0f, 3.0f);
			ml::Vector3<float> Vec3B(1.0f, 2.0f, 3.0f);
			ml::Vector3<float> Vec3C(4.0f, 5.0f, 6.0f);
			Assert::IsTrue(Vec3A.Equals(Vec3B));
			Assert::IsFalse(Vec3A.Equals(Vec3C));
		}

		TEST_METHOD(TEST_TOSTRING)
		{
			ml::Vector3<float> Vec3A(1.0f, 2.0f, 3.0f);
			std::string Str = Vec3A.ToString();
			Assert::AreEqual(Str, std::string("(1.000000, 2.000000, 3.000000)"));
		}

		TEST_METHOD(TEST_LERP)
		{
			ml::Vector3<float> Vec3A(1.0f, 2.0f, 3.0f);
			ml::Vector3<float> Vec3B(4.0f, 5.0f, 6.0f);
			ml::Vector3<float> Vec3C = ml::Vector3<float>::Lerp(Vec3A, Vec3B, 0.5f);
			Assert::AreEqual(Vec3C.X(), 2.5f);
			Assert::AreEqual(Vec3C.Y(), 3.5f);
			Assert::AreEqual(Vec3C.Z(), 4.5f);
		}

		TEST_METHOD(TEST_LERPUNCLAMPED)
		{
			ml::Vector3<float> Vec3A(1.0f, 2.0f, 3.0f);
			ml::Vector3<float> Vec3B(4.0f, 5.0f, 6.0f);
			ml::Vector3<float> Vec3C = ml::Vector3<float>::LerpUnclamped(Vec3A, Vec3B, 1.5f);
			Assert::AreEqual(Vec3C.X(), 5.5f);
			Assert::AreEqual(Vec3C.Y(), 6.5f);
			Assert::AreEqual(Vec3C.Z(), 7.5f);
		}

		TEST_METHOD(TEST_CLAMPMAGNITUDE)
		{
			ml::Vector3<float> Vec3A(3.0f, 4.0f, 0.0f);
			ml::Vector3<float> Vec3B = ml::Vector3<float>::ClampMagnitude(Vec3A, 5.0f);
			Assert::AreEqual(Vec3B.X(), 3.0f);
			Assert::AreEqual(Vec3B.Y(), 4.0f);
			Assert::AreEqual(Vec3B.Z(), 0.0f);
			ml::Vector3<float> Vec3C = ml::Vector3<float>::ClampMagnitude(Vec3A, 4.0f);
			Assert::AreEqual(Vec3C.X(), 2.4f);
			Assert::AreEqual(Vec3C.Y(), 3.2f);
			Assert::AreEqual(Vec3C.Z(), 0.0f);
		}

		TEST_METHOD(TEST_SET)
		{
			ml::Vector3<float> Vec3A(1.0f, 2.0f, 3.0f);
			Vec3A.Set(4.0f, 5.0f, 6.0f);
			Assert::AreEqual(Vec3A.X(), 4.0f);
			Assert::AreEqual(Vec3A.Y(), 5.0f);
			Assert::AreEqual(Vec3A.Z(), 6.0f);
		}

		TEST_METHOD(TEST_THIS)
		{
			ml::Vector3<float> Vec3A(1.0f, 2.0f, 3.0f);
			Assert::AreEqual(Vec3A.This(0), 1.0f);
			Assert::AreEqual(Vec3A.This(1), 2.0f);
			Assert::AreEqual(Vec3A.This(2), 3.0f);
		}

		TEST_METHOD(DISTANCE)
		{
			ml::Vector3<float> Vec3A(1.0f, 2.0f, 3.0f);
			ml::Vector3<float> Vec3B(4.0f, 6.0f, 3.0f);
			float Dist = ml::Vector3<float>::Distance(Vec3A, Vec3B);
			Assert::AreEqual(Dist, 5.0f);
		}

		TEST_METHOD(TEST_SCALE)
		{
			ml::Vector3<float> Vec3A(1.0f, 2.0f, 3.0f);
			ml::Vector3<float> Vec3B(4.0f, 5.0f, 6.0f);
			ml::Vector3<float> Vec3C = ml::Vector3<float>::Scale(Vec3A, Vec3B);
			Assert::AreEqual(Vec3C.X(), 4.0f);
			Assert::AreEqual(Vec3C.Y(), 10.0f);
			Assert::AreEqual(Vec3C.Z(), 18.0f);
		}

		TEST_METHOD(TEST_SLERP)
		{
			ml::Vector3<float> Vec3A(1.0f, 0.0f, 0.0f);
			ml::Vector3<float> Vec3B(0.0f, 1.0f, 0.0f);
			ml::Vector3<float> Vec3C = ml::Vector3<float>::Slerp(Vec3A, Vec3B, 0.5f);
			Assert::AreEqual(Vec3C.X(), 0.7071068f, epsilon);
			Assert::AreEqual(Vec3C.Y(), 0.7071068f, epsilon);
			Assert::AreEqual(Vec3C.Z(), 0.0f, epsilon);
		}

		TEST_METHOD(TEST_SIGNEDANGLE)
		{
			ml::Vector3<float> Vec3A(1.0f, 0.0f, 0.0f);
			ml::Vector3<float> Vec3B(0.0f, 1.0f, 0.0f);
			ml::Vector3<float> Axis(0.0f, 0.0f, 1.0f);
			float SignedAngle = ml::Vector3<float>::SignedAngle(Vec3A, Vec3B, Axis);
			Assert::AreEqual(SignedAngle, 1.570796f, epsilon); // Pi/2
		}

		TEST_METHOD(TEST_MIN)
		{
			ml::Vector3<float> Vec3A(1.0f, 4.0f, 3.0f);
			ml::Vector3<float> Vec3B(4.0f, 2.0f, 6.0f);
			ml::Vector3<float> Vec3C = ml::Vector3<float>::Min(Vec3A, Vec3B);
			Assert::AreEqual(Vec3C.X(), 1.0f);
			Assert::AreEqual(Vec3C.Y(), 2.0f);
			Assert::AreEqual(Vec3C.Z(), 3.0f);
		}

		TEST_METHOD(TEST_MAX)
		{
			ml::Vector3<float> Vec3A(1.0f, 4.0f, 3.0f);
			ml::Vector3<float> Vec3B(4.0f, 2.0f, 6.0f);
			ml::Vector3<float> Vec3C = ml::Vector3<float>::Max(Vec3A, Vec3B);
			Assert::AreEqual(Vec3C.X(), 4.0f);
			Assert::AreEqual(Vec3C.Y(), 4.0f);
			Assert::AreEqual(Vec3C.Z(), 6.0f);
		}

		TEST_METHOD(TEST_MOVE_TOWARDS)
		{
			ml::Vector3<float> Vec3A(1.0f, 2.0f, 3.0f);
			ml::Vector3<float> Vec3B(4.0f, 6.0f, 3.0f);
			ml::Vector3<float> Vec3C = ml::Vector3<float>::MoveTowards(Vec3A, Vec3B, 5.0f);
			Assert::AreEqual(Vec3C.X(), 4.0f);
			Assert::AreEqual(Vec3C.Y(), 6.0f);
			Assert::AreEqual(Vec3C.Z(), 3.0f);
		}

		TEST_METHOD(TEST_PROJECT) // les calculs sont bon mais pas pour visual c'est pour m'abattre ou quoi ?
		{
			ml::Vector3<float> Vec3A(1.0f, 2.0f, 3.0f);
			ml::Vector3<float> Vec3B(4.0f, 5.0f, 6.0f);
			ml::Vector3<float> Vec3C = ml::Vector3<float>::Project(Vec3A, Vec3B);
			Assert::AreEqual(Vec3C.X(), 1.6623377f, epsilon);
			Assert::AreEqual(Vec3C.Y(), 2.077922f, epsilon);
			Assert::AreEqual(Vec3C.Z(), 2.4935064f, epsilon);
		}

		TEST_METHOD(TEST_PROJECTONPLANE)
		{
			ml::Vector3<float> Vec3A(1.0f, 2.0f, 3.0f);
			ml::Vector3<float> Vec3B(0.0f, 1.0f, 0.0f);
			ml::Vector3<float> Vec3C = ml::Vector3<float>::ProjectOnPlane(Vec3A, Vec3B);
			Assert::AreEqual(Vec3C.X(), 1.0f, epsilon);
			Assert::AreEqual(Vec3C.Y(), 0.0f, epsilon);
			Assert::AreEqual(Vec3C.Z(), 3.0f, epsilon);
		}

		TEST_METHOD(TEST_REFLECT) /// c'est supposé bon mais apparement non
		{
			ml::Vector3<float> Vec3A(1.0f, -1.0f, 0.0f);
			ml::Vector3<float> Vec3B(0.0f, 1.0f, 0.0f);
			ml::Vector3<float> Vec3C = ml::Vector3<float>::Reflect(Vec3A, Vec3B);
			Assert::AreEqual(Vec3C.X(), 1.0f, epsilon);
			Assert::AreEqual(Vec3C.Y(), 1.0f, epsilon);
			Assert::AreEqual(Vec3C.Z(), 0.0f, epsilon);
		}

		TEST_METHOD(TEST_NORMALIZE)
		{
			ml::Vector3<float> Vec3A(1.0f, 2.0f, 2.0f);
			Vec3A.Normalize();
			Assert::AreEqual(Vec3A.X(), 1.0f / 3.0f, epsilon);
			Assert::AreEqual(Vec3A.Y(), 2.0f / 3.0f, epsilon);
			Assert::AreEqual(Vec3A.Z(), 2.0f / 3.0f, epsilon);
		}

	};
}