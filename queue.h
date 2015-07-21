#ifndef QUEUE_H_
#define QUEUE_H_

typedef struct QueueNode {
	struct QueueNode *next;
	int val;
} QueueNode;

void enqueue(int val);

int dequeue(void);

void displayQueue(void);

#endif
