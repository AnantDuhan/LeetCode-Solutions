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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* runner = dummy;
        ListNode* walker = dummy;
        
        for(int i=1;i<=n+1;i++)
           runner = runner->next;
        
        while(runner != NULL) {
            runner = runner->next;
            walker = walker->next;
        }
        
        walker->next = walker->next->next;
        return dummy->next;
    }
};