/*
 * datastructure.c
 *
 *  Created on: Feb 9, 2020
 *      Author: leoroman
 */
#include "header/countingpairs.h"
#include "header/countingvalleys.h"
#include "header/magicsquare.h"

#define SIZE (12)
#define MAGIC_CONST (15)

//extern int CONSTANT_numbers[];
//extern char CONSTANT_steps[];

extern int* CONSTANT_magicsquare[];
//int CONSTANT_magicsquare[3][3] = { {1,3,5}, {6,4,6}, {7,8,9} };

int main()
{
	//  problem 1: number of pairs
	//findNumberOfPairs(CONSTANT_numbers,100);

	// Problem 2: Counting Valleys
	//countingValleys(CONSTANT_steps,12);

	// Problem 3: Magic square
	// Array of pointers of type path_t
	int num_cells = 3;
	int num_paths = 8;
	cell_t** magic_square[num_cells];
	bool init = makearray_cell(magic_square,CONSTANT_magicsquare,num_cells);
	path_t* path_arr[num_paths];
	bool initpaths = makearray_path(path_arr,magic_square,num_cells);
	//path_arr[0]->elements[0]->data = 10;
	if(init == true && initpaths==true)
	{
		printmagicsquare(magic_square,num_cells);
		printpaths(path_arr,num_cells);
		calcsum_path(path_arr,num_paths,num_cells,MAGIC_CONST);
		printmagicsquare(magic_square,num_cells);
		printpaths(path_arr,num_cells);
		deletearray_cell(magic_square,num_cells);
	}
	//bool init = makeMagicSquare(path,CONSTANT_magicsquare, 3);

	return 0;
}

//  problem 1: number of pairs

// Problem 2: Counting Valleys

