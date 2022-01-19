// TC - O(N), SC - O(1)
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* walker = head;
        ListNode* runner = head;

        if (head == NULL || head->next == NULL)
            return NULL;
        bool isCycle = false;

        while (walker != NULL && runner != NULL) {
            walker = walker->next;
            if (runner->next == NULL)
                return NULL;
            runner = runner->next->next;
            if (walker == runner) {
                isCycle = true;
                break;
            }
        }

        if (!isCycle)
            return NULL;

        walker = head;
        while (walker != runner) {
            walker = walker->next;
            runner = runner->next;
        }
        return walker;
    }
};