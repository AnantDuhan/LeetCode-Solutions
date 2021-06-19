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
    void helper_PreOrder(TreeNode* r,vector<string>& ans,string s)
    {
    
        if(r==NULL) return; 
    
        if(r->left==NULL && r->right==NULL)
        {   
            s += to_string(r->val);
            ans.push_back(s);
        }
    
        s  +=  to_string(r->val) + "->" ;
    
    helper_PreOrder(r->left,ans,  s);  
    helper_PreOrder(r->right,ans, s); 
    
    }

    vector<string> binaryTreePaths(TreeNode* root) 
    {
        vector<string> ans;

        helper_PreOrder(root, ans,"");
        return ans;
    }
};