#include <bits/stdc++.h>
using namespace std;
class minstack
{
public:
    int top;
    int min;
    vector<pair<int, int>> v;
    minstack()
    {
        top = -1;
        min = INT_MAX;
    }
    void push(int value)
    {

        top++;
        v[top].first = value;
        v[top].second = value;
        if (value < min)
        {
            min = value;
        }
        v[top].second = min;
    }

    void pop(){
        if(top==-1){
            cout<<"Stack is empty"<<endl;
            return;
        }else{
            top--;

        }
    }
    bool empty(){
        if(top==-1){
            cout<<"Stack is empty"<<endl;
            return 1;
        }
        return 0;
    }
    int gettop(){
        return v[top].first;
    }
};
int main()
{
minstack ms;
ms.push(5);
ms.push(5);
ms.push(5);
ms.push(5);
ms.pop();
while (!ms.empty()){
    cout<<ms.gettop()<<endl;
    ms.pop();


} 

    return 0;
}