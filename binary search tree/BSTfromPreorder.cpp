#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;    
    
    TreeNode* left; 
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* solve(vector<int>& preorder , int &index, int maxBound){
        if(index>=preorder.size() || preorder[index]>maxBound){
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[index++]);
        root->left = solve(preorder, index, root->val);
        root->right = solve(preorder, index, maxBound);
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        return solve(preorder, index, INT_MAX);
    }
};




void printInOrder(TreeNode* root) {
    if (root == NULL) {
        return; 
    }

    printInOrder(root->left);
    
    cout << root->val << " ";

    printInOrder(root->right);
}


int main() {
    Solution solution;

    vector<int> preorder = {8,5,1,7,10,12};
    TreeNode* root = solution.bstFromPreorder(preorder);

    cout << "Inorder Traversal of Tree:" << endl;
    printInOrder(root);
    cout << endl;


    return 0;
}