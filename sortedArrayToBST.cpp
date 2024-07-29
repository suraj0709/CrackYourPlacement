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
    TreeNode* makeBST(vector<int>& nums, int low, int high){
        if(low > high) return NULL;
        int mid = low + (high - low)/2;

        TreeNode* temp = new TreeNode(nums[mid]);
        temp->left = makeBST(nums, low, mid-1);
        temp->right = makeBST(nums, mid+1, high);

        return temp;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;

        return makeBST(nums, low, high);
    }
};
