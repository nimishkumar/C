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

TreeNode* insert(TreeNode *node, TreeNode *newNode) {
	if(node==NULL) {
		return newNode;
	}
	if(newNode->val < node->val)
		node->left = insert(node->left, newNode);
	else
		node->right = insert(node->right, newNode);
	return node;
}

void insertTree(int val) {
	TreeNode *newNode = (TreeNode*)malloc(sizeof(TreeNode));
	newNode->val = val;
	newNode->left = NULL;
	newNode->right = NULL;

	root = insert(root, newNode);
}

int removeTree(int val) {
	return 0;
}

int lookup(TreeNode *node, int val) {
	if(node == NULL) return -1;
	if(node->val == val)
		return 0;
	if(val < node->val)
		return lookup(node->left, val);
	return lookup(node->right, val);
}

int lookupTree(int val) {
	return lookup(root, val);
}

int size(TreeNode *node) {
	if(node==NULL)
		return 0;
	return 1+size(node->left)+size(node->right);
}

int sizeTree(void) {
	return size(root);
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
	printf("Depth: %d, size: %d\n", depth, sizeTree());
	for(i=0; i<depth; i++) {
		for(j=0; j<depth-i-1; j++) {
			printf("  ");
		}
		displayLevel(root, i);
		printf("\n");
	}
}
