#include<bits/stdc++.h>
using namespace std;

string str ="   ";
    void permutationS(string &s ,int index){
        
        if(index>=s.length()){
            cout<<" "<<s;
            str=str+s+"     ";
            return;
        }
        int i;
        for ( i = index; i < s.length(); i++)
        { 
            swap(s[index],s[i]);

        permutationS(s,index+1);
        swap(s[index],s[i]);
        }
        // undo the operation made by swapping

    }

int main(){
    
    // to find all permutation of strig 
    string s="abcd";
    permutationS( s ,0);
    // cout<<str;
    // cout<<s;
    return 0;
}