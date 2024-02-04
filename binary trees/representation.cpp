#include<stdio.h>

// Type 1 
// struct Node{
//     int data;
//     Node *left;
//     Node *right;
//     Node(value){
//         data = value;
//         left = right = Null;
//     }   
// }

// int main(){
//     struct Node* root = new Node(1);
//     root->left = new Node(2);
//     root->right = new Node(3);
// }

// Type 2 representation

struct node{
    int data;
    struct node *left, *right;
}

struct node *newNode(int data){
    struct node *node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = Null;
    node->right = Null;
    return  node;
}

