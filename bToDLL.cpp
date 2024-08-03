class Solution
{
    public: 
    
    Node* prev = NULL;
    
    void bToDLLHelper(Node* root, Node* &head){
        if(root == NULL) return;
        bToDLLHelper(root->left, head);
        
        if(prev == NULL){
            head = root;
        }
        else{
            prev->right = root;
            root->left = prev;
        }
        prev = root;
        
        bToDLLHelper(root->right, head);
    }
    //Function to convert binary tree to doubly linked list and return it.
    Node * bToDLL(Node *root)
    {
        Node* head = NULL;
        bToDLLHelper(root, head);
        return head;
    }
};
