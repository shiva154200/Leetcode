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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* t1= l1;
        ListNode* t2= l2;
        ListNode*t=new ListNode(0);
        ListNode*temp=t;
        int c=0;
        while(t1&&t2){
            int x=t1->val+t2->val+c;
            ListNode*n=new ListNode(x%10);
            c=x/10;
            temp->next=n;
            temp=n;  
            t1=t1->next; 
            t2=t2->next; 
        }
        while(t1){
            int x=t1->val+c;
              ListNode*n=new ListNode(x%10);
            c=x/10;
            temp->next=n;
            temp=n;
            t1=t1->next;    
        }

         while(t2){
            int x=t2->val+c;
               ListNode*n=new ListNode(x%10);
            c=x/10;
            temp->next=n;
            temp=n; 
            t2=t2->next;   
        }

        if (c){
            temp->next=(new ListNode(c));
        }
        return t->next;



        

        
    }
};