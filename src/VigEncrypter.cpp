#include "VigEncrypter.h"

/**
* A class used to perform the encrypting algorithm
*/

VigEncrypter::VigEncrypter(string plaintext, string key) {
    this->plaintext = plaintext;
    this->key = key;
}

int VigEncrypter::charToInt(char c) {
    return c - 'a';
}

char VigEncrypter::intToChar(int i) {
    return (char) ('a' + i);
}

string VigEncrypter::extendKey(string key, int length) { // Extends the key so that its length equals the plaintext's length
    int index = 0;
    int originalLength = key.length();
    while (key.length() < length) {
        key += key[index];
        index = (index + 1) % originalLength;
    }
    return key;
}

string VigEncrypter::encrypt() { // Actual encrypting function
    if (plaintext.length() > key.length()) {
        key = extendKey(key, plaintext.length());
    }
    string encryptedText = "";
    for (int i = 0; i < plaintext.length(); i++) { // Iterates over the characters in the plaintext
        char currP = plaintext[i];
        char currKey = key[i];
        bool isUpperCase = isupper(currP);
        char encryptedP = intToChar((charToInt(tolower(currP)) + charToInt(tolower(currKey))) % 26);
        if (isUpperCase) {
            encryptedP = toupper(encryptedP);
        }
        encryptedText += encryptedP;
    }
    return encryptedText;
}
