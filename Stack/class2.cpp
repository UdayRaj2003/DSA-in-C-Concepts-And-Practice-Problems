#include<bits/stdc++.h>
using namespace std;

class Stack{
    public:
    int * arr;
    int top1;
    int top2;
    int size;

    Stack(int size){
        this->size = size;
        arr= new int [size];
        top1 = -1;
        top2 = size;
    }

    void push1(int value){
        if(top2-top1==1){
            cout<<"Stack1 OverFlow"<<endl;
            return ;
        }else{
            top1++;
            arr[top1] = value;
            
        }
    }
    void push2(int value){
        if(top2-top1==1){
            cout<<"Stack2 OverFlow"<<endl;
            return ;
        }else{
            top2--;
            arr[top2] = value;

        }
    }
    void pop1(){
        if(top1==-1){
            cout<<"Stack1 UnderFlow"<<endl;
            return ;
        }else{
            arr[top1] = 0;
            top1--;

        }
    }
    void pop2(){
        if(top2==size){
            cout<<"Stack2 UnderFlow"<<endl;
            return ;
        }else{
            arr[top2] = 0;
            top2++;

        }
    }

    void print (){
        for (int i = 0; i < size; i++)
        {
            cout<<arr[i]<<"  ";
        }
        cout<<endl;
        
    }
};



int main(){
    Stack st(5);
    st.push1(1);
    st.push1(1);
    st.push1(1);
    st.push1(1);
    // st.push1(1);
    st.push2(100);
    st.print();
    st.push2(100);
    st.pop1();
    st.pop2();
    st.pop2();
    st.print();
    st.push2(100);
    st.print();


    
    return 0;
}