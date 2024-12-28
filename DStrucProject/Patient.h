#pragma once
#include "LinkedQueue.h"
#include "priQueue.h"
#include <iostream>
using namespace std;
class Patient
{
private:
	int ID;
	int ReqTime=0;
	int cancellationtime=0;
	int fininshtime=0;
	int Pickuptime=0;
	int waitingtime=0;
	int distance=0;
	string ptType;
	int HID;
	int severity;
	int Hdis;
public:
	Patient(string t, int RqTime,int id, int hid,int Hdis, int sev = 1);
	int getsev() const;
	void AssignHospital(int hid);
	string gettype() const;
	int getReqTime() const;
	int getHID();
	int getID();
	void setPickUpTime(int time);
	int getPickTime()const;
	void setFinishTime(int time);
	int getDistance() const;
	void setdis(int dis);
	int getcancelTime()const;
	void setcancelTime(int time);
	int getWaitTime()const;
	int getFinishTime()const;
	void setHID(int hid) {
		HID = hid;
	}
};

