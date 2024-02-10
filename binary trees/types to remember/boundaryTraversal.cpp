#include <bits/stdc++.h>

using namespace std;

struct node {
  int data;
  struct node * left, * right;
};

bool isLeaf(node * root) {
    return !root->left && !root->right;
}

void addLeftBoundary(node * root, vector < int > & res) {
  node* current = root->left;
  while(current){
    if(!isLeaf(current))    res.push_back(current->data);
    if(current->left)   current = current->left;
    else    current = current->right;
  }
}
void addRightBoundary(node * root, vector < int > & res) {
  node* current = root->right;
  stack<int> s;
  while(current){
    if(!isLeaf(current))    s.push(current->data);
    if(current->left)   current = current->left;
    else    current = current->right;
  }
  while(!s.empty()){
    res.push_back(s.top());
    s.pop();
  }
}

void addLeaves(node * root, vector < int > & res) {
  if (isLeaf(root)) {
    res.push_back(root -> data);
    return;
  }
  if (root -> left) addLeaves(root -> left, res);
  if (root -> right) addLeaves(root -> right, res);
}

vector < int > printBoundary(node * root) {
  vector < int > res;
  if (!root) return res;
  if(!isLeaf(root)) res.push_back(root->data);

  addLeftBoundary(root, res);

  addLeaves(root, res);

  addRightBoundary(root, res);
  return res;
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
  root -> left -> left = newNode(3);
  root -> left -> left -> right = newNode(4);
  root -> left -> left -> right -> left = newNode(5);
  root -> left -> left -> right -> right = newNode(6);
  root -> right = newNode(7);
  root -> right -> right = newNode(8);
  root -> right -> right -> left = newNode(9);
  root -> right -> right -> left -> left = newNode(10);
  root -> right -> right -> left -> right = newNode(11);

  vector < int > boundaryTraversal;
  boundaryTraversal = printBoundary(root);

  cout << "The Boundary Traversal is : ";
  for (int i = 0; i < boundaryTraversal.size(); i++) {
    cout << boundaryTraversal[i] << " ";
  }
  return 0;
}