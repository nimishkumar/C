#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "node.h"

int main(int argc, char *argv[]) {
	int num1, num2;
	char *buf = (char*)calloc(MAX_SIZE, sizeof(char));
	printf("Enter number 1: ");
	fgets(buf, MAX_SIZE, stdin);
	trim(buf);
	num1 = my_atoi(buf);

	printf("Enter number 2: ");
	fgets(buf, MAX_SIZE, stdin);
	trim(buf);
	num2 = my_atoi(buf);

	Node *head1 = list_from_num(num1);
	Node *head2 = list_from_num(num2);

	Node *sum = sum_lists_reverse(head1, head2);

	print_list(head1);
	print_list(head2);
	print_list(sum);

	return 0;
}
