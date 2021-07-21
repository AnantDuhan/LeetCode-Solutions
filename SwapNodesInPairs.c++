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
        
        while(runner->next != NULL && runner->next->next != NULL) {
            ListNode* r1 = runner->next;
            ListNode* r2 = runner->next->next;
            
            runner->next = r2;
            r1->next = r2->next;
            r2->next = r1;
            
            runner = runner->next->next;
        }
        return dummy->next;
    }
};