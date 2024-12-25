#pragma once
#include "LinkedQueue.h"
#include "priQueue.h"
#include <iostream>
using namespace std;
class Patient
{
private:
	int ID;
	int ReqTime;
	int cancellationtime;
	int fininshtime;
	int Pickuptime;
	int waitingtime;
	int distance;
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
	void setPickUpTime(int time);
	int getPickTime()const;
	void setFinishTime(int time);
	int getDistance() const;
	void setdis();
	int getcancelTime()const;
	void setcancelTime(int time);
	int getWaitTime()const;
	int getFinishTime()const;

};

