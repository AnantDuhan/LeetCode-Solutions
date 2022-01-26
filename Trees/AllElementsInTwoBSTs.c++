// TC - O(NlogN), SC - O(N)
class Solution {
    vector<int> res;
private:
    void dfs(TreeNode* root) {
        if (!root)
            return;
        res.push_back(root->val);
        dfs(root->left);
        dfs(root->right);
    }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        dfs(root1);
        dfs(root2);
        sort(res.begin(), res.end());
        return res;
    }
};

// TC - O(N), SC - O(N)
class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> res;
        stack<TreeNode *> s1, s2;
        while (root1 || root2 || !s1.empty() || !s2.empty()) {
            while (root1 != NULL) {
                s1.push(root1);
                root1 = root1->left;
            }
            while (root2 != NULL) {
                s2.push(root2);
                root2 = root2->left;
            }
            if (s2.empty() || (!s1.empty() && s1.top()->val <= s2.top()->val)) {
                root1 = s1.top();
                s1.pop();
                res.push_back(root1->val);
                root1 = root1->right;
            } else {
                root2 = s2.top();
                s2.pop();
                res.push_back(root2->val);
                root2 = root2->right;
            }
        }
        return res;
    }
};