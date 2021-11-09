#include <stdio.h>
#include <stdbool.h>

#include "main.h"
#include "triangleSolver.h"
#include "rectangleSolver.h"
#include"rectanglePoints.h"

int side = 0;

int main() {
	bool continueProgram = true;
	while (continueProgram) {
		printWelcome();

		int shapeChoice = printShapeMenu();

		switch (shapeChoice)
		{
		case 0:
			continueProgram = false;
			break;

		case 1:

			printf_s("Triangle selected.\n");

			int triangleSides[3] = { 0, 0, 0 };
			int* triangleSidesPtr = getTriangleSides(triangleSides);

			int triangleSides2[3] = { triangleSides[1], triangleSides[0], triangleSides[2] };		// Makes another array which will pass in the sides in a different order so the function can be called 3 times
			int triangleSides3[3] = { triangleSides[2], triangleSides[0], triangleSides[1] };
			//printf_s("! %d\n", triangleSidesPtr[0]);

			char* result = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);

			double angleA = angleCalculatorTriangle(triangleSides);		// Solves for the first angle
			double angleB = angleCalculatorTriangle(triangleSides2);	// Solves for the second angle
			double angleC = angleCalculatorTriangle(triangleSides3);	// Solbes for the thrid angle

			if (angleCalculatorTriangle180(angleA, angleB, angleC) == 180)
				printf_s("%s\n", result);

			break;

		case 2:

			printf_s("Rectangle Selected.\n");
			int fourPoints[8] = { 0,0,0,0,0,0,0,0 };
			int* rectanglePointsPtr = getRectanglePoints(fourPoints);

			orderRectanglePoints(fourPoints);
			for (int i = 0; i < 8; i += 2)
				printf("\n %d %d", fourPoints[i], fourPoints[i + 1]);
			
			int pointOne[2] = {0, 0};
			pointOne[0] = fourPoints[0];
			pointOne[1] = fourPoints[1];

			int pointTwo[2] = { 0, 0 };
			pointTwo[0] = fourPoints[2];
			pointTwo[1] = fourPoints[3];

			int pointThree[2] = { 0, 0 };
			pointThree[0] = fourPoints[4];
			pointThree[1] = fourPoints[5];

			int pointFour[2] = { 0, 0 };
			pointFour[0] = fourPoints[6];
			pointFour[1] = fourPoints[7];

			float perimeter = 0;
			perimeter = getRectangleSides(pointOne, pointTwo, pointThree, pointFour);

			printf("\n the perimeter is: %f", perimeter);

			

			break;

		default:
			printf_s("Invalid value entered.\n");
			break;

		}
	}
	return 0;
}

void printWelcome() 
{
	printf_s("\n");
	printf_s(" **********************\n");
	printf_s("**     Welcome to     **\n");
	printf_s("**   Polygon Checker  **\n");
	printf_s(" **********************\n");
}

int printShapeMenu() 
{
	printf_s("1. Triangle\n");
	printf_s("2. Rectangle\n");
	printf_s("0. Exit\n");

	int shapeChoice;

	printf_s("Enter number: ");
	scanf_s("%1o", &shapeChoice);

	return shapeChoice;
}

int* getTriangleSides(int* triangleSides) 
{
	printf_s("Enter the three sides of the triangle: ");
	for (int i = 0; i < 3; i++)
	{
		while (scanf_s("%d", &triangleSides[i])==0) // Checks to see if input is valid on triangle side lengths
		{ 
			printf("\nInvalid input. Please enter a number, such as 2, 10, or 5: ");
			scanf_s("%*s", &triangleSides[i]); // Ignore the last input and scan the new input
		}
		
	}

	return triangleSides;
}





