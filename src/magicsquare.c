#include "magicsquare.h"
#import <math.h>

///////////////////////////////////////////////////////////////////////////////////
// Private helper methods
///////////////////////////////////////////////////////////////////////////////////
static inline void set_magicpath(Path_t* path, int size);
static inline void update_sum(Path_t* path,int magic_const,int size);
static inline Cell_t* makecell(uint16_t row, uint16_t col, uint16_t data);
static inline Path_t* makepath(char* type, int size);

///////////////////////////////////////////////////////////////////////////////////
// @param
// @param
// @param
// @return
///////////////////////////////////////////////////////////////////////////////////
bool makearray_cell(Cell_t*** cell_arr,int** arr, int size)
{
	//bool success = false;
	printf("Allocating memory for Magic Square\n");
	for (int i = 0; i < size; i++)
	{
		cell_arr[i] = malloc(size * sizeof(Cell_t));
		printf("%p...................cells[%i]...............base address\n",cell_arr[i],i);
		for (int j = 0; j < size; j++)
		{
			cell_arr[i][j] = makecell(i,j,arr[i][j]);
			printf("%p...................cells[%i][%i]............value stored %i\n",cell_arr[i][j],i,j,cell_arr[i][j]->data);
		}
	}
	return true;
}

///////////////////////////////////////////////////////////////////////////////////
// @param
// @param
// @param
// @return
///////////////////////////////////////////////////////////////////////////////////
static inline Cell_t* makecell(uint16_t row, uint16_t col, uint16_t data)
{
	Cell_t* cell = malloc(sizeof(Cell_t));
	cell->row = row;
	cell->col = col;
	cell->data = data;
	cell->istaken = false;

	return cell;
}

///////////////////////////////////////////////////////////////////////////////////
// @param
// @param
// @param
// @return
///////////////////////////////////////////////////////////////////////////////////
bool makearray_path(Path_t** path_arr, Cell_t*** cell_arr, int size)
{
	// Allocate memory for diagonal 1
	Path_t* diag1 = makepath("diagonal",size);
	printf("%p...................diag1..................base address\n",diag1);
	// Allocate memory for diagonal 2
	Path_t* diag2 = makepath("diagonal",size);
	printf("%p...................diag2..................base address\n",diag2);
	int i;
	for (i = 0; i < size; i++)
	{
		// Allocate memory for each row
		Path_t* row = makepath("row",size);
		printf("%p...................row....................base address\n",row);
		// Allocate memory for each column
		Path_t* col = makepath("column",size);
		printf("%p...................column.................base address\n",col);
		// populate array of paths
		for (int j = 0; j < size; j++)
		{
			row->elements[j] = cell_arr[i][j];	// assign cells to each row
			row->sum += cell_arr[i][j]->data;	// initial sum for row
			printf("%p...................row[%i][%i]..............value stored  %i\n",row->elements[j],i,j,row->elements[j]->data);
			col->elements[j] = cell_arr[j][i];	// assign cells to each column
			col->sum += cell_arr[j][i]->data;	// initial sum for column
			printf("%p...................column[%i][%i]...........value stored  %i\n",col->elements[j],j,i,col->elements[j]->data);
			// assign cells to diagonals
			if(i == j)
			{
				diag1->elements[i] = row->elements[j];	// assign cells to diagonal 1
				diag1->sum += cell_arr[i][j]->data;		// initial sum for diagonal 1
				printf("%p...................diagonal1[%i][%i]........value stored  %i\n",diag1->elements[j],i,j,diag1->elements[j]->data);
			}
			if(i + j == (size-1))
			{
				diag2->elements[i] = col->elements[j];	// assign cells to diagonal 2
				diag2->sum += cell_arr[i][j]->data;		// initial sum for diagonal 2
				printf("%p...................diagonal2[%i][%i]........value stored  %i\n",diag2->elements[i],j,i,diag2->elements[i]->data);
			}
		}
		path_arr[i] = row;		// store rows in array
		path_arr[i+size] = col; // store columns in array
	}
	i = size * 2;				// last 2 for diagonals
	path_arr[i] = diag1;		// path[n-1]
	path_arr[i+1] = diag2;		// path[n]
	return true;
}

///////////////////////////////////////////////////////////////////////////////////
// @param
// @param
// @return
///////////////////////////////////////////////////////////////////////////////////
static inline Path_t* makepath(char* type, int size)
{
	Path_t* path = malloc(sizeof(Path_t));
	path->type = type;
	path->sum = 0;
	path->ismagic = false;
	path->elements = malloc(size * sizeof(Path_t));

	return path;
}

///////////////////////////////////////////////////////////////////////////////////
// @param
// @return
///////////////////////////////////////////////////////////////////////////////////
int calcsum_path(Path_t** path_arr,int num_paths,int num_cells, int magic_const)
{
	// for each path's sum, find the ones with magic constant
	for(int i = 0; i < num_paths; i++)
	{
		Path_t* path = path_arr[i];
		if(path->sum == magic_const)
		{
			// mark path as magic path
			set_magicpath(path,num_cells);
			printf("The sum of %s %i is a magic constant\n",path->type,(i+1)%3);
		}
	}
	// for each non magic paths, make changes
	for(int i = 0; i < num_paths; i++)
	{
		Path_t* path = path_arr[i];
		// change value of cell for paths that are not magic
		if(path->ismagic == false)
		{
			// for each cell in path, find the ones that are not taken by a magic path
			for(int j = 0; j < num_cells; j++)
			{
				Cell_t* cell = path->elements[j];
				if(cell->istaken == false)
				{
					int sum = path->sum;
					// Update cell's data
					int difference = abs(sum - magic_const);
					printf("difference %i\n",difference);
					if(sum > magic_const)
					{
						int data = abs(difference - cell->data);
						cell->data = data == 0 ? 1 : data;
					}
					else
					{
						cell->data += difference;
					}
					update_sum(path,magic_const,num_cells);
				}
			}
		}
	}
	return 0;
}

///////////////////////////////////////////////////////////////////////////////////
// @param
// @return
///////////////////////////////////////////////////////////////////////////////////
static inline void update_sum(Path_t* path, int magic_const, int size)
{
	int newsum = 0;
	for(int i = 0; i < size; i++)
	{
		newsum += path->elements[i]->data;
	}
	if(newsum == magic_const)
	{
		// mark path as magic path
		set_magicpath(path,size);
	}
	path->sum = newsum;
}

///////////////////////////////////////////////////////////////////////////////////
// @param
// @return
///////////////////////////////////////////////////////////////////////////////////
static inline void set_magicpath(Path_t* path, int size)
{
	path->ismagic = true;
	for(int j = 0; j < size; j++)
	{
		// lock path's cells so no one may change them
		path->elements[j]->istaken = true;
	}
}

///////////////////////////////////////////////////////////////////////////////////
// @param
// @param
///////////////////////////////////////////////////////////////////////////////////
void printmagicsquare(Cell_t*** cells,int size)
{
	printf("magic square\n");
	printf(" _______\n");
	for(int i = 0; i < size; i++)
	{
		printf("| ");
		for(int j = 0; j < size; j++)
		{
			printf("%i ",cells[i][j]->data);
		}
		printf("|\n");
	}
	printf(" -------\n");
}

///////////////////////////////////////////////////////////////////////////////////
// @param
// @param
///////////////////////////////////////////////////////////////////////////////////
void deletearray_cell(Cell_t*** cells,int size)
{
	printf("Deleting %ix%i magic square\n",size,size);
	printf(" _______\n");
	for(int i = 0; i < size; i++)
	{
		printf("| ");
		for(int j = 0; j < size; j++)
		{
			cells[i][j]->data = 0;
			printf("%i ",cells[i][j]->data);
			free(cells[i][j]);
			cells[i][j] = NULL;
		}
		free(cells[i]);
		printf("|\n");
	}
	printf(" -------\n");
}

///////////////////////////////////////////////////////////////////////////////////
// @param
// @param
///////////////////////////////////////////////////////////////////////////////////
void printpaths(Path_t** path_arr,int size)
{
	printf("magic square's paths\n");
	for(int i = 0; i < 8; i++)
	{
		printf("%s[ ",path_arr[i]->type);
		for(int j = 0; j < size; j++)
		{
			printf("%i ",path_arr[i]->elements[j]->data);
		}
		printf("] Sum=%i\n",path_arr[i]->sum);
	}
}

///////////////////////////////////////////////////////////////////////////////////
// @param
// @param
///////////////////////////////////////////////////////////////////////////////////
void deletearray_path(Path_t** path_arr,int size)
{

}
