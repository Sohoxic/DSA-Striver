#include <bits/stdc++.h>

using namespace std;

struct node {
  int data;
  struct node * left, * right;
};

vector < int > inorderTraversal(node * root) {
    vector < int > inorder;
    node* curr = root;
    while(curr!=NULL){
        if(curr->left == NULL){
            inorder.push_back(curr->data);
            curr = curr->right;
        }
        else{
            node* rightmost = curr->left;
            while(rightmost->right!=NULL && rightmost->right!=curr){
                rightmost = rightmost->right;
            }
            if(rightmost->right == NULL){
                rightmost->right = curr;
                curr = curr->left;
            }
            else{
                rightmost->right = NULL;
                inorder.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    return inorder;
}

struct node * newNode(int data) {
  struct node * node = (struct node * ) malloc(sizeof(struct node));
  node -> data = data;
  node -> left = NULL;
  node -> right = NULL;

  return (node);
}

int main() {

  struct node * root = newNode(1);
  root -> left = newNode(2);
  root -> right = newNode(3);
  root -> left -> left = newNode(4);
  root -> left -> right = newNode(5);
  root -> left -> right -> right = newNode(6);

  vector < int > inorder;
  inorder = inorderTraversal(root);

  cout << "The Inorder Traversal is: ";
  for (int i = 0; i < inorder.size(); i++) {
    cout << inorder[i] << " ";
  }

  return 0;
}