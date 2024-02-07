#include<bits/stdc++.h>

using namespace std;

class Node {
  public:
    int val;
  Node * left, * right;
};

vector < vector < int >> zigzagLevelOrder(Node * root) {
  vector < vector < int >> result;
  if(root == NULL) return result;
  queue<Node *> q;
  q.push(root);
  bool left2right = true;

  while(!q.empty()){
    int size = q.size();
    vector<int> levelwiseelements(size);
    for(int i = 0; i<size; i++){
        Node * temp = q.front();
        q.pop();
        // position to insert element
        int index = left2right ? i : size-1-i;
        levelwiseelements[index] = temp->val;
        if(temp->left)  q.push(temp->left);
        if(temp->right)  q.push(temp->right);
    }

    left2right = !left2right;
    result.push_back(levelwiseelements);

  }

  return result;
}
Node * newNode(int data) {
  Node * node = new Node;
  node -> val = data;
  node -> left = NULL;
  node -> right = NULL;
  return node;
}
int main() {
  int i, j;
  Node * root = newNode(3);
  root -> left = newNode(9);
  root -> right = newNode(20);
  root -> right -> left = newNode(15);
  root -> right -> right = newNode(7);
  vector < vector < int >> ans;
  ans = zigzagLevelOrder(root);
  cout << "Zig Zag Traversal of Binary Tree" << endl;
  for (i = 0; i < ans.size(); i++) {
    for (j = 0; j < ans[i].size(); j++) {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}