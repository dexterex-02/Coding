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

int solve(node *root, int &i, int k)
{
    if (root == NULL)
        return -1;

    int left = solve(root->left, i, k);
    if (left != -1)
        return left;

    i++;
    if (i == k)
        return root->data;
    int right = solve(root->right, i, k);
    return right;
}

int kthSmallest(node *root, int k)
{
    int i = 0;
    int ans = solve(root, i, k);
    return ans;
}

int main()
{
    node *root = NULL;
    root = buildtree(root);
    levelOrderTraversal(root);
    int k;
    cin >> k;
    cout << kthSmallest(root, k);
    return 0;
}