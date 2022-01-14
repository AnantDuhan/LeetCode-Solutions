// TC - O(n1+n2), SC - O(n1+n2)
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* res = NULL;
        if (list1 == NULL)
            return list2;
        else if (list2 == NULL)
            return list1;

        if (list1->val <= list2->val) {
            res = list1;
            res->next = mergeTwoLists(list1->next, list2);
        } else {
            res = list2;
            res->next = mergeTwoLists(list1, list2->next);
        }
        return res;
    }
};

// TC - O(n1+n2), SC - O(1)
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode();
        ListNode* temp = res;

        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                res->next = l1;
                res = res->next;
                l1 = l1->next;
            } else {
                res->next = l2;
                res = res->next;
                l2 = l2->next;
            }
        }

        while (l1 != NULL) {
            res->next = l1;
            res = res->next;
            l1 = l1->next;
        }
        while (l2 != NULL) {
            res->next = l2;
            res = res->next;
            l2 = l2->next;
        }
        return temp->next;
    }
};