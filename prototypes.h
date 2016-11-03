
#ifndef PROTOTYPES_H_INCLUDED
#define PROTOTYPES_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>

typedef struct _Node
{
    int data;
    struct _Node *left;
    struct _Node *right;
}
Node;

Node  *rt;
void Display(Node* root, int nivel);
Node *Add_Node(Node *root,int data);
void preorder (Node *root);
void inorder(Node *root);
void postorder(Node *root);
Node* FindMin(Node* root);
void Delete( Node *root, int data);



#endif // PROTOTYPES_H_INCLUDED
