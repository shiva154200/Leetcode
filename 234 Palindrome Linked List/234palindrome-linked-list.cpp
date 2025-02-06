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
    bool isPalindrome(ListNode* head) {
        if(head==NULL||head->next==NULL) return true;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL&&fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* reversalhalf=reverseList(slow->next);
        slow->next=reversalhalf;
        slow=reversalhalf;
        fast=head;
        while(slow!=NULL){
            if(slow->val!=fast->val) return false;
            slow=slow->next;
            fast=fast->next;
        }
        return true;
        
        
    }
};