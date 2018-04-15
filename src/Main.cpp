#include <iostream>
#include <string>
#include <stdexcept>
#include "Arguments.h"
#include "VigCipher.h"
using namespace std;

int main() {
    string text;
    string key;
    string operation;
    string processedText;

    cout << "Welcome to the Vigenere Cipher encrypter\n";
    Arguments arguments;
    text = arguments.getMessage();
    key = arguments.getKey();
    operation = arguments.getOperation();
    VigCipher vigCipher(text, key);
    if (operation.compare("encrypt") == 0) {
        processedText = vigCipher.encrypt();
    } else {
        processedText = vigCipher.decrypt();
    }
    cout << "Here's your " + operation + "ed text: " + processedText << endl;
    return 0;
}
