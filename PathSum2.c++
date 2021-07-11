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
    vector<vector<int>> res;
    void pathSumUtil(TreeNode* root, int targetSum, vector<int> v) {
        if(!root) return;
        if(root) {
            v.push_back(root->val);
            int sum = accumulate(v.begin(), v.end(), 0);
            
            if(sum==targetSum && !root->left && !root->right) this->res.push_back(v);
            
            if(root->left) pathSumUtil(root->left, targetSum, v);
            if(root->right) pathSumUtil(root->right, targetSum, v);
            
        }
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> v;
        pathSumUtil(root, targetSum, v);
        return this->res;
    }
};