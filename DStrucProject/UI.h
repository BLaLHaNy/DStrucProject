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
    int InterfaceMode=0;
    Organizer* organizer; 

public:
    UI(Organizer* org); 
    void printHospitals(Hospital *H, int id);
    void printCars(PriQueueCancel *out, priQueue<Car*>* back, LinkedQueue<Patient*>* finished);
    void OutputFile();
};



