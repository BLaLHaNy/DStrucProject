#pragma once
#include <vector>
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include "LinkedQueue.h"
#include "PriQueue.h"
#include "PriQueueCancel.h"
#include "Hospital.h"
#include "Patient.h"
#include "Car.h"

// Forward declaration
class UI;

using namespace std;

class Organizer {
private:
    UI* ui=nullptr;  // Use forward declaration
    LinkedQueue<Patient*> AllPatients;
    LinkedQueue<Patient*> Cancellationlist;
    LinkedQueue<Patient*> DonePatients;
    PriQueueCancel OutCar;
    priQueue<Car*> BackCar;
    string fname;
    int NoHp;
    int noNC;
    int numOutCars, numBackCars;
    int fprob = 0;
    int DonePcount = 0;
    int SpeedScar, SpeedNcar;
    int** distance;
    int timestep;
    int NoReq, NoCancReq;
    int noHospitals;
public:
    Hospital** Hospitals;

    Organizer(const string& fnames);
    void Load();
    LinkedQueue<Patient*> getdone();
    LinkedQueue<Patient*> getcanceeled();
    LinkedQueue<Patient*> getallpatients();
    Hospital** gethospitallist();
    void Addfinished(Patient* p);
    void cancelP(int time);
    ~Organizer();
    void Simulate(int mode);
    int getTimestep();
    int getNoHp();
    priQueue<Car*> getOutCars();
    priQueue<Car*> getBackCars();

    bool addOutCar(int hid, string type);
    bool addBackCar(int current_time);
    bool addFreeCar(int current_time);
    void printDone();
    void printOutCars();
    void printBackCars();

    void assignEPtoNewHospital(Patient* p, int severity);
};

