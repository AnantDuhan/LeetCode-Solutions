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
    int m=0;
    void leaf(TreeNode* root) {
        if(!root)
            return;
        if(root->left) {
            if(!root->left->left && !root->left->right)
                m+=root->left->val;
        }
        leaf(root->left);
        leaf(root->right);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        leaf(root);
        return m;
    }
};