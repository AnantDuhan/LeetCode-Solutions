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
    ListNode* oddEvenList(ListNode* head) {
        
        ListNode* dummy = head;
        
        ListNode* oddStart = new ListNode(0);
        ListNode* odd = oddStart;
        
        ListNode* evenStart = new ListNode(0);
        ListNode* even = evenStart;
        
        int flag = 0;
        
        while(dummy) {
            if(!flag) {
                odd->next = dummy;
                odd = odd->next;
            }
            if(flag) {
                even->next = dummy;
                even = even->next;
            }
            
            flag ^= 1;
            dummy = dummy->next;
        }
        odd->next = evenStart->next;
        even->next = NULL;
        
        return oddStart->next;
    }
};