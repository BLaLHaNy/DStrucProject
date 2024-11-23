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
public:
	Car(string t, int s);
	string gettype() const;
	void Pickup();//not done yet
	int getspeed() const;
	void setAP(Patient* AP);
	void dropoff();//not done yet
	void setstatus(string s);
	Patient* getAP();
	/*void setspeed(Car*c);*/
};

