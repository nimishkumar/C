#include "node.h"
#include <stdio.h>
#include <stdlib.h>

Node* init_node(int val) {
	Node *new_node = (Node*)malloc(sizeof(Node));
	new_node->val = val;
	new_node->next = NULL;
	return new_node;
}

Node* sum_lists_reverse(Node *head1, Node *head2) {
	Node *sum_head, *curr;
	int carry = 0, sum, iter = 0;

	while(head1) {
		sum = head1->val+head2->val+(carry/10);
		carry = sum - (sum%10);
		if(iter==0) {
			curr = init_node(sum%10);
			sum_head = curr;
			iter++;
		}
		else {
			curr->next = init_node(sum%10);
			curr = curr->next;
		}
		head1 = head1->next;
		head2 = head2->next;
	}
	if(carry)
		curr->next = init_node(carry/10);
	return sum_head;
}

Node* list_from_num(int num) {
	Node *head = init_node(num%10);
	Node *curr = head;
	while(num/10>0) {
		num = num/10;
		curr->next = init_node(num%10);
		curr = curr->next;
	}
	return head;
}

Node* reverse_list_from_num(int num) {
	Node *head;
	int i=num, j=1;
	if(num/10==0) {
		head = init_node(num);
		return head;
	}
	while(i/10>0) {
		i = i/10;
		j = j*10;
	}
	head = init_node(i);
	head->next = list_from_num(num-(i*j));
	return head;
}

void print_list(Node *head) {
	while(head) {
		printf("%d, ", head->val);
		head = head->next;
	}
	printf("\n");
}
