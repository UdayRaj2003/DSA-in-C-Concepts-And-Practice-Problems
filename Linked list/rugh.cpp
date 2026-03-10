#include<bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
    node()
    {
        this->next = nullptr;
    }
};

int main(){
    node* head=new node(5);

    node head2;
    head2.data=5;
    head2.next =nullptr;
    cout<<head2.data<<head2.next<<endl;
    cout<<head->data<<head->next<<endl;
    return 0;
}