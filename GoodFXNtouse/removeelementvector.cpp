
    #include<bits/stdc++.h>
using namespace std;






int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int i = 0;
        int k = 0;
        while (i < n) {   
            // cout << nums[i]  << " " << k << "\n";
            if (nums[i] == val) {
                swap(nums[i], nums[n-1]);
                n--;
            } else {
                i++;
                k++;
            }
        }
        return k;
    }



//  int removeElement(vector<int>& nums, int val) {

//         for (int i = 0; i < nums.size(); i++) {
//             if (nums[i] == val) {

//                 nums.erase(nums.begin() + i);
//                 i--;
//             }
//         }
//         return nums.size();
//     }







int removeElement(vector<int>& nums, int val) {
    int left = 0;
    for (int right = 0; right < nums.size(); right++) {
        if (nums[right] != val) {
            nums[left] = nums[right];
            left++;
        }
    }
    nums.resize(left);
    return left;
}
// essay on cow?
int main(){
    vector<int> nums = {3,2,2,5,1};
    int val = 2;
    int newSize = removeElement(nums, val);
    cout << "New size of the vector after removing the elements with value " << val << " is " << newSize << endl;
    for (int i = 0; i < newSize; i++) {
        cout << nums[i] << " ";
    }
    return 0;
}
