#include <iostream>
#include <string>
#include <stdexcept>
#include "VigEncrypter.h"
using namespace std;

int main() {
    string plaintext;
    string key;
    cout << "Welcome to the Vigenere Cipher encrypter\n";
    cout << "Please enter a text to encrypt: ";
    getline(cin, plaintext);
    if (plaintext.length() <= 0) { // Checks whether the plaintext is valid
        throw invalid_argument("Null plaintext");
    }
    cout << "Please enter a key: ";
    getline(cin, key);
    if (key.length() <= 0) { // Checks whether the key is valid
        throw invalid_argument("Null key");
    }
    VigEncrypter vigEncrypter(plaintext, key);
    string encryptedText = vigEncrypter.encrypt();
    cout << "Here's your encrypted text: " + encryptedText << endl;
    return 0;
}
