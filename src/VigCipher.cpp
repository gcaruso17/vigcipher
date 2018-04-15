#include "VigCipher.h"

/**
* The class used to represent A Vigenere Cipher
*/

VigCipher::VigCipher(string plaintext, string key) {
    this->plaintext = plaintext;
    this->key = key;
}

int VigCipher::charToInt(char c) {
    return c - 'a';
}

char VigCipher::intToChar(int i) {
    return (char) ('a' + i);
}

int VigCipher::eucMod(int a, int b) {
    return a < 0 ? (((a % b) + b) % b) : (a % b);
}

string VigCipher::extendKey(string key, int length) { // Extends the key so that its length equals the plaintext's length
    int index = 0;
    int originalLength = key.length();
    while (key.length() < length) {
        key += key[index];
        index = (index + 1) % originalLength;
    }
    return key;
}

string VigCipher::processText(string operation) { // Processes the characters in the plaintext
    if (plaintext.length() > key.length()) {
        key = extendKey(key, plaintext.length());
    }
    string processedText = "";
    for (int i = 0; i < plaintext.length(); i++) { // Iterates over the characters in the plaintext
        char currP = plaintext[i];
        char currKey = key[i];
        bool wasUpperCase = isupper(currP);
        char processedP;
        if (operation.compare("crypt") == 0) {
            processedP = intToChar(eucMod((charToInt(tolower(currP)) + charToInt(tolower(currKey))), 26));
        } else {
            processedP = intToChar(eucMod((charToInt(tolower(currP)) - charToInt(tolower(currKey))), 26));
        }
        if (wasUpperCase) {
            processedP = toupper(processedP);
        }
        processedText += processedP;
    }
    return processedText;
}

string VigCipher::encrypt() { // Actual encrypting function
    return processText("crypt");
}

string VigCipher::decrypt() { // Actual decrypting function
    return processText("decrypt");
}
