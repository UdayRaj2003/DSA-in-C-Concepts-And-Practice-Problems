#include <bits/stdc++.h>
using namespace std;

int bs(vector<int> &nums, int s, int e, int target)
{
    int mid = 0, ans = -1;
    while (s <= e)
    {
        mid = (s)/2 + (e) / 2;
        if (nums[mid] == target)
        {
            ans = mid;
            break;
        }
        else if (nums[mid] < target)
        {
            s = mid + 1;
        }
        else if (nums[mid] > target)
        {
            e = mid - 1;
        }
    }
    return ans;
}

int Expoindex(vector<int> &nums, int n, int target)
{
    if (nums[0] == target)
    {
        return 0;
    }
    int i = 1;
    while (i <= n && nums[i] <= target)
    {
        i = i * 2;
    }
    return bs(nums, i / 2, min(i, n), target);
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = nums.size() - 1, target = 7;
    cout << "Exponent Index: " << Expoindex(nums, n, target) << endl;

    return 0;
}