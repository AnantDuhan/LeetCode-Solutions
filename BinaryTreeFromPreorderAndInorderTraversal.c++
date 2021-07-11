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
    int findIndexOf(vector<int> &arr, int key) {
        for(int i=0; i<arr.size(); i++)
            if(arr[i] == key)
                return i;
        return -1;
    }
        
    TreeNode* buildTree(vector<int> preorder, vector<int> inorder) {
        if(preorder.size() == 0)
            return NULL;
               
        TreeNode *root = new TreeNode(preorder[0]);
        
        int i = findIndexOf(inorder, preorder[0]);
             
        root->left = buildTree(vector<int>(preorder.begin()+1, preorder.begin()+i+1), vector<int>(inorder.begin(), inorder.begin() + i));
        root->right = buildTree(vector<int>(preorder.begin()+1+i, preorder.end()), vector<int>(inorder.begin() + i + 1, inorder.end()));
        
        return root;
    }
};