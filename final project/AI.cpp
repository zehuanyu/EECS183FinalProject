/*
 * Copyright 2023 University of Michigan EECS183
 *
 * AI.cpp
 * Project UID 28eb18c2c1ce490aada441e65559efdd
 *
 * <#Names#>
 * <#Uniqnames#>
 *
 * Final Project - Elevators
 */

#include "AI.h"
#include <cassert>

// This file is used only in the Reach, not the Core.
// You do not need to make any changes to this file for the Core

string getAIMoveString(const BuildingState& buildingState) {
    string result = "";
    string pass = "";
    //elevator pick up
    for (int n = 0; n < NUM_ELEVATORS; n++) {
        int cf = buildingState.elevators[n].currentFloor;
        if (!buildingState.elevators[n].isServicing && buildingState.floors[cf].numPeople != 0) {
            result = 'e' + to_string(n) + 'p';
            return result;
        }
    }
    //find the floor with the max angerlevel
    int tanger = 0;
    int pickf = 0;
    for (int i = 0; i < NUM_FLOORS; i++) {
        int anger = 0;
        for (int j = 0; j < buildingState.floors[i].numPeople; j++) {
            anger += buildingState.floors[i].people[j].angerLevel;
        }
        if (anger > tanger && buildingState.floors[i].numPeople > 0 ) {
            int check1 = 0;
            for (int k = 0; k < NUM_ELEVATORS; k++ ) {
                if (buildingState.elevators[k].targetFloor == i) {
                    check1 +=1;
                }
            }
            if (check1 == 0) {
                pickf = i;
                tanger = anger;
            }
        }
    }

    int maxp = 0;
    if (tanger == 0) {
        for (int q = 0; q < NUM_FLOORS; q++) {
            if (maxp < buildingState.floors[q].numPeople) {
                maxp = buildingState.floors[q].numPeople;
                pickf = q;
            }
        }
    }

    //elevator pass (all elevator are not servicing; all floor has no person)
    int check2 = 0;
    for (int l = 0; l < NUM_ELEVATORS; l++) {
        if (buildingState.elevators[l].isServicing) {
            check2 += 1;
        }
    }
    if (check2 == NUM_ELEVATORS){
        return "";
    }
    
    int nop = 0;
    for (int p = 0; p < NUM_FLOORS; p++) {
        if (buildingState.floors[p].numPeople == 0) {
            nop++;
        }
    }
    if (nop == NUM_FLOORS) {
        return "";
    }
    
    //elevator serviving: find which elevator is close to the pick up floor(with max angerlevel)
    int d;
    int mind = 11;
    int id = 0;
    for (int m = 0; m < NUM_ELEVATORS; m++) {
        if (!buildingState.elevators[m].isServicing) {
            d = abs(buildingState.elevators[m].currentFloor - pickf);
            if (d < mind) {
                mind = d;
                id = m;
            }
        }
    }
    if (mind != 0 && mind < 11) {
        result = 'e' + to_string(id) + 'f' + to_string(pickf);
    }
    return result;
}

string getAIPickupList(const Move& move, const BuildingState& buildingState, 
                       const Floor& floorToPickup) {
    string plist="";
    int uanger = 0;
    int danger = 0;
    int up = 0;
    int dp = 0;
    for (int i = 0; i < floorToPickup.getNumPeople(); i++) {
        if (floorToPickup.getPersonByIndex(i).getTargetFloor() - floorToPickup.getPersonByIndex(i).getCurrentFloor() >=0){
            uanger += floorToPickup.getPersonByIndex(i).getAngerLevel();
            up += 1;
        }
        else {
            danger += floorToPickup.getPersonByIndex(i).getAngerLevel();
            dp += 1;
        }
    }
    if (uanger >= danger) {
        for (int j = 0; j < floorToPickup.getNumPeople(); j++) {
            if (floorToPickup.getPersonByIndex(j).getTargetFloor() - floorToPickup.getPersonByIndex(j).getCurrentFloor() >= 0){
                plist += to_string(j);
            }
        }
    }
    else if (uanger < danger) {
        for (int k = 0; k < floorToPickup.getNumPeople(); k++) {
            if (floorToPickup.getPersonByIndex(k).getTargetFloor() - floorToPickup.getPersonByIndex(k).getCurrentFloor() < 0){
                plist += to_string(k);
            }
        }
    }
    
    return plist;
}









