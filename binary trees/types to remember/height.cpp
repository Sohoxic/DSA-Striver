//Height is found using DFS as we are using recursion, i.e. stack

int maxDepth(Treenode *root){
    if(root == NULL) return 0;
    int leftHeight = maxDepth(root->left);
    int rightHeight = maxDepth(root->right);
    return 1 + max(leftHeight,rightHeight);
}