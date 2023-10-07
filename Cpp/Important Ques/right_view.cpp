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

void solve(node *root, vector<int> &ans, int level)
{
    // base case
    if (root == NULL)
        return;

    // we entered into a new level
    if (level == ans.size())
        ans.push_back(root->data);

    solve(root->right, ans, level + 1);
    solve(root->left, ans, level + 1);
}
vector<int> rightView(node *root)
{
    vector<int> ans;
    solve(root, ans, 0);
    return ans;
}

int main()
{
    node *root = NULL;
    root = buildtree(root);
    levelOrderTraversal(root);
    vector<int> ans = rightView(root);
    for(auto i:ans)
        cout << i << " ";
    return 0;
}