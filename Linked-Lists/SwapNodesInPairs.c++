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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* runner = dummy;

        while (runner->next != NULL && runner->next->next != NULL) {
            ListNode* runner1 = runner->next;
            ListNode* runner2 = runner->next->next;

            runner->next = runner2;
            runner1->next = runner2->next;
            runner2->next = runner1;

            runner = runner->next->next;
        }
        return dummy->next;
    }
};