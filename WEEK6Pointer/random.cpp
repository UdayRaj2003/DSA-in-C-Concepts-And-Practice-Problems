#include<bits/stdc++.h>
using namespace std;

int gcd(int a , int b ){
    if(a==0)return b;
    if(b==0)return a;
while(a>0&&b>0)
{  if(a>b){
        a=a-b;
            }

    if(b>a){
        b=b-a;
            }}  
            return a=0?b:a;

}


int main(){
   cout<< gcd(70,24);
    return 0;
}