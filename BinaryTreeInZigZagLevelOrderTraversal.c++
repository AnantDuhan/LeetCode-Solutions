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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> bfs;
        bool ltr = true;
        if(root == NULL)
            return bfs;
        
        queue<TreeNode *>queue;
        queue.push(root);
        while(!queue.empty())
        {
            int level = queue.size();
            vector<int> temp(level);
            for(int i = 0; i < level; i++)
            {
                TreeNode *curr = queue.front();
                queue.pop();
                if(ltr)
                    temp[i] = curr->val;
                else 
                    temp[level-1-i] = curr->val;
                
                if(curr->left != NULL)
                    queue.push(curr->left);
                if(curr->right != NULL)
                    queue.push(curr->right);
            }
            bfs.push_back(temp);
            ltr = ! ltr;
        }    
        return bfs;
    }
};