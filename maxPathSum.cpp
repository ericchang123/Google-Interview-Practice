/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int calculateSum(TreeNode* root, int &m){
        if (root == NULL) return 0;
        int left = calculateSum(root->left, m);
        int right = calculateSum(root->right, m);
        int current = max(root->val, max(root->val + left, root->val + right));
        m = max(m, max(current, left + root->val + right));
        return current;
    }

    int maxPathSum(TreeNode* root) {
        int m = INT_MIN;
        calculateSum(root, m);
        return m;
    }
};
