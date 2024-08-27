/*
 * caesar.cpp
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

#include "caesar.h"
#include <iostream>
char shiftAlphaCharacter(char c, int n) {
    int ch=c;
    int remainder = n % 26;
    if ((c >= 'A')&&(c <= 'Z')) {
        ch = c + remainder;
        if (ch > 'Z') {
            ch = ch - 26;
        }
        else if (ch < 'A') {
            ch = ch + 26;
        }
    }
    else if ((c >= 'a')&&(c <= 'z')) {
        ch = c + remainder;
        if (ch > 'z') {
            ch = ch - 26;
        }
        else if (ch < 'a') {
            ch = ch + 26;
        }
    }
    return ch;
}
        


string caesarCipher(string original, int key, bool encrypt){
    for (int i=0; i<original.size(); ++i) {
        if (isalpha(original[i])) {
            if (encrypt) {
                original[i]=shiftAlphaCharacter(original[i], key);
            }
            else {
                original[i]=shiftAlphaCharacter(original[i], -key);
            }
        }
    }
    return original;
}
