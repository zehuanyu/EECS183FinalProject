/*
 * vigenere.cpp
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
#include <iostream>

string vigenereCipher(string original, string keyword, bool encrypt) {
    keyword = toUpperCase(keyword);
    keyword = removeNonAlphas(keyword);
    string needkey = "";
    while (keyword.size() < original.size()) {
        keyword += keyword;
    }
    int record=0;
    
    for (int i=0; i < original.size(); ++i) {
        if (isalpha(original[i])) {
            needkey += keyword[record];
            record += 1;
        }
        else {
            needkey += " ";
        }
    }
    
    int move=0;
    
    for (int j = 0; j < original.size(); ++j) {
        move = needkey[j] - 'A';
        if (encrypt) {
            original[j]=shiftAlphaCharacter(original[j], move);
        }
        else {
            original[j]=shiftAlphaCharacter(original[j], -move);
            move = needkey[j] - 'A';
        }
    }
    return original;
}
