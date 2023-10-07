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

int lca(node *root, int n1, int n2)
{
    // base case
    if (root == NULL)
    {
        return 0;
    }

    if (root->data == n1 || root->data == n2)
    {
        return root->data;
    }

    int leftAns = lca(root->left, n1, n2);
    int rightAns = lca(root->right, n1, n2);

    if (leftAns != 0 && rightAns != 0)
    {
        return root->data;
    }
    else if (leftAns != 0 && rightAns == 0)
        return leftAns;
    else if (leftAns == 0 && rightAns != 0)
        return rightAns;
    else
        return 0;
}

int main()
{
    node *root = NULL;
    root = buildtree(root);
    levelOrderTraversal(root);
    int n1, n2;
    cin >> n1 >> n2;
    cout << lca(root, n1, n2);
    return 0;
}