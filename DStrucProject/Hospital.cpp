#include "Hospital.h"
#include <iostream>
using namespace std;
Hospital::Hospital() {
	id = nextID++;
}

void Hospital::setPatients(Patient* p)
{
	if (p->gettype() == "NP") {
		NP.enqueue(p);
	}
	else if (p->gettype() == "SP") {
		SP.enqueue(p);
	}
	else if (p->gettype() == "EP") {
		EP.enqueue(p, p->getsev());
	}
}

void Hospital::setCars(Car* c)
{
	if (c->gettype() == "NC") {
		NC.enqueue(c);
	}
	else if (c->gettype() == "SC") {
		SC.enqueue(c);
	}

}

void Hospital::assigncar(Patient* P, Car* C)
{
	C->setAP(P);
}

QueueCancel Hospital::getNp()
{
	return NP;
}

LinkedQueue<Patient*> Hospital::getSp()
{
	return SP;
}

priQueue<Patient*> Hospital::getEp()
{
	return EP;
}

LinkedQueue<Car*> Hospital::getSc()
{
	return this->SC;
}

LinkedQueue<Car*> Hospital::getNc()
{
	return this->NC;
}
 int Hospital:: nextID = 0; // Static variable to hold the next ID
