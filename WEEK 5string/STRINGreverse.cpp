#include<bits/stdc++.h>
using namespace std;

int main(){
    char ch[20]="RACECAR";
// cout<< char(ch+32);
int i=0,j=strlen(ch)-1;

while(i<=j){
swap(ch[i],ch[j]);
i++;
j--;
}


for(int k=0;k<strlen(ch);k++)
{cout<<ch[k];
}     


     return 0;
}