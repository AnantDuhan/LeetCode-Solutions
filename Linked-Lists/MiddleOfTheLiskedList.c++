// Brute Force
// TC - O(n) + O(n/2), SC - O(1)
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

// Optimal Approach
// TC - O(n/2), SC - O(1)
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* walker = head;
        ListNode* runner = head;
        while (runner && runner->next) {
            walker = walker->next;
            runner = runner->next->next;
        }
        return walker;
    }
};