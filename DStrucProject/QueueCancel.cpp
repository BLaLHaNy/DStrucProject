#include "QueueCancel.h"
#include"Patient.h"
#include "LinkedQueue.h"

void QueueCancel::Cancel(LinkedQueue<Patient*>& queue, const int targetItem)
{
	LinkedQueue<Patient*> tempQueue;
	Patient* P;
	bool found=false;
	while (!queue.isEmpty())
	{
		queue.dequeue(P);	
		if (P->getID() == targetItem && !found) {
			found = true;
		}
		else {
			tempQueue.enqueue(P);
		}
	}
	while (!tempQueue.isEmpty()) {
		tempQueue.dequeue(P);
		queue.enqueue(P);
	}
}