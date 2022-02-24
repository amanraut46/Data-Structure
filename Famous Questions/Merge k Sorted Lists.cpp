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
ListNode* mergeTwoList(ListNode* l1,ListNode* l2);
ListNode* mergeKLists(vector<ListNode*>& lists) {

      if(lists.empty())
                return NULL;
        
        int left=0;
        int right=lists.size()-1;
        
        while(right>0)
        {
            lists[left]=mergeTwoList(lists[left],lists[right]);
            left++;
            right--;
            
            if(left>=right)
            {
                left=0;
            }
        }
        return lists[0];
}
ListNode* mergeTwoList(ListNode* l1,ListNode* l2)
{
    ListNode dummy{0};
    ListNode *curr=&dummy;

    while (l1 && l2)
    {
        if(l1->data <= l2->data)
        {
            curr->next=l1;
            l1=l1->next;
        }
        else
        {
            curr->next=l2;
            l2=l2->next;
        }
        curr=curr->next;
    }
    curr->next=l1?l1:l2;

    return dummy.next;
}
void printList(ListNode* head)
{
    if(head==NULL)
        return;

    cout<<head->data<<" ";
    printList(head->next);
}
int main()
{
    ListNode* head1;
    ListNode* head2;
    ListNode* head3;

    head1=new ListNode(1);
    head1->next=new ListNode(4);
    head1->next->next=new ListNode(5);

    head2=new ListNode(1);
    head2->next=new ListNode(3);
    head2->next->next=new ListNode(4);

    head3=new ListNode(2);
    head3=new ListNode(6);

    vector<ListNode*> ls;

    ls.push_back(head1);
    ls.push_back(head2);
    ls.push_back(head3);
    

    printList(mergeKLists(ls));
    return 0;
}