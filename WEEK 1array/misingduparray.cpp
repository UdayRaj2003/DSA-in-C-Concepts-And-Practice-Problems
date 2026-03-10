#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {1, 3, 4, 3, 5, 6, 7, 8};
    int ans = 0, i = 0, j = arr.size();
    while (i <= j)
    {
        if (i == j)
        {
            j--;
            i = 0;
            // cout<<"            "  <<j<<"   =j";}
        }
        else if (arr[i] == arr[j])
        {
            ans = arr[i];
            // cout <<"\n  val  i = " <<i << ",    j=  " << j << endl;
            i++;
        }
        else
        {
            i++;
        }
    }
    for (int k = 0; k < arr.size(); k++)
    {
        ans ^= arr[k];
    }
    for (int i = 1; i <= arr.size(); i++)
    {
        ans ^= i;
    }
    cout << "Missing no. is: " << ans;

    return 0;
}