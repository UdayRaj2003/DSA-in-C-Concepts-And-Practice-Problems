#include <bits/stdc++.h>
using namespace std;

int solve(int n)
{
    if (n == 0)
        return 1;
    // if(n==1)return 1;
    int ans = 0;
    ans = 2 * solve(n - 1);
    return ans;
}
// sum till n;

int sum(int n)
{
    if (n == 0)
        return 0;
    int ans = 0;
    ans = n + sum(n - 1);
    return ans;
}


int climbingStairs(int n)
{
    if (n == 0)
        return 1;
    if(n==1)return 1;
    int ans = 1;
    ans =climbingStairs(n-1)+climbingStairs(n-2);

    return ans;
}
int main()
{
    int n = 30;
    // cout << solve(n)<<endl;
cout<<sum(3)<<endl;
// cout<<climbingStairs(45);
    return 0;
}