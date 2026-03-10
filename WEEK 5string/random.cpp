#include <bits/stdc++.h>
#include <string>
using namespace std;
void print2d(vector<vector<char>> vect);

//     string removeDuplicates(string s) {
//             for(int j=0; j<=s.length();j++){
//              for(int i=0; i<=s.length();i++){
//                 if( s[i]==s[i+1]){
//                     s.erase(i,2);

//             }
//             }}

//             cout<<s;}

//             class Solution {
// public:

bool pal(string str)
{
  int k = 0, z = str.length() - 1;
  while (k <= z)
  {
    if (str[k] == str[z])
    {
      k++;
      z--;
    }
    else
    {
      return false;
    }
  }
  return true;
}
bool isPalindrome(int x)
{
  if (x < 0)
    return false;

  long reversed = 0;
  int y = x;

  while (y > 0)
  {
    reversed = reversed * 10 + y % 10;
    y /= 10;
  }

  return reversed == x;
}
// bool validPalindrome(string s) {
//        int arr[2] ;
//     int i = 0, j = s.length() - 1;
//     if (checkpal(s, i, j,arr)==1) {
//         return true;
//     }
//     else if (checkpal(s, arr[0]+1, arr[1],arr) || checkpal(s, arr[0], arr[1]- 1,arr)) {
//         return true;
//     } else {
//         return false;
//     }

// }
// }



void print2d(vector<vector<char>> vect)
{

  for (int i = 0; i < vect.size(); i++)
  {
    for (int j = 0; j < vect[i].size(); j++)
    {
      cout << vect[i][j] << " ";
    }
    cout << endl;
  cout<<"hell111"<<endl;
  }
}

int main()
{
  string s = "PAYPALISHIRING"; 
  // string str = "b";

  // int a = pal(str);
  // cout << a;
  // cout<< char(ch+32);
  // removeDuplicates(s);
  // cout << "The String after removing duplicates is :" << s ;
  // string s = "abba";

  // for (auto c : s)
  //   cout << c << endl;
  return 0;
}
