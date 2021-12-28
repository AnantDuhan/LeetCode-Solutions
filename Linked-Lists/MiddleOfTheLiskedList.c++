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
    ListNode* middleNode(ListNode* head) {
        ListNode* dummy = head;
        int len = 1;
        while (dummy->next != NULL) {
            dummy = dummy->next;
            len++;
        }

        int mid = len / 2;

        dummy = head;
        int i = 0;
        while (i < mid) {
            dummy = dummy->next;
            i++;
        }
        return dummy;
    }
};