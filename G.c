#include "genetic_behaviour.h"

void genetic_behaviour(char event, int* movement)
{
	/*
	 * movement[0] = left
	 * movement[1] = down
	 * movement[2] = up
	 * movement[3] = right
	 */
	if (event == 'a'){
		movement[0] = -4;
		movement[1] = 0;
		movement[2] = 6;
		movement[3] = 0;
	}
	if (event == 'b'){
		movement[0] = -3;
		movement[1] = -3;
		movement[2] = 0;
		movement[3] = 0;
	}
	if (event == 'c'){
		movement[0] = 0;
		movement[1] = 0;
		movement[2] = 1;
		movement[3] = 2;
	}
	if (event == 'd'){
		movement[0] = 0;
		movement[1] = -3;
		movement[2] = 4;
		movement[3] = 0;
	}
	if (event == 'e'){
		movement[0] = 0;
		movement[1] = 0;
		movement[2] = 0;
		movement[3] = 0;
	} 
}