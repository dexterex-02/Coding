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

bool twoSumInBST(node *root, int target)
{
    // Write your code here
    vector<int> temp;
    inorder(root, temp);

    int n = temp.size();
    int s = 0;
    int e = n - 1;
    while (s < e)
    {
        if (temp[s] + temp[e] == target)
            return true;

        else if (temp[s] + temp[e] > target)
            e--;
        else
            s++;
    }
    return false;
}

int main()
{
    node *root = NULL;
    root = buildtree(root);
    levelOrderTraversal(root);
    int t;
    cin >> t;
    if (twoSumInBST(root, t))
        cout << "yes";
    else
        cout << "no";
    return 0;
}