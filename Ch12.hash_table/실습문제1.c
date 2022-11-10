#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int n;
	struct node* next;
}node;

node *hash;
int m;

int h(int x) {
	return x % m;
}

void insert(int x) {
	int v = h(x);
	node* p = hash + v;
	node* nd = (node*)malloc(sizeof(node));
	nd->n = x;
	nd->next = NULL;
	if (p->next == NULL)
		p->next = nd;
	else {
		nd->next = p->next;
		p->next = nd;
	}
}

int search(int x) {
	int v = h(x);
	node* p = hash + v;
	int c = 0;
	if (p->next == NULL)
		return 0;
	else {
		while (1) {
			p = p->next;
			c++;
			if (p->n == x)
				return c;
			if (p->next == NULL)
				return 0;
		}
	}
}


int delete(int x) {
	int v = h(x), c = 0;

	struct node* pt = hash + v, * p = hash+ v;

	if (p->next == NULL) {

		return 0;

	}

	else {

		while (1) {

			p = p->next;

			c++;

			if (p->n == x) {

				while (pt->next != p) {

					pt = pt->next;

				}

				pt->next = p->next;

				

				return c;

			}

			if (p->next == NULL) {

				return 0;

			}

		}

	}
}

void print() {
	node* p;
	for (int i = 0; i < m; i++) {
		p = hash + i;
		if (p->next != NULL) {
			p = p->next;
			printf(" %d", p->n);
			while (p->next != NULL) {
				p = p->next;
				printf(" %d", p->n);
			}
		}
	}
	printf("\n");
}

int main()
{
	int k;
	char ch;

	scanf("%d", &m);
	hash = (node*)malloc(sizeof(node) * m);
	for (int i = 0; i < m; i++) {
		(hash + i)->n = NULL;
		(hash + i)->next = NULL;
	}

	while (1) {
		scanf("%c", &ch);
		if (ch == 'i') {
			scanf("%d", &k);
			insert(k);
			getchar();
		}
		else if (ch == 's') {
			scanf("%d", &k);
			printf("%d\n", search(k));
			getchar();
		}
		else if (ch == 'd') {
			scanf("%d", &k);
			printf("%d\n", delete(k));
			getchar();
		}
		else if (ch == 'p') {
			print();
			getchar();
		}
		else if (ch == 'e') {
			break;
		}
	}

	return 0;
}
