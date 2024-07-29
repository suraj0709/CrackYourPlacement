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
private:
    void preOrder(TreeNode* root, string & str){
        if(root == NULL){
            str += "null";
            return;
        }

        str += "^" + to_string(root->val);
        preOrder(root->left, str);
        preOrder(root->right, str);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string rootString = "";
        string subRootString = "";

        preOrder(root, rootString);
        preOrder(subRoot, subRootString);

        return rootString.find(subRootString) != string::npos;
    }
};
