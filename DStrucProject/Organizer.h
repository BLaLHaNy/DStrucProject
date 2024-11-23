#pragma once
#include "LinkedQueue.h"
#include "priQueue.h"
#include "Patient.h"
#include "QueueCancel.h"

#include <iostream>

using namespace std;


#include "Hospital.h"

class Organizer
{

private:
	LinkedQueue<Patient*> AllPatients;
	LinkedQueue<Patient*> Cancellationlist;
	LinkedQueue<Patient*> DonePatients;
	priQueue<Car*> OutCar;
	priQueue<Car*> BackCar;
	int NoHp;
	int** distance;
	Hospital** Hospitals = new Hospital * [NoHp];
	int timestep;


public:

	Organizer(const string& fname);
	void store(const string& fname);//not done yet
	LinkedQueue<Patient*> getdone();
	LinkedQueue<Patient*> getcanceeled();
	LinkedQueue<Patient*> getallpatients();
	Hospital** gethospitallist();
	~Organizer();

};



