#ifndef PUBLISHER_CLASS_H
#define PUBLISHER_CLASS_H

typedef void(*Subscriber)(int);

typedef struct _Observer
{
	char* subsystemName;
	int subscriberId;
	Subscriber notify;

} Observer;

void publisher_Subscribe(Observer*);
void publisher_NotifyBatteryLife(int);

#endif
