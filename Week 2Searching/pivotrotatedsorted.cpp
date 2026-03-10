#include <bits/stdc++.h>
using namespace std;
int main()
{
                // vector<int> nums={4,5,6,7,0,1,2};

    vector<int> nums = {70, 80, 9, 20, 30, 50, 60};
    // vector<int> nums = {70};
    int s = 0, ans = -1, e = nums.size() - 1, mid = 0;

    mid = (s + e) / 2;
    while (s <= e)
    {
        mid = (s + e) / 2;
        if ( nums[mid +1] < nums[mid])
        {
            ans = mid;
            break;
        }
        if (nums[mid] < nums[s])
        {
            e = mid - 1;
        }
       else if (nums[mid] > nums[s])
        {
            s = mid + 1;
        }
        else
        {
            ans = mid;break;}
    }

    cout << s << e << mid << endl;

    cout << "\n Pivot  no. is = " << nums[ans] << endl;
    ;
}