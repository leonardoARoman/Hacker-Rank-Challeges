#include "../header/countingpairs.h"

// add key value pair
void put(Map *map, int key, int size)
{
	int index = key%size;
	// offset is taken
	if(map[index].value > 0)
	{
		// check if given key exist if not assign another slot
		if(map[index].key == key)
		{
			map[index].value += 1;
			//printf("map[%i] = {%i,%i}\n",index,map[index].key,map[index].value);
		}
		else
		{
			//printf("Slot %i taken assigning to next empty slot %i\n",index,--size );
			put(map,key,--size);
		}
	}
	else
	{
		map[index].key = key;
		map[index].value += 1;
		//printf("map[%i] = {%i,%i}\n",index,*map[index].key,map[index].value);
	}
}

void delete(Map *map,int count)
{
	free(map);
}

void findNumberOfPairs(int* numbers, int SIZE)
{
	Map* map = malloc(SIZE * sizeof(map));
	for (int i = 0; i < SIZE; i++)
	{
		put(map,numbers[i],SIZE);
	}
	int ar_count = 0;
	for (int i = 0; i < SIZE; i++)
	{
		if(map[i].value >= 2)
		{
			printf("map[%i] = {%i,%i}\n",i,map[i].key,map[i].value);
			int numofpairs = map[i].value/2;
			ar_count += numofpairs;
		}
	}
	printf("number of pairs %i\n",ar_count );
	delete(map,SIZE);
}
