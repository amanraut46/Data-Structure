#include<iostream>
#include<vector>
#include<stack>
#include <algorithm>
#include<queue>
using namespace std;
class ListNode
{
    public:
    int data;
    ListNode* next;

    
    ListNode(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};
void traversal(ListNode* head){

    if(head==NULL)
        return;

    cout<<head->data<<" ";

    traversal(head->next);
}
int LengthNode(ListNode *head)
{
    int i=1;
    while (head->next!=NULL)
    {
        head=head->next;
        i++;
    }
    return i;
}
ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(head==NULL)
            return NULL;
        
        
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* nextnode=NULL;

        int i=0;
        if(LengthNode(curr)-k>=0)
        {
            while (curr!=NULL && i<k)
            {
            nextnode=curr->next;
            curr->next=prev;

            prev=curr;
            curr=nextnode;
            i++;
            }
         
            if(nextnode!=NULL)
            {
            head->next=reverseKGroup(nextnode,k); 
            }
            return prev;
        }
        else{
            return curr;
        }
        
        
        
        
        
}
int main()
{
    ListNode* head=new ListNode(1);
    head->next=new ListNode(2);
    head->next->next=new ListNode(3);
    head->next->next->next=new ListNode(4);
    head->next->next->next->next=new ListNode(5);
    
    traversal(reverseKGroup(head,3));
    return 0;
}