#pragma once
#include "LinkedQueue.h"
#include "priQueue.h"
#include "Patient.h"
#include <iostream>
using namespace std;
class Car
{
private:
	Patient* AssignedPatient = nullptr;
	string type;
	int speed;
	string status = "FreeCar";
	int assignTime ;
	int HospitalID;
	int arrivalTime;
	bool failed = false;
public:
	Car(string t, int s, int HID);
	string gettype() const;
	void Pickup();//not done yet
	int getspeed() const;
	void setAP(Patient* AP,int time);
	Patient* dropoff();//not done yet
	int cancelAssignedPatient();
	void setstatus(string s);
	Patient* getAP();
	int getReachTime();
	int getAssignmentTime();
	/*Patient* getAssignedPatient();*/
	bool getfailed() const;
	void setfailed();
	void setreachtime(int time) {
		arrivalTime = time;
	}
	void setfailedpatient();
	int getHID();
	~Car();
	
};

