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

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if (!root) return nullptr;

        unordered_map<TreeNode*, TreeNode*> parent;
        vector<pr> v;
        queue<pr> q;

        q.push({root, 0});
        v.push_back({root, 0});

        int d = 0;

        
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();

            TreeNode* temp = cur.first;
            int l = cur.second;

            d = max(d, l);   

            if (temp->left) {
                parent[temp->left] = temp;
                q.push({temp->left, l + 1});
                v.push_back({temp->left, l + 1});
            }

            if (temp->right) {
                parent[temp->right] = temp;
                q.push({temp->right, l + 1});
                v.push_back({temp->right, l + 1});
            }
        }

        
        unordered_set<TreeNode*> st;
        for (int i = v.size() - 1; i >= 0; i--) {
            if (v[i].second == d)
                st.insert(v[i].first);
            else
                break;
        }

        
        while (st.size() > 1) {
            unordered_set<TreeNode*> next;
            for (auto node : st) {
                if (parent.count(node))
                    next.insert(parent[node]);
            }
            st = move(next);
        }

        return *st.begin();
    }
};
