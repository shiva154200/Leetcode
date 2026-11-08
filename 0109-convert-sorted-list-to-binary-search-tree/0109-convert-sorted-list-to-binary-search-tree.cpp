/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    ListNode* curr;

    int getLength(ListNode* head) {
        int len = 0;
        while(head) {
            len++;
            head = head->next;
        }
        return len;
    }

    TreeNode* helper(int l, int r) {
        if(l > r) return NULL;

        int mid = l + (r-l)/2;

        TreeNode* left = helper(l, mid-1);

        TreeNode* root = new TreeNode(curr->val);
        curr = curr->next;

        root->left = left;
        root->right = helper(mid+1, r);

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        curr = head;
        int n = getLength(head);

        return helper(0, n-1);
    }
};