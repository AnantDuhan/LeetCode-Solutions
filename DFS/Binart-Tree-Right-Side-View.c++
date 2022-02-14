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
    unordered_map<int, int> h;
private:
    void solve(TreeNode* root, int height) {
        if (!root)
            return;
        solve(root->right, height + 1);
        if (h.find(height) == h.end()) {
            h.insert({height, root->val});
        }
        solve(root->left, height + 1);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        solve(root, 0);
        vector<int> ans;
        int n = h.size(), i = 0;
        while (i < n) {
            ans.push_back(h[i++]);
        }
        return ans;
    }
};