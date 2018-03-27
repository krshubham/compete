#include <bits/stdc++.h>
using namespace std;

typedef struct node{
	int data;
	struct node* next;
} Node;

Node* newNode(int data){
	Node* node = new Node;
	node->data = data;
	node->next = NULL;
	return node;
}

Node* insert(Node* head, int data){
	if(head == NULL) return newNode(data);
	Node* temp = head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = newNode(data);
	return head;
}

bool has_cycle(Node* head){
	Node* slow_p = head, fast_p = head;
	while (slow_p && fast_p && fast_p->next){
		slow_p = slow_p->next;
		fast_p  = fast_p->next->next;
		if (slow_p == fast_p){
			return true;
		}
	}
	return 0;
}
