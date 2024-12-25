#include "Car.h"
Car::Car(string t, int s,int HID) :type(t), speed(s), HospitalID(HID) {
	
}

string Car::gettype() const {
	return type;
}
void Car::Pickup()
{
	setstatus("BusyCar");

}
int Car::getspeed() const
{
	return speed;
}
void Car::setAP(Patient* AP,int time)
{
	AssignedPatient = AP;
}
void Car::dropoff()
{
	setstatus("FreeCar");
}

int Car::cancelAssignedPatient()
{
	return 0;
}

void Car::setstatus(string s)
{
	status = s;
}

Patient* Car::getAP()
{
	return AssignedPatient;
}

int Car::getReachTime()
{
	return 0;
}

int Car::getAssignmentTime()
{
	return 0;
}

Patient* Car::getAssignedPatient()
{
	return nullptr;
}

bool Car::getfailed() const
{
	return false;
}

void Car::setfailed()
{
}

void Car::setfailedpatient()
{
}

Car::~Car()
{
	delete AssignedPatient;
	AssignedPatient = nullptr;
}
