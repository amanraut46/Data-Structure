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
vector<int> zigzag(Node* root)
{
    queue<Node*> q;
    vector<int> rs;
    bool lefttoright=true;

    q.push(root);

    while (!q.empty())
    {
        int n=q.size();
        vector<int> ans(n);
        for (size_t i = 0; i < n; i++)
        {
            Node* front=q.front();
            q.pop();

            int index=lefttoright?i:n-i-1;

            ans[index]=front->data;

            if(front->left)
                q.push(front->left);
            
            if(front->right)
                q.push(front->right);
        }

        lefttoright=!(lefttoright);

        for(int i:ans)
        {
            rs.push_back(i);
        }
        
    }
    
    return rs;
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
    for(auto i:zigzag(root))
    {
        cout<<i<<" ";
    }
    return 0;
}