#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node* next;
} node1;

node1* newnode(int data){
	node1*temp=(node1*)malloc(sizeof(node1));
	temp->data=data;
	temp->next=NULL;
	return temp;
}
node1* insert(node1*head,int data){
	if(head==NULL){
		return(newnode(data));
	}
	node1*temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=newnode(data);
	return head;
}
void display(node1*head){
	if(head==NULL){
		return;
	}
	display(head->next);
	printf("%d\n",head->data);
}
void search(node1*head,int data){
	if(head==NULL){
		printf("the list is empty\n");
	}
	if(head->data==data){// you had done head->data = data;
		printf("yes it is there in list\n");
		return;
	}
	else{
		printf("not in the list\n");
	}
}
node1* delete(node1*head,int data){
	if(head==NULL){
		printf("list is empty");
	}
	if(head->data==data){
		node1*temp=head->next;
		free(head);
		return temp;
	}
	node1* temp=head;
	node1* prev=NULL;
	while(temp!=NULL&&temp->data!=data){
		prev=temp;
		temp=temp->next;
	}
	if(temp!=NULL){
		prev->next=temp->next;
		free(temp);
	}
	return head;
}

int main(){
	node1*head=NULL;
	head=insert(head,456);
	head=insert(head,25);
	head=insert(head,9887);
	head=delete(head,25);
	display(head);
	search(head,95);
}