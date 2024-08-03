void inOrder(struct Node* root, vector<int> &inOrderList){
    if(root == NULL) return;
    inOrder(root->left, inOrderList);
    inOrderList.push_back(root->data);
    inOrder(root->right, inOrderList);
}
float findMedian(struct Node *root)
{
      vector<int> inOrderList;
      inOrder(root, inOrderList);
      
      int size = inOrderList.size();
      if(size % 2 == 0){
          return (inOrderList[size/2] + inOrderList[(size/2)-1])/2.0;
      }
      else{
          return inOrderList[size/2];
      }
}
