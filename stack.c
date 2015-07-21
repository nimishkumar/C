#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

StackNode *top = NULL;

void push(int val) {
	StackNode *temp = (StackNode*)malloc(sizeof(StackNode));
	temp->val = val;
	if(top==NULL) {
		top = temp;
		top->next = NULL;
	}
	else {
		temp->next = top;
		top = temp;
	}
}

int pop(void) {
	int ret;
	StackNode *temp;
	if(top==NULL)
		return -1;
	temp = top;
	ret = temp->val;
	top = temp->next;
	free(temp);
	return ret;
}

void displayStack(void) {
	StackNode *curr = top;

	if(!curr) {
		printf("Stack is empty\n");
		return;
	}
	printf("Stack elements are: ");
	while(curr) {
		printf("%d", curr->val);
		if(curr->next)
			printf("->");
		curr = curr->next;
	}
	printf("\n");
}
