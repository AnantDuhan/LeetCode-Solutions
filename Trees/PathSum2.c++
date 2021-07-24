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
    void solve(TreeNode* root, int target, vector<vector<int>>&res, vector<int>&v, int sum) {
        if(root == NULL)
            return;
        sum += root->val;
        v.push_back(root->val);
        
        if(root->left == NULL && root->right == NULL) {
            if(target == sum) {
                res.push_back(v);
            }
        }
        
        solve(root->left,target,res,v,sum);
        solve(root->right,target,res,v,sum);
        v.pop_back();
    }
    
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> v;
        
        solve(root, targetSum, res, v, 0);
        return res;
        
    }
};