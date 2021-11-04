#include "pch.h"
#include "CppUnitTest.h"

extern "C" { // call functions from main.c, rectangleSolver.c and triangleSolver.c
	int* getRectanglePoints(int* rectanglePoints);
	int* getTriangleSides(int* triangleSides);
	void angleCalculatorTriangle(int* triangleSides);
	char* analyzeTriangle(int side1, int side2, int side3);
}


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TextingPolygons
{
	TEST_CLASS(TestingPolygons)
	{
	public:
		
		TEST_METHOD(TestTriangleSides)
		{


		}
		TEST_METHOD(TestRectangleSides)
		{


		}
		TEST_METHOD(TestAngleCalculator)
		{


		}
		TEST_METHOD(TestAnalyzeTriangle)
		{


		}

	};
}
