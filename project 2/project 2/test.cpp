/**
 * test.cpp
 * Project UID 24b93ce4a6274610f4c3f3e31fe17277t
 *
 * Zehuan Yu
 * zehuanyu
 *
 * EECS 183: Project 2
 * Winter 2023
 *
 * Testing functions for your rps.cpp implementation.
 * Holds the definitions of required testing functions.
 * We have stubbed all required functions for you.
 */

#include <iostream>
#include <string>

using namespace std;


//************************************************************************
// You should have implemented the following functions in rps.cpp
//************************************************************************
string getName(int playerNumber);
int getMenuChoice();
bool isMoveGood(char move);
char getMove(string playerName);
bool isRoundWinner(char move, char opponentMove);
void announceRoundWinner(string winnerName);
int doRound(string p1Name, string p2Name);
void announceWinner(string winnerName);
string doGame(string p1Name, string p2Name, int gameType);

//************************************************************************
// The following functions were already implemented for you in rps.cpp
//************************************************************************
void printInitialHeader();
void printMenu();
void printErrorMessage(int errorNumber);
void printCloser();

//************************************************************************
// Testing function declarations. Function definition is below main.
//************************************************************************
void test_isMoveGood();
void test_isRoundWinner();
void test_announceRoundWinner();
void test_announceWinner();


void startTests() {
    cout << "\nExecuting your test cases\n";

    test_isMoveGood();
    test_isRoundWinner();
    test_announceRoundWinner();
    test_announceWinner();

    
    

    return;
}

//************************************************************************
// Put all your test function implementations below here.
// We have stubbed all required functions for you
// to recieve full points when submitting test.cpp
// NOTE: We will only grade your tests for the following functions
//       * isMoveGood
//       * isRoundWinner
//       * announceRoundWinner()
//       * announceWinner()
//************************************************************************

void test_isMoveGood() {
    cout << "Now testing function isMoveGood()\n";
    cout << "'r': Expected: 1, Actual: " << isMoveGood('r') << endl;
    cout << "'q': Expected: 0, Actual: " << isMoveGood('q') << endl;
    cout << "'P': Expected: 1, Actual: " << isMoveGood('P') << endl;
    return;
}

void test_isRoundWinner() {
    cout << "Now testing function isRoundWinner()\n";
    cout << "'r' and 's': Expected: 1, Actual: " << isRoundWinner('r','s') << endl;
    cout << "'p' and 's': Expected: 0, Actual: " << isRoundWinner('p','s') << endl;
    cout << "'p' and 'p': Expected: 0, Actual: " << isRoundWinner('p','p') << endl;
    cout << "'R' and 's': Expected: 1, Actual: " << isRoundWinner('R','s') << endl;
    cout << "'s' and 'P': Expected: 1, Actual: " << isRoundWinner('s','P') << endl;
    cout << "'P' and 'P': Expected: 0, Actual: " << isRoundWinner('P','P') << endl;
    cout << "'R' and 'S': Expected: 1, Actual: " << isRoundWinner('R','S') << endl;
    return;
}

void test_announceRoundWinner() {
    cout << "Now testing function announceRoundWinner()\n";
    cout << "Rana Makki: Expected: Rana Makki wins the round!, Actual: ";
    announceRoundWinner("Rana Makki");
    cout << "'': Expected: This round is a draw!, Actual: ";
    announceRoundWinner("");
    return;
}

void test_announceWinner() {
    cout << "Now testing function announceRoundWinner()\n";
    cout << "Rana Makki: Expected: Congratulations Rana Makki!..., Actual: ";
    announceWinner("Rana Makki");
    cout << "'': Expected: No winner!, Actual: ";
    announceWinner("");
    return;
}

