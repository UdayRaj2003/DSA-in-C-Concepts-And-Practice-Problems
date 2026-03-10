#include <bits/stdc++.h>
using namespace std;
// by two pointer approach
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        set<pair<int, int>> count;
        int index = 0, moveindex = 1;
        while (moveindex > index && moveindex < nums.size()) {
            if (nums[moveindex] - nums[index] == k) {
                cout << "indexo= " << index << "  moveindex = " << moveindex
                     << endl;
                index++;
                moveindex++;
                count.insert({nums[index - 1], nums[moveindex - 1]});
            } else if (nums[moveindex] - nums[index] < k) {
                moveindex++;
                cout << "indexl= " << index << "  moveindex = " << moveindex
                     << endl;
            } else if (nums[moveindex] - nums[index] > k) {
                cout << "indexg= " << index << "  moveindex = " << moveindex
                     << endl;
                index++;

            }
                            if(moveindex==index){
                    moveindex++;
                }
        }
        return count.size();
    }

    // by binary search approach

      
      
    
int main(){
    // your code goes here
  vector<int> nums={1,2,4,4,3,3,0,9,2,3};
    // cout<<searchMatrix(matrix,1);
    
  cout<<  findPairs(nums,2);
}    








