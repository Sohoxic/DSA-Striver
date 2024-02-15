#include <bits/stdc++.h>

using namespace std;

struct node {
  int data;
  struct node * left, * right;
};

int widthOfBinaryTree(node * root) {
  if(!root) return 0;
  int ans=0;
  queue<pair<node*, int>> q;
  q.push({root, 0});
  while(!q.empty()){
    int size = q.size();
    int curmin = q.front().second;
    int leftMost, rightMost;
    for(int i=0; i<size; i++){
        int curId = q.front().second - curmin;
        node *temp = q.front().first;
        q.pop();
        if (i == 0) leftMost = curId;
        if (i == size - 1) rightMost = curId;
        if(temp->left)  q.push({temp->left, curId*2+1});
        if(temp->right)  q.push({temp->right, curId*2+2});
    }
    ans = max(ans, rightMost-leftMost+1);
  }
  return ans;
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
  root -> left = newNode(3);
  root -> left -> left = newNode(5);
  root -> left -> left -> left = newNode(7);
  root -> right = newNode(2);
  root -> right -> right = newNode(4);
  root -> right -> right -> right = newNode(6);

  int maxWidth = widthOfBinaryTree(root);
  cout << "The maximum width of the Binary Tree is " << maxWidth;

  return 0;
}