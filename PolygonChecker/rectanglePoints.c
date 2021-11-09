#include <stdio.h>

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

void swap(int* firstNum, int* secondsNum)
{
	int temp = *firstNum;
	*firstNum = *secondsNum;
	*secondsNum = temp;
}

void orderRectanglePoints(int* order)
{
	int pointOrder;
	int smallest;
	int smallestPair;
	int j;
	for (pointOrder = 0; pointOrder < 8; pointOrder += 2)
	{
		smallest = pointOrder;
		for (j = pointOrder + 2; j < 8; j += 2)
		{
			if (order[j] < order[smallest])
			{
				smallest = j;
			}
		}

		swap(&order[smallest], &order[pointOrder]);
		swap(&order[smallest + 1], &order[pointOrder + 1]);
	}
	if (order[0] == order[2])
	{
		if (order[1] > order[3])
		{
			swap(&order[0], &order[2]);
			swap(&order[1], &order[3]);
		}
	}
	if (order[4] == order[6])
	{
		if (order[5] < order[7])
		{
			swap(&order[4], &order[6]);
			swap(&order[5], &order[7]);
		}
	}
}