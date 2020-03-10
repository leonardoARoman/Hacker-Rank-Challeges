#include "synchronousshopping.h"

// To keep a count of stores created from the csv file
static uint32_t storeCount = 0;

// private helper methods
static inline void split(char*);

///////////////////////////////////////////////////////////////////////////////////
// @param fileName 	-csv file with store record
// @param head 		-head of the store list
///////////////////////////////////////////////////////////////////////////////////
void buildStoreArrayList(char* fileName, Store_t* head)
{
	Store_t store = {"A",false,NULL};
	// TODO open the csv file

	// TODO traverse the file and create Nodes
	split(NULL);
	// TODO split each line in file on every comma
	if(head == NULL)
	{

	}
	// TODO close file
	storeCount++;
}

///////////////////////////////////////////////////////////////////////////////////
// @return storeCount -The count of stores created
///////////////////////////////////////////////////////////////////////////////////
uint32_t getStoreCount()
{
	return storeCount;
}


static inline void split(char* str)
{

}
