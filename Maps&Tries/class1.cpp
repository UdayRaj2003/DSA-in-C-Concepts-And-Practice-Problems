#include <bits/stdc++.h>
using namespace std;

int main() {
    string str = "lovebabbar";
    unordered_map<char, int> count;

    for (int i = 0; i < str.length(); i++) {
        count[str[i]]++;
    }

    for (auto pair : count) {
        cout << pair.first << " -> " << pair.second << endl;
    }

    return 0;
}
