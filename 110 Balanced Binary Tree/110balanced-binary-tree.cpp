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
    unordered_map<TreeNode* ,int>mp;
    int c;
    int height(TreeNode* root){
        if(c) return 0;
        if(!root) return 0;
        if(mp.count(root)) return mp[root];
        int lft=height(root->left);
        int rght=height(root->right);
        mp[root]=1+max(lft,rght);

        if(  abs(lft-rght) > 1  ) c++;
        return mp[root];


    }
    bool isBalanced(TreeNode* root) {
        c=0;
        height(root);

        return c==0;

        
        
    }
};