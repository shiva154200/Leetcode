/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    typedef pair<TreeNode*, int> pr;
    int maxLevelSum(TreeNode* root) {

        vector<long long> v;
        v.push_back(0);
        queue<pr> q;
      
        q.push({root, 0});

        while (q.size()) {

            TreeNode* t = q.front().first;
            int l = q.front().second;

            q.pop();
            if (v.size() <= l)
                v.push_back(0);
            v[l] += t->val;

            if (t->left) {
                q.push({t->left, l + 1});
            }
             if (t->right) {
                q.push({t->right, l + 1});
            }
        }

        int ml=0;
        for(int i=0;i<v.size();i++){
            if(v[ml]<v[i]) ml=i;
        }

        return ml+1;
    }
};