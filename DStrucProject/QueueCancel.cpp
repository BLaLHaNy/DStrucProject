#include "QueueCancel.h"
#include"Patient.h"
#include "LinkedQueue.h"

void QueueCancel::Cancel(const int targetItem) {
    Node<Patient*>* ptr = frontPtr;
    Node<Patient*>* prev = nullptr; 

  
    if (ptr == nullptr) {
        return;
    }

 
    if (ptr->getItem()->getID() == targetItem) {
        frontPtr = ptr->getNext(); 
        delete ptr;             
        return;
    }

    
    while (ptr != nullptr) {
        if (ptr->getItem()->getID() == targetItem) {
            prev->setNext(ptr->getNext());
            delete ptr;                   
            return;
        }
        prev = ptr; 
        ptr = ptr->getNext(); 
    }
}
