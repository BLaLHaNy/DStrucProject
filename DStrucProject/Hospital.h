#pragma once
#include "LinkedQueue.h"
#include "priQueue.h"
#include "Patient.h"
#include "QueueCancel.h"
#include "Car.h"
#include "Organizer.h"

class Hospital
{
private:
	int HID;
	int distance;
	Organizer* organizer;
	LinkedQueue<Patient*> WaitingP;
	QueueCancel NP;
	LinkedQueue<Patient*> SP;
	priQueue<Patient*> EP;
	LinkedQueue<Car*> SC;
	LinkedQueue<Car*> NC;
	int cSc =0, cNc=0,cNp=0,cSp=0,cEp=0;
	int WaitingTime = 0;
	int carBusyTime = 0;

public:
	static int nextID; // Static variable to hold the next ID

	Hospital(Organizer* o);
	void setPatients(Patient* p);
	void setCars(Car* p);
	
	QueueCancel* getNp();
	LinkedQueue<Patient*>* getSp();
	priQueue<Patient*>* getEp();
	LinkedQueue<Car*>* getSc();
	LinkedQueue<Car*>* getNc();
	void assignCartoEP(int currentTime);
	void assignCartoSP(int currentTime);
	void assignCartoNP(int currentTime);
	void addfailedP(Patient* p, string& type);
	void print();
	int getHID();
	int getcEp();
	int getcSp();
	int getcNp();
	int getcSc();
	int getcNc();
	

};


