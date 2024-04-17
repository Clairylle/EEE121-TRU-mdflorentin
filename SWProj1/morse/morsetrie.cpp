#include <iostream>
#include <unordered_map>
#include <string>

class TrieNode {
public:
    std::unordered_map<char, TrieNode*> children;
    bool isEndOfWord;
    
    TrieNode() {
        isEndOfWord = false;
    }
};

class MorseCode {
private:
    TrieNode* root;
    std::unordered_map<char, std::string> morseAlphabet;
    
public:
    MorseCode() {
        root = new TrieNode();
        morseAlphabet = {
            {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."}, {'E', "."}, {'F', "..-."},
            {'G', "--."}, {'H', "...."}, {'I', ".."}, {'J', ".---"}, {'K', "-.-"}, {'L', ".-.."},
            {'M', "--"}, {'N', "-."}, {'O', "---"}, {'P', ".--."}, {'Q', "--.-"}, {'R', ".-."},
            {'S', "..."}, {'T', "-"}, {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"},
            {'Y', "-.--"}, {'Z', "--.."}, {' ', "/"}
        };
        buildTrie();
    }
    
    void buildTrie() {
        for (const auto& pair : morseAlphabet) {
            TrieNode* current = root;
            for (char c : pair.second) {
                if (current->children.find(c) == current->children.end()) {
                    current->children[c] = new TrieNode();
                }
                current = current->children[c];
            }
            current->isEndOfWord = true;
        }
    }
    
    std::string encode(const std::string& text) {
        std::string encodedText = "";
        for (char c : text) {
            if (morseAlphabet.find(toupper(c)) != morseAlphabet.end()) {
                encodedText += morseAlphabet[toupper(c)] + " ";
            }
        }
        return encodedText;
    }
    
    std::string decode(const std::string& morseCode) {
        std::string decodedText = "";
        std::string currentMorse = "";
        for (char c : morseCode) {
            if (c == ' ' && !currentMorse.empty()) {
                for (const auto& pair : morseAlphabet) {
                    if (pair.second == currentMorse) {
                        decodedText += pair.first;
                        break;
                    }
                }
                currentMorse = "";
            } else if (c != ' ') {
                currentMorse += c;
            }
        }
        if (!currentMorse.empty()) {
            for (const auto& pair : morseAlphabet) {
                if (pair.second == currentMorse) {
                    decodedText += pair.first;
                    break;
                }
            }
        }
        return decodedText;
    }
};

int main() {
    MorseCode morseCode;
    
    std::string input;
    char choice;
    std::cout << "Enter 'E' to encode or 'D' to decode: ";
    std::cin >> choice;
    
    if (toupper(choice) == 'E') {
        std::cout << "Enter text to encode: ";
        std::cin.ignore();
        std::getline(std::cin, input);
        std::cout << "Encoded text: " << morseCode.encode(input) << std::endl;
    } else if (toupper(choice) == 'D') {
        std::cout << "Enter Morse code to decode: ";
        std::cin.ignore();
        std::getline(std::cin, input);
        std::cout << "Decoded text: " << morseCode.decode(input) << std::endl;
    } else {
        std::cout << "Invalid choice. Please enter 'E' to encode or 'D' to decode." << std::endl;
    }
    
    return 0;
}
