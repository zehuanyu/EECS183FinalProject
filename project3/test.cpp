/*
 * test.cpp
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
#include "caesar.h"
#include "vigenere.h"
#include "polybius.h"
#include <iostream>
#include <string>


using namespace std;


void testShiftAlphaCharacter();
void testcaesarCipher();
void testvigenereCipher();
void testmixKey();
void testfillGrid();
void testFindInGrid();
void testPolybiusSquare();

void startTests() {
    testShiftAlphaCharacter();
    testcaesarCipher();
    testvigenereCipher();
    testmixKey();
    testfillGrid();
    testFindInGrid();
    testPolybiusSquare();



    return;
}


void testShiftAlphaCharacter() {
    cout << "Now testing function ShiftAlphaCharacter()" << endl;
    cout << "Expected: 'a', Actual: '" << shiftAlphaCharacter('a', 0) << "'" << endl;
    cout << "Expected: 'j', Actual: '" << shiftAlphaCharacter('t', 42) << "'" << endl;
    cout << "Expected: 'd', Actual: '" << shiftAlphaCharacter('b', 2) << "'" << endl;
    cout << "Expected: 'C', Actual: '" << shiftAlphaCharacter('X', 5) << "'" << endl;
    cout << "Expected: 'M', Actual: '" << shiftAlphaCharacter('C', -42) << "'" << endl;
    return;
}
void testcaesarCipher() {
    cout << "Now testing function testcaesarCipher()" << endl;
    cout << "Expected: Cuuj cu qj jxu Tyqw qj 11 f.c." << endl;
    cout << "Actual: " << caesarCipher ("Meet me at the Diag at 11 p.m.", 42, true) << endl;
    cout << "Expected: Meet me at the Diag at 11 p.m." << endl;
    cout << "Actual: " << caesarCipher ("Cuuj cu qj jxu Tyqw qj 11 f.c.", 42, false) << endl;
    cout << "Expected: Euyb dv ee lxy Lzrk ll 11 f.g." << endl;
    cout << "Actual: " << caesarCipher ("Meet me at the Diag at 11 p.m.", 112, false) << endl;
}
void testvigenereCipher() {
    cout << "Now testing function testvigenereCipher()" << endl;
    cout << "Expected: Euyb dv ee lxy Lzrk ll 11 f.g." << endl;
    cout << "Actual: " << vigenereCipher("Meet me at the Diag at 11 p.m.", "Squirrel!", true) << endl;
    cout << "Expected: Meet me at the Diag at 11 p.m." << endl;
    cout << "Actual: " << vigenereCipher("Euyb dv ee lxy Lzrk ll 11 f.g.", "Squirrel!", false) << endl;
}
void testmixKey() {
    cout << "Now testing function testmixKey()" << endl;
    cout << "Expected: POLYBIUSACDEFGHJKMNQRTVWXZ0123456789" << endl;
    cout << "Actual: " << mixKey("POLYBIUS") << endl;
}

void testfillGrid() {
    char grid[SIZE][SIZE];
    fillGrid(grid, ALNUM);
    printGrid(grid);
    
}

void testFindInGrid() {
    cout << "Now test for findInGrid:" << endl;
    char grid[SIZE][SIZE];
    fillGrid(grid, "183ABCDEFGHIJKLMNOPQRSTUVWXYZ0245679");
    printGrid(grid);
    cout << "Expected: 10, Actual: " << findInGrid('G', grid) << endl;
    cout << "Expected: 55, Actual: " << findInGrid('9', grid) << endl;
    cout << "Expected: 00, Actual: " << findInGrid('A', grid) << endl;
    //cout << findInGrid('A', grid) << endl;
    }



void testPolybiusSquare() {
    cout << "Now test for polybiusSquare:" << endl;
    char grid[SIZE][SIZE];
    fillGrid(grid, ALNUM);
    cout << "Expected: 11110533 000102 1533 341411 04113334" << endl;
    cout << "Actual  : ";
    cout << polybiusSquare(grid, "183", "EECS 183 IS THE BEST", true) << endl;
    cout << "Expected: EECS 183 IS THE BEST" << endl;
    cout << "Actual  : ";
    cout << polybiusSquare(grid, "183", "11110533 000102 1533 341411 04113334", false) << endl;
    cout << polybiusSquare(grid, "POLYBIUS", "EECS 183 IS THE BEST", true) << endl;
    cout << polybiusSquare(grid, "POLYBIUS", "15151311 435445 0511 332215 04151133", false) << endl;
}


