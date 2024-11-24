#pragma once
#include "LinkedQueue.h"
#include "priQueue.h"
#include "Patient.h"

class QueueCancel: public LinkedQueue<Patient*>
{

public:
	void Cancel(int id);

};


