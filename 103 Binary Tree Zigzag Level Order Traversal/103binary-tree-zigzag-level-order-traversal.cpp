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
 void levelnodes(int i,int l,TreeNode *root,vector<int>&v){
    if(root==NULL) return;
    if(l == i)
    {v.push_back(root->val);
               return;} 
       if(l%2==0)
       {levelnodes(i+1,l,root->right,v) ; 
       levelnodes(i+1,l,root->left,v) ; } 
       else{
       levelnodes(i+1,l,root->left,v) ;
       levelnodes(i+1,l,root->right,v) ; 
       }
        
 }

 int level(TreeNode *root){
    if(!root) return 0; 
    return 1+ max(level(root->left),level(root->right));
  
}

 void fill(TreeNode*root,vector<vector<int>>&ans){
   for(int i=1;i<=level(root);i++){
    vector<int>v;
    levelnodes(1,i,root,v);
    ans.push_back(v);

   }
 }
  
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
     vector<vector<int>>ans;
     fill(root,ans);
     return ans;
       
    }
};
