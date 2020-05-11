#include <stdio.h>

#include "publisherIf.h"

#define SUBSCRIBER_COUNT 4

// Private attributes
static int m_batteryLifePercentage;
static Observer* m_subscribers[SUBSCRIBER_COUNT];

// private functions
static void publisher_Publish();

void publisher_Subscribe(Observer* subscriber)
{
	for(int i = 0; i < SUBSCRIBER_COUNT; i++)
	{
		if(m_subscribers[i] == NULL)
		{
			printf("Publisher: %s has subscribed!\n",subscriber->subsystemName);
			m_subscribers[i] = subscriber;
			m_subscribers[i]->subscriberId = i + 1;
			break;
		}
	}
}

void publisher_Publish()
{
	// publish battery life
	for(int i = 0; i < SUBSCRIBER_COUNT; i++)
	{
		if(m_subscribers[i] != NULL)
		{
			printf("Publisher: Publishing Battery Life to all Observers...\n");
			m_subscribers[i]->notify(m_batteryLifePercentage);
		}
	}

}

void publisher_NotifyBatteryLife(int batteryLifePercentage)
{
	m_batteryLifePercentage = batteryLifePercentage;
	publisher_Publish();
}
