#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> nums = {2, 1, 4, 3, 5, 7, 6, 8, 9};
    int s = 0, ans = -1, e = nums.size() - 1, mid = 0, target = 4,flag=0;

    // DONT USE  mid = (s + e) / 2; BCZ IF S AND E BOTH VALUE INT MAX THEN IT WILL OVERFLOW ;
    // USE---> bcz e-s will not lead to over flow// also can us == s/2+ e/2;
    mid=s+(e-s)/2;
    while (s <= e)
    {
        if (nums[mid] == target)
        {
            ans = mid;break;
        }
        
        if (nums[mid-1] == target)
        {
            ans = mid-1;break;
        }
        
        if (nums[mid+1] == target)
        {
            ans = mid+1;break;
        }
        else if (nums[mid] < target)
        {
            s = mid + 2;
        }
        else if (nums[mid] > target)
        {
            e = mid - 2;
        }
        mid = (s + e) / 2;
  
  
    }
    cout <<"\n the index of target is =  "<< ans<<endl;
    return 0;
}
