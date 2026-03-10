#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int s = 0, ans = 0, e = nums.size() - 1, mid = 0, target = 4,flag=0;

    // DONT USE  mid = (s + e) / 2; BCZ IF S AND E BOTH VALUE INT MAX THEN IT WILL OVERFLOW ;
    // USE---> bcz e-s will not lead to over flow// also can us == s/2+ e/2;
    mid=s+(e-s)/2; 
    while (s <= e)
    {
        if (nums[mid] == target)
        {
            ans = mid;break;


        }
        else if (nums[mid] < target)
        {
            s = mid + 1;
        }
        else if (nums[mid] > target)
        {
            e = mid - 1;
        }
        mid = (s + e) / 2;
  
  
    }
    cout <<"\nans= "<< ans<<endl;
    return 0;
}
