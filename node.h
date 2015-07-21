#ifndef HEAP_H_
#define HEAP_H_

typedef struct Node {
	struct Node *next;
	int val;
} Node;

Node* init_node(int val);

Node* sum_lists_reverse(Node *head1, Node *head2);

Node* list_from_num(int num);

Node* reverse_list_from_num(int num);

void print_list(Node *head);

#endif
