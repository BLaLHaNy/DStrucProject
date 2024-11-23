#include "Car.h"
Car::Car(string t, int s) :type(t), speed(s) {}

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
void Car::setAP(Patient* AP)
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