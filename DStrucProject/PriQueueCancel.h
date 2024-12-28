#pragma once
#include "priQueue.h"
#include "Car.h"
#include <iostream>

using namespace std;

class PriQueueCancel : public priQueue <Car*>
{

public:
	Car* Cancel(Patient* p);


};


