
#include<bits/stdc++.h>
using namespace std;
    vector<int> searchRange(vector<int>& nums, int target) {
       vector<int>arr= {-1, -1};
        int s = 0, ans = -1, e = nums.size() - 1, mid = 0;
        mid = (s + e) / 2;
        //    to find first occur
        while (s <= e) {
            if (nums[mid] == target) {
                ans = mid;
                // left me jao
                e = mid - 1;
            }
            // right me jao?
            else if (nums[mid] < target) {
                s = mid + 1;
            }
            // left me jao?
            else if (nums[mid] > target) {
                e = mid - 1;
            }
            mid = (s + e) / 2;
        }
        arr[0] = ans;
        int val=nums[ans];
        int index=ans+1;
        int flag=0;
        while(index<nums.size() && nums[index]==val)
        {
            index++;
            flag=1;
        }
        if(flag==0)
        index=-1;
        arr[1]=index-1;

        return arr;
    }

int main(){
        vector<int> nums = {1, 2,2, 3, 3, 3, 7, 8, 9};
       for(auto  i:searchRange(nums,3))
       { cout<<i<<" ";
        cout<<endl;
       }
        // cout<<"The element is at "<<searchRange(nums, 3);
    return 0;
}