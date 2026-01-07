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
    unordered_map<TreeNode*,long long>sumOfTree;
    long long mod=1e9+7;
    long long helper(TreeNode* root) {
        if (!root)
            return 0;
        
        if(sumOfTree.count(root)) return sumOfTree[root];
        sumOfTree[root]=root->val+helper(root->left)+helper(root->right);
        return sumOfTree[root];

         
        
    }

    int maxProduct(TreeNode* root) {
        helper(root);

        long long l = sumOfTree[root->left];
        long long r = sumOfTree[root->right];
        long long s1;
        long long s2;
        TreeNode* temp;
        if (l < r) {
            s1 = (l + root->val)%mod;
            s2 = r%mod;
            temp = root->right;
        } else {
            s1 =( r + root->val)%mod;
            s2 = l%mod;
            temp = root->left;
        }

        while (1) {
            l = sumOfTree[temp->left];
            r = sumOfTree[temp->right];
            // if((s1+temp->val+min(l,r)>max(l,r))) break; 
            // if(  ((s1*s2)%mod)   >  ( (s1+temp->val+min(l,r))*(max(l,r))%mod ) break; 
            if( min(s1,s2) >= min( s1+temp->val+min(l,r) , max(l,r))) break;

            if (l < r) {
                s1=(s1+l+temp->val)%mod;
                s2=r%mod;
                temp=temp->right;
            } 
            else{                 
                s1 =(s1+ r + temp->val)%mod;
                s2 = l%mod;
                temp = temp->left;
            }
        }

        return (s1*s2)%mod;
    }
};