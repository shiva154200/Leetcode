/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode*f=new ListNode(INT_MIN);
        f->next=head;

    ListNode*temp=head->next;
    ListNode*prev;
    ListNode*nxt;
    ListNode*lst=head;

    while(temp){
        int k=temp->val;
        prev=f;
        nxt=f->next;
        while(nxt->val<k) {
            prev=nxt;
            nxt=nxt->next;
        }
        if(nxt->val==k&& nxt==temp) {
           
            lst=temp;
            

            temp=temp->next;
            lst->next=temp;
            continue;
            }
        
        prev->next=temp;
        ListNode*temp1=temp->next;
        temp->next=nxt;
        

        temp=temp1;
        lst->next=temp;


    }

    lst->next=NULL;

    return f->next;
        
    }
};