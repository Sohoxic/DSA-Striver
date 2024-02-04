#include <bits/stdc++.h>
using namespace std;

// since DFS so we'll use a stack for the iterative implementation

struct node {
  int data;
  struct node * left, * right;
};

struct node * newNode(int data) {
  struct node * node = (struct node * ) malloc(sizeof(struct node));
  node -> data = data;
  node -> left = NULL;
  node -> right = NULL;

  return (node);
}

vector<int> preOrderTrav(struct node* root){
    
    vector<int> ans;
     
    if(root == NULL) return ans;

    stack<node *> s;
    s.push(root);

    while(!s.empty()){
        struct node* topNode = s.top();
        ans.push_back(topNode->data);
        s.pop();
        if(topNode->right!=NULL){
            s.push(topNode->right);
        }
        if(topNode->left!=NULL){    // not else if since we have to look into both the left and right node and not either or.
            s.push(topNode->left);
        }

    }
    return ans;

}

int main(){
    struct node * root = newNode(1);
    root -> left = newNode(2);
    root -> right = newNode(3);
    root -> left -> left = newNode(4);
    root -> left -> right = newNode(5);
    root -> left -> right -> left = newNode(8);
    root -> right -> left = newNode(6);
    root -> right -> right = newNode(7);
    root -> right -> right -> left = newNode(9);
    root -> right -> right -> right = newNode(10);

    vector < int > preOrder;
    preOrder = preOrderTrav(root);

    cout << "The preOrder Traversal is : ";
    for (int i = 0; i < preOrder.size(); i++) {
      cout << preOrder[i] << " ";
    }

    return 0;
}