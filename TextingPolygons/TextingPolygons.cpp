#include "pch.h"
#include "CppUnitTest.h"

extern "C" { // call functions from main.c, rectangleSolver.c and triangleSolver.c
	int* getRectanglePoints(int* rectanglePoints);
	int* getTriangleSides(int* triangleSides);
	void angleCalculator(int* triangleSides);
	char* analyzeTriangle(int side1, int side2, int side3);
}


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TextingPolygons
{
	TEST_CLASS(TextingPolygons)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
		}
	};
}
