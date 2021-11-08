#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "triangleSolver.h"

#define RAD_TO_DEG 57.2957795
#define VALID_TRIANGLE 180

char* analyzeTriangle(int side1, int side2, int side3) {
	char* result = "";
	if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
		result = "Not a triangle";
	}
	else if (side1 == side2 && side1 == side3) {
		result = "Equilateral triangle";
	}
	else if ((side1 == side2 && side1 != side3) || 
		(side1 == side3 && side1 != side2))
	{
		result = "Isosceles triangle";
	}
	else {
		result = "Scalene triangle";
	}

	return result;
}

int angleCalculatorTriangle(int* triangleSides)		// a, b and c used to make the variables match the actual math formula
{
	double angleResult = 0;
	double angleInRad  = 0;
	double angleAInDeg = 0;
	double angleBInDeg = 0;
	double angleCInDeg = 0;
	double a = triangleSides[0];
	double b = triangleSides[1];
	double c = triangleSides[2];

	angleInRad = acos(((b * b) + (c * c) - (a * a)) / (2 * b * c));	// Law of cosine rearranged to solve for angle A
	angleAInDeg = angleInRad * RAD_TO_DEG;

	angleInRad = acos(((a * a) + (c * c) - (b * b)) / (2 * a * c)); // Solve for angle B
	angleBInDeg = angleInRad * RAD_TO_DEG;

	angleInRad = acos(((b * b) + (a * a) - (c * c)) / (2 * b * a)); // Solve for angle C
	angleCInDeg = angleInRad * RAD_TO_DEG;

	angleResult = round(angleAInDeg + angleBInDeg + angleCInDeg, 0);		// Rounding to make it equal to exactly 180 so it can be checked in the if statement

	if (angleResult == VALID_TRIANGLE) {
		printf("Angles of this triangle are: %f\n%f\n%f\n", angleAInDeg, angleBInDeg, angleCInDeg);		// Print the angles if they add to 180
		int angles[4];
			angles[0] = angleResult;
			angles[1] = angleAInDeg;
			angles[2] = angleBInDeg;
			angles[3] = angleCInDeg;
		return angles;
	}
	else {
		printf("Angles do not create a triangle\n");		// Print this if the angles do not equal 180
	}
}