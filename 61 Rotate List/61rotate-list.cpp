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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return head;
        int s=0;
        ListNode*temp= head;
        ListNode*tail= head;
        while(temp){
            tail=temp;
            temp=temp->next;
            s++;
        }
        if(k%s==0||k==0) return head;
        if(k>s) k=k%s;

        int j=s-k;
        temp= head;
        while(j>1){
          temp=temp->next;
          j--;

        }
        ListNode*newHead=temp->next;
        temp->next=NULL;
        tail->next=head;
        return newHead;




        
    }
};