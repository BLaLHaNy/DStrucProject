#pragma once
#include "LinkedQueue.h"
#include "priQueue.h"
#include "Patient.h"
#include "QueueCancel.h"
#include "Car.h"

class Hospital
{
private:
	static int HID;
	int distance;
	LinkedQueue<Patient*> WaitingP;
	QueueCancel NP;
	LinkedQueue<Patient*> SP;
	priQueue<Patient*> EP;
	LinkedQueue<Car*> SC;
	LinkedQueue<Car*> NC;
public:
	Hospital();
	void setPatients(Patient* p);
	void setCars(Car* p);
	void assigncar(Patient* P, Car* c);//not done yet
	QueueCancel getNp();
	LinkedQueue<Patient*> getSp();
	priQueue<Patient*> getEp();
	LinkedQueue<Car*> getSc();
	LinkedQueue<Car*> getNc();
	int getHID();

};

int Hospital:: HID = 0;