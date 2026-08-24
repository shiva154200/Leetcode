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
    TreeNode*helper(vector<int>& nums,int i,int j){
        if(i>j) return NULL;
        int Max=INT_MIN; 
        int idx=i;
        for(int k=i;k<=j;k++){
          if(Max<nums[k]){
            idx=k;
            Max=nums[k];
          }

        }

        TreeNode*root=new TreeNode(Max);
        root->left=helper(nums,i,idx-1);
        root->right=helper(nums,idx+1,j);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode*root=
        helper(nums,0,nums.size()-1);
        return root;
        
        
    }
};