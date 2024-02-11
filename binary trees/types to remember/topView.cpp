#include <bits/stdc++.h>
using namespace std;

struct node {
  int data;
  struct node * left, * right;
};

vector<int> topView(node *root){
    vector<int> ans;
    queue<pair<node *, int>> q;
    map<int, int> mpp;
    q.push({root, 0});
    while(!q.empty()){
        auto temp = q.front();
        q.pop();
        node *node = temp.first;
        int x = temp.second;
        if(mpp.find(x) == mpp.end())    mpp[x] = node->data;
        if(node->left)  q.push({node->left, x-1});
        if(node->right)  q.push({node->right, x+1});
    }
    
    for(auto it:mpp){
        ans.push_back(it.second);
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
  root -> left = newNode(2);
  root -> left -> left = newNode(4);
  root -> left -> right = newNode(5);
  root -> left -> right -> left = newNode(6);
  root -> right = newNode(3);
  root -> right -> right = newNode(7);

  vector<int> top = topView(root);

  cout << "The topview is : " << endl;
  for (auto it: top) {
    cout<<it<<" ";
  }
  return 0;
}