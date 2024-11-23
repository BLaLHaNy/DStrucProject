#pragma once
#include "priQueueCancel.h"
template <typename T>

class PriQueueReturn : public PriQueueCancel<T>
{
public : 
	void returnCar();
};


