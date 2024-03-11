#include<bits/stdc++.h>
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
    TreeNode* inorderSuccessor (TreeNode* root, int target) {
        TreeNode* successor = NULL;
        while (root != NULL) {
            if (target >= root->val) {
                root = root->right;
            } 
            else {
                successor = root;
                root = root->left;
            }
        }
        return successor;
    }

};


int main() {
    Solution solution;

    // Creating a sample tree
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);
    root->right->right->left = new TreeNode(8);
    cout << endl;
    // cout<<root->val;
    TreeNode* inorderSuccessor = solution.inorderSuccessor(root, 8);
    cout<<"The inorder Successor is"<< inorderSuccessor->val;
    return 0;
}