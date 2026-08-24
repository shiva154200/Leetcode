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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0);       // dummy node before head
        dummy.next = head;
        ListNode* prev = &dummy;

        while (head) {
            // Check if current value is duplicated
            if (head->next && head->val == head->next->val) {
                // Skip all nodes with this value
                while (head->next && head->val == head->next->val)
                    head = head->next;
                prev->next = head->next;  // skip the entire group
            } else {
                prev = prev->next;  // move prev only when no deletion
            }
            head = head->next;
        }

        return dummy.next;
    }
};
