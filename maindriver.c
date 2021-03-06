/*
 * datastructure.c
 *
 *  Created on: Feb 9, 2020
 *      Author: leoroman
 */
//#include "countingpairs.h"
//#include "countingvalleys.h"
//#include "magicsquare.h"
//#include "fileInterface.h"
//#include "synchronousshopping.h"
//#include "datastructures.h"
//#include "class.h"

#include <string.h>

#include "designpatterns/observer/observer_phonescreen.h"
#include "designpatterns/observer/observer_phonealert.h"

#define SIZE (12)
#define MAGIC_CONST (15)

//extern int CONSTANT_numbers[];
//extern char CONSTANT_steps[];
//extern int* CONSTANT_magicsquare[];

extern void publisher_NotifyBatteryLife(int);

int main()
{

	if(!subservice_PhoneScreenInit())
	{
		printf("error: could not initialized Phone Screen\n");
	}
	if(!subservice_PhoneAlertInit())
	{
		printf("error: could not initialized Phone Alert\n");
	}
	publisher_NotifyBatteryLife(100);
	//	size_t maxInt = 4294967295;
	//	size_t maxbin = 0b11111111111111111111111111111111;
	//	size_t maxhex = 0xffffffff; // 4294967295
	//	printf("max binary %lu\n",maxbin);
	//	printf("max hex    %lu\n",maxhex);
	//	printf("max int    %lu\n",maxInt);
	//  problem 1: number of pairs
	//findNumberOfPairs(CONSTANT_numbers,100);

	// Problem 2: Counting Valleys
	//countingValleys(CONSTANT_steps,12);

	// Problem 3: Magic square
	// Array of pointers of type path_t
	//	int num_cells = 3;
	//	int num_paths = 8;
	//	Cell_t** magic_square[num_cells];
	//	bool init = makearray_cell(magic_square,CONSTANT_magicsquare,num_cells);
	//	Path_t* path_arr[num_paths];
	//	bool initpaths = makearray_path(path_arr,magic_square,num_cells);
	//	if(init == true && initpaths==true)
	//	{
	//		printmagicsquare(magic_square,num_cells);
	//		printpaths(path_arr,num_cells);
	//		calcsum_path(path_arr,num_paths,num_cells,MAGIC_CONST);
	//		printmagicsquare(magic_square,num_cells);
	//		printpaths(path_arr,num_cells);
	//		deletearray_cell(magic_square,num_cells);
	//	}

	//(/* Dereference pointer */*((/* cast to a pointer */unsigned int*)0x7ff87d401b60));
	// Problem 4 synchronous shopping
//	char* storeFile = "files/stores.csv";		/* csv file containing store record */
//	char* centersFile = "files/shopping_centers.csv";		/* csv file containing store record */
//	bool exists = isFile(centersFile);
//	if(exists == true)
//	{
//		printf("file exists\n");
//		size_t size = fileSize(storeFile, row);
//		printf("Number of rows %lu\n", size);
//		StorePtr_t storeList = buildStoreList(storeFile);
//		StorePathPtr_t path = buildStorePathList(centersFile);
//		for(StorePathPtr_t ptr = path; ptr!=NULL; ptr = ptr->nextPath)
//		{
//			printf("Path from %s to %s with distance %i.\n",
//					ptr->m_storeA->m_storeName,
//					ptr->m_storeB->m_storeName,
//					ptr->m_distance);
//			//free(ptr->m_distance);
//		}
//		for(StorePtr_t ptr = storeList; ptr != NULL; ptr = ptr->m_nextStore){
//			printf("store %s has %i types of fish.\n",ptr->m_storeName,ptr->numberFish);
//			free(ptr->m_storeName);
//			for(FishPtr_t fishPtr = ptr->m_fishList; fishPtr != NULL; fishPtr = fishPtr->m_nextFish)
//			{
//				printf("\tType of fish: %s\n",fishPtr->m_fishName);
//				free(fishPtr);
//			}
//			free(ptr);
//		}
//	}
//	else
//	{
//		printf("file does not exist");
//	}

	return 0;
}
