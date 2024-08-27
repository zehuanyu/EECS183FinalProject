/*
 * Copyright 2023 University of Michigan EECS183
 *
 * Floor.cpp
 * Project UID 28eb18c2c1ce490aada441e65559efdd
 *
 * Ruoyan Zhao
 * ruoyan
 *
 * Final Project - Elevators
 */


#include "Floor.h"

using namespace std;

/*
 * Requires: nothing
 * Modifies: people
 * Effects:  Ticks each person on this floor
 *           Also removes any Person who explodes
 *           Returns the number of exploded people
 */
int Floor::tick(int currentTime) {
    int explodes = 0;
    int RemoveIndice[MAX_PEOPLE_PER_FLOOR];
    for (int i = 0; i < numPeople; i++) {
        bool a = people[i].tick(currentTime);
        if (a) {
            RemoveIndice[explodes] = i;
            explodes++;
        }
    }
    removePeople(RemoveIndice, explodes);
    return explodes;
}


/*
 * Requires: request != 0
 * Modifies: hasUpRequest, hasDownRequest, numPeople, people
 * Effects:  If there is still room, add newPerson to people.
 *           Updates hasUpRequest or hasDownRequest based on value of request
 */
void Floor::addPerson(Person newPerson, int request) {
    if (numPeople < MAX_PEOPLE_PER_FLOOR) {
        people[numPeople] = newPerson;
        numPeople += 1;
        if (request > 0) {
            hasUpRequest = true;
        }
        else if (request < 0) {
            hasDownRequest = true;
        }
    }
}

/*
 * Requires: numPeopleToRemove >= 0, numPeopleToRemove <= MAX_PEOPLE_PER_FLOOR,
 *           numPeopleToRemove >= 0, numPeopleToRemove <= numPeople,
 *           for all values of i such that 0 <= i < numPeopleToRemove, indicesToRemove[i] < numPeople
 * Modifies: people[], numPeople, hasUpRequest, hasDownRequest
 * Effects:  Removes objects from people[] at indices specified in indicesToRemove[].
 *           The size of indicesToRemove[] is given by numPeopleToRemove.
 *           After removals, calls resetRequests() to update hasUpRequest and hasDownRequest.
 */

void Floor::removePeople(int indicesToRemove[MAX_PEOPLE_PER_FLOOR], int numPeopleToRemove) {
    int add = 0;
    std::sort(indicesToRemove, indicesToRemove+numPeopleToRemove);
    for (int m = 0; m < numPeopleToRemove; m++) {
        for (int n = indicesToRemove[m] - add; n < numPeople - 1; n++) {
            people[n]=people[n+1];
            }
        add++;
        numPeople--;
    }
    resetRequests();
}



/*
 * Requires: nothing
 * Modifies: hasUpRequest, hasDownRequest
 * Effects: Search through people to find if there are any
 *          pending up requests or down requests. Set the
 *          values of hasUpRequest and hasDownRequest appropriately.
 *          This function is used to recalculate requests whenever
 *          the people on this floor are added or removed.
 */
void Floor::resetRequests() {
    hasUpRequest = false;
    hasDownRequest = false;
    for (int i = 0; i < numPeople; i++) {
        if (people[i].getTargetFloor() > people[i].getCurrentFloor()) {
            hasUpRequest = true;
        }
        else if (people[i].getTargetFloor() < people[i].getCurrentFloor()) {
            hasDownRequest = true;
        }
    }
}

//////////////////////////////////////////////////////
////// DO NOT MODIFY ANY CODE BENEATH THIS LINE //////
//////////////////////////////////////////////////////

Floor::Floor() {
    hasDownRequest = false;
    hasUpRequest = false;
    numPeople = 0;
}

void Floor::prettyPrintFloorLine1(ostream& outs) const {
    string up = "U";
    outs << (hasUpRequest ? up : " ") << " ";
    for (int i = 0; i < numPeople; ++i){
        outs << people[i].getAngerLevel();
        outs << ((people[i].getAngerLevel() < MAX_ANGER) ? "   " : "  ");
    }
    outs << endl;
}

void Floor::prettyPrintFloorLine2(ostream& outs) const {
    string down = "D";
    outs << (hasDownRequest ? down : " ") << " ";
    for (int i = 0; i < numPeople; ++i) {
        outs << "o   ";
    }
    outs << endl;
}

void Floor::printFloorPickupMenu(ostream& outs) const {
    cout << endl;
    outs << "Select People to Load by Index" << endl;
    outs << "All people must be going in same direction!";
    /*  O   O
    // -|- -|-
    //  |   |
    // / \ / \  */
    outs << endl << "              ";
    for (int i = 0; i < numPeople; ++i) {
        outs << " O   ";
    }
    outs << endl << "              ";
    for (int i = 0; i < numPeople; ++i) {
        outs << "-|-  ";
    }
    outs << endl << "              ";
    for (int i = 0; i < numPeople; ++i) {
        outs << " |   ";
    }
    outs << endl << "              ";
    for (int i = 0; i < numPeople; ++i) {
        outs << "/ \\  ";
    }
    outs << endl << "INDEX:        ";
    for (int i = 0; i < numPeople; ++i) {
        outs << " " << i << "   ";
    }
    outs << endl << "ANGER:        ";
    for (int i = 0; i < numPeople; ++i) {
        outs << " " << people[i].getAngerLevel() << "   ";
    }
    outs << endl << "TARGET FLOOR: ";
    for (int i = 0; i < numPeople; ++i) {
        outs << " " << people[i].getTargetFloor() << "   ";
    }
}

void Floor::setHasUpRequest(bool hasRequest) {
    hasUpRequest = hasRequest;
}

bool Floor::getHasUpRequest() const {
    return hasUpRequest;
}

void Floor::setHasDownRequest(bool hasRequest) {
    hasDownRequest = hasRequest;
}

bool Floor::getHasDownRequest() const {
    return hasDownRequest;
}

int Floor::getNumPeople() const {
    return numPeople;
}

Person Floor::getPersonByIndex(int index) const {
    return people[index];
}
