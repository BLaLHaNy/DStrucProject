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
	int ReqTime;
	string ptType;
	int HID;
	int severity;
	int Hdis;
public:
	Patient(string t, int RqTime,int id, int hid,int Hdis, int sev = 1);
	int getsev() const;
	void AssignHospital();
	string gettype() const;
	int getReqTime();
	int getHID();
	int getID();


};

