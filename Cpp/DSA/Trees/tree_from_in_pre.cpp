//! important ques of tree

#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

int findpos(vector<int> inorder, int data, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (inorder[i] == data)
            return i;
    }
    return -1;
}

node *solve(vector<int> &preorder, vector<int> &inorder, int &index, int start, int end, int n)
{
    if (index >= n || start > end)
        return NULL;

    int data = preorder[index++];
    node *root = new node(data);
    int pos = findpos(inorder, data, n);

    root->left = solve(preorder, inorder, index, start, pos - 1, n);
    root->right = solve(preorder, inorder, index, pos + 1, end, n);
    return root;
}

node *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    int index = 0;
    int n = preorder.size();
    node *root = solve(preorder, inorder, index, 0, n - 1, n);
    return root;
}

void levelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
    }
}

int main()
{
    vector<int> inorder;
    int n, value;
    cin >> n;
    for (int i = 0; i < n ; i++)
    {
        cin >> value;
        inorder.push_back(value);
    }
    vector<int> preorder;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        preorder.push_back(value);
    }

    node* root= buildTree(preorder, inorder);
    levelOrderTraversal(root);
    return 0;
}