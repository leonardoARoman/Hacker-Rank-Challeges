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

typedef struct Fish_t
{
	char* m_fishName;
	struct Fish_t* m_nextFish;

} Fish_t;

typedef struct Store_t
{
	char* m_storeName; 				/* string 		Store Name 				 */
	Fish_t* m_fishList;				/* StringArray 	Types of Fishes  	 	 */
	bool m_hasBeenVisited;			/* boolean 		Flag 					 */
	struct Store_t* m_nextStore;	/* Store_t* 	Shortest Distance Store	 */

} Store_t;

typedef struct StorePath
{
	Store_t m_storeA;
	Store_t m_storeB;
	uint32_t m_distance;

} StorePath_t;

typedef struct Cat
{
	char* m_cat;
	char* m_fishes[4];
	StorePath_t* m_path;

} Cat_t;

typedef struct RoadMap
{
	Store_t* m_stores[4];

} RoadMap_t;

Store_t* buildStoreList(const char*);
uint32_t getStoreCount();
#endif /* SYSNCHRONOUS_SHOPPING_H */
