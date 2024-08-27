/*
 * ciphers.cpp
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
void ciphers(){
    cout << "Choose a cipher (Caesar, Vigenere, or Polybius): ";
    string cipher;
    string crypt;
    string message;
    string result;
    getline(cin, cipher);
    cout << endl;
    cipher=toUpperCase(cipher);
    if ((cipher == "CAESAR") || (cipher == "C")) {
        cout << "Encrypt or decrypt: ";
        getline(cin, crypt);
        cout << endl;
        crypt=toUpperCase(crypt);
        bool encipherC=true;
        if ((crypt == "ENCRYPT") || (crypt == "E") || (crypt == "DECRYPT")|| (crypt == "D")){
            if ((crypt == "ENCRYPT") || (crypt == "E")) {
                encipherC = true;
            }
            else {
                encipherC = false;
            }
            cout << "Enter a message: ";
            getline(cin, message);
            cout << endl;
            int key;
            cout << "What is your key: ";
            cin >> key;
            cout << endl;
            result = caesarCipher(message, key, encipherC);
            if (encipherC==true) {
                cout << "The encrypted message is: " << result << endl;
            }
            else {
                cout << "The decrypted message is: " << result << endl;
            }
        }
        else {
            cout << "Invalid mode!" << endl;
        }
    }
    else if ((cipher == "VIGENERE") || (cipher == "V")) {
        cout << "Encrypt or decrypt: ";
        getline(cin, crypt);
        cout << endl;
        crypt=toUpperCase(crypt);
        bool encipherV = true;
        if ((crypt == "ENCRYPT") || (crypt == "E") || (crypt == "DECRYPT")|| (crypt == "D")){
            if ((crypt == "ENCRYPT") || (crypt == "E")) {
                encipherV = true;
            }
            else {
                encipherV = false;
            }
            cout << "Enter a message: ";
            getline(cin, message);
            cout << endl;
            string keyword;
            cout << "What is your key: ";
            getline(cin,keyword);
            cout << endl;
            int recordkey=0;
            for (int j=0; j < keyword.size(); ++j) {
                if (isalpha(keyword[j])) {
                    recordkey+=1;
                }
            }
            if (recordkey>0) {
                result = vigenereCipher(message, keyword, encipherV);
                if (encipherV==true) {
                    cout << "The encrypted message is: " << result << endl;
                }
                else {
                    cout << "The decrypted message is: " << result << endl;
                }
            }
            else {
                cout << "Invalid key!" << endl;
            }
        }
        else {
            cout << "Invalid mode!" << endl;
        }
    }
    else if ((cipher == "POLYBIUS") || (cipher == "P")){
        cout << "Encrypt or decrypt: ";
        getline(cin, crypt);
        cout << endl;
        crypt=toUpperCase(crypt);
        bool encipherP = true;
        if ((crypt == "ENCRYPT") || (crypt == "E") || (crypt == "DECRYPT")|| (crypt == "D")){
            if ((crypt == "ENCRYPT") || (crypt == "E")) {
                encipherP = true;
                cout << "Enter a message: ";
                getline(cin, message);
                cout << endl;
                message=toUpperCase(message);
                int record=0;
                for (int i=0; i < message.size(); ++i) {
                    if (isalpha(message[i]) || isdigit(message[i]) || message[i] == ' ' ) {
                        record+=1;
                    }
                }
                if (record == message.size()) {
                    string keyword;
                    cout << "What is your key: ";
                    getline(cin,keyword);
                    cout << endl;
                    keyword=toUpperCase(keyword);
                    keyword=removeDuplicate(keyword);
                    keyword=mixKey(keyword);
                    char grid[SIZE][SIZE];
                    fillGrid(grid, ALNUM);
                    result = polybiusSquare(grid, keyword, message, encipherP);
                    cout << "The encrypted message is: " << result << endl;
                }
                else {
                    cout << "Invalid message!" << endl;
                }
            }
            else {
                encipherP = false;
                cout << "Enter a message: ";
                getline(cin, message);
                cout << endl;
                message=toUpperCase(message);
                int record=0;
                for (int i=0; i < message.size(); ++i) {
                    if (isdigit(message[i]) || message[i] == ' ' ) {
                        record+=1;
                    }
                }
                if (record == message.size()) {
                    string keyword;
                    cout << "Enter a message: ";
                    getline(cin,keyword);
                    cout << endl;
                    keyword=toUpperCase(keyword);
                    keyword=removeDuplicate(keyword);
                    keyword=mixKey(keyword);
                    char grid[SIZE][SIZE];
                    fillGrid(grid, ALNUM);
                    result = polybiusSquare(grid, keyword, message, encipherP);
                    cout << "The decrypted message is: " << result << endl;
                }
                else {
                    cout << "Invalid message!" << endl;
                }
            }
        }
        else {
            cout << "Invalid mode!" << endl;
        }
    }
    else {
        cout << "Invalid cipher!" << endl;
    }
}
