#include "UI.h"

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
#include "Organizer.h"

using namespace std;

void UI::ProgramInterface()
{
	cout << "Choose Interface Mode (1==>Interactive Mode , 2==>Silent Mode): ";
	if (InterfaceMode == 1)
	{
		Organizer o("Input.txt");
		Hospital* h=o.gethospitallist();
		Patient* p;
		for (int i = 0; i < o.getNoHp(); i++)
		{
			cout << "Current Timestep: " << o.getTimestep()<<endl;
			cout << "========== Hospital #"<<h[i].getHID()<< " data ==========" << endl;
			cout << h[i].getEp().getcount() << " EP requests: ";
			for (int i = 0; i < h[i].getEp().getcount(); i++)
			{
				priQueue<Patient*> temp = h[i].getEp();
				Patient* tempPatient;
				int pri;
				temp.dequeue(tempPatient,pri);
				cout << tempPatient->getID() << ", ";
			}
			cout << endl;
			cout << h[i].getSp().getCount() << " SP requests: ";
			for (int i = 0; i < h[i].getSp().getCount(); i++)
			{
				Patient* tempPatient;
				temp.dequeue(tempPatient);
				cout << tempPatient->getID() << ", ";
			}
			cout << endl;
			cout << h[i].getNp().getCount() << " SP requests: ";
			for (int i = 0; i < h[i].getNp().getCount(); i++)
			{
				QueueCancel temp = h[i].getNp();
				Patient* tempPatient;
				temp.dequeue(tempPatient);
				cout << tempPatient->getID() << ", ";
			}
			cout << endl;
			cout << "Free cars: " << h[i].getSc().getCount() << " SCars, " << h[i].getNc().getCount() << " NCars" << endl;
			cout << "========== Hospital #" << h[i].getHID() << " data end ==========" << endl;
			cout << "------------------------------------------------------" << endl;
		}


	}
	else
	{
		cout << "Silent Mode, Simulation Starts..."<<endl;
		cout << "Simulation ends, Output file created"<<endl;
	}
}
