#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;    
    TreeNode* left; 
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Nodeval{
    public:
        int minNode, maxNode, maxSize;
        Nodeval(int minNode, int maxNode, int maxSize){
            this->minNode = minNode;
            this->maxNode = maxNode;
            this->maxSize = maxSize;
        }
};

class Solution{
    private:
        Nodeval largestBSTSubtreeHelper(TreeNode* root){
            if(!root){
                return Nodeval(INT_MAX, INT_MIN, 0);
            }
            auto left = largestBSTSubtreeHelper(root->left);
            auto right = largestBSTSubtreeHelper(root->right);
            if(left.maxNode<root->val && root->val < right.minNode){
                return Nodeval(min(root->val, left.minNode), max(root->val, right.maxNode), 1+left.maxSize+right.maxSize);
            }
            return Nodeval(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
        }  
    public:
        int largestBST(TreeNode *root){
            return largestBSTSubtreeHelper(root).maxSize;
        }
};

int main() {
    Solution solution;

    // Creating a sample tree
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(2);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    cout<<solution.largestBST(root);
    return 0;
}