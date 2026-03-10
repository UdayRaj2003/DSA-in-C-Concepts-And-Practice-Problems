#include <bits/stdc++.h>
using namespace std;

void printv(vector<int> nums){
    for (auto i:nums)
    {
        cout<<i;
        cout<<" ";
    }
}

void mergearr(vector<int>&nums, int s, int mid, int e)
{
    int leftlength = mid - s + 1;
    int rightlength = e - mid;
    int *leftarr = new int[leftlength];
    int *rightarr = new int[rightlength];
    for (int i = 0; i < leftlength; i++)
    {
        leftarr[i] = nums[s + i];
    }
    for (int j = 0; j < rightlength; j++)
    {
        rightarr[j] = nums[mid + 1 + j];
    }

	//actual merge logic here
	//left array is already sorted
	//right array is already sorted
	int leftIndex = 0;
	int rightIndex = 0;
	//yahi pr galti karte h log
	int mainArrayIndex = s;

	while(leftIndex < leftlength &&  rightIndex < rightlength) {
		
		if(leftarr[leftIndex] < rightarr[rightIndex] ) {
			nums[mainArrayIndex] =  leftarr[leftIndex];
			mainArrayIndex++;
			leftIndex++;
		}
		else {
			nums[mainArrayIndex] =  rightarr[rightIndex];
			mainArrayIndex++;
			rightIndex++;
		}
	}


	//2 more cases

	//1 case -> left array exhaust but right array me element abhi bhi bache hai
	while(rightIndex < rightlength) {
		nums[mainArrayIndex] =  rightarr[rightIndex];
		mainArrayIndex++;
		rightIndex++;
	}
	

	//2nd case -> rigght array exhaust but left array me element abhi bhi bache hai
	while(leftIndex <leftlength) {
		nums[mainArrayIndex] =  leftarr[leftIndex];
		mainArrayIndex++;
		leftIndex++;
	}
	//1 more step pending
    delete[] leftarr;
    delete[] rightarr;
}


void mergesort(vector<int>&nums, int s, int e)
{
    // basecase
    if (s >= e)
    {
        return ;
    }
    int mid = (s + e) / 2;
    // for left part
    mergesort(nums, s, mid);

    // for right part of array

    mergesort(nums, mid + 1, e);

    // for merging the arrays
    
    mergearr(nums, s, mid, e);
}

int main()
{
    vector<int>nums={2,5,4,3,1,8,7,0};
    int n= nums.size()-1;
    cout<<"Given array is \n";
    printv(nums);
    cout << "Sorted array \n";
mergesort(nums, 0, n );
    printv(nums);
    return 0;
}