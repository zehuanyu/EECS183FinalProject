/*
 * Copyright 2023 University of Michigan EECS183
 *
 * Move.cpp
 * Project UID 28eb18c2c1ce490aada441e65559efdd
 *
 * Ruoyan Zhao
 * ruoyan
 *
 * Final Project - Elevators
 */
 
#include <cmath>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include "Move.h"

using namespace std;

/**
 * Requires: commandString is a valid string
 * Modifies: elevatorId, targetFloor, isPass, isPickup, isSave, isQuit
 * Effects:  creates a Move object based on
 *           the characters in commandString
 *
 *           Examples:
 *           commandString = "e1f4"; - elevatorID of 1 has a targetFloor of 4
 *           commandString = "e1p"; - elevatorID of 1 will pickup people on
 *                                    its current floor
 *
 *           when commandString is "", or "S", or "Q", etc.:
 *                sets the corresponding private data member to true
 */
Move::Move(string commandString) : Move() {
    if (commandString == "") {
        isPass = true;
    }
    else {
    char letter = commandString.at(0);
        if (letter == 'S') {
        isSave = true;
        }
        else if(letter == 'Q') {
        isQuit = true;
        }
        else {
            char letter2 = commandString.at(2);
            if (letter2 == 'p') {
                elevatorId = commandString.at(1) - '0';
                isPickup = true;
            }
            else {
                targetFloor = commandString.at(3) - '0';
                elevatorId = commandString.at(1) - '0';
            }
        }
    }
}






/**
 * Requires: elevators represents the elevator servicing states
 * Modifies: nothing
 * Effects:  returns true if this Move instance is valid, false otherwise
 *
 *           The following are the criterion for validity:
 *
 *           If a move is a Pass Move, a Quit Move, or a Save Move it is valid
 *           For both Pickup Moves and Servicing Moves:
 *               0 <= elevatorId < NUM_ELEVATORS
 *               The corresponding Elevator is currently not
 *                  servicing a request.
 *           For Servicing Moves only:
 *               0 <= targetFloor < NUM_FLOORS
 *               targetFloor is different from the corresponding
 *                  Elevator's currentFloor
 */
bool Move::isValidMove(Elevator elevators[NUM_ELEVATORS]) const {
    if(isPass || isQuit|| isSave){
        return true;
    }
    if (elevatorId >= 0 && elevatorId < NUM_ELEVATORS && !elevators[elevatorId].isServicing()){
        if (!isPickup && targetFloor >= 0 && targetFloor < NUM_FLOORS && targetFloor != elevators[elevatorId].getCurrentFloor()){
            return true;
        }
        else if(isPickup){
            return true;
        }
    }
    return false;
}





/**
 * Requires: pickupList is a valid list of indices
 *           currentFloor is the floor number where the pickup
 *             is taking place
 *           pickupFloor is the Floor instance where the pickup
 *            is taking place
 * Modifies: numPeopleToPickup, peopleToPickup, totalSatisfaction, targetFloor
 * Effects:  sets numPeopleToPickup and totalSatisfaction to 0
 *           adds the indices specified in pickupList to peopleToPickup
 *           increments numPeopleToPickup by 1 for each person being picked up
 *           adds satisfaction gained from each person picked up
 *              to totalSatisfaction
 *           sets targetFloor to be the most extreme floor of those
 *              being picked up (furthest up or down)
 */
void Move::setPeopleToPickup(const string& pickupList, const int currentFloor, const Floor& pickupFloor) {
    numPeopleToPickup = 0;
    totalSatisfaction = 0;
    int floordistance = 0;
    int targetdistance = 0;
    Person random;
    for (int i = 0; i < pickupList.size(); i++){
        peopleToPickup[i] = pickupList[i] - '0';
        random = pickupFloor.getPersonByIndex(peopleToPickup[i]);
        numPeopleToPickup++;
        totalSatisfaction += MAX_ANGER - random.getAngerLevel();
    }
    int a = pickupFloor.getPersonByIndex(peopleToPickup[0]).getTargetFloor();
    
    for (int j = 0; j < pickupList.size(); j++){
        Person p = pickupFloor.getPersonByIndex(peopleToPickup[j]);
        floordistance = abs(p.getTargetFloor() - currentFloor);
        targetdistance = abs(a - currentFloor);
        if (floordistance > targetdistance) {
            a = p.getTargetFloor();
        }
    }
    targetFloor = a;
}

//////////////////////////////////////////////////////
////// DO NOT MODIFY ANY CODE BENEATH THIS LINE //////
//////////////////////////////////////////////////////

Move::Move() {
    elevatorId = -1;
    targetFloor = -1;
    numPeopleToPickup = 0;
    totalSatisfaction = 0;
    isPass = false;
    isPickup = false;
    isSave = false;
    isQuit = false;
}

bool Move::isPickupMove() const {
    return isPickup;
}

bool Move::isPassMove() const {
    return isPass;
}

bool Move::isSaveMove() const {
    return isSave;
}

bool Move::isQuitMove() const {
    return isQuit;
}

int Move::getElevatorId() const {
    return elevatorId;
}

int Move::getTargetFloor() const {
    return targetFloor;
}

int Move::getNumPeopleToPickup() const {
    return numPeopleToPickup;
}

int Move::getTotalSatisfaction() const {
    return totalSatisfaction;
}

void Move::setTargetFloor(int inTargetFloor) {
    targetFloor = inTargetFloor;
}

void Move::copyListOfPeopleToPickup(int newList[MAX_PEOPLE_PER_FLOOR]) const {
    for (int i = 0; i < numPeopleToPickup; ++i) {
        newList[i] = peopleToPickup[i];
    }
}
