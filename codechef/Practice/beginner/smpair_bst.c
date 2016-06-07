#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
}

struct node* getNewNode(int data){
	struct node *newNode;
	newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}
struct node* insert(struct node * root,int data){
	if(root==NULL){
		root = getNewNode(int data);
	}
	else if(data<=root->data){
		root->left = insert(root->left,data);
	}
	else{
		root->right = insert(root->right,data);
	}
	return root;
}

