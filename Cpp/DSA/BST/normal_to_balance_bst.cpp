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

void inorder(node *root, vector<int> &temp)
{
    if (root == NULL)
        return;

    inorder(root->left, temp);
    temp.push_back(root->data);
    inorder(root->right, temp);
}

node *solve(vector<int> temp, int s, int e)
{
    if (s > e)
        return NULL;

    int mid = s + ((e - s) / 2);
    node *ans = new node(temp[mid]);
    ans->left = solve(temp, s, mid - 1);
    ans->right = solve(temp, mid + 1, e);
    return ans;
}

node *balancedBst(node *root)
{
    vector<int> temp;
    inorder(root, temp);

    int s = 0;
    int e = temp.size() - 1;
    node *ans = solve(temp, s, e);
    return ans;
}

int main()
{
    node *root = NULL;
    root = buildtree(root);
    levelOrderTraversal(root);
    root = balancedBst(root);
    levelOrderTraversal(root);
    return 0;
}