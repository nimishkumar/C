#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "string.h"

extern TreeNode *root;

int main(int argc, char *argv[]) {
	insertTree(5);
	displayTree();

	insertTree(3);
	insertTree(7);
	displayTree();

	insertTree(2);
	insertTree(4);
	insertTree(6);
	insertTree(8);
	displayTree();

	return 0;
}
