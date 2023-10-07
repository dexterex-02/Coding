//!important ques of tree

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

void createmap(map<int, int> &m, vector<int> inorder, int n)
{
    for (int i = 0; i < n; i++)
        m[inorder[i]] = i;
}

node *solve(vector<int> &inorder, vector<int> &postorder, int &index, int start, int end, int n, map<int, int> &m)
{
    if (index < 0 || start > end)
        return NULL;

    int data = postorder[index--];
    node *root = new node(data);
    int pos = m[data];
    root->right = solve(inorder, postorder, index, pos + 1, end, n, m);
    root->left = solve(inorder, postorder, index, start, pos - 1, n, m);

    return root;
}

node *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    int n = inorder.size();
    int index = n - 1;
    map<int, int> m;
    createmap(m, inorder, n);
    node *root = solve(inorder, postorder, index, 0, n - 1, n, m);
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

int main()
{
    vector<int> inorder;
    int n, value;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        inorder.push_back(value);
    }
    vector<int> postorder;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        postorder.push_back(value);
    }

    node *root = buildTree(inorder, postorder);
    levelOrderTraversal(root);
    return 0;
}