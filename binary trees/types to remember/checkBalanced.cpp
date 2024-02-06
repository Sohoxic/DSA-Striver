int maxDepth(Treenode *root){
    if(root == NULL) return 0;
    int leftHeight = maxDepth(root->left);
    if(leftHeight==-1)   return -1;
    int rightHeight = maxDepth(root->right);
    if(rightHeight==-1)   return -1;
    if(abs(leftHeight-rightHeight)>1)   return -1;
    return 1 + max(leftHeight,rightHeight);
}