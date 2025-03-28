#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    getline(cin, s);

    int counts[26] = {0}; // initialize all counts to 0
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (c >= 'A' && c <= 'Z') {
            counts[c - 'A']++;
        }
    }

    int total = 1;
    for (int i = 0; i < 26; i++) {
        total *= (counts[i] + 1);
    }

    cout << total - 1 << endl; // subtract 1 to exclude the case where no letters are highlighted
    return 0;
}
