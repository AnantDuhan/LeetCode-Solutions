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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* l1 = head->next;
        if (!l1)
            return head;
        while (l1) {
            ListNode* l2 = head;
            while (l1 != l2) {
                if (l2->val > l1->val) {
                    swap(l2->val, l1->val);
                }
                l2 = l2->next;
            }
            l1 = l1->next;
        }
        return head;
    }
};