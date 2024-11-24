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

void UI::PtogramInterface()
{
	int mode=0;
	cout << "Enter 1 for interaction, 2 for silent";
	cin >> mode;
	Organizer org("Input.txt"); 
	org.Load();
	Hospital* hosp = org.gethospitallist();
	 priQueue<Patient*>tempEP;
	 cout << "current time step" << org.gettimestep();
	if (mode == 1) {
		for (int i = 0; i < org.getnohospital(); i++)
		{
		
			cout << "=============== Hospital#" << hosp[i].getid() << "data" << endl;
			cout << hosp[i].getcEp() <<" EP requests: ";
			for (int j = 0; j < hosp[i].getcEp(); j++)
			{
				Patient* emp;
				int pri;
				hosp[i].getEp().dequeue(emp, pri);
				tempEP.enqueue(emp, pri);
				cout << emp->getID();
				Patient* emp1;
				int pri1;
				tempEP.dequeue(emp, pri);
				hosp[i].getEp().enqueue(emp, pri);
			}
			cout << endl;
			

		}
		
	}
	else if(mode==2)
	{
		cout << "silent mode, simulation starts...";
	}

}
