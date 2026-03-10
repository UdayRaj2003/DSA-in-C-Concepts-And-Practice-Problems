#include <bits/stdc++.h>
using namespace std;

void printarray(int arr[], int n, int index)
{
    if (n > 0)
    {
        cout << arr[index] << " ";
    }
    printarray(arr, n - 1, index + 1);
}
// function to perform Linear Search{}

bool linearsearch(int arr[], int target, int n, int index)
{
    if (index >= n)
    {
        return false;
    }

    if (arr[index] == target)
    {
        return true;
    }

    bool ans = linearsearch(arr, target, n, index + 1);
    return ans;
}
int findmin(int *arr, int n, int &mina, int index)
{
    if (index >= n)
    {
        return -1;
    }

    mina = min(mina, arr[index]);

    findmin(arr, n, mina, index + 1);
    return mina;
}

int findmax(int *arr, int n, int &maxu, int index)
{
    if (index >= n)
    {
        return -1;
    }

    maxu = max(maxu, arr[index]);

    findmax(arr, n, maxu, index + 1);
    return maxu;
}
void checkeven(int *arr, vector<int> &nums, int index, int size)
{
    if (index >= size)
    {
        return;
    }

    if (arr[index] % 2 == 0)
    {
        nums.push_back(arr[index]);
    }
    checkeven(arr, nums, index + 1, size);
}
void printv(vector<int> nums)
{
    for (auto i : nums)
    {
        cout << i;
        cout << " ";
    }
}
vector<int> doubleno(vector<int> &nums, int size, int index)
{
    if (index >= size)
        return nums;

    nums[index] = 2 * nums[index];
    doubleno(nums, size, index + 1);
    return nums;
}

// binary search by recusion;
int bs(vector<int> nums, int target, int start, int end, int mid, int *ans)
{
    // Your code here
    if (nums[mid] == target)
    {
        return mid;
    }
    if  (start> end)
    {
        return -1;
    }
    if (nums[mid] > target)
    {
        end = mid - 1;
    }
    if (nums[mid] < target)
    {
        start = mid + 1;
    }
    mid = (start + end) / 2;
    *ans = bs(nums, target, start, end, mid, ans);
    return *ans;
}
void alloccurence(vector<int> nums, int n, int target, int index)
{
    if (index >= n)
    {
        return;
    }
    if (nums[index] == target)
    {
        cout << index << endl;
    }

    alloccurence(nums, n, target, index + 1);
}

vector<int> storeoccurence(vector<int> nums, int n, int target, int index)
{

    vector<int> store;
    if (index >= n)
    {
        return store;
    }
    if (nums[index] == target)
    {
        store.push_back(index);
    }
    // sort(store.begin(), store.end());

    vector<int> store1 = storeoccurence(nums, n, target, index + 1);
    sort(store1.begin(), store1.end());
    merge(store.begin(), store.end(), store1.begin(), store1.end(), back_inserter(store));

    //    yaha pr apan ko merge krna pdega pehli wli store vector aur jo recursion se aya hai store vector .
    return store;
}
void storedigits(vector<int> &nums, int n, int index)
{
    if (n == 0)
    {
        return;
    }
  int k = n % 10;
    n /= 10;
    storedigits(nums, n, index + 1);
    nums.push_back(k);
}

int main()
{
    int arr[5] = {6, 245, 38, 5, 4};

    // printarray(arr, 5, 0);
    // if (linearsearch(arr, 1, 5, 0) == 1)
    // {
    //     cout << "Element is present in the array. \n";
    // }
    // else
    // {
    //     cout << "Element is not present in the array.\n";
    // }
    // int mina= INT_MAX;
    // cout << findmin(arr, 5,mina, 0);

    // int maxu= INT_MIN;
    // cout << findmax(arr, 5,maxu, 0);
    // checkeven(arr, nums, 0, 5);
    // doubleno(nums, 7, 0);

    // binary search by recusion;

    vector<int> nums = {1, 2, 5, 8, 9, 11, 31, 45, 76, 98, 100};
    int start = 0,end=nums.size()-1,mid=0,target=45,ans=0;
       ans= bs(nums, target, start, end, mid,&ans);
       cout<<"target found at "<<ans<<"  index"<<endl;;
    // vector<int> nums = {1, 2, 5, 8, 9, 2, 4654, 5, 2, 6, 5, 2, 2};
    // alloccurence(nums, nums.size(), 2, 0);
    // to store all occurence of in a  vector
    //  vector<int>ans  = storeoccurence(nums, nums.size(), 2, 0);

    // printv(ans);
    // vector<int> nums;
    // storedigits(nums, 12345, 0);
    printv(nums);

    return 0;
}
