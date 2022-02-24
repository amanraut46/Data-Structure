#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include<map>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};
void topView(Node* root)
{
    map<int,int> mp;
    queue<pair<Node*,int>> q;
    int h=0;
    q.push({root,h});

    while (!q.empty())
    {
        Node* front=q.front().first;
        h=q.front().second;

        q.pop();

        if(!mp[h])
        {
            mp[h]=front->data;
        }

        if(front->left)
            q.push({front->left,h-1});
        
        if(front->right)
            q.push({front->right,h+1});
    }

    for(pair<int,int> p:mp)
    {
        cout<<p.second<<" ";
    }
    
}
int main()
{
    Node *root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(5);
    root->left->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(25);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    cout << "Bottom view of the given binary tree :\n";
    topView(root);
    return 0;
    return 0;
}