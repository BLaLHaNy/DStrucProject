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
	return this->HID;
}

int Patient::getID()
{
	return ID;
}
