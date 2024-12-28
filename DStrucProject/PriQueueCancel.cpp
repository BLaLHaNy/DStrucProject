#include "PriQueueCancel.h"
#include "priQueue.h"
#include "Car.h"
#include <iostream>


using namespace std;

Car* PriQueueCancel::Cancel(Patient* p) {
    if (this->isEmpty()) {
        return nullptr;
    }

    priQueue<Car*> temp;
    Car* currentCar = nullptr;
    Car* found = nullptr;
    int time = p->getPickTime();
    while (this->dequeue(currentCar, time)) {
        time = currentCar->getAP()->getPickTime();
        if (currentCar->getAP()->getID() == p->getID()) {
            found = currentCar;
            /*this->dequeue(currentCar, time);*/
        }
        else {
            temp.enqueue(currentCar, time);
        }
    }
    while (temp.dequeue(currentCar, time)) {
        time = currentCar->getAP()->getPickTime(); // Get the pick time after dequeuing
        this->enqueue(currentCar, time);
    }
    if (found) {
        int canceltime = found->cancelAssignedPatient();
        found->setreachtime(2 * canceltime - found->getAssignmentTime());
    }//do i have to update AT?
    return found;


    //priNode<Car*>* current = head; // Pointer to traverse the priority queue
    //priNode<Car*>* prev = nullptr;    // Pointer to keep track of the previous node
    //int pri;
    //// If the priority queue is empty
    //if (current == nullptr) {
    //    return;
    //}

    //// Check if the front node matches the target car
    //if (current->getItem(pri) == targetCar) {
    //    frontPtr = current->getNext();  // Adjust the front pointer
    //    backcar.enqueue(current->getItem(pri), current->getPri()); // Move to backcar queue
    //    delete current;                 // Remove the node from the current queue
    //    return;
    //}

    //// Traverse the queue to find the target car
    //while (current != nullptr) {
    //    if (current->getItem(pri) == targetCar) {
    //        // Remove the car by bypassing the node
    //        prev->setNext(current->getNext());

    //        // Move the car to the backcar priority queue
    //        backcar.enqueue(current->getItem(pri), current->getPri());

    //        // Delete the node from the current queue
    //        delete current;
    //        return;
    //    }

    //    prev = current;            // Move `prev` to the current node
    //    current = current->getNext(); // Move to the next node
    // }
}

