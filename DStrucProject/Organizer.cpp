#include "Organizer.h"
#include "UI.h"
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include "LinkedQueue.h"
#include "PriQueue.h"
#include "Hospital.h"
#include "Patient.h"
#include "Car.h"
#include <cstdlib>
//Organizer::Organizer(int No, LinkedQueue<Patient*> AllP, LinkedQueue<Patient*> Cancellist, PriQueueReturn<Car*> OC, priQueue<Car*> BC, int** d) : NoHp(No), AllPatients(AllP), Cancellationlist(Cancellist), OutCar(OC), BackCar(BC) {
//	distance = new int* [NoHp];
//	for (int i = 0; i < NoHp; i++)
//	{
//		distance[i] = new int[NoHp];
//	}
//	for (int i = 0; i < NoHp; i++)
//	{
//		for (int j = 0; j < NoHp; j++)
//		{
//			distance[i][j] = d[i][j];
//		}
//
//	}
//
//
//
//}
Organizer::Organizer(const string& fnames)
{
    this->fname = fnames;
	timestep = 1;
    Hospitals = nullptr;
    NoCancReq = 0;
    NoHp = 0;
    NoReq = 0;
    distance = nullptr;
    SpeedNcar = 0;
    SpeedScar = 0;
	
}

void Organizer::Load()
{
    fstream Finput;
    
    Finput.open(fname, ios::in);

    if (!Finput.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }

    if (!(Finput >> NoHp)) {
        cout << "Error reading integer from file!" << endl;
        Finput.close();
        return;
    }
   
    Hospitals = new Hospital[NoHp];
    Finput >> SpeedScar;
    Finput >> SpeedNcar;

 /*   cout << NoHp << endl << SpeedScar << endl << SpeedNcar << endl;*/

     distance = new int* [NoHp];
    for (int i = 0; i < NoHp; i++) {
        distance[i] = new int[NoHp];
    }
    for (int i = 0; i < NoHp; i++)
    {
        for (int j = 0; j < NoHp; j++)
        {
            Finput >> distance[i][j];
        }
    }
 /*   for (int i = 0; i < NoHp; i++)
    {
        for (int j = 0; j < NoHp; j++)
        {
            cout << distance[i][j] << " ";
        }
        cout << endl;
    }*/


    int sc, nc;
    for (int i = 0; i < NoHp; i++)
    {
        Finput >> sc >> nc;
        for (int j = 0; j < sc; j++)
        {
            Car* Sc = new Car("SC",SpeedScar);
            Hospitals[i].setCars(Sc);
        }
        for (int k = 0; k < nc; k++)
        {
            Car* Nc = new Car("NC",SpeedNcar);
            Hospitals[i].setCars(Nc);
        }
    }

   
    Finput >> NoReq;
    int requestTimes, requestPatientID, requestHospitalID, requestDistances, requestSeverity;
    string requestType;


    for (int i = 0; i < NoReq; i++)
    {
        
        Finput >> requestType;
        if (requestType == "EP")
        {
            Finput >> requestTimes >> requestPatientID >> requestHospitalID >> requestDistances >> requestSeverity;
            Patient P(requestType, requestTimes, requestPatientID, requestHospitalID, requestDistances, requestSeverity);
            Patient* q = &P;
            AllPatients.enqueue(q);
            Hospitals[requestHospitalID-1].setPatients(q);
            //cout<< requestTimes<<" " << requestPatientID << " " << requestHospitalID << " " << requestDistances << " " << requestSeverity<<endl;
        }
        else
        {
            Finput >> requestTimes >> requestPatientID >> requestHospitalID >> requestDistances;
            Patient P(requestType, requestTimes, requestPatientID, requestHospitalID, requestDistances);
            Patient* q = &P;
            AllPatients.enqueue(q);
            Hospitals[requestHospitalID-1].setPatients(q);

        }
    }
    
    Finput >> NoCancReq;

    int CancellationTime;
    for (int i = 0; i < NoCancReq; i++)
    {
        Finput >> CancellationTime >> requestPatientID >> requestHospitalID;
        Patient P("NP", CancellationTime, requestPatientID, requestHospitalID, 0);
        Patient* q = &P;
        Cancellationlist.enqueue(q);
    }

    while (!AllPatients.isEmpty())
    {
        Patient* patient;
        AllPatients.dequeue(patient);
        cout << patient->gettype() << endl;
    }
    Finput.close();
}
LinkedQueue<Patient*> Organizer::getdone()
{
	return DonePatients;
}
LinkedQueue<Patient*> Organizer::getcanceeled()
{
	return Cancellationlist;
}
LinkedQueue<Patient*> Organizer::getallpatients()
{
	return AllPatients;
}
Hospital* Organizer::gethospitallist()
{
	return Hospitals;
}
Organizer::~Organizer() {
	for (int i = 0; i < NoHp; i++)
	{
		delete[] distance[i];
	}
	delete[] distance;
    distance = nullptr;
    delete[] Hospitals;
    Hospitals = nullptr;
}

void Organizer::Simulate()
{
    Load();
    while (DonePatients.getCount() != NoReq)
    {

        for (int i = 0; i < NoReq; i++)
        {
            Patient* P;
            AllPatients.peek(P);
            int HOSID = P->getHID();
            if (this->timestep = P->getReqTime())
            {
                AllPatients.dequeue(P);
                Hospitals[HOSID].setPatients(P);

            }
            else
                break;
        }
        int lowerBound = 1;
        int upperBound = 100;
        int randomInRange = lowerBound + (rand() % (upperBound - lowerBound + 1));
        cout << "TimeStep: " << timestep << endl;;
        for (int i = 0; i < NoHp; i++)
        {
            if (10 <= randomInRange && randomInRange < 20)
            {
                cout << "random number is: " << randomInRange << " so we dequeue from Sp and enqueue to donepatients.";
                Patient* P;
                Hospitals[i].getSp()->dequeue(P);
                DonePatients.enqueue(P);
            }
            else if (20 <= randomInRange && randomInRange < 25)
            {
                cout << "random number is: " << randomInRange << " so we dequeue from Ep and enqueue to donepatients.";
                Patient* P;
                int n;
                Hospitals[i].getEp()->dequeue(P, n);
                DonePatients.enqueue(P);
            }
            else if (30 <= randomInRange && randomInRange < 40)
            {
                cout << "random number is: " << randomInRange << " so we dequeue from Np and enqueue to donepatients.";
                Patient* P;
                Hospitals[i].getNp()->dequeue(P);
                DonePatients.enqueue(P);
            }
            else if (40 <= randomInRange && randomInRange < 45)
            {
                cout << "random number is: " << randomInRange << " so we dequeue from Sc and enqueue to OutCars.";
                Car* C;
                int n = 0;
                Hospitals[i].getSc()->dequeue(C);
                OutCar.enqueue(C, n);
            }
            else if (70 <= randomInRange && randomInRange < 75)
            {
                cout << "random number is: " << randomInRange << " so we dequeue from Nc and enqueue to OutCars.";
                Car* P;
                int n = 0;
                Hospitals[i].getNc()->dequeue(P);
                OutCar.enqueue(P, n);
            }
            else if (80 <= randomInRange && randomInRange < 90)
            {
                cout << "random number is: " << randomInRange << " so we dequeue from OutCars and enqueue to Backcars.";
                Car* P;
                int n = 0;
                OutCar.dequeue(P, n);
                BackCar.enqueue(P, n);
            }
            else if (91 <= randomInRange && randomInRange < 95)
            {
                cout << "random number is: " << randomInRange << " so we dequeue from BackCars and enqueue to FreeCars.";
                Car* P;
                int n;
                BackCar.dequeue(P, n);
                Hospitals[i].setCars(P);
            }


            //programinterface
            for (int j = 0; j < NoHp; j++) {
                cout << "==========Hospital#" << j + 1 << "============" << endl;
                cout << Hospitals[i].getcEp() << " EP requests: ";
                priQueue<Patient*>* temp = Hospitals[i].getEp();

                for (int j = 0; j < Hospitals[i].getcEp(); j++)
                {

                    Patient* tempPatient;
                    int pri;
                    temp->dequeue(tempPatient, pri);
                    cout << tempPatient->getID() << "  ";


                }
                cout << endl;

                //Special Patient

                cout << Hospitals[i].getcSp() << " SP requests: ";
                LinkedQueue<Patient*>* temp1 = Hospitals[i].getSp();

                for (int k = 0; k < Hospitals[i].getcSp(); k++)
                {
                    Patient* tempPatient;
                    temp1->dequeue(tempPatient);
                    cout << tempPatient->getID() << "  ";


                }
                cout << endl;

                //Normal Patient

                cout << Hospitals[i].getcNp() << " NP requests: ";
                QueueCancel* temp2 = Hospitals[i].getNp();
                for (int l = 0; l < Hospitals[i].getcNp(); l++)
                {

                    Patient* tempPatient;
                    temp2->dequeue(tempPatient);
                    cout << tempPatient->getID() << "  ";


                }
                cout << endl;

                //SCars & NCars

                cout << "Free cars: " << Hospitals[i].getcSc() << " SCars, " << Hospitals[i].getcNc() << " NCars" << endl;
                cout << "========== Hospital #" << Hospitals[i].getHID() << " data end ==========" << endl;
                cout << "------------------------------------------------------" << endl;
            }



            timestep++;

        }
    }
}
    


int Organizer::getTimestep()
{
    return timestep;
}

int Organizer::getNoHp()
{
    return NoHp;
}

