#include <bits/stdc++.h>
using namespace std;

  
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int column= matrix[0].size();
        
  
    int s = 0, ans = 0, e = (row*column) - 1, mid = 0;
    // for convert 2d into 1d use -->  i = index/col;j = index%col;

    mid=s+(e-s)/2;
    
    while (s <= e)
    {
        int rowindex= mid/column;
        int columnindex = mid% column;
        if (matrix[rowindex][columnindex] == target)
        {
                return true;
                
        }
        else if ( matrix[rowindex][columnindex]< target)
        {
            s = mid+1;
        }
        else if (matrix[rowindex][columnindex] > target)
        {
            e = mid - 1;
        }
        mid = (s + e) / 2;
  
  
    }
    
    return false;
}


int main(){
    // your code goes here
    vector<vector<int> > matrix={{1,3,5,7},{9,11,13,15}};
    cout<<searchMatrix(matrix,11);
    
}    
