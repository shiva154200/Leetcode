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
    int to_binary(string& s) {
        int i = s.size()-1;
        long long m = 1;
        long long r = 0;

        while (i >= 0) {
            r += (s[i] - 48) * m;
            m *= 2;
            i--;
        }

        return r;
    }

    void helper(TreeNode* root, string s,int& ans) {
        if(!root) return;
        if(root->left==NULL&&root->right==NULL) {
              s.push_back((root->val+'0'));

            ans+=to_binary(s);
            return;

        }
        s.push_back((root->val+'0'));
        helper(root->left,s,ans);
        helper(root->right,s,ans);

        return;

    }
    int sumRootToLeaf(TreeNode* root) {

        int ans = 0;
        helper(root, "0", ans);
        return ans;
    }
};