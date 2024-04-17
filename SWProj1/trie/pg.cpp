#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<string> binaryStrings(n);
        for (int i = 0; i < n; ++i) {
            cin >> binaryStrings[i];
        }

        // Calculate the required values
        // Number of digits in all binary strings
        int totalDigits = 0;
        for (const string& str : binaryStrings) {
            totalDigits += str.size();
        }

        // Number of nodes in Trie (Assuming Trie implementation)
        int totalNodes = 0; // Implement Trie and calculate nodes

        // Max Prefix Length (maxPrefixLengthCommonPrefix)
        int maxPrefixLength = 0; // Calculate max prefix length

        // Total Substrings (totalSubStringsCommonPrefixStringSet)
        int totalSubstrings = 0; // Calculate total substrings

        // Prefix Goodness (PG)
        int prefixGoodness = maxPrefixLength * totalSubstrings;

        // Output the results
        cout << totalDigits << " " << totalNodes << " " << maxPrefixLength << " " << totalSubstrings << " " << prefixGoodness << endl;
    }

    return 0;
}
