#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> nums = {3,3,2, 2,5,5,7,9, 9};
    int s = 0, ans = -1, e = nums.size() - 1, mid = 0, target = 4,flag=0;

    // DONT USE  mid = (s + e) / 2; BCZ IF S AND E BOTH VALUE INT MAX THEN IT WILL OVERFLOW ;
    // USE---> bcz e-s will not lead to over flow// also can us == s/2+ e/2;
    mid=s+(e-s)/2;
    while (s <= e)
    {
        if (nums[mid] == nums[mid+1] || nums[mid]== nums[mid-1])
        {
         if ((mid%2==0 &&nums[mid]==nums[mid-1]) || (mid%2!=0&&nums[mid]==nums[mid+1]))
        {
            e = mid -1;
        }
        else if((mid%2==0 &&nums[mid]==nums[mid+1]) || (mid%2!=0&&nums[mid]==nums[mid-1]))
        {
            s= mid +1;
        }
        else
        {
            ans=nums[mid];
            break;
        }
        mid = (s + e) / 2;
        }
        
        else {
            ans=nums[mid];
            break;
        }
  cout<<"hello";
    }
    cout <<"\n the target is =  "<< ans<<endl;
    return 0;
}