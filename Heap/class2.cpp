#include <bits/stdc++.h>
using namespace std;
class info
{
public:
    int maxval;
    bool isheap;
    
    info(int a, bool b)
    {
        this->isheap = b;
        this->maxval = a;
    };
};
class node
{
public:
    int val;
    node *left;
    node *right;
    node(int val)
    {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    };
};
node *createTree()
{
    {
    cout << "Enter Value: " << endl;
    int val;
    cin >> val;

    if (val == -1)
    {
        return NULL;
    }
    node *root = new node(val);
    cout << "Enter left child of " << val << ": " << endl;
    root->left = createTree();
    cout << "Enter right child of " << val << ": " << endl;

    root->right = createTree();
    return root;

}
}

int getkthsmallestno(int arr[], int size, int k)
{
    priority_queue<int> pq;
    int i;
    for (i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }
    while (i < size)
    {
        if (arr[i] < pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
        i++;
    }
    return pq.top();
}
int getkthgreatestno(int arr[], int size, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    int i;
    for (i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }
    while (i < size)
    {
        if (arr[i] > pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
        i++;
    }
    return pq.top();
}
info ismaxheap(node *root)
{
    if (root == NULL)
    {
        info temp(INT_MIN,true);
      
        return temp;
    }
    if (root->left == NULL && root->right == NULL)
    {
        info temp(root->val,true);
         
        return temp;
    }
    info left = ismaxheap(root->left);
    info right = ismaxheap(root->right);
    if (root->val > left.maxval && root->val > right.maxval && left.isheap && right.isheap)
    {
        info temp(root->val,true);
        
        return temp;
    }
    else
    {
        info temp(INT_MIN,false);
        return temp;
    }
}
bool iscbt(node* root,int count){
    if(root==NULL)
    {
        return true;
    }
    iscbt(root->left,count+1);
    iscbt(root->right,count+1);
}
int main()
{
    // for max heap we use this
    // priority_queue<int> pq;
    // pq.push(20);
    // pq.push(30);
    // pq.push(0);
    // pq.push(2);
    // cout << pq.top() << endl;
    // pq.pop();
    // cout << pq.top() << endl;
    // cout << pq.size() << endl;

    // // for min heap
    // priority_queue<int, vector<int>, greater<int>> pq1;
    // pq1.push(20);
    // pq1.push(30);
    // pq1.push(0);
    // pq1.push(2);

    // cout << pq1.top() << endl;
    // pq1.pop();
    // cout << pq1.top() << endl;
    // cout << pq1.size() << endl;
    // int arr[10] = {5, 3, 4, 2, 1, 6, 9, 8, 10, 7};
    // int k = 3;
    // cout << getkthsmallestno(arr, 10, k) << endl;
    // cout << getkthgreatestno(arr, 10, k) << endl;
    // node *root = createTree();
    // 10 20 40 -1 -1 50 70 110 -1 -1 111 -1 -1 80 -1 -1 30 -1 60 -1 90 112 -1 -1 113 -1 -1
    // info checkheap = ismaxheap(root);

    return 0;
}