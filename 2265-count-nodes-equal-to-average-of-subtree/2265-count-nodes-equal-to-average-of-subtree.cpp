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
  vector<int> helper(TreeNode* root,int &count){
    if(!root) return {0,0};
    if(root->left==NULL&&root->right==NULL){
        count++;
        return {root->val,1};
    } 

    vector<int> left=helper(root->left,count);
     vector<int> right=helper(root->right,count);
    int sum=root->val+left[0]+right[0];
    int c=1+left[1]+right[1];

  

    

    int avg=(sum)/c;
    if(avg==root->val) count++;
    return {sum,c};
    
  }
    int averageOfSubtree(TreeNode* root) {
        int count=0;
        helper(root,count);
        return count;
        
    }
};