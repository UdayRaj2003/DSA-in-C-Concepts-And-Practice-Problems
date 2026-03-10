#include <bits/stdc++.h>
using namespace std;

void printv(vector<int> nums)
{
    for (auto i : nums)
    {
        cout << i;
        cout << " ";
    }
} 


void normalquick(vector<int> &num, int index)
{
    if (index < 0 || index >= num.size())
    {
        return;
    }
    int pivot = index;
    for (int i = index; i < num.size(); i++)
    {

        if (num[index] > num[i])
        {
            swap(num[index], num[i]);
        }
    } 
    cout << endl;
    pivot++;
    normalquick(num, pivot);
}

void diffquicksort(vector<int>&num,int start,int pivot)
{
if(start>pivot)
return ;
    int j=start;
int i=j-1;
    while (j< pivot)
    { 
if(num[j] < num[pivot]){
  i++;
    swap(num[i],num[j]);
}
    j++;
}
    i++;
swap(num[i],num[pivot]);
diffquicksort(num,start,i-1);


diffquicksort(num,i +  1, pivot );
// printv(num);
    }
    



int main()
{
    int n, m;
    vector<int> num = {2,0,1,5,3,7,4,6,4,0};
    m = num.size(); // size of num
    // vector<int> nums2 = {4, 6, 3};
    // n = nums2.size(); // size of nums2
    // merge(nums1, m, nums2, n);

    // normalquick(num, 0);
    diffquicksort(num, 0, m-1);
    printv(num);

    return 0;
}