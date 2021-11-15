#include "pch.h"
#include "CppUnitTest.h"
#define TRIINNERANGLE 180
extern "C" { // call functions from main.c, rectangleSolver.c and triangleSolver.c
	int* getRectanglePoints(int* rectanglePoints);
	int* getTriangleSides(int* triangleSides);
	double angleCalculatorTriangle(int* trianglesides);
	int checkIfAngle180(double angleA, double angleB, double angleC);
	char* analyzeTriangle(int side1, int side2, int side3);
}


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TextingPolygons
{
	TEST_CLASS(TestingPolygons)
	{
	public:
		TEST_METHOD(TestScaleneTriangle)
		{
			//testing to make sure the triangle is outputed as being Scalene
			int side1, side2, side3;
			char* Result = " ";
			side1 = 4;
			side2 = 6; 
			side3 = 3;
			Result = analyzeTriangle(side1, side2, side3);
			Assert::AreEqual("Scalene triangle", Result);
		}
		TEST_METHOD(TestEqualTriangle)
		{
			//testing to make sure the triangle is outputed as being Equal
			int side1, side2, side3;
			char* Result = " ";
			side1 = 3;
			side2 = 3;
			side3 = 3;
			Result = analyzeTriangle(side1, side2, side3);
			Assert::AreEqual("Equilateral triangle", Result);
		}
		TEST_METHOD(TestIsoscelesTriangle)
		{
			//testing to make sure the triangle is outputed as being Isosceles
			int side1, side2, side3;
			char* Result = " ";
			side1 = 3;
			side2 = 3;
			side3 = 4;
			Result = analyzeTriangle(side1, side2, side3);
			Assert::AreEqual("Isosceles triangle", Result);
		}
		TEST_METHOD(TestIsItTriangle)
		{
			//testing to make sure the triangle is outputed as being not a triangle given invalid inputs
			int side1, side2, side3;
			char* Result = " ";
			side1 = -3;
			side2 = 0;
			side3 = 4;
			Result = analyzeTriangle(side1, side2, side3);
			Assert::AreEqual("Not a triangle", Result);
		}
		TEST_METHOD(TestTriangleAngle180)
		{
			// testing to make sure the input is valid and it returns the sum of the inner angles

			int Result;
			double angle1 = 60;
			double angle2 = 60;
			double angle3 = 60;
			Result = checkIfAngle180(angle1, angle2, angle3);
			Assert::AreEqual(TRIINNERANGLE, Result);
		}
		TEST_METHOD(TestTriangleAngle1)
		{
			// testing to make sure the input is valid and it returns the first angle

			double Result;
			double angle = 60;
			int Sides[3];
			Sides[0] = 5;
			Sides[1] = 5;
			Sides[2] = 5;

			Result = angleCalculatorTriangle(Sides);
			Assert::AreEqual(angle, round(Result));
		}
		TEST_METHOD(Test4Points)
		{
			// test to make sure the code accepts 4 points 

		}

	};
}
