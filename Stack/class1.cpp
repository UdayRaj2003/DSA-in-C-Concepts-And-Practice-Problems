#include<bits/stdc++.h>
using namespace std;
void print(stack<int>st){
  while (!st.empty())
     {
        cout<<st.top()<<"   ";
        st.pop();
     }
     cout<<endl;
}
// isnsert element at bottom of stack
void insertbottom(stack<int>&st,int value){
    if(st.empty()){
        st.push(value);
        return;
    }
    int remp = st.top();
    st.pop();
    insertbottom(st,value);
    st.push(remp);
}
// reverse using recursion
void  reversestack(stack<int>&st){
    if(st.empty()){
        return;
    }
    int temp = st.top();
    st.pop();
    reversestack(st);
    insertbottom(st,temp); 




}
// funtion to insert in sorted stack
void insertInSortedStack(stack<int>&st,int value){
    // if(st.empty()||value<st.top()){
    // above for reverse order
    if(st.empty()||value>st.top()){
        st.push(value);
        return;}
        int temp = st.top();
        st.pop();
        insertInSortedStack(st,value);
        st.push(temp);


}
// function to sort the stack 
void SortStack(stack<int>&st){
    if(st.empty()){
        return;
        }
        int temp = st.top();
        st.pop();
        SortStack(st);
        insertInSortedStack(st,temp);

}


    // delete element from stack at any position using recursion
void deleteAtPos(stack<int>&st,int pos){
    if(st.empty()||pos==1){
        st.pop();
        return ;
    }
    if(pos>st.size()||pos<=0)
    {
        return ;
    }
    pos--;
    int temp = st.top();
    st.pop();
    deleteAtPos(st,pos);
    st.push(temp);

}

    // insert element from stack at any position using recursion
void InsertAtPos(stack<int>&st,int pos,int value){
    if(st.empty()||pos==1){
        st.push(value);
        return ;
    }
    if(pos>st.size()||pos<=0)
    {
        return ;
    }
    pos--;
    int temp = st.top();
    st.pop();
    InsertAtPos(st,pos,value);
    st.push(temp);

}

int main(){
    // string s="hello jee";
    // cout<<s<<endl;
    // stack<char>st;
    // for (int i = 0; i < 9; i++)
    // {
    //     st.push(s[i]); 
    // }
    // print(st);
    stack<int>st;
    st.push(5);
    st.push(1);
    st.push(20);
    st.push(3);
    st.push(-4);
    st.push(-5);
    st.push(70);
    cout<<"Stack is : ";
//    print(st);
// insertbottom(st,7);
//    print(st);
// reversestack(st);
//     cout<<"Reverse Stack is : ";
// insertInSortedStack(st,0);
// insertInSortedStack(st,6);
//     cout<<"Inserted Sorted  Stack is : ";
// print(st);
SortStack(st);
// cout<<"Sorted Satck is : ";
   print(st);
// deleteAtPos(st,6);
// deleteAtPos(st,0);
// deleteAtPos(st,8);
// InsertAtPos(st,3,100);
//    print(st);
    return 0;
}