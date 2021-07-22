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
    ListNode* partition(ListNode* head, int x) {
        ListNode* before_head = new ListNode(0);
        ListNode* before_runner = before_head;
        ListNode* after_head = new ListNode(0);
        ListNode* after_runner = after_head;

        while(head != NULL) {
            if(head->val < x) {
                before_runner->next = head;
                before_runner = before_runner->next;
            } else {
                after_runner->next = head;
                after_runner = after_runner->next;
            }
            head = head->next;
        }

        after_runner->next = NULL;
        before_runner->next = after_head->next;
        return before_head->next;
    }
};