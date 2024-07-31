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
    void inOrder(TreeNode* root, vector<int> &list){
        if(root == NULL) return;
        inOrder(root->left, list);
        list.push_back(root->val);
        inOrder(root->right, list);
    }
public:
    bool isValidBST(TreeNode* root) {
        vector<int> list;
        inOrder(root, list);

        int size = list.size();
        int prev = list[0];

        for(int i=1; i<size; i++){
            if(list[i] <= prev)
                return false;
            prev = list[i];
        }
        return true;
    }
};
