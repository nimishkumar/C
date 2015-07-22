#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "tree.h"

extern TreeNode *root;

int main(int argc, char *argv[]) {
	insertTree(4);
	displayTree();

	insertTree(2);
	insertTree(6);
	displayTree();

	insertTree(1);
	insertTree(3);
	insertTree(5);
	insertTree(10);
	displayTree();

	insertTree(20);
	displayTree();

	return 0;
}
