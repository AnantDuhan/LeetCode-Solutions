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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode();
        ListNode *temp = head;
        
        if(l1==NULL)
            return l2;
        
        if(l2==NULL)
            return l1;
        
        int rem=0;
        
        while(l1!=NULL or l2!=NULL) {
            int x = (l1!=NULL) ? l1->val : 0;
            int y = (l2!=NULL) ? l2->val : 0;
            int sum = x + y + rem;
            rem = sum/10;
            sum%=10;
            
            if(l1!=NULL) {
                l1->val = sum;
                temp->next = l1;
            } else if(l2!=NULL) {
                l2->val = sum;
                temp->next = l2;
            }
            
            if(l1!=NULL)
                l1 = l1->next;
            
            if(l2!=NULL)
                l2 = l2->next;
            temp = temp->next;
        } 
        if(rem!=0)
            temp->next = new ListNode(rem);
        return head->next;
    }
};