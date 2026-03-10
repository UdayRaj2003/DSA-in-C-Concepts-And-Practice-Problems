#include <bits/stdc++.h>
using namespace std;

void printv(vector<string> nums)
{
    for (auto i : nums)
    {
        cout << "`" << i << "`";
        cout << "   ";
    }
}
bool checksort(vector<int> nums, int n, int index)
{
    if (index >= n)
    {
        return true;
    }
    if (nums[index] <= nums[index + 1])
    {
        return checksort(nums, n, index + 1);
    }
    else
    {
        return false;
    }
}

void findsubsequences(string str, vector<string> &nums, string output, int index)
{
    if (index >= str.length())
    {
        // cout<<"-->"<<output<<"."<<endl;
        nums.push_back(output);
        return;
    }
    // Recurse with the current character included in result
    findsubsequences(str, nums, output + str[index], index + 1);

    // Recurse with the current character excluded in result
    findsubsequences(str, nums, output, index + 1);
}

int findmax(vector<int> nums, int index, int n)
{

    if (index > n - 1)
        return 0;

    int option1 = nums[index] + findmax(nums, index + 2, n);

    int option2 = findmax(nums, index + 1, n);

    int finalAns = max(option1, option2);
    return finalAns;
}
// house robber
void rob(vector<int> nums)
{
    int maxans = findmax(nums, 0, nums.size() - 1);
    cout << maxans << endl;
}

// Driver code

int main()
{
    // vector<int>nums={5,7,8,6};

    // int n= nums.size();

    //   cout<<  checksort(nums,n,0);
    // vector<string> nums;
    // findsubsequences("abcd", nums, "", 0);
    // printv(nums);
    vector<int> nums = {3, 4, 5, 1};
    rob(nums);
    return 0;
}