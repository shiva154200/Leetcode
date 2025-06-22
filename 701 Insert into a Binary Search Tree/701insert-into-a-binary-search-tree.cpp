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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL){
            TreeNode*t=new TreeNode(val);
            root=t;
        }
       
        else if(root->val>val){
            if(!root->left) {
                TreeNode*t=new TreeNode(val);
                root->left=t;
            }
            else insertIntoBST( root->left,  val);
        }
        else {
            if(!root->right) {
                TreeNode*t=new TreeNode(val);
                root->right=t;
            }
            else insertIntoBST( root->right,  val);}
        return root;
        
    }
};