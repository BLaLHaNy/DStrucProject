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
#include <ctime>
#include <time.h>
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
    numOutCars = 0;
    numBackCars = 0;
    
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
   
    Hospitals = new Hospital*[NoHp];
    for (int i = 0; i < NoHp; i++) {
        Hospitals[i] = new Hospital(this);
    }
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
            Car* Sc = new Car("SC",SpeedScar,Hospitals[i]->getHID());
            Hospitals[i]->setCars(Sc);
        }
        for (int k = 0; k < nc; k++)
        {
            Car* Nc = new Car("NC",SpeedNcar, Hospitals[i]->getHID());
            Hospitals[i]->setCars(Nc);
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
            //Patient P(requestType, requestTimes, requestPatientID, requestHospitalID, requestDistances, requestSeverity);
            Patient* q = new Patient(requestType, requestTimes, requestPatientID, requestHospitalID, requestDistances, requestSeverity);
            AllPatients.enqueue(q);
           /* Hospitals[requestHospitalID-1]->setPatients(q);*/
            //cout<< requestTimes<<" " << requestPatientID << " " << requestHospitalID << " " << requestDistances << " " << requestSeverity<<endl;
        }
        else
        {
            Finput >> requestTimes >> requestPatientID >> requestHospitalID >> requestDistances;
            //Patient P
            Patient* q = new Patient(requestType, requestTimes, requestPatientID, requestHospitalID, requestDistances);
            AllPatients.enqueue(q);
           /* Hospitals[requestHospitalID-1]->setPatients(q);*/
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

 /*   while (!AllPatients.isEmpty())
    {
        Patient* patient;
        AllPatients.dequeue(patient);
        cout << patient->gettype() << endl;
    }*/
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
Hospital** Organizer::gethospitallist()
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

void Organizer::Simulate(int mode)
{
    Load();
    int step =  1 ;
   
    UI interface(this);
    
    
  


    while (true)
    {
        /*cancelP(step);*/

        Patient* p = nullptr;
        while(AllPatients.peek(p) && p->getReqTime() == step)
        {
            if (p && p->getReqTime() <= step)
            {
                AllPatients.dequeue(p);
                Hospitals[p->getHID() - 1]->setPatients(p);

            }
            

        }

        for (int i = 0; i < NoHp; i++)
        {
            Patient* ep;
            int sev;
            while(Hospitals[i]->getEp()->peek(ep, sev) && ep->getReqTime() == step) {
               
                if (Hospitals[i]->assignCartoEP(step)) {
                 /*   if (!addOutCar(i, "NC")) {
                        addOutCar(i, "SC");
                    }*/
                }

                    else {
                        assignEPtoNewHospital(ep, sev);
                    }
                
            }
            while (Hospitals[i]->getSp()->peek(ep) && ep->getReqTime() == step) {
                Hospitals[i]->assignCartoSP(step);
            }
              /*  if (addOutCar(i ,"SC")) {}*/
            
            while (Hospitals[i]->getNp()->peek(ep) && ep->getReqTime() == step) {
                Hospitals[i]->assignCartoNP(step);
            }
            /*    if (addOutCar(i ,"NC")) {}*/
            if (mode == 2) {
                cout << "Current Timestep: " << step << endl;
                interface.printHospitals(Hospitals[i], i + 1);
                interface.printCars(&OutCar,&BackCar,&DonePatients);
            }
            
      
            bool next;
            if (DonePcount == NoReq || DonePatients.getCount()==NoReq) {
                // generate output file   
                interface.OutputFile();
               
                return;
            }

            if (mode == 1)
            {
                SilentMode();
                break;
            }
            cin >> next;
        }
        step++;
    }
    
}


void Organizer::Addfinished(Patient* patient)
{
    DonePatients.enqueue(patient);
}

void Organizer::cancelP(int time)
{
    Patient* p = nullptr;

    while (Cancellationlist.peek(p) && p->getcancelTime() == time) {
        bool foundP = Hospitals[p->getHID() - 1]->cancelNP(p->getID());
        if (!foundP) {//Patient is not picked but car is out
            Car* cancelledCar = OutCar.Cancel(p);
            if (cancelledCar) {
                numOutCars--;
                Cancellationlist.dequeue(p);
                p->setPickUpTime(-1);
                delete p;

                //AddFinishedPatient(p);
                BackCar.enqueue(cancelledCar, cancelledCar->getReachTime());
                numBackCars++;
            }
            else {
                Cancellationlist.dequeue(p);
                NoCancReq--;

            } //When cancelTime>=pickUpTime, Patient is picked
        }
        else if (foundP) {//Patient is still in the hospital
            delete p;
            Cancellationlist.dequeue(p);
            //AddFinishedPatient(p);
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

priQueue<Car*> Organizer::getOutCars()
{
    return OutCar;
}

priQueue<Car*> Organizer::getBackCars()
{
    return BackCar;
}

bool Organizer::addOutCar(int hid, string type)
{
    Car* c = Hospitals[hid]->removecar(type);
    if (!c || !c->getAP()) {
        return false;
    }
    OutCar.enqueue(c, c->getAP()->getPickTime());
    numOutCars++;
    return true;
    
}
bool Organizer::addBackCar(int current_time)
{
    Car* c = nullptr; Patient* patient{ nullptr };
    int pickup_time = 0;
    if (OutCar.peek(c, pickup_time))
    {
        patient = c->getAP();
        int pp = patient->getPickTime();
        if (current_time == pp)
        {
            OutCar.dequeue(c, pp);
            c->Pickup();
            BackCar.enqueue(c, patient->getFinishTime());
            return true;
        }
    }
    return false;
}



bool Organizer::addFreeCar(int current_time)
{
    Car* c = nullptr;
    int finish_time = 0;
    if (BackCar.peek(c, finish_time))
    {
        Patient* patient = c->getAP();
        if (!patient) { return false; }
        int finish_time = patient->getFinishTime();
        if (current_time == finish_time)
        {
            BackCar.dequeue(c, finish_time);
            patient = c->dropoff();
            int hospitalID = c->getHID();
            Hospitals[hospitalID ]->setCars(c);
            string pt = patient->gettype();
            DonePatients.enqueue(patient);
            return true;
        }
    }
    return false;
}

void Organizer::printDone()
{
    int sev;
    Patient* temp;
    LinkedQueue<Patient*> temp2 = DonePatients;
    while (temp2.dequeue(temp)) {
        cout << temp->getID() << ", ";
    }
}




void Organizer::printOutCars()
{
    int sev;
    Car* temp;
    PriQueueCancel temp2 = OutCar;
    while (temp2.dequeue(temp,sev)) {
        cout << 'H' << temp->getHID() << "_P" << temp->getAP()->getID() << ", ";
    }
}

void Organizer::printBackCars()
{
    int sev;
    Car* temp;
    priQueue<Car*> temp2 = BackCar;
    while (temp2.dequeue(temp, sev)) {
        cout << 'H' << temp->getHID() << "_P" << temp->getAP()->getID() << ", ";
    }
}

int Organizer::getNoReq()
{
    return NoReq;
}

void Organizer::generate_OutputFile(const string& output_file_name, int total_simulation_time)
{

}

int Organizer::getNoCars()
{
    return  numOutCars + numBackCars;
}

void Organizer::SilentMode()
{
    Load();
    int step = 1;

    UI interface(this);





    while (true)
    {
        /*cancelP(step);*/

        Patient* p = nullptr;
        while (AllPatients.peek(p) && p->getReqTime() == step)
        {
            if (p && p->getReqTime() <= step)
            {
                AllPatients.dequeue(p);
                Hospitals[p->getHID() - 1]->setPatients(p);

            }


        }

        for (int i = 0; i < NoHp; i++)
        {
            Patient* ep;
            int sev;
            while (Hospitals[i]->getEp()->peek(ep, sev) && ep->getReqTime() == step) {

                if (Hospitals[i]->assignCartoEP(step)) {
                    /*   if (!addOutCar(i, "NC")) {
                           addOutCar(i, "SC");
                       }*/
                }

                else {
                    assignEPtoNewHospital(ep, sev);
                }

            }
            while (Hospitals[i]->getSp()->peek(ep) && ep->getReqTime() == step) {
                Hospitals[i]->assignCartoSP(step);
            }
            /*  if (addOutCar(i ,"SC")) {}*/

            while (Hospitals[i]->getNp()->peek(ep) && ep->getReqTime() == step) {
                Hospitals[i]->assignCartoNP(step);
            }
            /*    if (addOutCar(i ,"NC")) {}*/
            bool next;
            if (DonePcount == NoReq || DonePatients.getCount() == NoReq) {
                // generate output file   
                interface.OutputFile();

                return;
            }
            cin >> next;
        }
        step++;
    }
}



void Organizer::assignEPtoNewHospital(Patient* p, int severity)
{
    int H = p->getHID();
    int newHos;
    if (H != noHospitals)
    {
        newHos = H + 1;
    }
    else
    {
        newHos = 1;
    }
    p->setHID(newHos);
    Hospitals[newHos - 1]->setPatients(p);
}
int Organizer::calculateAverageWaitingTime()
{
    LinkedQueue<Patient*> FinishedPatients = DonePatients;

    Patient* FPatient;
    int totalWaitingTime = 0;
    //int numPatients = 0;

    while (FinishedPatients.dequeue(FPatient))
    {
        totalWaitingTime += FPatient->getWaitTime();
        //    numPatients++;
    }
    if (FinishedPatients.getCount() > 0)
    {
        return totalWaitingTime / FinishedPatients.getCount();
    }
    else
    {
        return 0;
    }
}
