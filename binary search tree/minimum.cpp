// find minimum in BST
#include <bits/stdc++.h>

using namespace std;

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

node* findMinimum(node* root) {
    while(root->left!=NULL){
        root = root->left;
    }
    return root;
}

int main() {

  struct node * root = newNode(8);
  root -> left = newNode(5);
  root -> left -> left = newNode(4);
  root -> left -> right = newNode(7);
  root -> left -> right -> left = newNode(6);
  root -> right = newNode(12);
  root -> right -> left = newNode(10);
  root -> right -> right = newNode(14);
  root -> right -> right ->left = newNode(13);

  node* minimumFound = findMinimum(root);
  
  cout<<"The smallest node is"<< minimumFound->data;
  return 0;
}