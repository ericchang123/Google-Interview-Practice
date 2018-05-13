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
    vector< vector<int> > levelOrder(TreeNode* root) {
        vector< vector<int> > out;
        vector<int> val;

        if(root == NULL) return out;
        queue<TreeNode*> current;
        queue<TreeNode*> next;
        current.push(root);
        while(!current.empty()){
            TreeNode* curr = current.front();
            current.pop();
            if(curr->left) next.push(curr->left);
            if(curr->right) next.push(curr->right);
            val.push_back(curr->val);
            if(current.empty()){
                current = next;
                queue<TreeNode*> empty;
                swap(next,empty);
                out.push_back(val);
                val.clear();
            }
        }
        return out;
    }
};
