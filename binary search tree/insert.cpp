#include <iostream>
using namespace std;

struct TreeNode {
    int val;    
    TreeNode* left; 
    TreeNode* right;

    // Constructor to initialize the node with a
    // value and set left and right pointers to null
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL){
            new TreeNode(val);
        }
        TreeNode* curr = root;
        while(true){
            if(val < curr->val){
                if(curr->left==NULL){
                    curr->left = new TreeNode(val);
                    break; 
                }
                else{
                    curr = curr->left;
                }
            }
            else{
                if(val >= curr->val){
                    if(curr->right == NULL){
                        curr->right = new TreeNode(val);
                        break;
                    }
                    else{
                        curr = curr->right;
                    }
                }
            }

        }

        return root;
    }
};



// Function to perform an in-order traversal
// of a binary tree and print its nodes
void printInOrder(TreeNode* root) {
    // Check if the current node
    // is null (base case for recursion)
    if (root == NULL) {
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

    // Printing the original tree
    cout << "Original Tree (Inorder Traversal): ";
    printInOrder(root);
    cout << endl;

    int keyToInsert = 5;
    TreeNode* updatedTree = solution.insertIntoBST(root, keyToInsert);

    cout << "Tree After Insertion (Inorder Traversal): ";
    printInOrder(updatedTree);
    cout << endl;

    return 0;
}