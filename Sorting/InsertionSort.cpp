#include<bits/stdc++.h>
using namespace std;

void printv(vector<int> nums){
    for (auto i:nums)
    {
        cout<<i;
        cout<<" ";
    }
}

void InsertionSort(vector<int>&nums,int n){

        for (int i = 1; i < n; i++)
        {
            int key=nums[i];
            int j=i-1;
           while (j>=0&& nums[j]>=key)
           { 
           
                 nums[j+1]=nums[j];
                 j=j-1; 

            }
            nums[j+1]=key;
            
        }
        
}

int main(){
    vector<int>nums;
    cout<<"Enter total  no. of entries: "<<endl;
    int n=-1;
    cin>>n;
    int d=0;
    cout<<"Enter entries: "<<endl;
    for (int j = 0; j < n; j++)
    {
        cin>>d;
        nums.push_back(d);
    }
    InsertionSort(nums,n);
    printv(nums); 
    
    return 0;
}