#ifndef TREE_H_
#define TREE_H_

typedef struct TreeNode {
	struct TreeNode *left;
	struct TreeNode *right;
	int val;
} TreeNode;

#endif

void insertTree(int val);

int removeTree(int val);

void displayTree(void);
