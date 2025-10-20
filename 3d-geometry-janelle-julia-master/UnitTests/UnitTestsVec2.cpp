 #include "pch.h"
#include "CppUnitTest.h"
#include "Vector2.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(UnitTests)
	{
	public:
		
		const float epsilon = 1e-6f; // tolérance

		TEST_METHOD(TEST_CONSTRUCTEUR)
		{
			ml::Vector2<float> Vec2(1.0f, 2.0f);
			Assert::AreEqual(Vec2.X(), 1.0f);
			Assert::AreEqual(Vec2.Y(), 2.0f);
		}

		TEST_METHOD(TEST_ADD)
		{
			ml::Vector2<float> Vec2A(1.0f, 2.0f);
			ml::Vector2<float> Vec2B(3.0f, 4.0f);
			ml::Vector2<float> Vec2C = Vec2A + Vec2B;
			Assert::AreEqual(Vec2C.X(), 4.0f);
			Assert::AreEqual(Vec2C.Y(), 6.0f);
		}

		TEST_METHOD(TEST_SUB)
		{
			ml::Vector2<float> Vec2A(1.0f, 2.0f);
			ml::Vector2<float> Vec2B(3.0f, 4.0f);
			ml::Vector2<float> Vec2C = Vec2A - Vec2B;
			Assert::AreEqual(Vec2C.X(), -2.0f);
			Assert::AreEqual(Vec2C.Y(), -2.0f);
		}

		TEST_METHOD(TEST_MUL)
		{
			ml::Vector2<float> Vec2A(1.0f, 2.0f);
			ml::Vector2<float> Vec2B(3.0f, 4.0f);
			ml::Vector2<float> Vec2C = Vec2A * Vec2B;
			Assert::AreEqual(Vec2C.X(), 3.0f);
			Assert::AreEqual(Vec2C.Y(), 8.0f);
		}

		TEST_METHOD(TEST_DIV)
		{
			ml::Vector2<float> Vec2A(1.0f, 2.0f);
			ml::Vector2<float> Vec2B(3.0f, 4.0f);
			ml::Vector2<float> Vec2C = Vec2A / Vec2B;
			Assert::AreEqual(Vec2C.X(), 1.0f / 3.0f);
			Assert::AreEqual(Vec2C.Y(), 0.5f);
		}

		TEST_METHOD(TEST_DOT)
		{
			ml::Vector2<float> Vec2A(1.0f, 2.0f);
			ml::Vector2<float> Vec2B(3.0f, 4.0f);
			float Dot = ml::Vector2<float>::Dot(Vec2A, Vec2B);
			Assert::AreEqual(Dot, 11.0f);
		}

		TEST_METHOD(TEST_MAGNITUDE)
		{
			ml::Vector2<float> Vec2A(3.0f, 4.0f);
			float Magnitude = Vec2A.Magnitude();
			Assert::AreEqual(Magnitude, 5.0f);
		}

		TEST_METHOD(TEST_NORMALIZED)
		{
			ml::Vector2<float> Vec2A(3.0f, 4.0f);
			ml::Vector2<float> Vec2B = Vec2A.Normalized();
			Assert::AreEqual(Vec2B.X(), 0.6f);
			Assert::AreEqual(Vec2B.Y(), 0.8f);
		}

		TEST_METHOD(TEST_DISTANCE)
		{
			ml::Vector2<float> Vec2A(1.0f, 2.0f);
			ml::Vector2<float> Vec2B(4.0f, 6.0f);
			float Distance = ml::Vector2<float>::Distance(Vec2A, Vec2B);
			Assert::AreEqual(Distance, 5.0f);
		}

		TEST_METHOD(TEST_LERP)
		{
			ml::Vector2<float> Vec2A(1.0f, 2.0f);
			ml::Vector2<float> Vec2B(3.0f, 4.0f);
			ml::Vector2<float> Vec2C = ml::Vector2<float>::Lerp(Vec2A, Vec2B, 0.5f);
			Assert::AreEqual(Vec2C.X(), 2.0f);
			Assert::AreEqual(Vec2C.Y(), 3.0f);
		}

		TEST_METHOD(TEST_CLAMPMAGNITUDE)
		{
			ml::Vector2<float> Vec2A(3.0f, 4.0f);
			ml::Vector2<float> Vec2B = ml::Vector2<float>::ClampMagnitude(Vec2A, 3.0f);
			Assert::AreEqual(Vec2B.Magnitude(), 3.0f);
		}

		TEST_METHOD(TEST_EQUAL)
		{
			ml::Vector2<float> Vec2A(1.0f, 2.0f);
			ml::Vector2<float> Vec2B(1.0f, 2.0f);
			ml::Vector2<float> Vec2C(3.0f, 4.0f);
			Assert::IsTrue(Vec2A.Equal(Vec2B));
			Assert::IsFalse(Vec2A.Equal(Vec2C));
		}

		TEST_METHOD(TEST_TOSTRING)
		{
			ml::Vector2<float> Vec2A(1.0f, 2.0f);
			std::string Str = Vec2A.ToString();
			Assert::AreEqual(Str, std::string("(1.000000, 2.000000)"));
		}

		TEST_METHOD(TEST_NORMALIZE)
		{
			ml::Vector2<float> Vec2A(3.0f, 4.0f);
			Vec2A.Normalize();
			Assert::AreEqual(Vec2A.X(), 0.6f);
			Assert::AreEqual(Vec2A.Y(), 0.8f);
		}

		TEST_METHOD(TEST_SET)
		{
			ml::Vector2<float> Vec2A(1.0f, 2.0f);
			Vec2A.Set(3.0f, 4.0f);
			Assert::AreEqual(Vec2A.X(), 3.0f);
			Assert::AreEqual(Vec2A.Y(), 4.0f);
		}

		TEST_METHOD(TEST_ANGLE)
		{
			ml::Vector2<float> Vec2A(1.0f, 0.0f);
			ml::Vector2<float> Vec2B(0.0f, 1.0f);
			float Angle = ml::Vector2<float>::Angle(Vec2A, Vec2B);
			Assert::AreEqual(Angle, 1.570796f, epsilon); // Pi/2
		}

		TEST_METHOD(TEST_SIGNEDANGLE)
		{
			ml::Vector2<float> Vec2A(1.0f, 0.0f);
			ml::Vector2<float> Vec2B(0.0f, 1.0f);
			float SignedAngle = ml::Vector2<float>::SignedAngle(Vec2A, Vec2B);
			Assert::AreEqual(SignedAngle, 1.570796f, epsilon); // Pi/2
		}

		TEST_METHOD(TEST_SCALE)
		{
			ml::Vector2<float> Vec2A(1.0f, 2.0f);
			ml::Vector2<float> Vec2B(3.0f, 4.0f);
			ml::Vector2<float> Vec2C = ml::Vector2<float>::Scale(Vec2A, Vec2B);
			Assert::AreEqual(Vec2C.X(), 3.0f);
			Assert::AreEqual(Vec2C.Y(), 8.0f);
		}

		TEST_METHOD(TEST_PERPENDICULAR)
		{
			ml::Vector2<float> Vec2A(1.0f, 0.0f);
			ml::Vector2<float> Vec2B = ml::Vector2<float>::Perpendicular(Vec2A);
			Assert::AreEqual(Vec2B.X(), 0.0f);
			Assert::AreEqual(Vec2B.Y(), 1.0f);
		}

		TEST_METHOD(TEST_MOVETOWARDS)
		{
			ml::Vector2<float> Vec2A(1.0f, 2.0f);
			ml::Vector2<float> Vec2B(4.0f, 6.0f);
			ml::Vector2<float> Vec2C = ml::Vector2<float>::MoveTowards(Vec2A, Vec2B, 5.0f);
			Assert::AreEqual(Vec2C.X(), 4.0f);
			Assert::AreEqual(Vec2C.Y(), 6.0f);
		}

		TEST_METHOD(TEST_MIN)
		{
			ml::Vector2<float> Vec2A(1.0f, 4.0f);
			ml::Vector2<float> Vec2B(3.0f, 2.0f);
			ml::Vector2<float> Vec2C = ml::Vector2<float>::Min(Vec2A, Vec2B);
			Assert::AreEqual(Vec2C.X(), 1.0f);
			Assert::AreEqual(Vec2C.Y(), 2.0f);
		}

		TEST_METHOD(TEST_MAX)
		{
			ml::Vector2<float> Vec2A(1.0f, 4.0f);
			ml::Vector2<float> Vec2B(3.0f, 2.0f);
			ml::Vector2<float> Vec2C = ml::Vector2<float>::Max(Vec2A, Vec2B);
			Assert::AreEqual(Vec2C.X(), 3.0f);
			Assert::AreEqual(Vec2C.Y(), 4.0f);
		}

		TEST_METHOD(TEST_LERPUNCLAMPED)
		{
			ml::Vector2<float> Vec2A(1.0f, 2.0f);
			ml::Vector2<float> Vec2B(3.0f, 4.0f);
			ml::Vector2<float> Vec2C = ml::Vector2<float>::LerpUnclamped(Vec2A, Vec2B, 1.5f);
			Assert::AreEqual(Vec2C.X(), 4.0f);
			Assert::AreEqual(Vec2C.Y(), 5.0f);
		}

		TEST_METHOD(TEST_THIS)
		{
			ml::Vector2<float> Vec2A(1.0f, 2.0f);
			Assert::AreEqual(Vec2A.This(0), 1.0f);
			Assert::AreEqual(Vec2A.This(1), 2.0f);
		}

		TEST_METHOD(TEST_SQRTMAGNITUDE)
		{
			ml::Vector2<float> Vec2A(3.0f, 4.0f);
			float SqrtMagnitude = Vec2A.SqrtMagnitude();
			Assert::AreEqual(SqrtMagnitude, 25.0f);
		}
	};
}
