/**
 * @brief 	 Magic Box
 * 			 Solution for Hacker Rank's Counting Pairs challenge
 *
 * @author	 Hacker Rank www.hackerrank.com
 *
 * @solution lroman 02/10/2020
 */
#include <stdlib.h>
#include <stdio.h>

#ifndef MAP_H
#define MAP_H

typedef struct
{
  int key;
  int value;
} Map;

// add key value pair
void put(Map *map, int key, int size);
void delete(Map *map,int count);

void findNumberOfPairs(int* numbers, int SIZE);
#endif /* MAP_H */
