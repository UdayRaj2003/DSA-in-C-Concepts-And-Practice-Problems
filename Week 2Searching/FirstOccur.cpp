#include <bits/stdc++.h>
using namespace std;
int main()

{
    vector<int> nums = {1, 2,2, 3, 3, 3, 7, 8, 9};
    int s = 0, ans = -1, e = nums.size() - 1, mid = 0, target = 2;
    mid = (s + e) / 2;
    cout << "hello";
    while (s <= e)
    {
        if (nums[mid] == target)
        {
            ans=mid;
            // left me jao 
            e = mid - 1;}
        // right me jao?
        else if (nums[mid] < target)
        {
            s = mid + 1;
        }
// left me jao?
        else if (nums[mid] > target)
        {
            e = mid - 1;
        }
        mid = (s + e) / 2;
  
    }
    cout <<"\nans= "<< ans<<endl;;
    return 0;
}
