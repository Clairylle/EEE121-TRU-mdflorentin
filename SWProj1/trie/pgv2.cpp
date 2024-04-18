#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAX_LEN = 200;
const int MAX_N = 50000;
const int ALPHABET_SIZE = 2;

// Trie Node
struct TrieNode {
    TrieNode* children[ALPHABET_SIZE];
    int count;

    TrieNode() {
        count = 0;
        memset(children, 0, sizeof(children));
    }
};

// Global variable to count nodes in the trie
int count = 0;

// Trie class
class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    // Insert a string into the trie
    void insert(string& str) {
        TrieNode* curr = root;
        for (char c : str) {
            int index = c - '0';
            if (!curr->children[index]) {
                curr->children[index] = new TrieNode();
                count++; // Increment count when a new node is created
            }
            curr = curr->children[index];
            curr->count++;
        }
    }

    // Calculate max prefix length
    int maxPrefixLength(TrieNode* node) {
        int length = 0;
        for (int i = 0; i < ALPHABET_SIZE; ++i) {
            if (node->children[i]) {
                length = max(length, 1 + maxPrefixLength(node->children[i]));
            }
        }
        return length;
    }

    // Function to calculate prefix goodness
    long long prefixGoodness(TrieNode* node, int len) {
        long long pg = 0;
        for (int i = 0; i < ALPHABET_SIZE; ++i) {
            if (node->children[i]) {
                pg += prefixGoodness(node->children[i], len + 1);
            }
        }
        pg += len * node->count;
        return pg;
    }

    // Get root node of the trie
    TrieNode* getRoot() {
        return root;
    }
};

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; ++t) {
        int n;
        cin >> n;

        Trie trie;
        int totalDigits = 0;
        count = 1; // Initialize count to 1 for the root node

        // Insert strings into trie
        for (int i = 0; i < n; ++i) {
            string str;
            cin >> str;
            trie.insert(str);
            totalDigits += str.size();
        }

        TrieNode* root = trie.getRoot();

        // Calculate max prefix length and prefix goodness
        int maxPrefixLen = trie.maxPrefixLength(root);
        long long totalSubstrings = (long long)n * (n + 1) / 2;
        long long prefixGoodness = maxPrefixLen * totalSubstrings;

        // Output results
        cout << "Test Case #" << t + 1 << ":" << endl;
        cout << "Number of digits in all binary strings: " << totalDigits << endl;
        cout << "Number of nodes in Trie: " << count << endl;
        cout << "Max Prefix Length: " << maxPrefixLen << endl;
        cout << "Total Substrings: " << totalSubstrings << endl;
        cout << "Prefix Goodness: " << prefixGoodness << endl;
    }

    return 0;
}
