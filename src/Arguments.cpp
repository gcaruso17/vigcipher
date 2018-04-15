#include <iostream>
#include "Arguments.h"
using namespace std;

/**
* A class used to parse the input
*/

Arguments::Arguments() {
    cout << "What would you like to do? (Encrypt e, Decrypt d): ";
    getline(cin, answer);
    if (answer.length() <= 0 || answer != "e" && answer != "d") {
        throw invalid_argument("Invalid answer");
    }
    cout << "Please enter a text: ";
    getline(cin, message);
    if (message.length() <= 0) { // Checks whether the text is valid
        throw invalid_argument("Null text");
    }
    cout << "Please enter a key: ";
    getline(cin, key);
    if (key.length() <= 0) { // Checks whether the key is valid
        throw invalid_argument("Null key");
    }
}

string Arguments::getMessage() {
    return message;
}

string Arguments::getKey() {
    return key;
}

string Arguments::getOperation() {
    return answer.compare("e") == 0 ? "encrypt" : "decrypt";
}
