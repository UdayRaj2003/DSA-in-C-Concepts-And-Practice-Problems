#include<bits/stdc++.h>
using namespace std;

void printv(vector<int> nums){
    for (auto i:nums)
    {
        cout<<i;
        cout<<" ";
    }
}

void Bubblesort(vector<int>&nums,int n){

        for (int i = 0; i < n-1; i++)
        {
            for (int j = 0; j < n-i-1; j++)
            {
                if(nums[j]>nums[j+1])
                swap(nums[j],nums[j+1]);

            }
            
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
    Bubblesort(nums,n);
    printv(nums); 
    
    return 0;
}