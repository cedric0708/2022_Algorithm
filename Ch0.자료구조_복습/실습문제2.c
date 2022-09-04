#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct treenode {
	int data;
	struct treenode* left, * right;
}treenode;

treenode* makenode(int data) {
	treenode* node = (treenode*)malloc(sizeof(treenode));
	node->data = data;
	node->left = node->right = NULL;

	return node;
}

treenode* findnode(treenode* root, int data) {
	treenode* p;

	if (root == NULL)
		return NULL;

	if (root->data == data)
		return root;

	p = findnode(root->left, data);
	if (p)
		return p;

	return findnode(root->right, data);
}

void connectnode(treenode* root, int d, int l, int r) {
	treenode* p = findnode(root, d);

	if (l != 0)
		p->left=makenode(l);
	if (r != 0)
		p->right=makenode(r);
}

treenode* maketree() {
	int n, d, l, r;
	treenode* root;

	scanf("%d", &n);
	scanf("%d %d %d", &d, &l, &r);

	root = makenode(d);
	root->left = makenode(l);
	root->right = makenode(r);

	for (int i = 1; i < n; i++) {
		scanf("%d %d %d", &d, &l, &r);
		connectnode(root, d, l, r);
	}

	return root;
}

void traversal(treenode* root, char* str) {
	printf(" %d", root->data);

	if (*str) {
		if (*str == 'L')
			traversal(root->left, str + 1);
		else if (*str == 'R')
			traversal(root->right, str + 1);
	}
}

int main()
{
	treenode* root = maketree();

	int n;
	char str[101];

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", str);
		traversal(root, str);
		printf("\n");
	}


	return 0;
}
