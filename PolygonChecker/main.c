#include <stdio.h>
#include <stdbool.h>

#include "main.h"
#include "triangleSolver.h"
#include "rectangleSolver.h"

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

			//printf_s("! %d\n", triangleSidesPtr[0]);

			char* result = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			printf_s("%s\n", result);

			angleCalculatorTriangle(triangleSides);


			break;

		case 2:

			printf_s("Rectangle Selected.\n");
			int fourPoints[8] = { 0,0,0,0,0,0,0,0 };
			int* rectanglePointsPtr = getRectanglePoints(fourPoints);

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

int* getRectanglePoints(int* rectanglePoints)
{
	int insertPoints[2] = { 0,0 };
	int pointLocation;
	for (int i = 0; i < 4; i++)
	{
		printf_s("Enter the x and y coordinates of point #%d:", i + 1);
		for (int x = 0; x < 2; x++)
		{
			while (scanf_s("%d", &insertPoints[x]) == 0) // Checks to see if input is valid on triangle side lengths
			{ 
				printf("\nInvalid input. Please enter a number, such as 2, 1, or 3: ");
				scanf_s("%*s", &insertPoints[i]); // Ignore the last input and scan the new input
			}
		}
		pointLocation = i * 2;
		rectanglePoints[pointLocation] = insertPoints[0];
		rectanglePoints[pointLocation + 1] = insertPoints[1];
	}
	return rectanglePoints;
}