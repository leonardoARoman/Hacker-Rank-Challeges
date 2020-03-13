#include "synchronousshopping.h"
#include <string.h>
#include <stdio.h>

// To keep a count of stores created from the csv file
static uint32_t storeCount = 0;

// private helper methods
static inline void split(char*);
static inline Store_t* makeStore(char*);
static inline Fish_t* makeFishList(Fish_t*, char*);

///////////////////////////////////////////////////////////////////////////////////
// @brief open file to create a linked list of stores and returns the head
// @param fileName 	-csv file with store record
// @return head  	-returns head of the store list
///////////////////////////////////////////////////////////////////////////////////
Store_t* buildStoreList(const char* fileName)
{
	const int SIZE = 1024;
	static Store_t* head = NULL;
	// TODO opening files may be expensive, may need to pass a FILE as argument
	FILE *stream = fopen(fileName,"r");
	char buff[SIZE];
	while (fgets(buff,SIZE,(FILE*)stream))  /* Stream line by line and put it in buffer */
	{
		int i = 0;							/* reset count for next store				*/
		char *token = strtok(buff,",");		/* point to the first string before a comma */
		Store_t* store = makeStore(token);
		while (token!=NULL)					/* traverse all commas 						*/
		{
			i++;							/* number of fishes counted 				*/
			token = strtok(NULL,",");		/* point to next string before a comma 		*/
			if(token!=NULL)
			{
				store->m_fishList = makeFishList(store->m_fishList,token);
				//printf("store %s fish %s\n",store->m_storeName,store->m_fishList->m_fishName);
			}
		}

		if(head == NULL){
			head = store;
		}else{
			store->m_nextStore = head;
			head = store;
		}
		storeCount++;
	}
	fclose((FILE*)stream);
	return head;
}

static inline Store_t* makeStore(char* token)
{
	Store_t* store = malloc(sizeof(Store_t));
	store->m_storeName = strdup(token);			/* save a copy of token */
	store->m_hasBeenVisited = false;
	store->m_fishList = NULL;
	store->m_nextStore = NULL;
	return store;
}

static inline Fish_t* makeFishList(Fish_t* headFish, char* token)
{
	Fish_t* fish = malloc(sizeof(Fish_t));
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


static inline void split(char* str)
{

}
