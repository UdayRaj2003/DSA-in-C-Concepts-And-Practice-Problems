#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x=0,s=0,ans=0;
    cout<<"Enter  the number of elements you want to find nearest root"<<endl;
    cin>>x;
    int e=x;
int mid=s+(e-s)/2;

    while (s <= e)
    {
        if (mid*mid == x)
        {
            ans = mid
        ;break;


        }
        else if (mid*mid  < x)
        {
            s = mid + 1;
            ans=mid;
        }
        else if (mid*mid> x)
        {
            e = mid - 1;
        }
        mid = (s + e) / 2;
  
  
    } 
    cout<<"nearest integer to root of x = "<<ans;

    
     return 0;
}