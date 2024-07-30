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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        int v = root->val;

        if(v > p->val && v > q->val)
            return lowestCommonAncestor(root->left, p, q);
        if(v < p->val && v < q->val)
            return lowestCommonAncestor(root->right, p, q);
        return root;
    }
};
