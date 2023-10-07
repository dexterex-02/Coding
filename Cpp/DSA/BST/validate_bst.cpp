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

bool isbst(node *root, int min, int max)
{
    if (root == NULL)
        return true;
    if (root->data >= min && root->data <= max)
    {
        bool left = isbst(root->left, min, root->data);
        bool right = isbst(root->right, root->data, max);
        return left && right;
    }
    return false;
}
bool validateBST(node *root)
{
    return isbst(root, INT_MIN, INT_MAX);
}

int main()
{
    node *root = NULL;
    root = buildtree(root);
    levelOrderTraversal(root);
    if(validateBST(root))
        cout << "yes";
    else
        cout << "no";
    return 0;
}