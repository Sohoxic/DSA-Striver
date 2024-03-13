#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator{
    stack<TreeNode*> s;
    bool reverse = true;
    public:
        BSTIterator(TreeNode* root, bool isReverse){
            reverse = isReverse;
            pushAll(root);
        }
        int next(){
            TreeNode* top = s.top();
            if(reverse){
                pushAll(top->right);
            }
            else{
                pushAll(top->left);
            }
            return top->val;
        }

        void pushAll(TreeNode* root){
            while(root){
                s.push(root);
                if(reverse){
                root = root->right;
                }
                else{
                root = root->left;
                }
            }
        }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator l(root, false);
        BSTIterator r(root, true);

        int i = l.next();
        int j = r.next();
        while(i<j){
            if(i+j == k)    return true;
            else if(i+j<k)  i = l.next();
            else    j = r.next();
        }
        return false;
    }
};

int main() {
    // Creating a sample tree
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);
    
    Solution isTwoSum;
    cout<<isTwoSum.findTarget(root, 9);

    
    return 0;
}