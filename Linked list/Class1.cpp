#include <bits/stdc++.h>
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
void print_length_LL(node *head)
{
    int length = 0;
    node *temp = head;
    // while(temp->next!=nullptr){
    // upar wle me sirf 3 value hi print hogi

    while (temp != nullptr)
    {
        cout << temp->data << " ";
        length++;
        temp = temp->next;
    }
    cout << endl;
    cout << "Length of ll is : " << length << endl;
}

// void insert_at_start(int data,node * head){
// upar wle me apan ne pass by value diya tha head me isiliye main list me koi change ni aya
// node* insert_at_start(int data, node *&head)
void insert_at_start(int data, node *&head)
{
    if (head == nullptr)
    {
        node *new_node = new node(data);
        head = new_node;
    }
    else
    {

        node *new_node = new node(data);
        new_node->next = head;
        head = new_node;
    }
}

void get_tail(node *&head, node *&tail)
{
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    tail = temp;
}

int findLength(node *&head)
{
    int len = 0;
    node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }
    return len;
}
void get_position(node *&head, node *&position_key, int position)
{
    node *temp = head;
    while (position > 0)
    {
        temp = temp->next;
        position--;
    }
    position_key = temp;
}


void insert_at_tail(int data, node *&head, node *&tail)
{
    if (head == nullptr)
    {
        node *new_node = new node(data);
        head = new_node;
    }
    else
    {

        node *new_node = new node(data);
        tail->next = new_node;
    }
}
void insertAtPosition(int data, int position, node *&head, node *&tail)
{
    int len = findLength(head);

    if (position == 1)
    {
        insert_at_start( data,head);
        return;
    }
    else if (position > len)
    {        insert_at_tail( data,tail,head); 
        return;
    }
    else
    {
        node *newNode = new node(data);

        node *prev = NULL;
        node *curr = head;
        while (position != 1)
        {
            position--;
            prev = curr;
            curr = curr->next;
        }

        // step3:
        newNode->next = curr;

        // step4:
        prev->next = newNode;
    }
}

int main()
{
    node *first = new node(1);
    node *second = new node(2);
    node *third = new node(3);
    node *fourth = new node(4);
    first->next = second;
    second->next = third;
    third->next = fourth;
    node *head = first;
    // cout << (third) << endl;
    // cout << (third->next) << endl;
    // cout << (third->data) << endl;
    cout << "Linked List is: ";
    print_length_LL(head);

    // insert_at_start(99, head);
    // print_length_LL(head);
    //  value considered to be zero below
    // node* head2= new node(NULL);
    //  value considered to be garbage value
    // node* head2= new node();
    // node *head2 = nullptr;
    // insert_at_start(2, head2);
    // print_length_LL(head2);
    // node* tail=fourth;
    node *tail = nullptr;
    get_tail(head, tail);

    insert_at_tail(55, head, tail);
    print_length_LL(head);
    node *position_key = nullptr;
    // get_position(head, position_key,2);
    insertAtPosition(77, 2, head, tail);
    print_length_LL(head);

    return 0;
}