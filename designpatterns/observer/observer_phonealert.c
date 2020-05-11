#include "observer_phonealert.h"
#include "interface/publisherIf.h"

static int m_batterylife;

static void subservice_UpdateBatteryLife(int);

static Observer observer =
{
	/* char*      subsystemName */ "Phone-Alert",
	/* int        subscriberId  */ 0,
	/* Subscriber notify        */ subservice_UpdateBatteryLife
};

bool subservice_PhoneAlertInit()
{
	printf("Subscriber: Phone-Alert is subscribing as observer of Battery-Life...\n");
	publisher_Subscribe(&observer);
	return true;
}

void subservice_UpdateBatteryLife(int batterylife)
{
	m_batterylife = batterylife;
	printf("Subscriber %i: battery percentage %i percent\n",observer.subscriberId, m_batterylife);
}
