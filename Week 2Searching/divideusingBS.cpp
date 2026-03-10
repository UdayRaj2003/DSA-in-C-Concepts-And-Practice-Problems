#include <bits/stdc++.h>
using namespace std;
// absolute fxn always return positive value of any real no. -->  abs(a+b) = |a+b|..  --> abs(-5)= 5;
int main()
{
    int x=0,s=0,ans=0,y=0;
    cout<<"Enter  the number of elements you want to divide = "<<endl;
    cin>>x>>y;
    // x/y;
    int e=x;
int mid=s+(e-s)/2;

    while (s <= e)
    {
        if (mid*y == x)
        {
            ans = mid
        ;break;


        }
        else if (mid*y  < x)
        {
            s = mid + 1;
            ans=mid;
        }
        else if (mid*y> x)
        {
            e = mid - 1;
        }
        mid = (s + e) / 2;
  
  
    } 
    cout<<"nearest integer when  x divide by y = "<<ans;

    
     return 0;
}