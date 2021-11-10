#include <stdio.h>
#include <stdbool.h>

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
		rectanglePoints[pointLocation] = insertPoints[0];     //puts all of the axsis into one array
		rectanglePoints[pointLocation + 1] = insertPoints[1];

	}
	return rectanglePoints;
}

void swap(int* firstNum, int* secondsNum)
{
	int temp = *firstNum;
	*firstNum = *secondsNum;			//a swap function so the 2 varibles can be swapped
	*secondsNum = temp;
}

void orderRectanglePoints(int* order)
{
	int pointOrder;
	int smallest;
	int j;
	for (pointOrder = 0; pointOrder < 8; pointOrder += 2)
	{
		smallest = pointOrder;
		for (j = pointOrder + 2; j < 8; j += 2)		//finds the smallest x value of the unsorted section of the array
		{
			if (order[j] < order[smallest])				
			{
				smallest = j;
			}
		}

		swap(&order[smallest], &order[pointOrder]); //swaps the smallest X value of the unsorted section into the correct location
		swap(&order[smallest + 1], &order[pointOrder + 1]); //swaps the corresponding Y value along with it
	}
	if (order[0] == order[2])
	{
		if (order[1] > order[3])		//orders the point correctly incase of a repeated X value in the first 2 axsis'
		{
			swap(&order[0], &order[2]);
			swap(&order[1], &order[3]);
		}
	}
	if (order[4] == order[6])
	{
		if (order[5] < order[7]) // orders the points correctly incase of a repeteated X value in the second 2 axsis'
		{
			swap(&order[4], &order[6]);
			swap(&order[5], &order[7]);		
		}
	}
}

bool axsisRepeatCheck(int *numbers)
{
	int xCheck = 0;
	int yCheck = 0;
	for (int i = 0; i < 8; i += 2)
	{
		for (int j = i + 2; j < 8; j += 2)
		{
			if (numbers[i] == numbers[j])		//checks to see if there are repeating X axis'
			{
				xCheck++;
			}
		}
	}
	for (int i = 1; i < 8; i += 2)
	{
		for (int j = i + 2; j < 8; j += 2)
		{
			if (numbers[i] == numbers[j])		//checks to see if there are repeating Y axis'
			{
				yCheck++;
			}
		}
	}

	if (xCheck >= 3 || yCheck >= 3)		// if there are more the 3 of the same X or Y axis' it will return false
	{
		return false;
	}
	else
	{
		return true; // if there are an allowed amount of repeates will return true
	}
}