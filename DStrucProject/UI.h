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



class UI
{
private:
	int InterfaceMode;
	Organizer* organizer;
	string ifname;
	string ofname;
public:
	void ProgramInterface();
    UI(Organizer* org) : organizer(org) {};
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



