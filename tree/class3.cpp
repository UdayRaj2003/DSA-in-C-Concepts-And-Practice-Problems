#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

TreeNode *createTree()
{
    cout << "Enter Value: " << endl;
    int val;
    cin >> val;

    if (val == -1)
    {
        return NULL;
    }
    TreeNode *root = new TreeNode(val);
    cout << "Enter left child of " << val << ": " << endl;
    root->left = createTree();
    cout << "Enter right child of " << val << ": " << endl;

    root->right = createTree();
    return root;
}
void leftview(TreeNode *root, int level, vector<int> &left)
{
    if (root == NULL)
    {
        return;
    }
    if (level == left.size())
    {
        cout << root->val << " ";
        left.push_back(root->val);
    }
    leftview(root->left, level + 1, left);
    leftview(root->right, level + 1, left);
}
void levelorder(TreeNode *root)
{
    queue<TreeNode *> q;
    q.push(root);
    q.push(NULL);

    // asli traversal start krete h

    while (!q.empty())
    {
        TreeNode *front = q.front();
        q.pop();

        if (front == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            // valid node wala case
            cout << front->val << " ";

            if (front->left != NULL)
            {
                q.push(front->left);
            }
            if (front->right != NULL)
            {
                q.push(front->right);
            }
        }
    }
}
void createmap(TreeNode *root, int &level, map<int, int> &m)
{
    if (m[root->val] == NULL)
    {
        m[root->val] = level;
    }
    else
    {
        return;
    }
}
vector<int> topview(TreeNode *root , vector<int> &top)
{
    if (root == NULL)
    {
        return top;
    }
    queue<pair<TreeNode *,int>> q;
    int level =0 ;
    q.push( make_pair (root,0));
      
    while (!q.empty())
    {
        TreeNode *front = q.front();
        q.pop();
        if (front == NULL)
        {
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {

            if (front->left != NULL)
            {
                q.push(front->left);
                createmap(front->left, --level, m);
            }
            if (front->right != NULL)
            {
                q.push(front->right);
                createmap(front->right, ++level, m);
            }
        }
    }
    while(!m.empty())
    {
        top.push_back(m.begin()->second);
cout<<m.begin()->second<<"  ";
    }
    
}
void preorder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}
int main()
{
    TreeNode *root = createTree();
    cout << "Preorder Traversal: ";
    // 10 20 40 -1 -1 50 70 110 -1 -1 111 -1 -1 80 -1 -1 30 -1 60 -1 90 112 -1 -1 113 -1 -1
    preorder(root);
    cout << endl;
    cout << "level order:" << endl;

    levelorder(root);
    cout << endl;
    cout << "left view: "<<endl;
    vector<int> left;
    vector<int> top;
    leftview(root, 0, left);
    cout << "top view: "<<endl;
    topview(root, top);


    return 0;
}
