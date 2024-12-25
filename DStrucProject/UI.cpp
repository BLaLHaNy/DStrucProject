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

void UI::ProgramInterface(Hospital* h,int timestep,int NoHp, int cOc, int cBc)
{
	int mode;
	cout << "Choose Interface Mode (1==>Interactive Mode , 2==>Silent Mode): ";
	cin >> mode;
	if (mode == 1)
	{
		//Organizer o("Input.txt");
		//o.Load();
		//Hospital* h=o.gethospitallist();
		
		
	
		//Patient* tempPatient;
		//int lkjl;
		//temp1->dequeue(tempPatient);
		//cout << "nnnnnnnnnn"<<tempPatient->getID() << " nnnnnnnnnnnnnnnnnnnnn ";
		cout <<"TimeStep: " << timestep << endl;

		for (int i = 0; i < NoHp; i++)
		{
			
			cout << "========== Hospital #"<<h[i].getHID()<< " data ==========" << endl;
			
			

			//cout << h[i].getEp().getcount() << endl;

			//Emergency Patient

			cout << h[i].getcEp() << " EP requests: ";
			priQueue<Patient*>* temp = h[i].getEp();
			int pri;
			
			priQueue<Patient*> nottemp2;
			Patient* tempPatient;
			for (int k = 0; k < h[i].getcSp(); k++)
			{

				temp->dequeue(tempPatient,pri);
				cout << tempPatient->getID() << "  ";
				nottemp2.enqueue(tempPatient,pri);

			}
			for (int k = 0; k < h[i].getcSp(); k++)
			{

				nottemp2.dequeue(tempPatient,pri);
				temp->enqueue(tempPatient,pri);

			}
			cout << endl;

			//Special Patient

			cout << h[i].getcSp() << " SP requests: ";
			LinkedQueue<Patient*>* temp1 = h[i].getSp();
			LinkedQueue<Patient*> nottemp;
			
			for (int k = 0; k < h[i].getcSp(); k++)
			{
				
				temp1->dequeue(tempPatient);
				cout << tempPatient->getID() << "  ";
				nottemp.enqueue(tempPatient);
			
			}
			for (int k = 0; k < h[i].getcSp(); k++)
			{
				
				nottemp.dequeue(tempPatient);
				temp1->enqueue(tempPatient);

			}
			cout << endl;

			//Normal Patient

			cout << h[i].getcNp() << " NP requests: ";
			QueueCancel* temp2 = h[i].getNp();
			QueueCancel nottemp3;

			for (int k = 0; k < h[i].getcSp(); k++)
			{

				temp2->dequeue(tempPatient);
				cout << tempPatient->getID() << "  ";
				nottemp3.enqueue(tempPatient);

			}
			for (int k = 0; k < h[i].getcSp(); k++)
			{

				nottemp3.dequeue(tempPatient);
				temp2->enqueue(tempPatient);

			}
			cout << endl;
			
			//SCars & NCars

			cout << "Free cars: " << h[i].getcSc() << " SCars, " << h[i].getcNc() << " NCars" << endl;
			cout << "========== Hospital #" << h[i].getHID() << " data end ==========" << endl;
			cout << "------------------------------------------------------" << endl;
			cout << "OutCars: " << cOc << endl;
			cout << "BackCars: " << cBc << endl;
		}
		//delete[] h;
		//h = nullptr;
		

	}
	else
	{
		cout << "Silent Mode, Simulation Starts..."<<endl;
		cout << "Simulation ends, Output file created"<<endl;
	}
	
}

bool UI::chooseMode()
{
	return false;
}

void UI::printStatus()
{
}

void UI::printFinalStatistics()
{
}

void UI::printQueue(const LinkedQueue<Patient*> queue)
{
}

void UI::printPriorityQueue(const PriQueueCancel& queue)
{
}

int UI::GetNumCars()
{
	return 0;
}

int UI::GetNumNCars()
{
	return 0;
}

int UI::GetNumSCars()
{
	return 0;
}

void UI::writeOutputFile()
{
}

void UI::OutputFile()
{
}


