#include "Car.h"
Car::Car(string t, int s,int HID) :type(t), speed(s), HospitalID(HID) {
	
}

string Car::gettype() const {
	return type;
}
void Car::Pickup()
{
	if (AssignedPatient) {
		setstatus("BusyCar");
		arrivalTime = AssignedPatient->getPickTime() + AssignedPatient->getDistance() / speed;
	}

}
int Car::getspeed() const
{
	return speed;
}
void Car::setAP(Patient* AP,int time)
{
	AssignedPatient = AP;
	assignTime = time;
	setstatus("AssignedCar");
	int timePickedUp = assignTime + (AssignedPatient->getDistance() / speed);
	AssignedPatient->setPickUpTime(timePickedUp);
}
Patient* Car::dropoff()
{
	setstatus("FreeCar");
	int finishTime = AssignedPatient->getPickTime() + AssignedPatient->getDistance() / speed;
	AssignedPatient->setFinishTime(finishTime);
	Patient* AP = AssignedPatient;
	AssignedPatient = nullptr;
	assignTime = arrivalTime = NULL;
	return AP;
	
}

int Car::cancelAssignedPatient()
{
	int canceltime = AssignedPatient->getcancelTime();
	AssignedPatient = nullptr;
	return canceltime;
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
	return arrivalTime;
}

int Car::getAssignmentTime()
{
	return assignTime;
}

Patient* Car::getAssignedPatient()
{
	return AssignedPatient;
}

bool Car::getfailed() const
{
	return failed;
}

void Car::setfailed()
{
	if (failed == false)
	{
		failed = true;
	}
	else if (failed == true)
	{
		failed = false;
	}
}

void Car::setfailedpatient()
{
	AssignedPatient = nullptr;
}

int Car::getHID()
{
	return HospitalID;
}

Car::~Car()
{
	delete AssignedPatient;
	AssignedPatient = nullptr;
}
