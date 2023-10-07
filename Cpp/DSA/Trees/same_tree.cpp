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

bool isIdentical(node *r1, node *r2)
{
    // base case
    if (r1 == NULL && r2 == NULL)
        return true;

    if (r1 == NULL && r2 != NULL)
        return false;

    if (r1 != NULL && r2 == NULL)
        return false;

    bool left = isIdentical(r1->left, r2->left);
    bool right = isIdentical(r1->right, r2->right);
    bool value = r1->data == r2->data;

    if (left && right && value)
        return true;
    else
        return false;
}

int main()
{
    node *root1 = NULL;
    root1 = buildtree(root1);
    levelOrderTraversal(root1);
    node *root2 = NULL;
    root2 = buildtree(root2);
    levelOrderTraversal(root2);
    if(isIdentical(root1, root2))
        cout << "identical";
    else
        cout << "not identical";
    return 0;
}