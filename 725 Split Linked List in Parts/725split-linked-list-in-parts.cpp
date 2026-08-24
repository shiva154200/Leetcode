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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
      int n=0;
      ListNode*temp= head;
      while(temp){
        n++;
        temp=temp->next;
      }

       vector<ListNode*>v(k,NULL);
       int size;
       int e;
       if(k>n){
        size=1;
        e=0;
       }
       else{
        size=n/k;
        e=n%k;
       }
       temp= head;
       ListNode*curr= head;
       int i=0;
       while(curr){
         int t=size;
         if(e>0) {t=t+1;e--;}
         while(t>1){
            temp=temp->next;
            t--;
         }
         v[i]=curr;
         curr=temp->next;
         temp->next=NULL;
         temp=curr;
         i++;
       }
      return v;
       

        
       
    }
};