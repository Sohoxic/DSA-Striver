#include <iostream>
#include <climits>
using namespace std;

// Definition of TreeNode structure
// for a binary tree node
struct TreeNode {
    // Value of the node
    int val;
    
    // Pointer to the left child node
    TreeNode* left;
    
    // Pointer to the right child node
    TreeNode* right;

    // Constructor to initialize the node with a
    // value and set left and right pointers to null
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Function to find the lowest common ancestor (LCA)
    // of two nodes in a binary search tree (BST)
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Check if the root is null
        if (root == nullptr) {
            // If null, return null as there's no LCA
            return nullptr; 
        }
        
        // Store the value of the current root node
        int curr = root->val;
        
        // If both p and q values are greater
        // than the current root's value
        if (curr < p->val && curr < q->val) {
            // Recursively search in the
            // right subtree for the LCA
            return lowestCommonAncestor(root->right, p, q);
        }
        
        // If both p and q values are smaller
        // than the current root's value
        if (curr > p->val && curr > q->val) {
            // Recursively search in the
            // left subtree for the LCA
            return lowestCommonAncestor(root->left, p, q);
        }
        
        // If the values are on either side of the current root's value,
        // or one of the values matches the current root's value,
        // return the current root as the LCA
        return root;
    }
};


// Function to perform an in-order traversal
// of a binary tree and print its nodes
void printInOrder(TreeNode* root) {
    // Check if the current node
    // is null (base case for recursion)
    if (root == nullptr) {
        // If null, return and
        // terminate the function
        return;
    }

    // Recursively call printInOrder
    // for the left subtree
    printInOrder(root->left);

    // Print the value of the current node
    cout << root->val << " ";

    // Recursively call printInOrder
    // for the right subtree
    printInOrder(root->right);
}

int main() {
    Solution solution;

    // Creating a sample tree
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(3);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(7);
    cout << "Inorder Traversal of Tree:" << endl;
    printInOrder(root);
    cout << endl;

    // Node with value 2
    TreeNode* p = root->left->left;  
    
    // Node with value 4
    TreeNode* q = root->left->right; 
    
    TreeNode* lca = solution.lowestCommonAncestor(root, p, q);

    cout << "Lowest Common Ancestor of " << p->val << " and " << q->val << " is: " << lca->val << endl;

    return 0;
}