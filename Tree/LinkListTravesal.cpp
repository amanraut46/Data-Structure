#include<iostream>

using namespace std;
class Node
{
public:
    int data;
    Node* next;

    public:Node(int item)
    {
        data = item;
    }
};
void printList(Node* top){
    while (top!=NULL)
    {
        cout << top->data << " ";
        top = top->next;
    }
}
int main()
{
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);

    // n1->data = 1;
    // n2->data = 2;
    // n3->data = 3;
    // n4->data = 4;cls
    
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = NULL;
    printList(n1);
    return 0;
}

