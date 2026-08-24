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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head->next==NULL||left==right) return head;
        if(left==1){
            int j=1;
            ListNode* temp=head;
            while(j<right){
                temp=temp->next;
                j++;
            }
            ListNode* help=temp->next;
            temp->next=NULL;
            reverseList( head);
            head->next=help;
            return temp;
        }
        else{
            int j=1;
            ListNode* temp=head;
            while(j<left-1){
                temp=temp->next;
                j++;
            }
            ListNode* help=temp->next;
            j=1;
            ListNode* temp1=head;
            while(j<right){
                temp1=temp1->next;
                j++;
            }
            ListNode* help1=temp1->next;
            temp1->next=NULL;
            reverseList(temp->next);
            temp->next=temp1;
            help->next=help1;

            return head;

        }
return head;
    }
};