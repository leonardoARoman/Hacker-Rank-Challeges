/**
 * @brief 	 Synchronous Shopping
 * 			 Solution for Hacker Rank's Forming a Magic Square challenge
 *
 * @author	 Hacker Rank www.hackerrank.com
 * 			 "Bitville is a seaside city that has a number of shopping centers connected
 * 			 by bidirectional roads, each of which has a travel time associated with it.
 * 			 Each of the shopping centers may have a fishmonger who sells one or more
 * 			 kinds of fish. Two cats, Big Cat and Little Cat, are at shopping center
 * 			 (each of the centers is numbered consecutively from  to ). They have a list
 * 			 of fish they want to purchase, and to save time, they will divide the list
 * 			 between them. Determine the total travel time for the cats to purchase all
 * 			 of the types of fish, finally meeting at shopping center . Their paths may
 * 			 intersect, they may backtrack through shopping center , and one may arrive
 * 			 at a different time than the other. The minimum time to determine is when
 * 			 both have arrived at the destination."
 *
 * @solution lroman 03/5/2020
 */
#include <stdlib.h>
#include <stdbool.h>

#ifndef SYSNCHRONOUS_SHOPPING_H
#define SYSNCHRONOUS_SHOPPING_H

struct Fish_t
{
	char* m_fishName;
	struct Fish_t* m_nextFish;

};
typedef struct Fish_t* FishPtr_t;

struct Store_t
{
	char* m_storeName;           /* string         Store Name                */
	uint8_t numberFish;          /* uint8_t        number of fish type       */
	FishPtr_t m_fishList;        /* StringArray    Types of Fishes           */
	bool m_hasBeenVisited;       /* boolean        Flag                      */
	struct Store_t* m_nextStore; /* Store_t*       Shortest Distance Store	 */

};
typedef struct Store_t* StorePtr_t;

struct StorePath_t
{
	StorePtr_t m_storeA;
	StorePtr_t m_storeB;
	int* m_distance;
	struct StorePath_t* nextPath;

};
typedef struct StorePath_t* StorePathPtr_t;

typedef struct Cat
{
	char* m_cat;
	char* m_fishes[4];
	StorePathPtr_t* m_path;

} Cat_t;

typedef struct RoadMap
{
	StorePtr_t m_stores[4];

} RoadMap_t;

StorePtr_t buildStoreList(const char*);
StorePtr_t findStore(const char*);
StorePathPtr_t buildStorePathList(const char*);
uint32_t getStoreCount();
#endif /* SYSNCHRONOUS_SHOPPING_H */
