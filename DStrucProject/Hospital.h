#pragma once
#include <vector>
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include "LinkedQueue.h"
#include "PriQueue.h"
#include "PriQueueCancel.h"
#include "QueueCancel.h"
#include "Patient.h"
#include "Car.h"


// Forward declaration of Organizer
class Organizer;

class Hospital {
private:
    int HID=NULL;
    int distance=NULL;
    Organizer* organizer=nullptr; // Forward-declared
    LinkedQueue<Patient*> WaitingP;
    QueueCancel NP;
    LinkedQueue<Patient*> SP;
    priQueue<Patient*> EP;
    LinkedQueue<Car*> SC;
    LinkedQueue<Car*> NC;
    int cSc = 0, cNc = 0, cNp = 0, cSp = 0, cEp = 0; // Counts for SC, NC, NP, etc.
    int WaitingTime = 0;
    int carBusyTime = 0;

public:
    static int nextID; // Static variable to hold the next ID

    // Constructor
    Hospital(Organizer* o);

    // Default constructor
    Hospital() {}

    // Member functions
    void setPatients(Patient* p);
    void setCars(Car* p);
    QueueCancel* getNp();
    LinkedQueue<Patient*>* getSp();
    priQueue<Patient*>* getEp();
    LinkedQueue<Car*>* getSc();
    LinkedQueue<Car*>* getNc();
    bool assignCartoEP(int currentTime);
    bool assignCartoSP(int currentTime);
    bool assignCartoNP(int currentTime);
    void addfailedP(Patient* p, std::string& type);
    Car* removecar(string cartype);
    void print();
    int getHID();
    int getcEp();
    int getcSp();
    int getcNp();
    int getcSc();
    int getcNc();
    bool cancelNP(int pid);
    void PrintEPatinets();
    void PrintSPatinets();
    void PrintNPatinets();
    void PrintNCar();
    void PrintSCar();
};
