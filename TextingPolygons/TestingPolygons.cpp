#include "pch.h"
#include "CppUnitTest.h"
#define TRIINNERANGLE 180
extern "C" { // call functions from main.c, rectangleSolver.c and triangleSolver.c
	int* getRectanglePoints(int* rectanglePoints);
	int* getTriangleSides(int* triangleSides);
	int angleCalculatorTriangle(int* triangleSides);
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
		TEST_METHOD(TestAngleCalculatorTriangle)
		{
			// testing to make sure the input is valid and it returns the angle
			int* trianglesides[3];
			int Result[4] = { 0, 0, 0, 0 };
			*trianglesides[0] = 3;
			*trianglesides[1] = 3;
			*trianglesides[2] = 3;
			Result[0] = angleCalculatorTriangle(*trianglesides);
			Assert::AreEqual(TRIINNERANGLE, Result[0]);
		}
		TEST_METHOD(Test4Points)
		{
			// test to make sure the code accepts 4 points 

		}

	};
}
