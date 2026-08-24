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
    int level(TreeNode*root){
        if(!root) return 0;
        return 1+max(level(root->right),level(root->left));
    }
    void parentmapping(TreeNode*root,unordered_map<TreeNode*,TreeNode*>&mp){
       if(!root)  return;
       if(root->left) {
        mp[root->left]=root;
        parentmapping(root->left,mp);

       }
       if(root->right) {mp[root->right]=root;
        parentmapping(root->right,mp);
       }
    }
   TreeNode* findstartNode(TreeNode*root, int k){
        if(!root) return NULL;
        if(root->val==k) return root;
        
         TreeNode*t=findstartNode(root->left,k);
         if(t) return t;
         return findstartNode(root->right,k);
         
    }

    int amountOfTime(TreeNode* root, int k) {
        TreeNode*start=findstartNode( root,  k);
        if(start==root) return(level(root)-1);
        unordered_map<TreeNode*,TreeNode*>mp;
        parentmapping(root,mp);
        int Min=0;
        TreeNode*temp=start;
        TreeNode*prev=start;

        while(mp.count(temp)){
            prev=temp;
            Min++;
            temp=mp[temp];
        }

        if(temp->right==prev) Min+=level(temp->left);
        else Min+=level(temp->right);
        
        int x=Min;
        int n=level(start)-1;
        if(x<n){
            Min+=(n-x);
              x=n; 
        } 

        temp=start;
     

        while(mp.count(temp)){
            x-=1;
            
            if(mp[temp]->left==temp) n=level(mp[temp]->right);
            else n=level(mp[temp]->left);
            if(x<n){
            Min+=(n-x);
              x=n; 
           } 
           temp=mp[temp];
        
        }

        
    return Min;

    }
};