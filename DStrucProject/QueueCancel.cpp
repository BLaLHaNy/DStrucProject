#include "QueueCancel.h"
#include"Patient.h"
#include "LinkedQueue.h"

bool QueueCancel::Cancel(const int targetItem) {
    Node<Patient*>* ptr = frontPtr;
    Node<Patient*>* prev = nullptr; 

  
    if (ptr == nullptr) {
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
    }
}
