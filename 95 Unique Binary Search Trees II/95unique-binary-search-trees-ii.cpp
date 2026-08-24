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
   string serialize(TreeNode* root) {
    if (!root) return "#"; // Use "#" to represent null
    return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
}
   TreeNode*insert(TreeNode*root,int k){
    if(root==NULL){
        TreeNode*t=new TreeNode(k);
        return t;
    }
    if(root->val>k){
        root->left=insert(root->left,k);
    }
    else{
         root->right=insert(root->right,k);
    }
    return root; 
   }


   TreeNode*makebst(vector<int>v){
    TreeNode*root=new TreeNode(v[0]);
        for(int i=1;i<v.size();i++){
            insert(root,v[i]); 
            
        }
        return root;
    }

   

   unordered_set<string> seen;

void helper(string s, vector<int> v, vector<TreeNode*>& ans) {
    if (s.empty()) {
        TreeNode* bst = makebst(v);
        string sig = serialize(bst);
        if (seen.count(sig) == 0) {
            seen.insert(sig);
            ans.push_back(bst);
        }
        return;
    }
    for (int i = 0; i < s.size(); i++) {
        v.push_back(s[i] - '0');
        helper(s.substr(0, i) + s.substr(i + 1), v, ans);
        v.pop_back();
    }
}


    vector<TreeNode*> generateTrees(int n) {
       string s="";
       for(int i=1;i<=n;i++) {
        s+=to_string(i);
       }
       vector<TreeNode*>ans;
       vector<int>v;
       helper(s,v,ans);
       return ans;
      
    }
};