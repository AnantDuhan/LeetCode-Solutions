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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* dummy = head;
        for (int i = 1; i < k; i++)
            dummy = dummy->next;

        ListNode* walker = head;
        ListNode* runner = dummy->next;

        while (runner) {
            runner = runner->next;
            walker = walker->next;
        }
        swap(walker->val, dummy->val);
        return head;
    }
};