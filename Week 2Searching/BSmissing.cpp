
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> nums = {0,1,3,4,5,6,7};
    int s = 0, ans = -1, e = nums.size() - 1, mid = 0;

        mid = (s + e) / 2;
        
    while (s <=e)
    {
    mid=(s+e)/2;
         cout<<s<<e<<endl;
     if (nums[mid] == mid)
        {
            s = mid + 1;
        }
        else if (nums[mid] == mid+1)
        {
            e = mid - 1;
            ans=mid;
        }

    }if(nums[nums.size()-1]!=  nums.size())
    ans=nums.size();
   
    cout <<"\n Missing no. is = "<< ans<<endl;;

}