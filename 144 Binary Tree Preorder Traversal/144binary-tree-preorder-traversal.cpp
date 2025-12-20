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
    vector<int> preorderTraversal(TreeNode* root) {

        stack<TreeNode*>st;
       
        vector<int>ans;
        
        TreeNode* curr=root;
        
        while(curr || st.size()){

            while(curr){
                ans.push_back(curr->val);
               
                st.push(curr);
                 curr=curr->left;
            }

            curr=st.top()->right;
            st.pop();

            

        }

        return ans;
        
    }
};