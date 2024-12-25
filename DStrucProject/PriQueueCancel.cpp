#include "PriQueueCancel.h"
#include "priQueue.h"
#include "Car.h"
#include <iostream>


using namespace std;

void PriQueueCancel::Cancel(Car* targetCar) {
    priNode<Car*>* current = head; // Pointer to traverse the priority queue
    priNode<Car*>* prev = nullptr;    // Pointer to keep track of the previous node
    int pri;
    // If the priority queue is empty
    if (current == nullptr) {
        return;
    }

    // Check if the front node matches the target car
    if (current->getItem(pri) == targetCar) {
        frontPtr = current->getNext();  // Adjust the front pointer
        backcar.enqueue(current->getItem(pri), current->getPri()); // Move to backcar queue
        delete current;                 // Remove the node from the current queue
        return;
    }

    // Traverse the queue to find the target car
    while (current != nullptr) {
        if (current->getItem(pri) == targetCar) {
            // Remove the car by bypassing the node
            prev->setNext(current->getNext());

            // Move the car to the backcar priority queue
            backcar.enqueue(current->getItem(pri), current->getPri());

            // Delete the node from the current queue
            delete current;
            return;
        }

        prev = current;            // Move `prev` to the current node
        current = current->getNext(); // Move to the next node
    }
}

