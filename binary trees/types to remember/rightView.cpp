#include <bits/stdc++.h>
using namespace std;

struct node {
  int data;
  struct node * left, * right;
};

void solve(node* root, int level, vector<int> &ans){
    if(root == NULL) return;
    if(ans.size()==level) ans.push_back(root->data);

    solve(root->right, level+1, ans);
    solve(root->left, level+1, ans);
}

vector <int> rightView(node *root) {
        vector<int> ans; 
        solve(root, 0, ans);
        return ans;  
    }

struct node * newnode(int data) {
  struct node * node = (struct node * ) malloc(sizeof(struct node));
  node -> data = data;
  node -> left = NULL;
  node -> right = NULL;

  return (node);
}

int main() {

  struct node * root = newnode(1);
  root -> left = newnode(2);
  root -> left -> left = newnode(4);
  root -> left -> right = newnode(6);
  root -> right = newnode(3);

  vector<int> right = rightView(root);

  cout << "The rightView is : " << endl;
  for (auto it: right) {
    cout<<it<<" ";
  }
  return 0;
}