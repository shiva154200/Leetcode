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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode*pre=head;
        ListNode*nxt=head;
        while(k>1) {nxt=nxt->next;
        k--;}

        ListNode*temp=nxt;

        while(nxt->next){
            pre=pre->next;
            nxt=nxt->next;
        }
       
       swap(pre->val,temp->val);

       return head;
        



        
        
    }
};