class Solution {
public:
    void leftTraversal(Node* root, vector<int> &ans){
        //base case
        if(root == NULL || (root->left == NULL && root->right == NULL))
            return;
            
        ans.push_back(root->data);
        
        if(root->left == NULL)
            leftTraversal(root->right, ans);
        else
            leftTraversal(root->left, ans);
            
    }
    
    void leafTraversal(Node* root, vector<int> &ans){
        //base case
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL){
            ans.push_back(root->data);
            return;
        }
        leafTraversal(root->left, ans);
        leafTraversal(root->right, ans);
    }
    
    void rightTraversal(Node* root, vector<int> &ans){
        if(root == NULL || (root->left == NULL && root->right == NULL))
            return;
        
        if(root->right == NULL)
            rightTraversal(root->left, ans);
        else
            rightTraversal(root->right, ans);
            
        ans.push_back(root->data);
    }
    vector <int> boundary(Node *root)
    {
        vector<int> ans;
        if(root == NULL) return ans;
        ans.push_back(root->data);
        
        //Left Traversal
        leftTraversal(root->left, ans);
        //leaf Traversal
        leafTraversal(root->left, ans);
        leafTraversal(root->right, ans);
        //Right Traversal
        rightTraversal(root->right, ans);
        
        return ans;
    }
};
