/// @author Adam Koehler
/// @date March 6, 8, 10, 2017
/// @brief Fun with pointers and trains!

#include <iostream>

using namespace std;

Train::Train()
{
    weight = 0;
    speed = 0;
    trainCarsHead = 0;
    trainCarsTail = 0;
}

void Train::display() const
{
    Car *cur = this->trainCarsHead;
    
    while(cur != 0)
    {
        cout << cur->getName();
        cur = cur->nextCar;
        if (cur != 0)
        {
            cout << " -> ";
        }
    }
}

Car* Train::getFirstCar() const
{
    return this->trainCarsHead;
}

Train & Train::operator=(const Train &rhs) {
    if (this != &rhs) {
        // what if some part of the train already exists?!?
        //      we cannot just add nodes to this train or else
        //      it won't be a copy
        
        // go through the rhs of operator and create new nodes for each
        // car in the train
        for (Car *i = rhs.trainCarsHead; i != 0; i = i->nextCar) {
            addCarBack(new Car(*i));
        }
    }
    return *this;
}

void Train::displayWeights() const
{
    Car *cur = this->trainCarsHead;
    
    while(cur != 0)
    {
        cout << cur->getWeight();
        cur = cur->nextCar;
        if (cur != 0)
        {
            cout << " -> ";
        }
    }
}


void Train::addCarFront(Car *toAdd)
{
    // Empty list needs to reconfigure the tail
    if (trainCarsHead == NULL)
    {
        trainCarsHead = toAdd;
        trainCarsTail = toAdd;
    }
    else
    {
        Car *temp = 0;
        
        // Non-empty list should not touch tail
        temp = trainCarsHead;
        trainCarsHead = toAdd;
        toAdd->nextCar = temp;//setNextCar(temp);
    }
}

void Train::addCarBack(Car *toAdd) {
    if (trainCarsHead == 0) {
        trainCarsHead = toAdd;
        trainCarsTail = toAdd;
    }
    else {
        trainCarsTail->nextCar = toAdd;
        trainCarsTail = toAdd;
    }
}


void Train::deleteCar(int carNum)
{
    // TODO: check for special case for head or tail depending on list 
    if (trainCarsHead == 0)
    {
        return;
    }
    
    // find previous node
    int i = 0;
    Car *prev = trainCarsHead;
    for(i = 1; i + 1 < carNum; i++)
    {
        prev = prev->nextCar;
    }
    
    // Store the node to be deleted in a temporary variable
    Car *temp;
    temp = prev->nextCar;
    
    // Reassign links of linked list to skip deleted node
    // prev->nextCar = (prev->nextCar)->nextCar;
    prev->nextCar = temp->nextCar;
    
    // Are we deleting the only node? If so prev will now be 0.
    if (prev == 0)
    {
        trainCarsTail = 0;
    }
    
    // delete node
    delete temp;
}

void Train::deleteFirstCar()
{
    /* TODO */
}