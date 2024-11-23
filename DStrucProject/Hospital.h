#pragma once
#include "LinkedQueue.h"
#include "priQueue.h"
#include "Patient.h"
#include "QueueCancel.h"
#include "Car.h"

class Hospital
{
private:
	int HID;
	int distance;
	LinkedQueue<Patient*> WaitingP;
	LinkedQueue<Patient*> NP;
	LinkedQueue<Patient*> SP;
	priQueue<Patient*> EP;
	LinkedQueue<Car*> SC;
	LinkedQueue<Car*> NC;
public:
	Hospital(int hid);
	void setPatients(Patient* p);
	void setCars(Car* p);
	void assigncar(Patient* P, Car* c);//not done yet
};

