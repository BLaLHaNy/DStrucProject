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
	QueueCancel NP;
	LinkedQueue<Patient*> SP;
	priQueue<Patient*> EP;
	LinkedQueue<Car*> SC;
	LinkedQueue<Car*> NC;
	int cSc =0, cNc=0,cNp=0,cSp=0,cEp=0;

public:
	static int nextID; // Static variable to hold the next ID

	Hospital();
	void setPatients(Patient* p);
	void setCars(Car* p);
	void assigncar(Patient* P, Car* c);//not done yet
	QueueCancel* getNp();
	LinkedQueue<Patient*>* getSp();
	priQueue<Patient*>* getEp();
	LinkedQueue<Car*>* getSc();
	LinkedQueue<Car*>* getNc();
	int getHID();
	int getcEp();
	int getcSp();
	int getcNp();
	int getcSc();
	int getcNc();
	

};


