#include "Patient.h"
Patient::Patient(string t, int RqTime, int id, int hid, int Hdist, int sev) :ptType(t),ReqTime(RqTime),ID(id), HID(hid),Hdis(Hdist),severity(sev) {}
int Patient::getsev() const
{
	return severity;
}

void Patient::AssignHospital()
{

}

string Patient::gettype() const
{
	return ptType;
}

int Patient::getReqTime()
{
	return ReqTime;
}

int Patient::getHID()
{
	return HID;
}

int Patient::getID()
{
	return ID;
}

void Patient::setPickUpTime(int time)
{
	Pickuptime = time;
	waitingtime = Pickuptime - ReqTime; 
}

int Patient::getPickTime() const
{
	return Pickuptime;
}

void Patient::setFinishTime(int)
{
}

int Patient::getDistance() const
{
	return distance;
}

void Patient::setdis()
{
}

int Patient::getcancelTime() const
{
	return 0;
}

void Patient::setcancelTime(int time)
{
}

int Patient::getWaitTime() const
{
	return 0;
}

int Patient::getFinishTime() const
{
	return 0;
}
