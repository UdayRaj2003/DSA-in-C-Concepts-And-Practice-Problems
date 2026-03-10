#include <bits/stdc++.h>
using namespace std;

void Selectionsort(int *arr, int n)
{
    for (int i = 0; i <= n - 1; i++)
    {
        int min = i;
        for (int j = i+1; j <= n - 1; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }

        swap(arr[i], arr[min]);
    }
}
    int main()
    {
int arr[]={1,7,4,9,3,2,6,3,5};
int n=9;
Selectionsort(arr,n);
cout<<"Sorted array is: ";
for(int i=0;i<n;i++)
   cout << arr[i] << " " ;
        return 0;
    }