// Brute Force
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
	int res = 0;

	int maxAncestorDiff(TreeNode* root) {
		if (root == NULL)
			return 0;
		res = 0;
		helper(root, root->val, root->val);
		return res;
	}

	void helper(TreeNode* node, int maxVal, int minVal) {
		if (node == NULL)
			return;

		int result = max(abs(maxVal - node->val), abs(minVal - node->val));
		res = max(res, result);

		maxVal = max(maxVal, node->val);
		minVal = min(minVal, node->val);
		helper(node->left, maxVal, minVal);
		helper(node->right, maxVal, minVal);
		return;
	}
};

// Optimal Approach
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
	int maxAncestorDiff(TreeNode* root) {
		if (root == NULL) {
			return 0;
		}
		return helper(root, root->val, root->val);
	}

	int helper(TreeNode* node, int maxVal, int minVal) {
		if (node == NULL)
			return maxVal - minVal;

		maxVal = max(maxVal, node->val);
		minVal = min(minVal, node->val);
		int left = helper(node->left, maxVal, minVal);
		int right = helper(node->right, maxVal, minVal);
		return max(left, right);
	}
};