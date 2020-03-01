#include "header/countingvalleys.h"

///////////////////////////////////////////////////////////////
// Private variable to store the head of the list
///////////////////////////////////////////////////////////////
static Terrain* head;

///////////////////////////////////////////////////////////////////////////////////
// @param
///////////////////////////////////////////////////////////////////////////////////
void AddTerrain(Terrain* terrain)
{
	Terrain* cpTerrain = (Terrain*)malloc(sizeof(*terrain));
	*cpTerrain = *terrain;
	if(head==NULL)
	{
		head = (Terrain*)malloc(sizeof(*terrain));
		head->nextTerrain = (Terrain*)malloc(sizeof(*terrain));
		*head = *terrain;
	}
	else
	{
		cpTerrain->nextTerrain = (Terrain*)malloc(sizeof(*terrain));
		*cpTerrain->nextTerrain = *head;
		*head = *cpTerrain;
		*head->nextTerrain = *cpTerrain->nextTerrain;
	}
	free(terrain);
	//printf("%s of size %i added to Hiker's log. Freeing [%s] at memory %lu\n",head->name,head->lenght,head->name,&terrain);
}

///////////////////////////////////////////////////////////////////////////////////
// @param
// @param
///////////////////////////////////////////////////////////////////////////////////
void countingValleys(char* steps, int size)
{
	Terrain* mountain = NULL;
	Terrain* valley = NULL;
	int stepcount = 0;
	for (int i = 0; i < size; i++)
	{
		if(steps[i]=='u')
		{
			stepcount++;
			printf("step %c; %i\n",steps[i],stepcount);
			if(mountain == NULL)
			{
				mountain = (Terrain*)malloc(sizeof(mountain)); // possible memory leak at one step up, one step down.
			}
			if(stepcount==2 && mountain->entered == 0)
			{
				// After two positive steps, define mountain record as entered
				printf("You are climbing a mountain...\n");
				mountain->entered = 1;
				mountain->lenght = 2;
			}
			else if(stepcount - mountain->lenght > 0)
			{
				// update mountain's height as number of steps increase
				mountain->lenght += 1;
			}
		}
		else if(steps[i]=='d')
		{
			stepcount--;
			printf("step %c; %i\n",steps[i],stepcount);
			if(valley == NULL)
			{
				printf("Warning: allocating memory for a valley!\n");
				valley = (Terrain*)malloc(sizeof(valley)); // possible memory leak at one step up, one step down.
			}
			if(stepcount==-2 && valley->entered == 0)
			{
				printf("You have entered a valley...\n");
				valley->entered = 1;
				valley->lenght = 2;
			}
			else if(stepcount + valley->lenght < 0)
			{
				valley->lenght += 1;
			}
		}
		// You either got out of a mountain or valley
		if (stepcount == 0)
		{
			if(mountain->entered == 1)
			{
				printf("You are off the mountain.\n");
				mountain->entered = 0;
				mountain->name = "Mountain";
				AddTerrain(mountain);
				mountain = NULL;
			}
			else if(valley->entered == 1)
			{
				printf("You are out the valley.\n");
				valley->entered = 0;
				valley->name = "Valley";
				AddTerrain(valley);
				valley = NULL;
			}
		}
	}
	// this may be put in main, optionally here.
	printPath();
	deleteTerrain(head);
}

///////////////////////////////////////////////////////////////////////////////////
// @return
///////////////////////////////////////////////////////////////////////////////////
Terrain* getHead()
{
	return head;
}

///////////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////////
void printPath()
{
	Terrain* curr = head;
	if (curr == NULL) {
		printf("Error: null pointer exception\n");
		return;
	}
	printf("Terrain List:\n");
	while(curr!= NULL)
	{
		printf("[%s: %i]->",curr->name,curr->lenght);
		curr = curr->nextTerrain;
	}
	printf("NULL\n");
}

///////////////////////////////////////////////////////////////////////////////////
// @param
///////////////////////////////////////////////////////////////////////////////////
void deleteTerrain(Terrain* head)
{
	Terrain* curr = head;
	while(curr!=NULL)
	{
		free(curr);
		//printf("Freeing [%s: %i]\tat memory %lu\n",curr->name,curr->lenght,&*curr);
		curr = curr->nextTerrain;
	}
	free(curr);
	curr = NULL;
}

