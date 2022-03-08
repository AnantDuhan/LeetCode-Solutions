/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* temp = new ListNode;
        while (head != NULL) {
            if (head->next == NULL) {
                return false;
            }
            if (head->next == temp) {
                return true;
            }
            ListNode* nex = head->next;
            head->next = temp;
            head = nex;
        }
        return false;
    }
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL)
            return false;
        ListNode* walker = head;
        ListNode* runner = head;
        while(runner->next != NULL and runner->next->next != NULL) {
            walker = walker->next;
            runner = runner->next->next;
            if(runner == walker)
                return true;
        }
        return false;
    }
};
