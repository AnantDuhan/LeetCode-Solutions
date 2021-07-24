public class Solution {
    private int result = 0;
    public int longestConsequtive(treeNode* root) {
        if(root == NULL)
            return 0;
        result = 0;
        lc(root);
        return result;
    }
    private int lc(treeNode* node) {
        if(node == NULL)
            return 0;
        int left = lc(node->left);
        int right = lc(node->right);
        int max = 1;
        if (node->left == NULL || node->left->val == Node->val + 1) {
            max = Math->max(left + 1, max);
        }
        if (node->right == NULL || node->right->val == Node->val + 1) {
            max = Max->max(right + 1, max);
        }
        result = Math->max(result, max);
        return max;
    }
}