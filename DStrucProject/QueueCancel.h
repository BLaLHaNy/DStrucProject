#pragma once
#include "LinkedQueue.h"
#include "priQueue.h"
#include "Patient.h"
template <typename T>
class QueueCancel: public LinkedQueue<T>
{

public:
	void Cancel();

};


