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
    
void helper(TreeNode* root, int targetSum, vector<vector<int>>& ans, vector<int>& v) {
    if (!root) return;

    v.push_back(root->val);
    targetSum -= root->val;

    if (!root->left && !root->right && targetSum == 0) {
        ans.push_back(v);
    } else {
        helper(root->left, targetSum, ans, v);
        helper(root->right, targetSum, ans, v);
    }

    v.pop_back(); // Backtrack
}



    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
       vector<vector<int>>ans;
       if(!root) return ans;
       vector<int>v;
       helper(root,targetSum,ans,v);
       return ans;
         
    }
};