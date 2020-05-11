/*
 * class.h
 *
 *  Created on: Apr 30, 2020
 *      Author: leoroman
 */

#ifndef HEADER_CLASS_H_
#define HEADER_CLASS_H_

typedef struct Class_Person
{
	char* name;
	int age;

	char*(*GetName)(void);
	void(*SetName)(char*);
	int(*GetAge)(void);
	void(*SetAge)(int);
} Person_t;

typedef Person_t* Person_Ptr;

// constructor
Person_Ptr Person(char*,int);

// destructure
void _Person(Person_Ptr);

#endif /* HEADER_CLASS_H_ */
