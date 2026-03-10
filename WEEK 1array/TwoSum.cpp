#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[6] = {1, 4, 5, 4, 6, 2}, x = 0, i = 0, j = 5, count = 0;
    cout << "Enter Sum  : ";
    cin >> x;
    while (i <= j)
    {

        if (i == j)
        {
            j--;
            i = 0;

            // cout<<"            "  <<j<<"   =j";}
        }

        else if (arr[i] + arr[j] == x)
        {
            count++;
            // cout <<"\n  val  i = " <<i << ",    j=  " << j << endl;
            i++;
        }
        else
        {
            i++;
        }
    }
    cout << "Times the sum of two is present:  " << count;
    return 0;
}
