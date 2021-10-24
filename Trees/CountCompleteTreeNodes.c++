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
    int countNodes(TreeNode* root) {
        if(root == NULL)
            return NULL;
        int hl, hr;
        TreeNode *l = root;
        TreeNode *r = root;
        
        while(l) {
            hl++;
            l = l->left;
        }
        while(r) {
            hr++;
            r = r->right;
        }
        if(hl == hr) {
            return pow(2,hl)-1;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
