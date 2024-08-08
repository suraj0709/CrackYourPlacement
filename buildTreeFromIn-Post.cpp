class Solution {
  public:
    int findPosition(int in[], int element, int start, int end){
        for(int i=start; i<=end; i++){
            if(in[i] == element){
                return i;
            }
        }
        return -1;
    }
    
    Node* solve(int in[], int post[], int n, int &postOrderIndex, 
    int inOrderStart, int inOrderEnd){
        //baseCase
        if(postOrderIndex < 0 || inOrderStart > inOrderEnd){
            return NULL;
        }
        int element = post[postOrderIndex--];
        Node* root = new Node(element);
        int position = findPosition(in, element, inOrderStart, inOrderEnd);
        
        root->right = solve(in, post, n, postOrderIndex, position+1, inOrderEnd);
        root->left = solve(in, post, n, postOrderIndex, inOrderStart, position-1);
        
        return root;
    }

    // Function to return a tree created from postorder and inoreder traversals.
    Node *buildTree(int n, int in[], int post[]) {
        int postOrderIndex = n-1;
        Node* root = solve(in, post, n, postOrderIndex, 0, n-1);
        return root;
    }
};
