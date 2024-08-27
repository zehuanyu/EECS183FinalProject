/*
 * Copyright 2023 University of Michigan EECS183
 *
 * test.cpp
 * Project UID 28eb18c2c1ce490aada441e65559efdd
 *
 * Final Project - Elevators
 */
 
////////////////////////////////////////////////
// You will submit test.cpp to the autograder //
// FOR LAB 8, but NOT the final project Core  //
////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <string>
#include "AI.h"
#include "Building.h"
#include "BuildingState.h"
#include "Elevator.h"
#include "Floor.h"
#include "Game.h"
#include "Move.h"
#include "Person.h"
#include "SatisfactionIndex.h"
#include "Utility.h"

using namespace std;

// declare your test functions here
void person_tests();
void elevator_tests();
void floor_tests();
void move_tests();
void building_tests();
void game_tests();
void AI_tests();

void start_tests() {
    person_tests();
    //elevator_tests();
    //floor_tests();
    //move_tests();
    //building_tests();
    //game_tests();
    //AI_tests();
    return;
}

void person_tests() {
    //initialize a person with targetFloor 5, anger 5
    Person p("0f0t5a5");

    cout << p.getTargetFloor() << " " << p.getAngerLevel() << " Expected 5 5" << endl;

    //simulate time being a multiple of TICKS_PER_ANGER_INCREASE
    bool exploded = p.tick(TICKS_PER_ANGER_INCREASE);

    cout << exploded << " Expected 0" << endl;

    cout << p.getTargetFloor() << " " << p.getAngerLevel() << " Expected 5 6" << endl;

    //simulate time not being a multiple
    p.tick(TICKS_PER_ANGER_INCREASE - 1);

    //no change
    cout << p.getTargetFloor() << " " << p.getAngerLevel() << " Expected 5 6" << endl;

    p.tick(TICKS_PER_ANGER_INCREASE); //7 after

    p.tick(TICKS_PER_ANGER_INCREASE); //8 after

    p.tick(TICKS_PER_ANGER_INCREASE); //9 after

    exploded = p.tick(TICKS_PER_ANGER_INCREASE);

    cout << exploded << " Expected 1" << endl;
    string personInfo = "7f4t8a3";
    Person newPerson(personInfo);
    newPerson.print(cout);
    
}

void elevator_tests() {
    cout << "Test of default constructor" << endl;
    Elevator E0;
    cout << E0.isServicing() << " Expected 0" << endl;
    cout << E0.getTargetFloor() << " Expected 0" << endl;
    cout << E0.getCurrentFloor() << " Expected 0" << endl;
    Elevator E1;
    E1.setCurrentFloor(1);
    E1.serviceRequest(3);
    
    

}

void floor_tests() {
    Floor test;
    Person p1;
    test.addPerson(p1, 1);
    cout << test.getNumPeople() << endl;
    cout << test.getHasUpRequest() << endl;
    cout << test.getHasDownRequest() << endl;
    
    test.addPerson(p1, 2);
    test.addPerson(p1, 3);
    test.addPerson(p1, 4);
    test.addPerson(p1, 5);
    test.addPerson(p1, 6);
    test.addPerson(p1, 7);
    test.addPerson(p1, 8);
    test.addPerson(p1, 9);
    test.addPerson(p1, 1);
    test.addPerson(p1, 2);
    cout << test.getNumPeople() << endl;
    cout << test.getHasUpRequest() << endl;
    cout << test.getHasDownRequest() << endl;
    
    const int num = 1;
    int indices [10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    test.removePeople(indices, num);
    cout << test.getNumPeople() << endl;
    cout << test.getHasUpRequest() << endl;
    cout << test.getHasDownRequest() << endl;
    
    cout << test.tick(3);
    cout << test.getPersonByIndex(2).getAngerLevel();
}

void move_tests() {
    Move test;
    cout << test.getElevatorId() << endl;
    cout << test.getTargetFloor() << endl;
    cout << test.getTotalSatisfaction() << endl;
    cout << test.getNumPeopleToPickup() << endl;
    cout << test.isPickupMove() << endl;
    
    Move test1("");
    cout << test1.isPassMove() << endl;
    Move test2("S");
    cout << test2.isSaveMove() << endl;
    Move test3("Q");
    cout << test3.isQuitMove() << endl;
    
}
void building_tests() {
    Building test;
    cout << test.getTime() << endl;
    
    test.spawnPerson(Person());
    cout << test.getFloorByFloorNum(1).getNumPeople() << endl;
    
    cout << test.tick(Move("e1f4"));
    cout << test.getFloorByFloorNum(4).getPersonByIndex(1).getAngerLevel() << endl;
    
    test.setTime(3);
    cout << test.getTime() << endl;
    
    test.setElevator("f4", 1);
    cout << test.getElevatorById(1).getCurrentFloor() << endl;
}

void game_tests() {
    
}
void AI_tests();
