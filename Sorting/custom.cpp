#include <bits/stdc++.h>
using namespace std;

bool mycompfor1stIndex(vector<int> &a, vector<int> &b) {
  return a[1] < b[1]; // dsc order
  // return a[1] < b[1]; // asc order
}
int main()
{
    vector<int> x;
    vector<vector<int>> temp={{10,2}, {70,6}, {3,4}};
    int a;
    int b;
    // for (int i = 0; i < 3; i++)
    // {
    //     cout << "Enter  the  elements in  array in row "<<i<<" : "<<endl;
    //     cin >> a >> b;
    //     x.push_back(a);
    //     x.push_back(b);
    //     temp.push_back(x);
    //     x.clear();
    // }

    for (int i = 0; i < 3; i++)
    {
        cout << " the number of row elements in  array  "<<i<<" :   ";
        cout<<temp[i][0]<<","<<temp[i][1]<<endl;

    }

    sort(temp.begin( ), temp.end( ) ); 

    for (int i = 0; i < 3; i++)
    {
        x.push_back(temp[i][0]);
        cout << " Sorted first element of each row is:  " << x[i] << endl;

    }
    vector<int>y;
    sort(temp.begin( ), temp.end( ) ,mycompfor1stIndex); 
    for (int i = 0; i < 3; i++)
    {
        y.push_back(temp[i][1]);
        cout << " Sorted first element of each row is:  " << y[i] << endl;

    }
    temp.clear();
    for (int i = 0; i < 3; i++)
    {
        temp.push_back(x);
        temp.push_back(y);
        // cout << " Sorted first element of each row is:  " << y[i] << endl;

    }


    for (int i = 0; i < 3; i++)
    {
        cout << " the number of row elements in  array  "<<i<<" :   ";
// cout<<"blah blah blah: \n";

        cout<<temp[0][i]<<","<<temp[1][i]<<endl;

        }

    return 0;
}