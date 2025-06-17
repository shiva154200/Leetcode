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
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *temp1= list1;
        ListNode *temp2= list2;
        ListNode*res=new ListNode(5);
        ListNode*temp=res;
        while(temp1&&temp2){
            if(temp1->val>temp2->val){
                temp->next=temp2;
                temp2=temp2->next;
            }
            else{
                temp->next=temp1;
                 temp1=temp1->next;
            }
            temp=temp->next;
        }
        if(!temp1) temp->next=temp2;
        else temp->next=temp1;
        return res->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        while(lists.size()>1){
            ListNode*temp=new ListNode(0);
           temp= mergeTwoLists(lists[0],lists[1]);
           lists.erase(lists.begin());
           lists.erase(lists.begin());
           lists.push_back(temp);
        }
       return lists[0]; 
    }
};