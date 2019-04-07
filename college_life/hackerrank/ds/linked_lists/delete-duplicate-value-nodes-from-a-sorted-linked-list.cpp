#include <bits/stdc++>h>
using namespace std;
/*
  Remove all duplicate elements from a sorted linked list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
typedef struct node {
	int data;
	struct node *next;
} Node;

Node* newNode(int data){
	Node* node = new Node;
	node->data = data;
	node->next = NULL;
	return node;
}

Node* insert(Node*head, int data){
	if(head == NULL) return newNode(data);
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

Node* RemoveDuplicates(Node *head){
	if(head == NULL) return NULL;
	Node* current = head;
	Node* next;
	while(current->next != NULL){
		if(current->data == current->next->data){
			next = current->next->next;
			delete current->next;
			current->next = next;
		}
		else{
			current = current->next;
		}
	}
	return head;
}



int main(int argc, char const *argv[]){
	
	return 0;
}