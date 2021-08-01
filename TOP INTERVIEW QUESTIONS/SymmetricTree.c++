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
iterative:
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
          queue<TreeNode*> q1;
          queue<TreeNode*> q2;
          q1.push(root->left);
          q2.push(root->right);
          while (!q1.empty() && !q2.empty()) {
              TreeNode* node1 = q1.front();
              TreeNode* node2 = q2.front();
              if (!node1 && !node2) {
                  q1.pop();
                  q2.pop();
                  continue;
              }
              if (!node1 || !node2) return false;
              if (node1 && node2 && node1->val != node2->val) return false;
              q1.push(node1->left);
              q1.push(node1->right);
              q2.push(node2->right);
              q2.push(node2->left);
              q1.pop();
              q2.pop();
          }
          return true;
    }
};

recursive:
class Solution {
public:
  bool isSymmetricHelper(TreeNode* n1, TreeNode* n2) {
	  if (!n1 && !n2) return true;
	  if (!n1 || !n2) return false;
	  if (n1->val != n2->val) return false;
	  return isSymmetricHelper(n1->left, n2->right) && isSymmetricHelper(n1->right, n2->left);
  }

  bool isSymmetric(TreeNode* root) {
	  return isSymmetricHelper(root->left, root->right);
  }
};