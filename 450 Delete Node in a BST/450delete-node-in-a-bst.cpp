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
    TreeNode*findpredecessor(TreeNode*root){
        while(root->right!=NULL){
            root=root->right;
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int k) {
        if(!root) return root;
        if(root->val==k){
            if(!root->left){
                TreeNode*temp=root->right;
                delete root;
                return temp;
                
            }
            else if(!root->right){
                TreeNode*temp=root->left;
                delete root;
                return temp;
                
            }
            else{
               TreeNode*temp=findpredecessor(root->left);
                root->val=temp->val;
                root->left=deleteNode(root->left, temp->val);
                return root;
            }

        }
        else if(root->val<k){
           root->right= deleteNode(root->right, k);
        }
        else root->left=deleteNode(root->left, k);

        return root;
    }
};