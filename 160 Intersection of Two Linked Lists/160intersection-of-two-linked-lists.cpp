/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
ListNode *find(ListNode *headA, ListNode *headB,int g){
     ListNode *tempA=headA;
     ListNode *tempB=headB;
     for(int i=0;i<g;i++){
         tempA=tempA->next;
     }
     while(tempB){
        if(tempA==tempB) return tempB;
         tempA=tempA->next;
         tempB=tempB->next;
     }
     return NULL;


}
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *tempA=headA;
        ListNode *tempB=headB;
        int LA=0;
        while(tempA){
            tempA=tempA->next;
            LA++;
        }
        int LB=0;
        while(tempB){
            tempB=tempB->next;
            LB++;
        }
        if(LA>LB) return find(headA,headB,LA-LB);
        return find(headB,headA,LB-LA);

        
        
    }
};