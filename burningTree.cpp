class Solution {
  public:
    Node* createParentMapping(Node* root, int target, 
        map<Node*, Node*> &nodeToParent){
        Node* res = NULL;
        
        queue<Node*> q;
        q.push(root);
        nodeToParent[root] = NULL;
        while(!q.empty()){
            Node* front = q.front();
            q.pop();
            if(front->data == target){
                res = front;
            }
            if(front->left){
                q.push(front->left);
                nodeToParent[front->left] = front;
            }
            if(front->right){
                q.push(front->right);
                nodeToParent[front->right] = front;
            }
        }
        return res;
    }
    
    int burnTree(Node* root, map<Node*, Node*> nodeToParent){
        int res = 0;
        map<Node*, bool> visited;
        visited[root] = true;
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            bool flag = 0;
            int size = q.size();
            for(int i=0; i<size; i++){
                Node* front = q.front();
                q.pop();
                if(front->left && !visited[front->left]){
                    flag = 1;
                    q.push(front->left);
                    visited[front->left] = true;
                }
                if(front->right && !visited[front->right]){
                    flag = 1;
                    q.push(front->right);
                    visited[front->right] = true;
                }
                if(nodeToParent[front] && !visited[nodeToParent[front]]){
                    flag = 1;
                    q.push(nodeToParent[front]);
                    visited[nodeToParent[front]] = true;
                }
            }
            if(flag) res++;
        }
        return res;
    }
    
    int minTime(Node* root, int target) 
    {
        //Create Parent Maping        //Find Target Node
        map<Node*, Node*> nodeToParent;
        Node* targetNode = createParentMapping(root, target, nodeToParent);
        
        //burn tree
        int res = burnTree(targetNode, nodeToParent);
        return res;
    }
};
