#pragma once
#include "LinkedQueue.h"
#include "priQueue.h"
#include "Patient.h"
#include "QueueCancel.h"
#include <vector>

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
	string fname;
	int NoHp;
	int SpeedScar, SpeedNcar;
	int** distance;
	/*int** arrCars;*/
	Hospital* Hospitals;
	int timestep,cOc,cBc;
	int NoReq, NoCancReq;
	/*vector<string> Requests,CancellationReq;*/




public:

	Organizer(const string& fnames);
	void Load();//not done yet
	LinkedQueue<Patient*> getdone();
	LinkedQueue<Patient*> getcanceeled();
	LinkedQueue<Patient*> getallpatients();
	Hospital* gethospitallist();
	~Organizer();
	void Simulate();
	int getTimestep();
	int getNoHp();
	priQueue<Car*> getOutCars();
	priQueue<Car*> getBackCars();




};

