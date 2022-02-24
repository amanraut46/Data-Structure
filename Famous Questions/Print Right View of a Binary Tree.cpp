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
void rightView(Node* root)
{
    queue<Node*> q;
    q.push(root);
    while (!q.empty())
    {
        int n=q.size();

        for (size_t i = 1; i <= n; i++)
        {
            Node* front=q.front();
            q.pop();
            if(i==n)
            {
                cout<<front->data<<" ";
            }
            if(front->left)
                q.push(front->left);
            if(front->right)
                q.push(front->right);
        }
        
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
    rightView(root);
    return 0;
}