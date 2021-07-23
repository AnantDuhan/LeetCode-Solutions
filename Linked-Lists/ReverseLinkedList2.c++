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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dummy = new ListNode(0, head), *node = dummy, *prev = nullptr; 
        for (int i = 0; i < left; ++i) {
            prev = node; 
            node = node->next; 
        }
        
        ListNode *pp = prev, *nn = node; 
        for (int i = left; i <= right; ++i) {
            ListNode* temp = node->next; 
            node->next = prev; 
            prev = node; 
            node = temp; 
        }
        
        pp->next = prev; 
        nn->next = node; 
        
        return dummy->next; 
    }
};