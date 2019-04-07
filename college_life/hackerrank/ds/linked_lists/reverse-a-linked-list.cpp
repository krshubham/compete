/*
  Reverse a linked list and return pointer to the head
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
#include <bits/stdc++.h>
using namespace std;

typedef struct node{
	int data;
	struct node *next;
} Node;

Node* Reverse(Node **head){
	if(*head == NULL) return NULL;
	else if((*head)->next == NULL) return *head;
	else{
		Node* prev   = NULL;
		Node* current = *head;
		Node* next;
		while (current != NULL){
			next  = current->next;  
			current->next = prev;   
			prev = current;
			current = next;
		}
		*head = prev;
	}
}

Node* newNode(int data){
	Node* temp = new Node;
	temp->data = data;
	temp->next = NULL;
	return temp;
}

Node* insert(Node *head, int data){
	if(head == NULL){
		return newNode(data);
	}
	Node* temp = head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = newNode(data);
	return head;
}

void print(Node* head){
	if(head == NULL){
		return;
	}
	cout<<head->data<<endl;
	print(head->next);
}


int main(int argc, char const *argv[]){
	Node *head = NULL;
	head = insert(head, 10);
	head = insert(head,20);
	head = insert(head,30);
	// print(head);
	Reverse(&head);
	print(head);
	return 0;
}