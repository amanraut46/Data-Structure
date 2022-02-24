#include<iostream>
using namespace std;

class Tree
{
public:
    char data;
    Tree* left;
    Tree* right;

public:
    Tree(char item)
    {
        data = item;
    }  
};
void preorder(Tree* root)
{
    if (root!=NULL)
    {
        cout << root->data <<' ';
        preorder(root->left);
        preorder(root->right);
    }
    
}
// void inorder(Tree* root)
// {
//     if (root!=NULL)
//     {
//         inorder(root->left);
//         cout << root->data <<" ";
//         inorder(root->right);
//     } 
// }
// void postorder(Tree* root)
// {
//     if (root!=NULL)
//     {
//         postorder(root->left);
//         postorder(root->right);
//         cout << root->data <<" ";   
//     } 
// }
int main()
{
    Tree* a = new Tree('a');
    Tree* b = new Tree('b');
    Tree* c = new Tree('c');
    Tree* d = new Tree('d');
    Tree* e = new Tree('e');
    Tree* h = new Tree('h');
    Tree* i = new Tree('i');

    Tree* f = new Tree('f');
    Tree* g = new Tree('g');

    Tree* j = new Tree('j');

    a->left = b;
    a->right = c;

    b->left = d;
    b->right = e;
    e->left = h;
    e->right = i;

    c->left=f;
    c->right = g;
    f->left = j;

    cout <<"preorder\n";
    preorder(a);

    cout << "inorder\n";
    //inorder(a);

    cout << "postorder\n";
    //postorder(a);

    return 0;
}


