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

class BSTIterator {
public:
    stack<TreeNode*> s;
    BSTIterator(TreeNode* root) {
        pushAll(root);

    }
    
    int next() {
        TreeNode* next = s.top();
        s.pop();
        pushAll(next->right);
        return next->val;
    }
    
    bool hasNext() {
        if(!s.empty())    return 1;
        return 0;
    }
    private: 
        void pushAll(TreeNode* root){
            while(root){
                s.push(root);
                root = root->left;
                
                // cout<<" the top is "<<s.top()->val<<endl;
            }
        }
};

int main() {
    // Creating a sample tree
    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(17);
    
    BSTIterator it(root);

    cout<<it.next()<<endl;
    cout<<it.hasNext()<< endl;
    cout<<it.next()<<endl;
    cout<<it.hasNext()<<endl;
    cout<<it.next()<<endl;
    cout<<it.hasNext()<<endl;
    cout<<it.next()<<endl;
    cout<<it.hasNext()<<endl;
    cout<<it.next()<<endl;
    cout<<it.hasNext()<<endl;
    
    return 0;
}