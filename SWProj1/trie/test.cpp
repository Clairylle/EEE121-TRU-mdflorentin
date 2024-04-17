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

        // Insert strings into trie
        for (int i = 0; i < n; ++i) {
            string str;
            cin >> str;
            trie.insert(str);
            totalDigits += str.size();
        }

        TrieNode* root = trie.getRoot();

        // Calculate number of nodes in the trie
        int numNodes = 0;
        for (int i = 0; i < ALPHABET_SIZE; ++i) {
            if (root->children[i]) {
                numNodes++;
            }
        }

        // Calculate max prefix length and prefix goodness
        int maxPrefixLen = trie.maxPrefixLength(root);
        long long prefixGoodness = trie.prefixGoodness(root, 0);
        long long totalSubstrings = (long long)n * (n + 1) / 2;

        // Output results
        cout << "Test Case #" << t + 1 << ":" << endl;
        cout << "Number of digits in all binary strings: " << totalDigits << endl;
        cout << "Number of nodes in Trie: " << numNodes << endl;
        cout << "Max Prefix Length: " << maxPrefixLen << endl;
        cout << "Total Substrings: " << totalSubstrings << endl;
        cout << "Prefix Goodness: " << prefixGoodness << endl;
    }

    return 0;
}
