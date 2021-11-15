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

double angleCalculatorTriangle(int* triangleSides)		
{
    double angleInRad = 0;
    double angleInDeg = 0;
	double a = triangleSides[0];
	double b = triangleSides[1];
	double c = triangleSides[2];
	double value = ((b * b) + (c * c) - (a * a)) / (2 * b * c);			// Law of cosine rearragned to solve for angle A

    angleInRad = acos(value);	
    angleInDeg = angleInRad * RAD_TO_DEG;		// Going from radians to degrees

    return angleInDeg;
}

int checkIfAngle180(double angleA, double angleB, double angleC)		// a, b and c used to make the variables match the actual math formula
{
	int angleResult = round(angleA + angleB + angleC, 0);		// Rounding to make it equal to exactly 180 so it can be checked in the if statement

	if (angleResult == VALID_TRIANGLE)
		printf("The angles of this triangle are: \n%.3f\n%.3f\n%.3f\n", angleA, angleB, angleC);// Print the angles if they add to 180
	else
		printf("These angles do not form a triangle\n");		// Print this if the angles do not equal 180

	return angleResult;
}