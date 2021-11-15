#include "pch.h"
#include "CppUnitTest.h"
#include<stdbool.h>
#define TRIINNERANGLE 180
extern "C" { // call functions from main.c, rectangleSolver.c and triangleSolver.c
	int* getRectanglePoints(int* rectanglePoints);
	int* getTriangleSides(int* triangleSides);
	double angleCalculatorTriangle(int* trianglesides);
	int checkIfAngle180(double angleA, double angleB, double angleC);
	char* analyzeTriangle(int side1, int side2, int side3);
	bool axsisRepeatCheck(int*);
	void orderRectanglePoints(int* order);
	void swap(int* firstNum, int* secondsNum);
	float getRectangleSides(int axsisOne[2], int axsisTwo[2], int axsisThree[2], int axsisFour[2]);

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
		TEST_METHOD(TestTriangleAngle)
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
		TEST_METHOD(RepeatX)
		{
			// test to make sure program does not build a rectangle with 3 repeated X points 1,1,1,3
			int fullList[] = { 1,2,1,6,1,9,3,7 };
			bool check = axsisRepeatCheck(fullList);
			
			Assert::IsFalse(check);
		}
		TEST_METHOD(RepeatY)
		{
			// test to make sure program does not build a rectangle with 3 repeated Y points 4,4,9,4
			int fullList[] = { 1,4,3,4,7,9,9,4 };
			bool check = axsisRepeatCheck(fullList);

			Assert::IsFalse(check);
		}
		TEST_METHOD(noRepeats)
		{
			// test to make sure program does build a rectangle with no repeated Axsis points 
			int fullList[] = { 1,8,6,4,2,9,11,6 };
			bool check = axsisRepeatCheck(fullList);

			Assert::IsTrue(check);
		}
		TEST_METHOD(orderAxsis)
		{
			// test the OrderRectanglePoints function by pasint in 1,3 6,5 2,5 1,1
			int fullList[] = { 1,3,6,5,2,5,1,1 };
			int expectedRturn[] = { 1,1,1,3,6,5,2,5 };
			orderRectanglePoints(fullList);

			Assert::AreEqual(*fullList, *expectedRturn);
		}
		TEST_METHOD(swaps)
		{
			//tests the swap function with x = 2 y = 5
			int x = 2;
			int y = 5;
			int expectedX = 5;
			int expectedY = 2;
			swap(&x, &y);
			Assert::AreEqual(x, expectedX);
			Assert::AreEqual(y, expectedY);

		}
		TEST_METHOD(swaps2)
		{
			//tests the swap function with x = 7 y = 2
			int x = 7;
			int y = 2;
			int expectedX = 2;
			int expectedY = 7;
			swap(&x, &y);
			Assert::AreEqual(y, expectedY);
		}
		TEST_METHOD(rectangleSides)
		{
			//tests the getRectangleSides Function with axsis points 1,1 4,7 2,5 8,3 an testing the resulting perimeter
			int pointOne[] = { 1,1 };
			int pointTwo[] = { 2, 5 };
			int pointThree[] = { 8, 3 };
			int pointFour[] = { 4,7 };
			float perimeter = getRectangleSides(pointOne, pointTwo, pointThree, pointFour);
			float expectedPerimeter = 19.88849692;
			Assert::AreEqual(perimeter, expectedPerimeter);
		}
	};
}
