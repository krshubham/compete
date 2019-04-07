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

int CompareLists(Node *headA, Node* headB){
	if(headA == NULL && headB == NULL) return 1;
	else if(headA == NULL) return 0;
	else if(headB == NULL) return 0;
	while(1){
		if(headA->data != headB->data){
			return 0;
		}
		if(headA->next == NULL && headB->next != NULL){
			return 0;
		}
		else if(headA->next != NULL && headB->next == NULL){
			return 0;
		}
		else if(headA->next == NULL && headB->next == NULL){
			break;
		}
		else{
			headA = headA->next;
			headB = headB->next;
		}
	}
	return 1;
}

Node* MergeLists(Node *headA, Node* headB){
	
}


int main(int argc, char const *argv[]){
	Node *heada = NULL;
	heada = insert(heada, 10);
	heada = insert(heada,20);
	// print(head);
	// Reverse(&head);
	print(heada);
	cout<<"-------"<<endl;
	Node* headb = NULL;
	headb = insert(headb, 10);
	headb = insert(headb, 20);
	headb = insert(headb, 30);
	print(headb);
	// cout<<CompareLists(heada,headb)<<endl;
	return 0;
}