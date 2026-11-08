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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

   TreeNode* helper(vector<int>&v,int l,int r){
       if(l>r) return NULL;
       int mid=(l+r+1)/2;
        TreeNode*t= new TreeNode(v[mid]);
        if(l==r) return t;
         t->left=helper(v,l,mid-1);
         t->right=helper(v,mid+1,r);

         return t;
    
   }

    TreeNode* sortedListToBST(ListNode* head) {

        vector<int>v;
         ListNode*temp=head;
         while(temp){
            v.push_back(temp->val);
            temp=temp->next;
         }
         int n=v.size();
         return helper(v,0,n-1);
   
    }
};