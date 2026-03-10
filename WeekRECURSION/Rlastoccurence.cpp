#include <bits/stdc++.h>
using namespace std;
// lastoccur through R to L
void lastandFirstoccur(vector<int> nums, int index, int size, int target, int &ans)
{
    if (index >= size)
    {
        return; //-1 indicates that the element is not present in array
    }
    // firstoccrur
    if (nums[index] == target)
    {
        ans = index;
        // store the answer here;
    }
    // lastoccurrence
    lastandFirstoccur(nums, index + 1, size, target, ans);
}

int lastoccur(vector<int> nums, int size, int target)
{

    if (size < 0 || nums[size] == target)
    {
        return size;
    }
    if (nums[size] == target)
    {
        int ans = size;
        return ans;
        // store the answer here;
    }
    int ans = lastoccur(nums, size - 1, target);
    return ans;
}
void reversestr(string str,int index,int strlen){
    if(index>=strlen){
        cout<<str<<endl;
        return  ;
    }
    swap(str[index],str[strlen]);
    reversestr(str,index+1,strlen-1);
}



int main()
{
    // vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 3, 8, 3, 9};
    // int n = nums.size(), ans = -1;
    // lastandFirstoccur(nums, 0, n, 3, ans);
    // vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 3, 8, 3, 9};
    // int n = nums.size(), ans = -1;
    // int z = lastoccur(nums, n - 1, 3);
    // cout << "The number which occurs  last is at position " << z << endl;
    // cout << "The number which occurs  last is at position " << ans << endl;
    string str;
    getline(cin, str);
    reversestr(str,0,str.length()-1);
    // cout << str << endl;

    return 0;
}