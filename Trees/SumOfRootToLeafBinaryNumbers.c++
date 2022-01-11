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
    vector<string> v;

    void traverse(TreeNode* root, string sum) {
        if (!root)
            return;
        sum += to_string(root->val);
        if (!root->left && !root->right) {
            v.push_back(sum);
        }
        traverse(root->left, sum);
        traverse(root->right, sum);
    }

    int sumRootToLeaf(TreeNode* root) {
        traverse(root, "");
        int res = 0;
        for (auto x : v) {
            res += stoi(x, NULL, 2);
        }
        return res;
    }
};