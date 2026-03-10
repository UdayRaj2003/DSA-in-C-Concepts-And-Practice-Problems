#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> nums = {1, 2, 3, 5, 6,7,8,0};
    int s = 0, ans = -1, e = nums.size() - 1, mid = 0, target = 4, flag = 0;

    mid = (s + e) / 2;
    flag = mid;
    while (s <= e)
    {
        mid = (s + e) / 2;
        if (nums[mid] < nums[mid + 1])
        {
            s = mid + 1;
        }
        else if (nums[mid] < nums[mid - 1])
        {
            e = mid - 1;
            ans = mid;
        }
        else
        {
            ans = mid;
            break;
        }
    }
        cout<< s << e << mid<<endl;
        if(ans==nums.size()){
            nums[ans]=-1;
        }

    cout << "\n Peak no. is = " << nums[ans] << endl;
    ;
}