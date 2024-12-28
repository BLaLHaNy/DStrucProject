#include "QueueCancel.h"
#include"Patient.h"
#include "LinkedQueue.h"

bool QueueCancel::Cancel(const int targetItem) {
    //Node<Patient*>* ptr = frontPtr;
    //Node<Patient*>* prev = nullptr; 
    LinkedQueue<Patient*> tempQueue;
    Patient* currentItem;
    bool success = false;
    while (this->dequeue(currentItem)) {
        if (currentItem->getID() == targetItem) {
            success = true;
        }
        else {
            tempQueue.enqueue(currentItem);
        }
    }
    while (tempQueue.dequeue(currentItem)) {
        this->enqueue(currentItem);
    }
    return success;
  
    /*if (ptr == nullptr) {
        return false;
    }

 
    if (ptr->getItem()->getID() == targetItem) {
        frontPtr = ptr->getNext(); 
        delete ptr;             
        return true;
    }

    
    while (ptr != nullptr) {
        if (ptr->getItem()->getID() == targetItem) {
            prev->setNext(ptr->getNext());
            delete ptr;                   
            return true;
        }
        prev = ptr; 
        ptr = ptr->getNext(); 
    }*/

}
QueueCancel::QueueCancel(const QueueCancel& cq) {
    frontPtr = backPtr = nullptr;
    Node<Patient*>* NodePtr = cq.frontPtr;	
    while (NodePtr)
    {
        enqueue(NodePtr->getItem());	 
        NodePtr = NodePtr->getNext();
    }
}
