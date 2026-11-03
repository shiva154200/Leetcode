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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        int sz=0;
        ListNode*temp=head;
        while(temp){
            sz++;
            temp=temp->next;
        }
        if(sz==n) return head->next;
        int idx=sz-n;
        int i=1;
        temp=head;

        while(i<idx&&temp){
            i++;
            temp=temp->next;
        }

        temp->next=temp->next->next;
        return head;

        
    }
};