#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

TreeNode *root = NULL;

TreeNode* findMin(TreeNode *node) {
	while(node->left!=NULL)
		node = node->left;
	return node;
}

TreeNode* findMax(TreeNode *node) {
	while(node->left!=NULL)
		node = node->left;
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

TreeNode* removeHelper(TreeNode *node, int val) {
	TreeNode *temp;
	if(node==NULL) {
		return node;
	}
	else if(val < node->val) {
		node->left = removeHelper(node->left, val);
	}
	else if(val > node->val) {
		node->right = removeHelper(node->right, val);
	}
	else {
		if(node->left==NULL) {
			temp = node->right;
			free(node);
			return temp;
		}
		else if(node->right==NULL) {
			temp = node->left;
			free(node);
			return temp;
		}
		else {
			temp = findMin(node->right);
			node->val = temp->val;
			node->right = removeHelper(node->right, temp->val);
		}
	}
	return node;
}

int removeTree(int val) {
	root = removeHelper(root, val);
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
	if(depth==0) {
		if(!node)
			printf("  ");
		else
			printf("%d ", node->val);
		return;
	}
	if(!node)
		return;
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
