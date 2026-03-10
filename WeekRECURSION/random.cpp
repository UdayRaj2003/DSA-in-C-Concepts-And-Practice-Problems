#include <bits/stdc++.h>
using namespace std;

void printv(vector<int> nums){
    for (auto i:nums)
    {
        cout<<i;
        cout<<" ";
    }
}
    
void print2DArray(const vector<vector<char>> &arr)
{
    for (int i = 0; i < arr.size(); ++i)
    {
        for (int j = 0; j < arr[i].size(); ++j)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}
int fact(int n)
{
    long fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact = fact * i;
    }
    return fact;
}

void add(string &a, string &b, int carry, int alen, int blen, string &s)
{
    if (alen < 0 && blen < 0)
    {
        if (carry != 0)
        {
            s.push_back(carry + '0');
        }
        return;
    }

    int x = (alen >= 0 ? a[alen] : '0') - '0';
    int y = (blen >= 0 ? b[blen] : '0') - '0';

    int z = x + y + carry;

    carry = z / 10;
    s.push_back(z % 10 + '0');
    add(a, b, carry, alen - 1, blen - 1, s);
}

string addStrings(string a, string b)
{
    int carry = 0;
    string s = "";

    add(a, b, carry, a.length() - 1, b.length() - 1, s);
    reverse(s.begin(), s.end());
    return s;
}

void checkpal(string &str,int index,int strlen){
    
    if(index>=strlen){
        cout<<str<<endl;
        return  ;
    }
    swap(str[index],str[strlen]);
    checkpal(str,index+1,strlen-1);
}


int main()
{
    string str;
    cout<<"Hehe boiii..  Give me a Pal: " ;
    getline(cin,str);

    string t=str ;
    checkpal(str,0,str.length()-1);
    if(t.compare(str)==0)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    
    // if(t.compare(checkpal(str,0,str.length()-1))==0){

    // }





    // cout<<strlen(sr);
    // cout<<sizeof(sr);
    // cout << sr[strlen(sr) - 1];
    // int alen = strlen(sr);

    // cout << addStrings(str, sr);

    // int x = stoi(sr[alen - 1]);

    // cout<<str.length();
    //   cout<<  fact(25);

    // vector<int> v;
    // v.push_back(1);
    // v.push_back(2);
    // v.push_back(3);
    // v.push_back(4);
    // v.push_back(5);
    // printv(v);
    return 0;
}
//     // remove the last element from the vector
// vector<int>a={11,22,33,44,55,66,77};
// sort(a.begin(),a.end());
// sort(v.begin(),v.end());
// vector<int>z;
//  merge(v.begin(),v.end(),a.begin(),a.end(),z.begin());

//     for (auto i : z)
//     {
//         cout << i;
//         cout << " ";
//     }

//       vector<int> arr1 = { 1, 4, 6, 3, 2 };

//     // initializing 2nd container
//     vector<int> arr2 = { 6, 2, 5, 7, 1 };

//     // declaring resultant container
//     vector<int> arr3(10);
//  string s="PAYPALISHIRING";
//  int n=s.length(),k=0;
//  int numrows=3 ;

//     vector<vector<char>>a;

//     for (int i = 0; i < numrows; i++)
//     {
//         for (int j = 0; j <v