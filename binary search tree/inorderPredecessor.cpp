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
    TreeNode* inorderPredecessor (TreeNode* root, int target) {
        TreeNode* Predecessor = NULL;
        while (root != NULL) {
            if (root->val>=target) {
                root = root->left;
            } 
            else {
                Predecessor = root;
                root = root->right;
            }
        }
        return Predecessor;
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
    TreeNode* inorderPredecessor = solution.inorderPredecessor(root, 8);
    cout<<"The inorder Predecessor is"<< inorderPredecessor->val;
    return 0;
}