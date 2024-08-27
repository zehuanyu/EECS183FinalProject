/*
 * utility.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * <#Names#>
 * <#Uniqnames#>
 *
 * EECS 183: Project 3
 * Winter 2023
 *
 * <#description#>
 */

#include "utility.h"
#include <iostream>


string toUpperCase(string original) {
    string copy = original;
      for (int i = 0; i < original.length(); i++) {
          if (isalpha(original[i])) {
              copy[i] = toupper(original[i]);
          }
          else {
              copy[i] = original[i];
          }
      }
      return copy;
}


string removeNonAlphas(string original) {
    string copy;
    for (int i = 0; i < original.length(); i ++) {
        if (isalpha(original[i])) {
            copy += original[i];
        }
    }
    return copy;
}

string removeDuplicate(string original) {
    string new_string;
        for (int i = 0; i < original.length(); i++) {
            if(original[i] != ' ') {
                new_string += original[i];
                for (int j = i + 1; j < original.length(); j++) {
                    if(original[j] == original[i]) {
                        original[j] = ' ';
                    }
                }
            }
        }
    return new_string;
}

int charToInt(char original) {
    int number;
    number = int(original) - 48;
    return number;
}

////////////////////////////////////////////////////////////////////////////////
// Do not touch code below. ////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void printGrid(const char grid[SIZE][SIZE]) {
    for (int col = 0; col < SIZE; col++) {
        cout << " ---";
    }
    cout << endl;
    for (int row = 0; row < SIZE; row++) {
        cout << "| ";
        for (int col = 0; col < SIZE; col++) {
            cout << string(1, grid[row][col]) + " | ";
        }
        cout << endl;
        for (int col = 0; col < SIZE; col++) {
            cout << " ---";
        }
        cout << endl;
    }
}
