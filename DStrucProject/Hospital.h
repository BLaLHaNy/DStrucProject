#pragma once
#include "LinkedQueue.h"
#include "priQueue.h"
#include "Patient.h"
#include "QueueCancel.h"
#include "Car.h"

class Hospital
{
private:
	int id;
	int distance;
	LinkedQueue<Patient*> WaitingP;
	QueueCancel NP;
	LinkedQueue<Patient*> SP;
	priQueue<Patient*> EP;
	LinkedQueue<Car*> SC;
	LinkedQueue<Car*> NC;
public:
	static int nextID; // Static variable to hold the next ID

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


