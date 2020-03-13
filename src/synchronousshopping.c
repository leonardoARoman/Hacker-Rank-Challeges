#include "synchronousshopping.h"
#include <string.h>
#include <stdio.h>

// To keep a count of stores created from the csv file
static uint32_t storeCount;
static StorePtr_t head;

// private helper methods
static inline StorePtr_t makeStore(char*);
static inline FishPtr_t makeFishList(FishPtr_t, char*);

///////////////////////////////////////////////////////////////////////////////////
// @brief open file to create a linked list of stores and returns the head
// @param fileName 	-csv file with store record
// @return head  	-returns head of the store list
///////////////////////////////////////////////////////////////////////////////////
StorePtr_t buildStoreList(const char* fileName)
{
	const int SIZE = 1024;
	// TODO opening files may be expensive, may need to pass a FILE as argument
	FILE *stream = fopen(fileName,"r");
	char buff[SIZE];
	while (fgets(buff,SIZE,(FILE*)stream))    /* Stream line by line and put it in buffer   */
	{
		int i = 0;                            /* reset count for next store                 */
		char *token = strtok(buff,",");       /* point to the first string before a comma   */
		StorePtr_t store = makeStore(token);  /* declare Store_t ptr and define attributes  */
		while (token!=NULL)                   /* traverse all commas                        */
		{
			token = strtok(NULL,",");         /* point to next string before a comma        */
			if(token!=NULL){
				i++;                          /* number of fishes counted                   */
				store->m_fishList = makeFishList(store->m_fishList,token);
			}
		}
		store->numberFish = i;
		if(head == NULL){
			head = store;
		}else{
			store->m_nextStore = head;
			head = store;
		}
	}
	fclose((FILE*)stream);
	return head;
}

static inline StorePtr_t makeStore(char* token)
{
	struct Store_t* store = malloc(sizeof(struct Store_t));
	store->m_storeName = strdup(token);
	store->numberFish = 0;
	store->m_fishList = NULL;
	store->m_hasBeenVisited = false;
	store->m_nextStore = NULL;
	storeCount++;
	return store;
}

static inline FishPtr_t makeFishList(FishPtr_t headFish, char* token)
{
	FishPtr_t fish = malloc(sizeof(FishPtr_t));
	fish->m_fishName = strdup(token);
	fish->m_nextFish = NULL;
	if(headFish == NULL){
		headFish = fish;
	}else{
		fish->m_nextFish = headFish;
		headFish = fish;
	}
	return headFish;
}

///////////////////////////////////////////////////////////////////////////////////
// @return storeCount -The count of stores created
///////////////////////////////////////////////////////////////////////////////////
uint32_t getStoreCount()
{
	return storeCount;
}

///////////////////////////////////////////////////////////////////////////////////
// @brief open file to create a linked list of paths and returns the head
// @param fileName 	-csv file with paths record
// @return head  	-returns head of the store list
///////////////////////////////////////////////////////////////////////////////////
StorePath_t* buildStorePathList(const char* file)
{
	const int SIZE = 1024;
	static StorePath_t* head = NULL;
	FILE *stream = fopen(file,"r");
	char buff[SIZE];
	while (fgets(buff,SIZE,(FILE*)stream))    /* Stream line by line and put it in buffer   */
	{
		char *store1 = strtok(buff,",");      /* point to the first string before a comma   */
		char *store2 = strtok(NULL,",");      /* point to the first string before a comma   */
		uint32_t distance = atoi(strtok(NULL,","));

		StorePtr_t storeA = findStore(store1);   /* Find store in linked list by name  */
		StorePtr_t storeB = findStore(store2);   /* Find store in linked list by name  */
		StorePath_t* path = malloc(sizeof(StorePath_t));
		path->m_storeA = storeA;
		path->m_storeB = storeB;
		path->m_distance = distance;

		if(head == NULL){
			head = path;
		}else{
			path->nextPath = head;
			head = path;
		}
	}
	fclose((FILE*)stream);
	return head;
}

StorePtr_t findStore(const char* storeName)
{
	StorePtr_t ptr = head;
	StorePtr_t store = NULL;
	while(ptr!=NULL)
	{
		if(strcmp(ptr->m_storeName,storeName)==0){
			printf("%s==%s\n",storeName,ptr->m_storeName);
			store = ptr;
		}
		ptr = ptr->m_nextStore;
	}
	return store;
}

