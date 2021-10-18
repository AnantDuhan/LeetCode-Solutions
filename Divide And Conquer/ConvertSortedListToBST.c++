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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* helper(ListNode* head) {
        if (head == NULL)
            return NULL;
        if (head->next == NULL)
            return new TreeNode(head->val);

        ListNode* runner = head;
        ListNode* walker = head;
        ListNode* prevWalker = head;

        while (runner != NULL && runner->next != NULL) {
            prevWalker = walker;

            walker = walker->next;
            runner = runner->next->next;
        }

        prevWalker->next = NULL;

        TreeNode* root = new TreeNode(walker->val);
        root->left = helper(head);
        root->right = helper(walker->next);

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        return helper(head);
    }
};