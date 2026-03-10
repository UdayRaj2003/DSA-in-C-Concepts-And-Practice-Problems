#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    char value;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char val) {
        this->value = val;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        this->isTerminal = false;
    }
};

void insertWord(TrieNode* root, const string& word) {
    if (word.length() == 0) {
        root->isTerminal = true;
        return;
    }

    char ch = word[0];
    int index = ch - 'a';
    TrieNode* child;
    if (root->children[index] != nullptr) {
        child = root->children[index];
    } else {
        child = new TrieNode(ch);
        root->children[index] = child;
    }

    insertWord(child, word.substr(1));
}

void collectwords(TrieNode* current, string str, vector<string>& ans, int& count) {
    if (current->isTerminal) {
        ans.push_back(str);
        count++;
    }

    for (int i = 0; i < 26; i++) {
        if (current->children[i] != nullptr) {
            char nextChar = 'a' + i;
            collectwords(current->children[i], str + nextChar, ans, count);
        }
    }
}

int printwithch(TrieNode* root, string str, vector<string>& ans) {
    TrieNode* current = root;
    for (char i : str) {
        int index = i - 'a';
        if (current->children[index] == nullptr) {
            return 0;
        }
        current = current->children[index];
    }
    int count = 0;
    collectwords(current, str, ans, count);
    return count;
}

// ✅ Wrap this inside a class
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        TrieNode* root = new TrieNode('-');

        for (const auto& word : strs) {
            insertWord(root, word);
        }

        string result = "";
        string put = "";
        string str = strs[0];

        for (char ch : str) {
            put += ch;
            vector<string> ans;
            int count = printwithch(root, put, ans);
            if (count == strs.size()) {
                result = put;
            } else {
                break;
            }
        }

        return result;
    }
};

int main() {
    vector<string> strs = {"flower", "flower", "flower", "flower"};

    // ✅ Create object and call the method
    Solution sol;
    string result = sol.longestCommonPrefix(strs);
    cout << result << endl;

    return 0;
}
