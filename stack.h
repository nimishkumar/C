#ifndef STACK_H_
#define STACK_H_

typedef struct StackNode {
	struct StackNode *next;
	int val;
} StackNode;

void push(int val);

int pop(void);

void displayStack(void);

#endif
