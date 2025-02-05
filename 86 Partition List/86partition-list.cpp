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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL||head->next==NULL) return head;
        ListNode* lesval=new ListNode(0);
        ListNode* hival=new ListNode(0);
        ListNode* temples=lesval;
        ListNode* temphi=hival;
        ListNode* temp=head;
        while(temp!=NULL){
            if(temp->val<x){
                temples->next=temp;
                temp=temp->next;
                temples=temples->next;
            }
            else{
                temphi->next=temp;
                temp=temp->next;
                temphi=temphi->next;
            }
        }
        temphi->next=NULL;
        temples->next=hival->next;
        return lesval->next;


        
    }
};