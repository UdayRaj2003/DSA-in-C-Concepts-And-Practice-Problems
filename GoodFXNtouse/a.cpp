#include <bits/stdc++.h>
using namespace std;
void inverted_solid_triangle_patten(int n)
{
    for (int i = n; i > 0; i--)
    {

        for (int j = 0; j < n - i; j++)
        {
            cout << " ";
        }
        for (int j = i; j > 0; j--)
        {
            cout << "* ";
        }
        cout << endl;
    }
}
void hollow_triangle_patten(int n)
{
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n - i-1; j++)
        {
            cout << " ";
        }
        for (int j = i; j >= 0; j--)
        {
            if (j == i || j == 0 || i == n - 1)
                cout << "* ";
            else
                cout << "  ";
        }
        cout << endl;
    }
}

int main()
{
    int n = 0;
    // cout<<"enter N: "<<endl;
    // cin >> n;
    n = 3;
    hollow_triangle_patten(n);
    cout << endl;

    return 0;
}
