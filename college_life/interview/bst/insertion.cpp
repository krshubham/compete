/*
* @Author: krshubham
* @Date:   2018-03-23 20:36:55
* @Last Modified by:   Kumar Shubham
* @Last Modified time: 2018-03-23 21:05:21
*/
#include <bits/stdc++.h>
using namespace std;

typedef struct node{
	int data;
	struct node *left,*right;
} Node;

Node* newNode(int data){
	Node* node = new Node;
	node->left = node->right = NULL;
	node->data = data;
	return node;
}

Node* insert(Node* root, int data){
	if(root == NULL) return newNode(data);
	if(data < root->data){
		root->left = insert(root->left, data);
	}
	else if(data > root->data){
		root->right = insert(root->right, data);
	}
	return root;
}

void inorder(Node* root){
	if(root == NULL) return;
	inorder(root->left);
	cout<<root->data<<endl;
	inorder(root->right);
}

Node* deleteNode(Node* root, int data){
	if(root == NULL) return root;
	if(data < root->data){
		root->left = deleteNode(root->left, data);
	}
	else if(data > root->data){
		root->right = deleteNode(root->right, data);
	}
	else{
		if(root->left == NULL){
			Node* temp = root->right;
			delete root;
			return temp;
		}
		else if(root->right == NULL){
			Node* temp = root->left;
			delete root;
			return temp;
		}
		Node* temp = minValueNode(root->right);
		root->key = temp->key;
		
	}
}