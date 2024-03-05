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

node* searchBST(node* root, int target) {
    while(root != NULL && root->data != target){
        root = (target<root->data? root->left:root->right);
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

  node* found = searchBST(root,10);
  
  if(found != NULL)
    cout<<"Node value with given target found";
  else cout<<"Node value with given target not found";

  return 0;
}