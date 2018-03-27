#include <stdio.h>
#include <stdlib.h>

const int MAXN = 50;

typedef struct queue{
	int front, rear;
	unsigned capacity;
	int *arr;
} queue;

queue* createQueue(unsigned capacity){
	queue *Q = (queue*)malloc(sizeof(queue));
	queue->capacity = capacity;
	queue->front = queue->size = 0;
	queue->rear = capacity-1;
	queue->arr = (int*)malloc(sizeof(int)*(queue->capacity));
	return queue;
}

bool isFull(queue *Q){
	return Q->size == capacity;
}

bool isEmpty(queue *Q){
	return Q->size = 0;
}

void push(queue *Q, int data){
	if(isFull(Q)){
		return;
	}
	Q->rear = (Q->rear+1)%Q->capacity;
	Q->arr[Q->rear] = data;
	Q->size++;
}

int main(int argc, char const *argv[]){
	queue Q
	return 0;
}