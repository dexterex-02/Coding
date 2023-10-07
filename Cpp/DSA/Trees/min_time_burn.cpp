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

node *createmap(node *root, int target, map<node *, node *> &ptoc)
{
    node *res = NULL;
    queue<node *> q;
    q.push(root);
    ptoc[root] = NULL;

    while (!q.empty())
    {
        node *front = q.front();
        q.pop();
        if (front->data == target)
            res = front;

        if (front->left)
        {
            ptoc[front->left] = front;
            q.push(front->left);
        }
        if (front->right)
        {
            ptoc[front->right] = front;
            q.push(front->right);
        }
    }
    return res;
}

int burntree(node *root, map<node *, node *> ptoc)
{
    map<node *, bool> visited;
    queue<node *> q;

    q.push(root);
    visited[root] = true;

    int ans = 0;
    while (!q.empty())
    {
        int size = q.size();
        int flag = 0;
        for (int i = 0; i < size; i++)
        {
            node *front = q.front();
            q.pop();

            if (front->left && !visited[front->left])
            {
                flag = 1;
                q.push(front->left);
                visited[front->left] = true;
            }
            if (front->right && !visited[front->right])
            {
                flag = 1;
                q.push(front->right);
                visited[front->right] = true;
            }
            if (ptoc[front] && !visited[ptoc[front]])
            {
                flag = 1;
                q.push(ptoc[front]);
                visited[ptoc[front]] = true;
            }
        }
        if (flag == 1)
            ans++;
    }
    return ans;
}

int minTime(node *root, int target)
{
    int time;
    map<node *, node *> ptoc;
    node *tar = createmap(root, target, ptoc);
    time = burntree(tar, ptoc);
    return time;
}

int main()
{
    node *root = NULL;
    root = buildtree(root);
    levelOrderTraversal(root);
    int t;
    cin >> t;
    cout << minTime(root, t);
    return 0;
}