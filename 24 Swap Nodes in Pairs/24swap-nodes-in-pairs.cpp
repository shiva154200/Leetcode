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
    ListNode* swapPairs(ListNode* head) {
        if(!head||!(head->next)) return head;

        ListNode*temp=head;
        ListNode *tnext=head->next;

        while(1){

            swap(temp->val,tnext->val);
            if(!(tnext->next)||!(tnext->next->next)) break;

            temp=temp->next->next;
            tnext=tnext->next->next;


        }

        return head;



        
    }
};