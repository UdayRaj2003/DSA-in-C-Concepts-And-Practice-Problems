
    #include <bits/stdc++.h>
using namespace std;


    int searchpivotindex(vector<int>& nums) {
            // vector<int> nums={8,9,2,3,4};

        int s = 0, ans = -1, e = nums.size() - 1, mid = 0;
        mid = (s + e) / 2;
        while (s <= e) {
            mid = (s + e) / 2;

            if ( (mid+1) < nums.size() && nums[mid + 1] < nums[mid]) {
                ans = mid;
                break;
            }
            if (nums[mid] < nums[s]) {
                e = mid - 1;
            } else if (nums[mid] >= nums[s]) {
                s = mid + 1;
                ans=mid;
            }
             else {
                ans = mid ;
                break;
            }
        }
        return ans;
    }
    int search(vector<int>& nums, int target) {
        int pivot = searchpivotindex(nums);
        int s = 0, ans = -1, e = nums.size() - 1, mid = 0;
        mid = (s + e) / 2;
        if (target <= nums[pivot] && nums[0] <= target) {
            s = 0, e = pivot;
        } else if (pivot+1<nums.size() && target >= nums[pivot + 1] && nums[nums.size() - 1] >= target) {
            s = pivot + 1, e = nums.size() - 1;
        }
        while (s <= e) {
            mid = (s + e) / 2;
            if (nums[mid] == target) {
                ans = mid;
                break;
            } else if (nums[mid] < target) {
                s = mid + 1;
            } else if (nums[mid] > target) {
                e = mid - 1;
            }
        }
        return ans;
    }

    // Solution 2nd more optimised soln;
    int searcha(vector<int>& nums, int target) {
        int n = nums.size();
        
        int low = 0, high = n-1;
        
        while(low <= high)
        {
            int mid = (low+high)/2;
            
            if(nums[mid] == target) return mid;
            
            if(nums[low] <= nums[mid])
            {
                if(nums[low] <= target && target <= nums[mid]) high = mid-1;
                else low = mid+1;
            }
            
            else
            {
                if(nums[mid] <= target && target <= nums[high]) low = mid+1;
                else high = mid-1;
            }
        }
        
        return -1;
    }

        int main(){
            vector<int> nums={8,9,2,3,4};
            int target=9;
           int x= search(nums,target);
            cout<<x;
            int y= searcha(nums,target);
            cout<<y;

        }