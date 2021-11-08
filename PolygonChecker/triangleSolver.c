#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "triangleSolver.h"

#define RAD_TO_DEG 57.2957795
#define DEGREEMAKEUP 1


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

void angleCalculatorTriangle(int* triangleSides)		// a, b and c used to make the formula easy to read
{
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

	int angleA = angleAInDeg, angleB = angleBInDeg, angleC = angleCInDeg;

	int angleResult = angleA + angleB + angleC + 1;

	printf("%d\n%d\n%d\n%d\n", angleA, angleB, angleC, angleResult);
	if (angleResult == 180) 
	{
		printf("%f\n%f\n%f\n", angleAInDeg, angleBInDeg, angleCInDeg);
		printf("Angles do make a triangle\n");
	}
	else
	{
		printf("Angles do not create a triangle\n");
		printf("%f\n", angleAInDeg + angleBInDeg + angleCInDeg);
	}
}