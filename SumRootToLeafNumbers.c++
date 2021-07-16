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
    int sum = 0;
    string s = "";
    
    void traverse(TreeNode* root){
        if(!root) return;
        
        if(root != NULL){
              s+=to_string(root->val);
        }
        traverse(root->left);
        if(!root->left && !root->right){
            sum+=stoi(s);
        }
        
        traverse(root->right);
        
        if(s.size()>1) s.erase(s.size()-1,1);
        return;
    }
    
    
    int sumNumbers(TreeNode* root) {
        traverse(root);
        return sum;
    }
};