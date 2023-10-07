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

node *flatten(node *root)
{
    vector<int> temp;
    inorder(root, temp);

    int n = temp.size();
    node *ans = new node(temp[0]);
    node *curr = ans;

    for (int i = 1; i < n; i++)
    {
        node *res = new node(temp[i]);

        curr->left = NULL;
        curr->right = res;
        curr = res;
    }

    curr->right = NULL;
    curr->left = NULL;
    return ans;
}

int main()
{
    node *root = NULL;
    root = buildtree(root);
    levelOrderTraversal(root);
    root = flatten(root);
    levelOrderTraversal(root);
    return 0;
}