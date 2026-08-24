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
    vector<TreeNode*>v;

    void helper(TreeNode*root){
        if(!root) return ;
        helper(root->left);
        v.push_back(root);
        helper(root->right);
    }

    TreeNode* MakeTree(int i,int j){
        if(i>j) return NULL;
      
        int mid=(i+j)/2;
        TreeNode * temp=v[mid];
        temp->left=MakeTree(i,mid-1);
        temp->right=MakeTree(mid+1,j);
        return temp;
    }
    TreeNode* balanceBST(TreeNode* root) {
        helper(root);
        int n=v.size();
        return MakeTree(0,v.size()-1);
        
    }
};