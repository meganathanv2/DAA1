
#include <iostream>
#include <vector>
#include <string>

using namespace std;
vector<int> computeLPS(string pattern) {
    int length = 0; 

    vector<int> lps(pattern.length(), 0);
    
    int i = 1;
    while (i < pattern.length()) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

void KMPSearch(string text, string pattern) {
    vector<int> lps = computeLPS(pattern);
    
    int i = 0; 
    int j = 0; 

    while (i < text.length()) {
        if (pattern[j] == text[i]) {
            j++;
            i++;
        }

        if (j == pattern.length()) {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];
        } else if (i < text.length() && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i = i + 1;
            }
        }
    }
}

int main() {
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";

    KMPSearch(text, pattern);

    return 0;
}
