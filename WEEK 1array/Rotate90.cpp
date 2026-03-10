#include <bits/stdc++.h>
using namespace std;

int main()
{
    int box[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};


    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << box[i][j] << " ";
        }
        cout << endl;
    }

    
    // Transpose of the matrix
    cout << "\nTranspose of the Matrix:\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = i + 1; j < 3; j++)
        {
            swap(box[i][j], box[j][i]);
        }
    }
    // exchange columns

    for (int k = 0; k < 3; k++)
    {
        swap(box[k][0], box[k][2]);
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << box[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}