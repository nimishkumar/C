#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "node.h"
#include "stack.h"
#include "queue.h"

extern QueueNode *first;
extern QueueNode *last;

int main(int argc, char *argv[]) {
	enqueue(5);
	enqueue(4);
	enqueue(3);
	enqueue(2);
	enqueue(1);
	displayQueue();

	dequeue();
	dequeue();
	displayQueue();

	dequeue();
	dequeue();
	dequeue();
	displayQueue();

	dequeue();
	displayQueue();

	return 0;
}
