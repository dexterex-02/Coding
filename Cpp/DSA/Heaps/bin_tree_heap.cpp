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

int countNodes(node *root)
{
    if (root == NULL)
        return 0;
    int ans = 1 + countNodes(root->left) + countNodes(root->right);
    return ans;
}

bool isCBT(node *root, int index, int total)
{
    if (root == NULL)
        return true;
    if (index >= total)
        return false;
    else
    {
        bool left = isCBT(root->left, 2 * index + 1, total);
        bool right = isCBT(root->right, 2 * index + 2, total);
        return (left && right);
    }
}

bool isMaxheap(node *root)
{
    if (root->left == NULL && root->right == NULL)
        return true;

    if (root->right == NULL)
    {
        return (root->data > root->left->data);
    }
    else
        return (isMaxheap(root->left) && isMaxheap(root->right) && (root->data > root->left->data) && (root->data > root->right->data));
}

bool isHeap(node *root)
{
    int index = 0;
    int total = countNodes(root);
    if (isCBT(root, index, total) && isMaxheap(root))
        return true;
    else
        return false;
}

int main()
{
    node *root = NULL;
    root = buildtree(root);
    levelOrderTraversal(root);
    if(isHeap(root))
        cout << "true";
    else
        cout << "false";
    return 0;
}