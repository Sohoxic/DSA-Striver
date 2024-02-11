#include <bits/stdc++.h>
using namespace std;

struct node {
  int data;
  struct node * left, * right;
};

vector <int> bottomView(node *root) {
        vector<int> ans; 
        if(root == NULL) return ans; 
        map<int,int> mpp; 
        queue<pair<node*, int>> q; 
        q.push({root, 0}); 
        while(!q.empty()) {
            auto it = q.front(); 
            q.pop(); 
            node* node = it.first; 
            int line = it.second; 
            mpp[line] = node->data; 
            
            if(node->left != NULL) {
                q.push({node->left, line-1}); 
            }
            if(node->right != NULL) {
                q.push({node->right, line + 1}); 
            }
            
        }
        
        for(auto it : mpp) {
            ans.push_back(it.second); 
        }
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
  root -> left -> right = newnode(5);
  root -> left -> right -> left = newnode(8);
  root -> left -> right -> right = newnode(9);
  root -> right = newnode(3);
  root -> right -> left = newnode(6);
  root -> right -> right = newnode(7);

  vector<int> bottom = bottomView(root);

  cout << "The bottomView is : " << endl;
  for (auto it: bottom) {
    cout<<it<<" ";
  }
  return 0;
}