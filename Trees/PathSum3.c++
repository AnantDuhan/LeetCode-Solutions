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
    int cnt = 0, target;
    unordered_map<int, int> seen;
public:
    int pathSum(TreeNode* root, int targetSum) {
        target = targetSum;
        _pathSum(root, 0);
        return cnt;
    }
    
    void _pathSum(TreeNode* node, int sum) {
        if(!node)
            return;
        sum += node->val;
        if(sum == target)
            cnt++;
        if(seen.find(sum - target) != seen.end())
            cnt += seen[sum-target];
        seen[sum]++;
        _pathSum(node->left, sum);
        _pathSum(node->right, sum);
        
        seen[sum]--;
    }
};
