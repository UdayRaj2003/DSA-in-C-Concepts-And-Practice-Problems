#include <bits/stdc++.h>
using namespace std;

void
mai ()
{
  int arr[] = { 4, 5, 6, 7 };

  int *p = arr; 
int*ptr=(arr+2);
  cout << ptr-p << endl;
  cout << ptr-arr;
// char b[]="xyz";
// char*c=&b[0];
// cout<<b<<endl;
// cout<<c;

}
void solve(int *arr)
{

    cout << &arr << endl;
    cout << arr << endl;
}
void soove(int *p){
    //yaha pr p ki ek copy bnegi isiliye 
    // cout << p  << endl; iski aur main fxn ke p ka address alag alag hoga ;
// {p=p+6;

    cout << p  << endl;
    cout << *p << endl;
}
int main()
{
    int a=7;
    int *p=&a;
    // int arr[4] = {1, 2, 3, 4};
    // cout << &arr << endl;
    // cout << arr << endl;

    cout << p  << endl;
    // cout << p +1 << endl;
    cout << *p << endl;
    cout << "hello" << endl;
    // solve(arr);

    soove(p);
    return 0;
}

