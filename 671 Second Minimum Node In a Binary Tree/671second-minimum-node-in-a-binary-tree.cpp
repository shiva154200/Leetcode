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
void inordertraversal(TreeNode*root,vector<int>&v){
        if(root==NULL) return ;
        inordertraversal(root->left,v);
        v.push_back(root->val);
        inordertraversal(root->right,v);    
    }
    int findSecondMinimumValue(TreeNode* root) {
        vector<int>v;
        
        inordertraversal(root,v);  
        sort(v.begin(),v.end());
        int k=v[0];
        for(int i=1;i<v.size();i++){
            if(k!=v[i]) return v[i];
        }
        return -1;
    }
};