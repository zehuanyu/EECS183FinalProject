/*
 * polybius.cpp
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


#include "polybius.h"
#include <string>
using namespace std;

string mixKey(string key) {
    string content = key;
    content += ALNUM;
    content = removeDuplicate(content);
    return content;
}

void fillGrid(char grid[SIZE][SIZE], string content) {
    int loc = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = content[loc];
            loc += 1;
        }
    }
    return;
}

string findInGrid(char c, char grid[SIZE][SIZE]) {
    string location;
    char row;
    char column;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (c == grid[i][j]) {
                row = i + '0';
                column = j + '0';
                location = location + row + column;
            }
        }
    }
    return location;
}
    
string polybiusSquare(char grid[SIZE][SIZE], string key,
                      string original, bool encrypt) {
    string content;
    string output;
    
    content = mixKey(key);
    fillGrid(grid, content);
    if (encrypt) {
        for (int i = 0; i < original.length(); i++) {
            if (isalnum(original[i])) {
                output = output + findInGrid(original[i], grid);
            }
            else {
                output = output + " ";
            }
        }
    }
    else {
        int i = 0;
        while (i < original.length()) {
            if (isalnum(original[i])) {
                int p1 = original[i] - '0';
                int p2 = original[i+1] - '0';
                output = output + grid[p1][p2];
                i += 2;
            }
            else {
                output = output + " ";
                i += 1;
            }
        }
    }
    return output;
}

