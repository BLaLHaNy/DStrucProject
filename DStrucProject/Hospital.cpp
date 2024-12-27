#include "Hospital.h"
#include <iostream>
#include "Organizer.h"
using namespace std;

Hospital::Hospital(Organizer* o):distance(0),organizer(o) {
	HID = nextID++;
}

void Hospital::setPatients(Patient* p)
{
	if (p->gettype() == "NP") {
		NP.enqueue(p);
		cNp++;
	}
	else if (p->gettype() == "SP") {
		SP.enqueue(p);
		cSp++;
	}
	else if (p->gettype() == "EP") {
		EP.enqueue(p, p->getsev());
		cEp++;
	}
}

void Hospital::setCars(Car* c)
{
	if (c->gettype() == "NC") {
		NC.enqueue(c);
		cNc++;
	}
	else if (c->gettype() == "SC") {
		SC.enqueue(c);
		cSc++;
	}

}



QueueCancel* Hospital::getNp()
{
	return &NP;
}

LinkedQueue<Patient*>* Hospital::getSp()
{
	return &SP;
}

priQueue<Patient*>* Hospital::getEp()
{
	return &EP;
}

LinkedQueue<Car*>* Hospital::getSc()
{
	return &SC;
}

LinkedQueue<Car*>* Hospital::getNc()
{
	return &NC;
}

void Hospital::assignCartoEP(int currentTime)
{
	Patient* p;
	int severity;
	Car* c;


	while (EP.peek(p, severity)) {
		if (p->getReqTime() <= currentTime) {
			if (NC.dequeue(c)) {
				EP.dequeue(p, severity);
				cNc--;
				cEp--;
				c->setAP(p, currentTime);

				carBusyTime = carBusyTime + (p->getDistance() / c->getspeed());
				WaitingTime = WaitingTime + (currentTime - p->getReqTime());
				/*int reachtime = 2 * (p->getPickTime() - c->getAssignmentTime());*/
				/*c->setreachtime(reachtime);*/
				organizer->addOutCar(c);

			}
			else if (SC.dequeue(c)) {
				EP.dequeue(p, severity);
				cSc--;
				cEp--;
				c->setAP(p, currentTime);
				carBusyTime = carBusyTime + (p->getDistance() / c->getspeed());
				WaitingTime = WaitingTime + (currentTime - p->getReqTime());
				/*int reachtime = 2 * (p->getPickTime() - c->getAssignmentTime());
				c->setreachtime(reachtime);*/
				organizer->addOutCar(c);
			}
			else {
				EP.dequeue(p, severity);
				cEp--;
				organizer->emergency_assign(p, severity);
				//should allow sending to another hospital
			}
		}
		else { return; }
	}
}

void Hospital::assignCartoSP(int currentTime) {
	Patient* p;
	Car* c;
	while (SP.peek(p)) {
		if (p->getReqTime() <= currentTime) {
			if (SC.dequeue(c)) {
				SP.dequeue(p);
				cSc--;
				cSp--;
				c->setAP(p, currentTime);
				carBusyTime = carBusyTime + (p->getDistance() / c->getspeed());
				WaitingTime = WaitingTime + (currentTime - p->getReqTime());
				organizer->addOutCar(c); // This line requires Organizer's full definition
			}
			else {
				return;
			}
		}
		else {
			break;
		}
	}
}


void Hospital::assignCartoNP(int currentTime)
{
	Patient* p;
	Car* c;
	while (NP.peek(p)) {
		if (p->getReqTime() <= currentTime) {
			if (NC.dequeue(c)) {
				NP.dequeue(p);
				cNc--;
				cNp--;
				c->setAP(p, currentTime);
				
				carBusyTime = carBusyTime + (p->getDistance() / c->getspeed());
				WaitingTime = WaitingTime + (currentTime - p->getReqTime());
				organizer->addOutCar(c);
			}
			else {
				return; 
			}
		}
		else {
			break; 
		}
	}
}

void Hospital::addfailedP(Patient* p, string& type)
{
	LinkedQueue<Patient*> temp;
	Patient* tempfpa;

	if (type == "SP") {
		while (SP.dequeue(tempfpa))
		{
			temp.enqueue(tempfpa);
		}

		SP.enqueue(p);

		while (temp.dequeue(tempfpa))
		{
			SP.enqueue(tempfpa);
		}
	}
	else if (type == "NP") {
		while (NP.dequeue(tempfpa))
		{
			temp.enqueue(tempfpa);
		}

		NP.enqueue(p);

		while (temp.dequeue(tempfpa))
		{
			NP.enqueue(tempfpa);
		}
	}
	else if (type == "EP") {
		EP.enqueue(p, p->getsev());
	}
}

void Hospital::print()
{
	Patient* p; 
	int severity;
	while (EP.dequeue(p, severity)) {
		cout << severity << endl;
	}
	cout << "Done";
}

int Hospital::getHID()
{
	return HID;
}
int Hospital::getcEp()
{
	
	return cEp;
}
int Hospital::getcNp()
{

	return cNp;
}
int Hospital::getcSp()
{

	return cSp;
}
int Hospital::getcSc()
{

	return cSc;
}
int Hospital::getcNc()
{

	return cNc;
}

bool Hospital::cancelNP(int pid)
{
	bool success = NP.Cancel(pid);
	if (success)
	{ 
		return true; 
	}
	else {
		return false;
	}
}



 int Hospital:: nextID = 1; // Static variable to hold the next ID
