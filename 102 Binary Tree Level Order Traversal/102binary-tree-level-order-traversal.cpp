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
    typedef pair<TreeNode*,int>pr;
    vector<vector<int>> levelOrder(TreeNode* root) {
       
        vector<vector<int>>ans;
         if(!root) return ans;
        queue<pr>q;
        pr p={root,0};
        q.push(p);
        while(q.size()){
            pr z=q.front();
            TreeNode* temp=z.first;
            int l=z.second;
            q.pop();
            if(l==ans.size()){
                 vector<int>t;
                  ans.push_back(t);
            }
            ans[l].push_back(temp->val);
            if(temp->left){
                pr p={temp->left,l+1};
                q.push(p);
            }
            if(temp->right){
                pr p={temp->right,l+1};
                q.push(p);
            }
            
        }
        
        
        return ans;
    }
};