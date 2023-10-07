//!very important question of BST

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

node *buildtree(node *root)
{
    int data;
    cin >> data;
    root = new node(data);
    if (data == -1)
        return NULL;
    root->left = buildtree(root->left);
    root->right = buildtree(root->right);
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

class info
{
public:
    int maxi;
    int mini;
    bool isbst;
    int size;
};

info solve(node *root, int &maxsize)
{
    if (root == NULL)
        return {INT_MIN, INT_MAX, true, 0};

    info left = solve(root->left, maxsize);
    info right = solve(root->right, maxsize);

    info curr;
    curr.size = left.size + right.size + 1;
    curr.maxi = max(root->data, right.maxi);
    curr.mini = min(root->data, left.mini);

    if (left.isbst && right.isbst && (root->data > left.maxi && root->data < right.mini))
    {
        curr.isbst = true;
    }
    else
        curr.isbst = false;

    if (curr.isbst)
        maxsize = max(maxsize, curr.size);
    return curr;
}

int largestBST(node *root)
{
    int maxsize = 0;
    info temp = solve(root, maxsize);
    return maxsize;
}

int main()
{
    node *root = NULL;
    root = buildtree(root);
    levelOrderTraversal(root);
    cout << largestBST(root);
    return 0;
}