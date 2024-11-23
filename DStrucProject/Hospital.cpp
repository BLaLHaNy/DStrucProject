#include "Hospital.h"
#include <iostream>
using namespace std;
Hospital::Hospital(int hid) {
	distance = 0;
	HID = hid;
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