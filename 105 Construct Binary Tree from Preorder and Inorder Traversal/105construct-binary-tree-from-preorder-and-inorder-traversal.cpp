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
     TreeNode* helper(vector<int>& preorder, vector<int>& inorder,int si,int ei,int si1,int ei1){
     
        if(si>ei) return NULL;
        int k=preorder[si1];
        TreeNode*root=new TreeNode(k);
        int i=si;
        int j=si1;
        while(inorder[i]!=k){
            i++;
            j++;
        }
        root->left=helper(preorder,inorder,si,i-1,si1+1,j);
        root->right=helper(preorder,inorder,i+1,ei,j+1,ei1);
        return root;



     }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
         TreeNode*root=helper(preorder,inorder,0,preorder.size()-1,0,preorder.size()-1);
         return root;
    }
};