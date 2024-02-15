// lowest common ancestor
node* lowestCommonAncestor(node* root, node* p, node* q) {
        //base case
        if (root == NULL || root == p || root == q) {
            return root;
        }
        node* left = lowestCommonAncestor(root->left, p, q);
        node* right = lowestCommonAncestor(root->right, p, q);

        //result
        if(left == NULL) {
            return right;
        }
        else if(right == NULL) {
            return left;
        }
        else { //both left and right are not null, we found our result
            return root;
        }
    }
