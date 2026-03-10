#include <iostream>
#include <vector>
#include <string>
using namespace std;

void printv(vector<int> nums){
    for (auto i:nums)
    {
        cout<<i;
        cout<<" ";
    }
    cout<<endl;
}
int solveLCS(string& text1, string& text2) {
    int n = text1.length();
    int m = text2.length();
    
    vector<int> dp(m + 1, 0);

    for (int i = n - 1; i >= 0; i--) {
        int diagonal = 0;
        for (int j = m - 1; j >= 0; j--) {
            int temp = dp[j];
            if (text1[i] == text2[j]) {
                dp[j] = 1 + diagonal;
            } else {
                dp[j] = max(dp[j], dp[j + 1]);
            }
            diagonal = temp;
            printv(dp);
            cout<<endl;
        }
            cout<<endl;
            cout<<endl;
            cout<<endl;

    }

    return dp[0];
}

int main() {
    string text1, text2;

    cout << "Enter first string: ";
    cin >> text1;

    cout << "Enter second string: ";
    cin >> text2;

    int lcsLength = solveLCS(text1, text2);
    cout << "Length of Longest Common Subsequence: " << lcsLength << endl;

    return 0;
}

