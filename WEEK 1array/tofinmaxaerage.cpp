#include<bits/stdc++.h>
using namespace std;

// bruute frce
    // double findMaxAverage(vector<int>& nums, int k) {
    //     double max = INT_MIN;
    //     double  i = 0;
    //     double sum = 0, j = k;
    //     while (i < j && j <= nums.size()) {
    //         sum = sum + nums[i];
    //         // cout << "sum                              : " << sum << endl;

    //         if (i == j - 1) {
    //             // cout << " ie= " << i;
    //             // cout << ", je=" << j << endl;
    //             i = 0;
    //             j++;
    //             i = j - k - 1;
    //             if (sum >= max) {
    //                 max = sum;
    //                 // cout << "sum ;" << sum << endl;
    //             }
    //                 sum = 0;
    //         }
    //         // cout << " i= " << i;
    //         // cout << ", j=" << j << endl;
    //         i++;
    //     }
    //     double ans = max / k;
    //     return ans;
    // }
double findMaxAverage(vector<int>& nums, int k) {
    double maxAvg = INT_MIN;
    double sum = 0;

    for (int i = 0; i < k; i++) {
        sum += nums[i];
    }

    double ans = sum;

    for (int j = k; j < nums.size(); j++) {
        sum = sum - nums[j - k];
        sum = sum + nums[j];
        ans = max(sum, ans);
    }

    return ans / k;
}


int main(){
    int k=4; vector<int>nums= {1,12,-5,-6,50,3};
    cout<<findMaxAverage(nums,k);
    return 0;
}