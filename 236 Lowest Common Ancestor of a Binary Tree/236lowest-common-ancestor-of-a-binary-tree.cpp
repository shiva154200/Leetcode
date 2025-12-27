/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent;
    void parentNode(TreeNode* root) {
        if (!root)
            return;
        if (root->left) {
            parent[root->left] = root;
            parentNode(root->left);
        }
        if (root->right) {
            parent[root->right] = root;
            parentNode(root->right);
        }
    }
    bool find(TreeNode* p, TreeNode* q) {
        if (!p)
            return false;
        if (p == q || find(p->left, q) || find(p->right, q))
            return true;

        return false;
    }

    TreeNode* helper(TreeNode* p, TreeNode* q) {
        if (find(p, q))
            return p;

        if (parent[p]->left == p) {
            p = parent[p];
            p->left = NULL;
        } else {
            p = parent[p];
            p->right = NULL;
        }

        return helper(p, q);
        return p;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if (!root || p == root || q == root)
            return root;
        if (p == q)
            return p;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left && right)
            return root;

        return left ? left : right;
    }
};