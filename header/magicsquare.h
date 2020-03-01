/**
 * @brief 	 Magic Box
 * 			 Solution for Hacker Rank's Magic Box challenge
 *
 * @author	 Hacker Rank www.hackerrank.com
 * 			 "We define a magic square to be an n x n matrix of distinct positive integers
 * 			 from 1 to n^2 to  where the sum of any row, column, or diagonal of length n is
 * 			 always equal to the same number: the magic constant. You will be given a 3 x 3
 * 			 matrix  of s integers in the inclusive range [1,9]. We can convert any digit 'a'
 * 			 to any other digit 'b' in the range [1,9] at cost of |a-b|. Given s, convert it
 * 			 into a magic square at minimal cost. Print this cost on a new line."
 *
 * @solution lroman 02/29/2020
 */
#include <stdio.h>
#include <stdlib.h>

#ifndef MAGIC_SQUARE_H
#define MAGIC_SQUARE_H

typedef enum Boolean { true, false } bool;

typedef struct Cell
{
	// row index
	uint16_t row;
	// column index
	uint16_t col;
	// index data
	int16_t data;
	// flag, path's sum equals magic constant
	bool istaken;
	// neighbors
	//struct cell_t* neighbors;
} cell_t;

typedef struct Path
{
	// type of path (row, column or diagonal)
	char* type;
	// sum of the path elements
	uint32_t sum;
	// the sum is perfect
	bool ismagic;
	// array of integers to store path elements
	cell_t** elements;
} path_t;

bool makearray_cell(cell_t***, int**, int);
bool makearray_path(path_t**, cell_t***, int);
int calcsum_path(path_t**, int, int, int);
void printmagicsquare(cell_t***, int);
void deletearray_cell(cell_t***, int);
void printpaths(path_t**, int);
void deletearray_path(path_t**, int);

#endif /* MAGIC_SQUARE_H */
