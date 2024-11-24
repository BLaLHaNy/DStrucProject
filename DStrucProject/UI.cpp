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
	int mode;
	cout << "Choose Interface Mode (1==>Interactive Mode , 2==>Silent Mode): ";
	cin >> mode;
	if (mode == 1)
	{
		Organizer o("Input.txt");
		o.Load();
		Hospital* h=o.gethospitallist();
		QueueCancel* temp1 = h[2].getNp();
		
	
		//Patient* tempPatient;
		//int lkjl;
		//temp1->dequeue(tempPatient);
		//cout << "nnnnnnnnnn"<<tempPatient->getID() << " nnnnnnnnnnnnnnnnnnnnn ";
		

		for (int i = 0; i < o.getNoHp(); i++)
		{
			
			cout << "========== Hospital #"<<h[i].getHID()<< " data ==========" << endl;
			
			

			//cout << h[i].getEp().getcount() << endl;

			//Emergency Patient

			cout << h[i].getcEp() << " EP requests: ";
			priQueue<Patient*>* temp = h[i].getEp();
			
			for (int j = 0; j < h[i].getcEp(); j++)
			{
				
				Patient* tempPatient;
				int pri;
				temp->dequeue(tempPatient,pri);
				cout << tempPatient->getID() << "  ";
				
				
			}
			cout << endl;

			//Special Patient

			cout << h[i].getcSp() << " SP requests: ";
			LinkedQueue<Patient*>* temp1 = h[i].getSp();
			
			for (int k = 0; k < h[i].getcSp(); k++)
			{
				Patient* tempPatient;
				temp1->dequeue(tempPatient);
				cout << tempPatient->getID() << "  ";
				
			
			}
			cout << endl;

			//Normal Patient

			cout << h[i].getcNp() << " NP requests: ";
			QueueCancel* temp2 = h[i].getNp();
			for (int l = 0; l < h[i].getcNp(); l++)
			{
				
				Patient* tempPatient;
				temp2->dequeue(tempPatient);
				cout << tempPatient->getID() << "  ";
				
				
			}
			cout << endl;

			//SCars & NCars

			cout << "Free cars: " << h[i].getcSc() << " SCars, " << h[i].getcNc() << " NCars" << endl;
			cout << "========== Hospital #" << h[i].getHID() << " data end ==========" << endl;
			cout << "------------------------------------------------------" << endl;
		}
		delete[] h;
		h = nullptr;
		

	}
	else
	{
		cout << "Silent Mode, Simulation Starts..."<<endl;
		cout << "Simulation ends, Output file created"<<endl;
	}
	
}
