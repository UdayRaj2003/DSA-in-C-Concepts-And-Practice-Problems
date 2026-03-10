
#include <bits/stdc++.h>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> v;
    int colm = matrix[0].size() - 1, rows = matrix.size() - 1;
    int rowindex = 0, colmindex = 0, i = 0, count = 0;
    int total = (colm + 1) * (rows + 1);

    while (count < total)
    {
        // starting row
        for (i = colmindex; i <= colm && count < total; i++)
        {
            v.push_back(matrix[rowindex][i]);
            count++;
        }
        rowindex++;

        // ending column
        for (int j = rowindex; j <= rows && count < total; j++)
        {
            v.push_back(matrix[j][colm]);
            count++;
        }
        colm--;

        // ending row
        for (int j = colm; j >= colmindex && count < total; j--)
        {
            v.push_back(matrix[rows][j]);
            count++;
        }
        rows--;

        // starting colm
        for (int j = rows; j >= rowindex && count < total; j--)
        {
            v.push_back(matrix[j][colmindex]);
            count++;
        }
        colmindex++;
    }

    return v;
}

int main()
{
    vector<vector<int>> matrix = {{1, 3, 4}, {5, 7, 8}, {9, 11, 12}, {13, 15, 16}, {18, 19, 20}, {99, 66, 33}};
    vector<int> v;
    v = spiralOrder(matrix);
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}
