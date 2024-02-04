#include<stdio.h>

struct Node{
    int data;
    Node *left;
    Node *right;
    Node(value){
        data = value;
        left = right = Null;
    }   
}

int main(){
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
}