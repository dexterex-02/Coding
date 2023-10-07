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

vector<int> zigZagTraversal(node *root)
{
    vector<int> result;
    if (root == NULL)
        return result;

    queue<node *> q;
    q.push(root);

    bool leftToRight = true;

    while (!q.empty())
    {

        int size = q.size();
        vector<int> ans(size);

        // Level Process
        for (int i = 0; i < size; i++)
        {

            node *frontNode = q.front();
            q.pop();

            // normal insert or reverse insert
            int index = leftToRight ? i : size - i - 1;
            ans[index] = frontNode->data;

            if (frontNode->left)
                q.push(frontNode->left);

            if (frontNode->right)
                q.push(frontNode->right);
        }

        // direction change karni h
        leftToRight = !leftToRight;

        for (auto i : ans)
            result.push_back(i);
    }
    return result;
}

int main()
{
    node *root = NULL;
    root = buildtree(root);
    levelOrderTraversal(root);
    vector<int> ans = zigZagTraversal(root);
    for(auto i:ans)
        cout << i << " ";
    return 0;
}