#include <vector>
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include "LinkedQueue.h"
#include "PriQueue.h"
#include "Hospital.h"
#include "Patient.h"
#include "Car.h"
#include "UI.h"
#include "Organizer.h"

using namespace std;

int main()
{
	Organizer x("Input.txt");
	x.Load();
}