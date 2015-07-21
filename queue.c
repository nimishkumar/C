#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

QueueNode *first = NULL;
QueueNode *last = NULL;

void enqueue(int val) {
	QueueNode *newNode = (QueueNode*)malloc(sizeof(QueueNode));
	newNode->val = val;
	newNode->next = NULL;
	if(first==NULL) {
		last = newNode;
		first = last;
	}
	else {
		last->next = newNode;
		last = last->next;
	}
}

int dequeue(void) {
	int ret;
	QueueNode *temp;
	if(first==NULL) {
		return -1;
	}
	temp = first;
	first = first->next;
	ret = temp->val;
	free(temp);
	return ret;
}

void displayQueue(void) {
	QueueNode *curr = first;
	if(curr==NULL) {
		printf("Queue is empty\n");
		return;
	}
	printf("Queue elements are: ");
	while(curr) {
		printf("%d", curr->val);
		if(curr->next)
			printf("->");
		curr = curr->next;
	}
	printf("\n");
}
