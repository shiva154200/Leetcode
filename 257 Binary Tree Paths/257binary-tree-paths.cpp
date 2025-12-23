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
    
  void helper(TreeNode* root,vector<string>&ans,string s){
    if(root->left==NULL&&root->right==NULL){
       s += to_string(root->val);
        ans.push_back(s);
        return;
    }

    s += to_string(root->val);
    s+="->";
    if(root->left) helper(root->left,ans,s);
    if(root->right) helper(root->right,ans,s);

   }
    vector<string> binaryTreePaths(TreeNode* root) {

        vector<string>ans;
        string t="";
        helper(root,ans,t);
        return ans;


    }
};