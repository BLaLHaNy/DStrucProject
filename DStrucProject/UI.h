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
#include "Organizer.h"

using namespace std;



class UI {
private:
    int InterfaceMode;
    Organizer* organizer; // Ensure this is declared properly
    string ifname;
    string ofname;

public:
    // Constructor correctly initializes organizer
    UI(Organizer* org) : organizer(org) {}
    void ProgramInterface(Hospital* h, int timestep, int NoHp, int cOc, int cBc);
    bool chooseMode();
    void printStatus();
    void printFinalStatistics();
    void printQueue(const LinkedQueue<Patient*> queue);
    void printPriorityQueue(const PriQueueCancel& queue);
    int GetNumCars();
    int GetNumNCars();
    int GetNumSCars();
    void writeOutputFile();
    void OutputFile();
};



