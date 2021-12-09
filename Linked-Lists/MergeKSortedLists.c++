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
// Brute Force
class Solution {
public:
    ListNode* merge(ListNode* a, ListNode* b) {
        if (!a)
            return b;
        if (!b)
            return a;
        ListNode* temp = NULL;
        if (a->val <= b->val) {
            temp = a;
            temp->next = merge(a->next, b);
        } else {
            temp = b;
            temp->next = merge(a, b->next);
        }
        return temp;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0)
            return NULL;
        if (lists.size() == 1)
            return lists[0];

        ListNode *ans = NULL;
        for (auto l : lists) {
            ans = merge(ans, l);
        }
        return ans;
    }
};

// Optimal Approach
class Solution {
public:
    ListNode* mergesort(ListNode* a, ListNode* b) {
        if (!a)
            return b;
        if (!b)
            return a;
        ListNode* temp = NULL;
        if (a->val <= b->val) {
            temp = a;
            temp->next = mergesort(a->next, b);
        } else {
            temp = b;
            temp->next = mergesort(a, b->next);
        }
        return temp;
    }

    ListNode* mergeK(vector<ListNode*>& lists, int k) {
        while (k != 0) {
            int i = 0, j = k;
            while (i < j) {
                lists[i] = mergesort(lists[i], lists[j]);
                i++;
                j--;
                if (i >= j)
                    k = j;
            }
        }
        return lists[0];
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0)
            return NULL;
        if (lists.size() == 1)
            return lists[0];

        ListNode*newhead = mergeK(lists, lists.size() - 1);
        return newhead;
    }
};
