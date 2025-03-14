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

UI::UI(Organizer* org)
{
	organizer = org;
}

void UI::OutputFile()
{
    ofstream file("output.txt");

        LinkedQueue<Patient*> tempQueue = organizer->getallpatients();
        Patient* temp;
        while (!tempQueue.isEmpty()) {
            tempQueue.dequeue(temp);
         
            file << temp->getFinishTime() << "\t"
                << temp->getID() << "\t"
                << temp->getReqTime() << "\t" << endl;
        }


        file << "--------------------------------------\n";
        file<< "Patients: " << organizer->getNoReq() << "\n";
        file << "hospitals " << organizer->getNoHp() << "\n";

        int ncar = 0; 
        int scar = 0;
        for (int i = 0; i < organizer->getNoHp(); i++)
        {
            ncar += organizer->gethospitallist()[i]->getcNc();
            scar += organizer->gethospitallist()[i]->getcSc();

        }
        file << "Cars: " << " [ " << "NCars " << ncar << " Scars " << scar << " ]" << endl;
        file << "Average Waiting Time: " << organizer->calculateAverageWaitingTime() << " timesteps\n";


    
}

void UI::printHospitals(Hospital* hospital, int ID)
{
    for (int i =0; i < 10; i++) {
        cout << '='; 
    } 
    cout << "Hospital #" << ID << "Data"; 
    for (int i = 0 ; i < 10; i++) { 
        cout << '='; 
    }
    cout << endl;

    priQueue<Patient*>* EP;
    LinkedQueue<Patient*>* SP;
    QueueCancel* NP;
    EP= hospital->getEp();
    SP = hospital->getSp();
    NP = hospital->getNp();
    cout << EP->getcount() << " EP requests: "; 
    hospital->PrintEPatinets();
    cout << endl;
    cout << SP->getCount() << " SP requests: ";
    hospital->PrintSPatinets();
    cout << endl;
    cout << NP->getCount() << " NP requests: ";
    hospital->PrintNPatinets();
    cout << endl;
    LinkedQueue<Car*>* NC;
    LinkedQueue<Car*>* SC;
    NC=hospital->getNc();
    SC = hospital->getSc();
    cout << "Free cars: " << NC->getCount() << " Normal, " << SC->getCount() << " Special" << endl;
    for (int i = 0; i < 10; i++) {
        cout << '='; 
    } 
    cout << "Hospital #" << ID << "END";
    for (int i = 0; i < 10; i++) { 
        cout << '='; 
    } 
    cout << endl;
}




void UI::printCars(PriQueueCancel* outcars, priQueue<Car*>* backcars, LinkedQueue<Patient*>* finishedlist)
{
    for (int i = 0; i < 20; i++) {
        cout << '-';
    } 
    cout << endl;
    cout << outcars->getcount() << " ==> Out Cars: ";
    organizer->printOutCars();
    cout << endl;
    cout << backcars->getcount() << " <== Back Cars: ";
    organizer->printBackCars();
    cout << endl;
    for (int i=0; i < 20; i++) {
        cout << '-';
    } cout << endl;
    cout << finishedlist->getCount() << " Finished Patients: ";
    organizer->printDone();
    cout << endl;

}



//void UI::ProgramInterface(Hospital* h,int timestep,int NoHp, int cOc, int cBc)
//{
//	int mode;
//	cout << "Choose Interface Mode (1==>Interactive Mode , 2==>Silent Mode): ";
//	cin >> mode;
//	if (mode == 1)
//	{
//		//Organizer o("Input.txt");
//		//o.Load();
//		//Hospital* h=o.gethospitallist();
//		
//		
//	
//		//Patient* tempPatient;
//		//int lkjl;
//		//temp1->dequeue(tempPatient);
//		//cout << "nnnnnnnnnn"<<tempPatient->getID() << " nnnnnnnnnnnnnnnnnnnnn ";
//		cout <<"TimeStep: " << timestep << endl;
//
//		for (int i = 0; i < NoHp; i++)
//		{
//			
//			cout << "========== Hospital #"<<h[i].getHID()<< " data ==========" << endl;
//			
//			
//
//			//cout << h[i].getEp().getcount() << endl;
//
//			//Emergency Patient
//
//			cout << h[i].getcEp() << " EP requests: ";
//			priQueue<Patient*>* temp = h[i].getEp();
//			int pri;
//			
//			priQueue<Patient*> nottemp2;
//			Patient* tempPatient;
//			for (int k = 0; k < h[i].getcSp(); k++)
//			{
//
//				temp->dequeue(tempPatient,pri);
//				cout << tempPatient->getID() << "  ";
//				nottemp2.enqueue(tempPatient,pri);
//
//			}
//			for (int k = 0; k < h[i].getcSp(); k++)
//			{
//
//				nottemp2.dequeue(tempPatient,pri);
//				temp->enqueue(tempPatient,pri);
//
//			}
//			cout << endl;
//
//			//Special Patient
//
//			cout << h[i].getcSp() << " SP requests: ";
//			LinkedQueue<Patient*>* temp1 = h[i].getSp();
//			LinkedQueue<Patient*> nottemp;
//			
//			for (int k = 0; k < h[i].getcSp(); k++)
//			{
//				
//				temp1->dequeue(tempPatient);
//				cout << tempPatient->getID() << "  ";
//				nottemp.enqueue(tempPatient);
//			
//			}
//			for (int k = 0; k < h[i].getcSp(); k++)
//			{
//				
//				nottemp.dequeue(tempPatient);
//				temp1->enqueue(tempPatient);
//
//			}
//			cout << endl;
//
//			//Normal Patient
//
//			cout << h[i].getcNp() << " NP requests: ";
//			QueueCancel* temp2 = h[i].getNp();
//			QueueCancel nottemp3;
//
//			for (int k = 0; k < h[i].getcSp(); k++)
//			{
//
//				temp2->dequeue(tempPatient);
//				cout << tempPatient->getID() << "  ";
//				nottemp3.enqueue(tempPatient);
//
//			}
//			for (int k = 0; k < h[i].getcSp(); k++)
//			{
//
//				nottemp3.dequeue(tempPatient);
//				temp2->enqueue(tempPatient);
//
//			}
//			cout << endl;
//			
//			//SCars & NCars
//
//			cout << "Free cars: " << h[i].getcSc() << " SCars, " << h[i].getcNc() << " NCars" << endl;
//			cout << "========== Hospital #" << h[i].getHID() << " data end ==========" << endl;
//			cout << "------------------------------------------------------" << endl;
//			cout << "OutCars: " << cOc << endl;
//			cout << "BackCars: " << cBc << endl;
//		}
//		//delete[] h;
//		//h = nullptr;
//		
//
//	}
//	else
//	{
//		cout << "Silent Mode, Simulation Starts..."<<endl;
//		cout << "Simulation ends, Output file created"<<endl;
//	}
//	
//}
//
//bool UI::chooseMode()
//{
//	return false;
//}
//
//void UI::printStatus()
//{
//}
//
//void UI::printFinalStatistics()
//{
//}
//
//void UI::printQueue(const LinkedQueue<Patient*> queue)
//{
//}
//
//void UI::printPriorityQueue(const PriQueueCancel& queue)
//{
//}
//
//int UI::GetNumCars()
//{
//	return 0;
//}
//
//int UI::GetNumNCars()
//{
//	return 0;
//}
//
//int UI::GetNumSCars()
//{
//	return 0;
//}
//
//void UI::writeOutputFile()
//{
//}
//
//void UI::OutputFile()
//{
//}

