#include <stdio.h>
#include <stdbool.h>

#include "main.h"
#include "triangleSolver.h"

int side = 0;

int main() {
	bool continueProgram = true;
	while (continueProgram) {
		printWelcome();

		int shapeChoice = printShapeMenu();

		switch (shapeChoice)
		{
		case 1:
			printf_s("Triangle selected.\n");
			int triangleSides[3] = { 0, 0, 0 };
			int* triangleSidesPtr = getTriangleSides(triangleSides);
			if (triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2] == 0) { // check to see if each input is a valid number
				continueProgram = false;  // if not stop the program
				printf_s("Inputted values do not form a triangle!\n");
				break;
			}
			//printf_s("! %d\n", triangleSidesPtr[0]);
			char* result = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			printf_s("%s\n", result);
			break;
		case 0:
			continueProgram = false;
			break;
		case 2:
			printf_s("Rectangle Selected.\n");
			int fourPoints[8] = { 0,0,0,0,0,0,0,0 };
			int* rectanglePointsPtr = getRectanglePoints(fourPoints);
			for (int i = 0; i < 8; i++)
			{
				printf_s("%d", fourPoints[i]);
			}
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


			break;
		default:
			printf_s("Invalid value entered.\n");
			break;
		}
	}
	return 0;
}

void printWelcome() {
	printf_s("\n");
	printf_s(" **********************\n");
	printf_s("**     Welcome to     **\n");
	printf_s("**   Polygon Checker  **\n");
	printf_s(" **********************\n");
}

int printShapeMenu() {
	printf_s("1. Triangle\n");
	printf_s("2. Rectangle\n");
	printf_s("0. Exit\n");

	int shapeChoice;

	printf_s("Enter number: ");
	scanf_s("%1o", &shapeChoice);

	return shapeChoice;
}

int* getTriangleSides(int* triangleSides) {
	printf_s("Enter the three sides of the triangle: ");
	for (int i = 0; i < 3; i++)
	{
		scanf_s("%d", &triangleSides[i]);
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
			scanf_s("%d", &insertPoints[x]);
		}
		pointLocation = i * 2;
		rectanglePoints[pointLocation] = insertPoints[0];
		rectanglePoints[pointLocation + 1] = insertPoints[1];
	}
	return rectanglePoints;
}