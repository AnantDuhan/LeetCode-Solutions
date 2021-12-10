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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL)
            return NULL;
        if (head->next == NULL)
            return head;

        int len = 0, rotation = 0;
        ListNode* dummy = head;
        while (dummy != NULL) {
            len++;
            dummy = dummy->next;
        }

        k = k % len;

        ListNode* runner = head;
        ListNode* walker = head;

        for (int i = 0; i < k; i++) {
            while (walker->next != NULL) {
                runner = walker;
                walker = walker->next;
            }
            runner->next = NULL;
            walker->next = head;
            head = walker;
        }
        return head;
    }
};