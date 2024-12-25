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

void Car::setstatus(string s)
{
	status = s;
}

Patient* Car::getAP()
{
	return AssignedPatient;
}

Car::~Car()
{
	delete AssignedPatient;
	AssignedPatient = nullptr;
}
