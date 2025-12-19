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
    vector<int> inorderTraversal(TreeNode* root) {

        vector<int>v;
        if(!root) return v;
        stack<TreeNode*>st;

  
      TreeNode *curr=root;

        while( curr ||st.size()){

          
            while(curr) {
            
                st.push(curr);
                curr=curr->left;
            }

            curr=st.top();
            v.push_back(curr->val);
            st.pop();

            curr=curr->right;
            
        }
        return v;
        
    }
};