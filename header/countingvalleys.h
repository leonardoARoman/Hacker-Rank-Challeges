/**
 * @brief 	 Magic Box
 * 			 Solution for Hacker Rank's Counting Valleys challenge
 *
 * @author	 Hacker Rank www.hackerrank.com
 * 			 "A mountain is a sequence of consecutive steps above sea
 * 			 level, starting with a step up from sea level and ending
 * 			 with a step down to sea level. A valley is a sequence of
 * 			 consecutive steps below sea level, starting with a step
 * 			 down from sea level and ending with a step up to sea
 * 			 level."
 * @solution lroman 02/15/2020
 */
#include <stdio.h>
#include <stdlib.h>

#ifndef COUNTINGVALLEYS_H
#define COUNTINGVALLEYS_H

typedef struct Terrain
{
	char* name;
	// 0-1 value acts as boolean
	int entered;
	// height or depth of terrain
	int lenght;
	// next terrain
	struct Terrain* nextTerrain;
} Terrain;

void AddTerrain(Terrain*);
void countingValleys(char*, int);
Terrain* getHead();
void printPath();
void deleteTerrain(Terrain*);

#endif /* COUNTINGVALLEYS_H */
