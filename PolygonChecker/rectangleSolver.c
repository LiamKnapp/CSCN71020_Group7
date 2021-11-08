#include<stdio.h>
#include <math.h>

#include"rectangleSolver.h"

float getRectangleSides(int axsisOne[2], int axsisTwo[2], int axsisThree[2], int axsisFour[2])
{
	float perimeter = 0;
	float sideOne = 0;
	float sideTwo = 0;
	float sideThree = 0;
	float sideFour = 0;

	float run = axsisTwo[0] - axsisOne[0];
	float rise = axsisTwo[1] - axsisOne[1];        //uses Pythagorean theorem to find distance from point 1 to point 2
	sideOne = sqrt(rise * rise + run * run);

	run = axsisThree[0] - axsisTwo[0];
	rise = axsisThree[1] - axsisTwo[1];				//uses Pythagorean theorem to find distance from point 2 to point 3
	sideTwo = sqrt(rise * rise + run * run);

	run = axsisFour[0] - axsisThree[0];
	rise = axsisFour[1] - axsisThree[1];			//uses Pythagorean theorem to find distance from point 3 to point 4
	sideThree = sqrt(rise * rise + run * run);

	run = axsisFour[0] - axsisOne[0];
	rise = axsisFour[1] - axsisOne[1];			//uses Pythagorean theorem to find distance from point 4 to point 1
	sideFour = sqrt(rise * rise + run * run);

	//printf("%f, %f, %f, %f\n", sideOne, sideTwo, sideThree, sideFour);

	perimeter = sideOne + sideTwo + sideThree + sideFour;  //finds perimeter of four sided polygon

	if (sideOne == sideThree && sideTwo == sideFour)
	{
		float area = sideOne * sideTwo;						// checks to see if the polygon is a rectangle/square
		printf(" the area of the rectangle is: %f\n", area);
	}


	return perimeter; // returns the perimeter

}