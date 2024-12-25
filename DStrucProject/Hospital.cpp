#include "Hospital.h"
#include <iostream>
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
}

void Hospital::assignCartoSP(int currentTime)
{
}

void Hospital::assignCartoNP(int currentTime)
{
}

void Hospital::addfailedP(Patient* p, string& type)
{
}

void Hospital::print()
{
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

 int Hospital:: nextID = 1; // Static variable to hold the next ID
