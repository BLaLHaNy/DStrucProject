#pragma once
#include "LinkedQueue.h"
#include "priQueue.h"
#include "Patient.h"
#include "QueueCancel.h"
#include <vector>
#include "UI.h"
#include <iostream>

using namespace std;


#include "Hospital.h"

class Organizer
{

private:
	UI* ui;
	LinkedQueue<Patient*> AllPatients;
	LinkedQueue<Patient*> Cancellationlist;
	LinkedQueue<Patient*> DonePatients;
	priQueue<Car*> OutCar;
	priQueue<Car*> BackCar;
	string fname;
	int NoHp;
	int noNC;
	int numOutCars, numBackCars;
	int fprob = 0;
	int DonePcount = 0;
	int SpeedScar, SpeedNcar;
	int** distance;
	/*int** arrCars;*/
	
	int timestep;
	int NoReq, NoCancReq;
	/*vector<string> Requests,CancellationReq;*/




public:
	Hospital* Hospitals;

	Organizer(const string& fnames);
	void Load();//not done yet
	LinkedQueue<Patient*> getdone();
	LinkedQueue<Patient*> getcanceeled();
	LinkedQueue<Patient*> getallpatients();
	Hospital* gethospitallist();
	void Addfinished(Patient* p);
	void cancelP();
	~Organizer();
	void Simulate();
	int getTimestep();
	int getNoHp();
	priQueue<Car*> getOutCars();
	priQueue<Car*> getBackCars();
	void addOutCar(Car* c);



};

