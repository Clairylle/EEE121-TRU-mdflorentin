// C++ program to encode and decode Morse code

#include <iostream>
#include <map>
#include <string>

using namespace std;

// Morse code map
map<char, string> morseCode = {
    {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."}, {'E', "."}, {'F', "..-."},
    {'G', "--."}, {'H', "...."}, {'I', ".."}, {'J', ".---"}, {'K', "-.-"}, {'L', ".-.."},
    {'M', "--"}, {'N', "-."}, {'O', "---"}, {'P', ".--."}, {'Q', "--.-"}, {'R', ".-."},
    {'S', "..."}, {'T', "-"}, {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"},
    {'Y', "-.--"}, {'Z', "--.."}, {' ', "/"}
};

// Function to encode a message to Morse code
string encodeToMorse(string message) {
    string morseMessage = "";
    for (char c : message) {
        morseMessage += morseCode[toupper(c)] + " ";
    }
    return morseMessage;
}

// Function to decode Morse code to a message
string decodeFromMorse(string morseMessage) {
    string message = "";
    string morseChar = "";
    for (char c : morseMessage) {
        if (c == ' ' && morseChar != "") {
            for (auto const &pair : morseCode) {
                if (pair.second == morseChar) {
                    message += pair.first;
                    break;
                }
            }
            morseChar = "";
        } else if (c != ' ') {
            morseChar += c;
        }
    }
    return message;
}

int main() {
    string message;
    cout << "Enter a message to encode/decode: ";
    getline(cin, message);

    string encodedMessage = encodeToMorse(message);
    cout << "Encoded message: " << encodedMessage << endl;

    string decodedMessage = decodeFromMorse(encodedMessage);
    cout << "Decoded message: " << decodedMessage << endl;

    return 0;
}
