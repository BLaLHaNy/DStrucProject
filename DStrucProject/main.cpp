#include <vector>
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include "LinkedQueue.h"
#include "PriQueue.h"
#include "Hospital.h"
#include "Patient.h"
#include "Car.h"
#include "UI.h"
#include "Organizer.h"

using namespace std;

int main()
{
	/*UI x;
	x.ProgramInterface();*/
	/*Organizer x("Input.txt");
	
	x.Simulate();*/
    Organizer org("Input.txt");
    // choose the scenario file
    int mode;
    cout << "Hello, Choose mode of operation(by typing index integer):" << endl;
    cout << "1. Silent\n2.Interactive" << endl;
    cin >> mode;
    org.Simulate(mode);

}