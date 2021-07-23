/**
 * Q147
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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* p1 = head->next;
        if(!p1)return head;
        while(p1){
            ListNode* p2 = head;
            while(p1!=p2){
                if(p2->val>p1->val){
                    swap(p2->val, p1->val);
                }
                p2 = p2->next;
            }
            p1= p1->next;
        }
        return head;
    }
};