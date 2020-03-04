/**
 * @brief 	 Magic Box
 * 			 Solution for Hacker Rank's Forming a Magic Square challenge
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
	//struct Cell_t* neighbors;
} Cell_t;

typedef struct Path
{
	// type of path (row, column or diagonal)
	char* type;
	// sum of the path elements
	uint32_t sum;
	// the sum is perfect
	bool ismagic;
	// array of integers to store path elements
	Cell_t** elements;
} Path_t;

bool makearray_cell(Cell_t***, int**, int);
bool makearray_path(Path_t**, Cell_t***, int);
int calcsum_path(Path_t**, int, int, int);
void printmagicsquare(Cell_t***, int);
void deletearray_cell(Cell_t***, int);
void printpaths(Path_t**, int);
void deletearray_path(Path_t**, int);

#endif /* MAGIC_SQUARE_H */
