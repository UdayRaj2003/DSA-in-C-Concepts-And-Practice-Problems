#include <bits/stdc++.h>
using namespace std;
// by brute force --> Time complexity o[n^2];

int pivotIndex(vector<int> &nums)
{
    int lsum = 0, rsum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        int lsum = 0, rsum = 0;
        for (int j = 0; j < i; j++)
        {
            lsum += nums[j];
        }
        for (int k = i + 1; k < nums.size(); k++)
        {
            rsum += nums[k];
        }
        if (lsum == rsum)
        {
            return i;
        }
    }
    return -1;
}
// Now by TC--> O[N];

int pivotIndex(vector<int> &nums)
{
    vector<int> lsum(nums.size(), 0);
    vector<int> rsum(nums.size(), 0);
    for (int i = 1; i < nums.size(); i++)
    {
        lsum[i] = lsum[i - 1] + nums[i - 1];
    }
    for (int j = nums.size() - 2; j >= 0; j--)
    {
        rsum[j] = rsum[j + 1] + nums[j + 1];
    }
    for (int k = 0; k < nums.size(); k++)
    {
        if (lsum[k] == rsum[k])
            return k;
    }
    return -1;
}
