#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

TreeNode *root = NULL;

TreeNode* findMin(TreeNode *node) {
	if(!node)
		return NULL;
	if(node->left)
		return findMin(node->left);
	return node;
}

TreeNode* findMax(TreeNode *node) {
	if(!node)
		return NULL;
	if(node->right)
		return findMax(node->right);
	return node;
}

int max(int a, int b) {
	return (a > b ? a : b);
}

int findDepth(TreeNode *root, int depth) {
	if(!root) {
		return depth;
	}
	return max(findDepth(root->left, depth+1), findDepth(root->right, depth+1));
}

void insertTree(int val) {
	TreeNode *newNode = (TreeNode*)malloc(sizeof(TreeNode));
	TreeNode *curr = root;
	newNode->val = val;
	newNode->left = NULL;
	newNode->right = NULL;
	while(curr) {
		if(val >= curr->val) {
			if(curr->right)
				curr = curr->right;
			else {
				curr->right = newNode;
				return;
			}
		}
		else {
			if(curr->left)
				curr = curr->left;
			else {
				curr->left = newNode;
				return;
			}
		}
	}
	root = newNode;
}

int removeTree(int val) {
	return 0;
}

void displayLevel(TreeNode *node, int depth) {
	if(!node)
		return;
	if(depth==0) {
		printf("%d ", node->val);
		return;
	}
	displayLevel(node->left, depth-1);
	displayLevel(node->right, depth-1);
}

void displayTree(void) {
	int i, j;
	int depth = findDepth(root, 0);
	printf("Depth: %d\n", depth);
	for(i=0; i<depth; i++) {
		for(j=0; j<depth-i-1; j++) {
			printf("  ");
		}
		displayLevel(root, i);
		printf("\n");
	}
}
