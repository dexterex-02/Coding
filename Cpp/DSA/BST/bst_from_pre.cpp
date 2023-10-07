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

node *solve(vector<int> &preorder, int mini, int maxi, int &i)
{
    if (i >= preorder.size())
        return NULL;

    if (preorder[i] < mini || preorder[i] > maxi)
        return NULL;

    node *root = new node(preorder[i++]);
    root->left = solve(preorder, mini, root->data, i);
    root->right = solve(preorder, root->data, maxi, i);
    return root;
}

node *preorderToBST(vector<int> &preorder)
{
    int maxi = INT_MAX;
    int mini = INT_MIN;

    int i = 0;
    return solve(preorder, mini, maxi, i);
}

int main()
{
    vector<int> v;
    int n, value;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        v.push_back(value);
    }
    node *root = preorderToBST(v);
    levelOrderTraversal(root);

    return 0;
}