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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *temp1= list1;
        ListNode *temp2= list2;
        ListNode*res=new ListNode(5);
        ListNode*temp=res;
        while(temp1&&temp2){
            if(temp1->val>temp2->val){
                temp->next=temp2;
                temp2=temp2->next;
            }
            else{
                temp->next=temp1;
                 temp1=temp1->next;
            }
            temp=temp->next;
        }
        if(!temp1) temp->next=temp2;
        else temp->next=temp1;
        return res->next;
    }
    ListNode* sortList(ListNode* head) {
       if (!head || !head->next) return head;
        ListNode*fast= head;
        ListNode*slow= head;
        while(fast->next&&fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        fast=slow->next;
        slow->next=NULL;

       head= sortList(head);
       fast= sortList(fast);

        return mergeTwoLists(head,fast);
        
    }
};