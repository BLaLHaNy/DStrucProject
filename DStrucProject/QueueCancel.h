#pragma once
#include "LinkedQueue.h"
#include "priQueue.h"
#include "Patient.h"

class QueueCancel: public LinkedQueue<Patient*>
{

public:

	bool Cancel(const int targetItem);
	QueueCancel(const QueueCancel& cq);
	QueueCancel(){}

};


