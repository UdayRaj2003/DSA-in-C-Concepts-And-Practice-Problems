#include <bits/stdc++.h>
using namespace std;
class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
// delete n nodes after m node
void linkdelete(  ListNode* &head, int n, int m) {
        // Add code here
        ListNode* temp = head;
        ListNode* t = head;
        while(temp->next!=NULL){
            
            for(int i=1; temp!=NULL&&i<m;i++){
                temp=temp->next;
                
            }
              t = temp;
            for( int j=1 ;temp!=NULL&&j<=n;j++){
                temp=temp->next;
            }
            t->next= temp->next;
            temp=NULL;
            temp= t->next;
        }
        return ;
        
    }
// I want to insert a node right at the end of LINKED LIST
void insertAtTail(ListNode *&head, ListNode *&tail, int data)
{
    if (head == NULL)
    {
        ListNode *newNode = new ListNode(data);
        head = newNode;
        tail = newNode;
    }
    else
    {
        // step1: creatae a node
        ListNode *newNode = new ListNode(data);
        // step2: connect woth tail ndoe
        tail->next = newNode;
        // step3: update tail;
        tail = newNode;
    }
}
void print(ListNode *head)
{

    ListNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
}
// reverese the LL|
ListNode *reverseLL(ListNode *&head)
{
    ListNode *prev = NULL;
    ListNode *curr = head;
    ListNode *next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
// add1

void addOne(ListNode *&head)
{
    // reverese ll
    head = reverseLL(head);
    // add1
    int carry = 1;
    ListNode *temp = head;

    int digit, totalsum;
    while (temp->next != NULL)
    {
        totalsum = carry + temp->val;
        digit = totalsum % 10;
        carry = totalsum / 10;

        temp->val = digit;
        temp = temp->next;
        if (carry == 0)
        {
            break;
        }
    }
    // processlast node
    if (carry != 0)
    {

        totalsum = carry + temp->val;
        digit = totalsum % 10;
        carry = totalsum / 10;
        temp->val = digit;
        if (carry != 0)
        {
            ListNode *newNode = new ListNode(carry);
            temp->next = newNode;
        }
    }
    // reverse again
    head = reverseLL(head);
}

ListNode* addTwoNumbers(ListNode *l1, ListNode *l2) {
    int carry = 0;
    ListNode dummy(0);  // Dummy node to simplify handling the head
    ListNode *current = &dummy;
    l1= reverseLL(l1);
    l2= reverseLL(l2);

    while (l1 != nullptr || l2 != nullptr || carry != 0) {
        int sum = carry;
        
        if (l1 != nullptr) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != nullptr) {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;
        current->next = new ListNode(sum % 10);  // Create a new node for the digit
        current = current->next;
    }
 dummy.next=reverseLL(dummy.next);
    return dummy.next;  // Return the head of the new linked list
}
// what is purpose of dummy here
// ChatGPT said:
// ChatGPT
// The purpose of the dummy node in the linked list implementation is to simplify the process of building the new linked list that represents the sum of the two numbers. Here's why it's useful:

// 1. Simplifying Edge Cases:
// When you create a new linked list, you have to handle the head (or the first node) differently from subsequent nodes. Without a dummy node, you would need to check if the new list is empty and, if so, set the head to the first new node.
// By using a dummy node, you always have a non-null starting point (dummy). You can safely add nodes after this dummy node without worrying about whether the list is empty.
// 2. Consistent Pointer Management:
// The dummy node allows you to consistently use the current pointer to track where the next node should be added. You don't have to worry about initializing the head of the list separately; you just keep linking new nodes to current->next and moving current forward.
// 3. Returning the Result:
// After the loop completes, the resulting sum linked list starts at dummy->next. The dummy itself is just a placeholder and not part of the actual data; it simplifies list construction but is excluded when you return the final result.
// Example without a Dummy Node:
// Without a dummy node, you'd need extra logic to handle the first node creation, like this:
// cpp
// Copy code
// ListNode *head = nullptr;
// ListNode *current = nullptr;

// if (head == nullptr) {
//     head = new ListNode(digit);
//     current = head;
// } else {
//     current->next = new ListNode(digit);
//     current = current->next;
// }





int main()
{
    // ListNode *head = NULL;
    // ListNode *tail = NULL;
    // insertAtTail(head, tail, 1);
    // insertAtTail(head, tail, 9);
    // insertAtTail(head, tail, 9);
    // insertAtTail(head, tail, 9);
    // insertAtTail(head, tail, 4);
    // insertAtTail(head, tail, 5);
    // print(head);
    // cout << endl;
    // head = reverseLL(head);
    // print(head);
    // cout << endl;
    // addOne(head);
    // print(head);
    // cout << endl;
    // ListNode *l1 = NULL;
    // ListNode *l1tail = NULL;
    // insertAtTail(l1, l1tail, 4);
    // insertAtTail(l1, l1tail, 2);
    // print(l1);
    // cout << endl;
    // l2 list
    // ListNode *l2 = NULL;
    // ListNode *l2tail = NULL;
    // insertAtTail(l2, l2tail, 2);
    // insertAtTail(l2, l2tail, 9);

    // print(l2);
    // cout << endl;
    // ListNode *sum = addTwoNumbers(l1, l2);

    // print(sum);
    // cout << endl;
ListNode *head = nullptr;
ListNode *tail = nullptr;
for (int i = 10; i >1; i--)
{
    ListNode* newnode = new ListNode(i);
    newnode->next = head;
    head = newnode;
}
linkdelete(head,1,2);
print (head);
    // cout << endl;

    return 0;
}