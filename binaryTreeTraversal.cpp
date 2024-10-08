#include <iostream>
#include <queue>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;
    
    node(int d){
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

node* buildTree(node* root){
    cout << "Enter the value : " << endl;
    int data;
    cin >> data;
    root = new node(data);
    
    if(data == -1)
        return NULL;
        
    cout << "Enter the data for inserting the left pointer for " << data << " : " << endl;
    root -> left = buildTree(root -> left);
    cout << "Enter the data for inserting the right pointer for " << data << " : " << endl;
    root -> right = buildTree(root -> right);
    
    return root;
}

void levelOrderTraversal(node* root){

    queue<node*> q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        
        if(temp == NULL){
            cout << endl;
            if(!q.empty())
                q.push(NULL);
        }
        else{
            cout << temp -> data << " ";
            if(temp -> left)
                q.push(temp -> left);
            if(temp -> right)
                q.push(temp ->right);
        }
    }
}

void buildFromLeverOrder(node* &root){
    queue<node*> q;
    cout << "Enter a data : " ;
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);
    
    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        
        cout<< "Enter the left of : " << temp -> data << endl;
        int leftData;
        cin >> leftData;
        
        if(leftData != -1){
            temp -> left = new node(leftData);
            q.push(temp -> left);
        }
        
        cout << "Enter the right of : " << temp -> data << endl;
        int rightData;
        cin >> rightData;
        
        if(rightData != -1){
            temp -> right = new node(rightData);
            q.push(temp->right);
        }
    }
}

void inOrder(node* root){
    if(root == NULL) return;
    
    inOrder(root -> left);
    cout << root -> data << " ";
    inOrder(root -> right);
}

void preOrder(node* root){
    if(root == NULL) return;
    
    cout << root -> data << " ";
    preOrder(root -> left); 
    preOrder(root -> right);
}

void postOrder(node* root){
    if(root == NULL) return;
    
    postOrder(root -> left);
    postOrder(root -> right);
    cout << root -> data << " ";
}

int main()
{
    node* root = NULL;
    buildFromLeverOrder(root);
    // root = buildTree(root);
    levelOrderTraversal(root);
    cout << endl;
    inOrder(root);
    cout << endl;
    preOrder(root);
    cout << endl;
    postOrder(root);
    cout << endl;

    return 0;
}
