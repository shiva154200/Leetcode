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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        int n= descriptions.size();
      
        unordered_map<int, TreeNode*>mp;
        unordered_set<int>childs;
        for(int i=0;i<n;i++){
            int ch=descriptions[i][1];
            int par=descriptions[i][0];
            bool lft=descriptions[i][2];
            childs.insert(ch);
            TreeNode* p;
            TreeNode* c;
            if(mp.count(par)){
                p=mp[par];
            }
            else{
                p=new TreeNode(par);
                mp[par]=p;
            }

            if(mp.count(ch)){
                c=mp[ch];
            }
            else{
                c=new TreeNode(ch);
                mp[ch]=c;
            }

            if(lft) p->left=c;
            else p->right=c;


        }
        
       

        for(const auto & [i,t]:mp){
            if(!childs.count(i)) return t;
        }

        return NULL;

        

        
    }
};