#pragma once
#include "LinkedQueue.h"
#include "priQueue.h"
#include "Patient.h"
#include <iostream>
using namespace std;
class Patient
{
private:
	int ID;
	string ptType;
	int HID;
	int severity;
public:
	Patient(int id, string t, int hid, int sev);
	int getsev() const;
	string gettype() const;


};

