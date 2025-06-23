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
int sum(TreeNode* root){
    if(!root) return 0;
    return root->val+sum(root->left)+sum(root->right);
}
   void helper(TreeNode*root,int &s){
    if(!root) return;
     helper(root->right,s);
     s+=root->val;
     root->val=s;
     helper(root->left,s);



   }
    TreeNode* bstToGst(TreeNode* root) {
        int s=0;
       helper(root,s) ;
       return root;
    }
};