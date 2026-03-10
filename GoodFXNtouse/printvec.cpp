#include<bits/stdc++.h>
using namespace std;

void printv(vector<int> nums){
    for (auto i:nums)
    {
        cout<<i;
        cout<<" ";
    }
    cout<<endl;
}

// v.size() is for no. of rows and  also shows length of column
// 0 0 0 
// 0 0 0 
// 0 0 0 
// 0 0 0 


        // cout<<v.size()<<endl;
        // cout<<v[0].size()=3<<endl;
// v.size()=4   means there are four rows in matrix
// nums[i].size() = number of columns in ith row of the matrix
// nums[i][j] gives element at position jth column of ith row

void print2d(vector<vector<int>>vect){
      
    for (int i = 0; i < vect.size(); i++)  
    { 
        for (int j = 0; j < vect[i].size(); j++) 
        { 
            cout << vect[i][j] << " "; 
        }     
        cout << endl; 
    } 
    
}
    
int main(){
    vector<int>num={1,2,3,4,5,6};
    // printv(num); 

    vector<vector<int>>nums;
    // nums.push_back({1,2,3});
    // nums.push_back({4,5,6});
    // for (int j = 0; j < 4; j++)
    // { 
    for (int i = 0; i < 3; i++)
    {
       int a=num[i];
        nums[i].push_back(a);
         
    }
    // }
    print2d(nums);


    return 0;
}