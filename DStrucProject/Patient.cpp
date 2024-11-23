#include "Patient.h"
Patient::Patient(int id, string t, int hid, int sev) :ID(id), ptType(t), HID(hid), severity(sev) {}
int Patient::getsev() const
{
	return severity;
}

string Patient::gettype() const
{
	return ptType;
}
