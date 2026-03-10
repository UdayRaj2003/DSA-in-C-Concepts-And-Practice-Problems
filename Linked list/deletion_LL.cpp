#include <iostream>
using namespace std;

class Node {
        public:
        int data;
        Node* next;

        Node() {
                this->data = 0;
                this->next = NULL;
        }
        Node(int data) {
                this->data = data;
                this->next = NULL;
        }


};

//I want to insert a node right at the head of Linked List
void deleteAtHead(Node* &head, Node* &tail) {
        //check for Empty LL
        if(head == NULL) {
              cout<<"Empty list"<<endl;
        }
        else {  
            Node*temp =head;

                head = temp->next;
                temp->next = NULL;
                delete temp;
        }
        


}
//I want to insert a node right at the end of LINKED LIST
void deleteAtTail(Node* &head, Node* &tail) {
        //check for Empty LL
        if(head == NULL) {
              cout<<"Empty list"<<endl;
        }
        else {  
            Node*temp =head;
            while (temp->next!=nullptr)
            {
                temp=temp->next;
            }
            

                head = temp->next;
                temp->next = NULL;
                delete temp;
        }
}
void print(Node* head) {

        Node* temp = head;
        while(temp != NULL)
         {
                cout << temp->data << " ";
                temp = temp->next;
        }
}

int findLength(Node* &head ) {
        int len = 0;
        Node* temp = head;
        while(temp != NULL) {
                temp = temp->next;
                len++;
        }
        return len;
}

void deleteAtPosition( int position, Node* &head, Node* &tail) {
        int len = findLength(head);
        
        if(position == 1) {
                deleteAtHead(head, tail);
                return;
        }
        else if(position > len) {
                deleteAtTail(head, tail);
                return;
        }
        else { 
            
            Node* prev = NULL;
            Node* curr = head;
            while(position != 1) {
                position--;
                prev = curr;
                curr = curr->next;
            }
             
            
        }
        
}


int main(){
    
    return 0;
}