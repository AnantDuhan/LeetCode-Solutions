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
        ListNode* temp;
        ListNode* temp1 = NULL;
        ListNode* res;
        ListNode* prev = NULL;
        if(head==NULL)
            return NULL;
        if(head->next==NULL)
            return head;
        
        res = head->next;
        while(head!=NULL) {
            temp1 = NULL;
            temp = head->next;
            if(prev!=NULL)
            prev->next=temp;
            if(temp!=NULL) {
                temp1 = head->next->next;
                temp->next = head;
                head->next = temp1;
                prev = head;
            
                head= temp1;
            } else {
                prev->next = head;
                break;
            }
        }
        return res;
    }
};