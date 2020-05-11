/*
 * class.c
 *
 *  Created on: Apr 30, 2020
 *      Author: leoroman
 */

#include <stdio.h>
#include <stdlib.h>

#include "class.h"


// to be allocated
Person_Ptr person;

char* getName()
{
	return person->name;
}

void setName(char* name)
{
	person->name = name;
}

int getAge()
{
	return person->age;
}

void setAge(int age)
{
	person->age = age;
}

Person_Ptr Person(char* name, int age)
{
	person = malloc(sizeof(Person_t));
	person->name = name;
	person->age = age;
	person->GetName = getName;
	person->SetName = setName;
	person->GetAge = getAge;
	person->SetAge = setAge;

	return person;
}

void _Person(Person_Ptr p)
{
	free(p);
}
