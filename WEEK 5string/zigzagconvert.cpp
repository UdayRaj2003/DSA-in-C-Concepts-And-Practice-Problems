#include <bits/stdc++.h>
using namespace std;

void printv(string s)
{
    for (auto i : s)
    {
        cout << i;
        cout << " ";
    }
}
  string converttt(string s, int numRows) {
        if(numRows==1){
            return s;
        }
        vector<string> temp(numRows);
        string ans = "";
        int row = 0;
        bool direction = 1;
        int y = s.size();
        // direction T->B  == 1
        int i = 0;
        while (i <s.size()) {
            if (direction) {
                for (row; row < numRows && i <= y-1; row++) {
                    temp[row].push_back(s[i++]);
                }
            } else {
                for (row = numRows - 2; row >= 0 && i <= y-1; row--) {
                    temp[row].push_back(s[i++]);
                }
                row = 1;
            }
            direction = !direction;
        }
        for (int i = 0; i < temp.size(); i++) {
            ans += temp[i];
        }
        return ans;
    }
 
    // the main idea ios to go with the direction
    // 1st is to go in a downward direction-> lets say that is denoted by 1
    // after we reach the last row (numRows-1) and input the character we will also be incrementing the row
    // but since the row has exceeded the numRows, we will have to reset the row to 1 before the last row, i.e (numRows-1)
    //  /make sure the / direction is going upwards now so lets denote that by -1
    // after we reach the 1st row again and input the character the row will be decrased by 1 so it will be in negative, so stop
    // change the direction and so on it goes
    // when does it stop?, it stops when the index iterating through each chacter of s comes to an end
     
int main()
{
    string s = "PAYPALISHIRING";
    string ans = converttt(s, 3);
    printv(ans);

    return 0;
}