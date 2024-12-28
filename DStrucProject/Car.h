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
	void Pickup();
	int getspeed() const;
	void setAP(Patient* AP,int time);
	Patient* dropoff();
	int cancelAssignedPatient();
	void setstatus(string s);
	Patient* getAP();
	int getReachTime();
	int getAssignmentTime();
	bool getfailed() const;//bonus
	void setfailed();//bonus
	void setreachtime(int time) {
		arrivalTime = time;
	}
	void setfailedpatient();//bonus
	int getHID();
	~Car();
	
};

