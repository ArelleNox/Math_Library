#include "pch.h"
#include "CppUnitTest.h"
#include "Quaternion.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(UnitTests)
	{
	public:
		const float epsilon = 1e-6f; // tolérance
		double PI = 3.14159265358979323846;

		TEST_METHOD(TEST_CONSTRUCTEUR)
		{
			ml::Quaternion<float> Quat(1.0f, 2.0f, 3.0f, 4.0f);
			Assert::AreEqual(Quat.x, 1.0f);
			Assert::AreEqual(Quat.y, 2.0f);
			Assert::AreEqual(Quat.z, 3.0f);
			Assert::AreEqual(Quat.w, 4.0f);
		}

		TEST_METHOD(TEST_IDENTITY)
		{
			ml::Quaternion<float> Quat = ml::Quaternion<float>::Identity();
			Assert::AreEqual(Quat.x, 0.0f);
			Assert::AreEqual(Quat.y, 0.0f);
			Assert::AreEqual(Quat.z, 0.0f);
			Assert::AreEqual(Quat.w, 1.0f);
		}

		TEST_METHOD(TEST_DOT)
		{
			ml::Quaternion<float> QuatA(1.0f, 2.0f, 3.0f, 4.0f);
			ml::Quaternion<float> QuatB(5.0f, 6.0f, 7.0f, 8.0f);
			float Dot = ml::Quaternion<float>::Dot(QuatA, QuatB);
			Assert::AreEqual(Dot, 70.0f);
		}

		TEST_METHOD(TEST_ANGLE)
		{
			ml::Quaternion<float> QuatA = ml::Quaternion<float>::Identity();
			ml::Vector3<float> Axis = ml::Vector3<float>(0.0f, 1.0f, 0.0f);
			ml::Quaternion<float> QuatB = ml::Quaternion<float>::FromAxisAngle(Axis, PI);
			float Angle = ml::Quaternion<float>::Angle(QuatA, QuatB);
			Assert::AreEqual(Angle, ml::Quat::PI, 0.0001f);
		}

		TEST_METHOD(TEST_TOEULER)
		{
			ml::Vector3<float> Euler(PI / 2.0f, 0.0f, 0.0f);
			ml::Quaternion<float> Quat = ml::Quaternion<float>::FromEuler(Euler);
			ml::Vector3<float> ResultEuler = Quat.ToEuler();
			Assert::AreEqual(ResultEuler.x, Euler.x, 0.0001f);
			Assert::AreEqual(ResultEuler.y, Euler.y, 0.0001f);
			Assert::AreEqual(ResultEuler.z, Euler.z, 0.0001f);
		}

		TEST_METHOD(TEST_LERP)
		{
			ml::Quaternion<float> QuatA = ml::Quaternion<float>::Identity();
			ml::Vector3<float> Axis = ml::Vector3<float>(0.0f, 1.0f, 0.0f);
			ml::Quaternion<float> QuatB = ml::Quaternion<float>::FromAxisAngle(Axis, PI);
			ml::Quaternion<float> QuatC = ml::Quaternion<float>::Lerp(QuatA, QuatB, 0.5f);
			ml::Vector3<float> OutAxis;
			float OutAngle;
			QuatC.ToAxisAngle(OutAxis, OutAngle);
			Assert::AreEqual(OutAxis.x, 0.0f, 0.0001f);
			Assert::AreEqual(OutAxis.y, 1.0f, 0.0001f);
			Assert::AreEqual(OutAxis.z, 0.0f, 0.0001f);
			Assert::AreEqual(OutAngle, ml::Quat::PI / 2.0f, 0.0001f);
		}

		TEST_METHOD(TEST_FROMAXISANGLE)
		{
			ml::Vector3<float> A = ml::Vector3<float>(0.0f, 1.0f, 0.0f);
			ml::Quaternion<float> Quat = ml::Quaternion<float>::FromAxisAngle(A, ml::Quaternion<float>::PI / 2.0f);
			Assert::AreEqual(Quat.x, 0.0f, 0.0001f);
			Assert::AreEqual(Quat.y, 0.7071f, 0.0001f);
			Assert::AreEqual(Quat.z, 0.0f, 0.0001f);
			Assert::AreEqual(Quat.w, 0.7071f, 0.0001f);
		}

		TEST_METHOD(TEST_INVERSE)
		{
			ml::Vector3<float> A = ml::Vector3<float>(0.0f, 1.0f, 0.0f);
			ml::Quaternion<float> Quat = ml::Quaternion<float>::FromAxisAngle(A, ml::Quaternion<float>::PI / 2.0f);
			ml::Quaternion<float> QuatInv = Quat.Inverse();
			ml::Quaternion<float> Result = Quat * QuatInv;
			Assert::AreEqual(Result.x, 0.0f, 0.0001f);
			Assert::AreEqual(Result.y, 0.0f, 0.0001f);
			Assert::AreEqual(Result.z, 0.0f, 0.0001f);
			Assert::AreEqual(Result.w, 1.0f, 0.0001f);
		}



	};
}