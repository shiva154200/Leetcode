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
 ListNode* reverseList(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
    
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* Next=head; 
        while(Next!=NULL){
            Next=Next->next;
            curr->next=prev;
            prev=curr;
            curr=Next;
        }

        return prev;
    }
    void reorderList(ListNode* head) {
     
     ListNode* slow=head;
     ListNode* fast=head;
     while(fast->next&&fast->next->next){
        slow=slow->next;
        fast=fast->next->next;
       
     }
      ListNode* help=reverseList(slow->next);
      slow->next=NULL;
      fast=head;
      ListNode* result=new ListNode(5);
      ListNode* temp=result;
      while(fast || help){
        temp->next=fast;
        temp=temp->next;
        fast=fast->next;
        if(help) {temp->next=help;
        temp=temp->next;
        help=help->next;}
       
      }
      head= result->next;



        
    }
};