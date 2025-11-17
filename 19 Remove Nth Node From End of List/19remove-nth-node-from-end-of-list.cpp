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
        ListNode* temp=head;
        int s=0;
        while(temp){
            s++;
            temp=temp->next;
        }

        if(s==n) return head->next;
        temp=head;
        for(int i=0;i<s-n-1;i++){
             temp=temp->next;
        }

        temp->next=temp->next->next;

        return head;
    }
};