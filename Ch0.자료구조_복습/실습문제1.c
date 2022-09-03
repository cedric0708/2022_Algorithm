#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
	char data;
	struct node* prev, * next;
}node;

void init(node* h, node* t) {
	h->next = t;
	t->prev = h;
}

int count(node * h, node* t) {
	int n = 0;
	for (node* p = h->next; p != t; p = p->next) {
		n++;
	}

	return n;
}

void add(node* p, int r, char e) {
	node* q = p;
	for (int i = 1; i < r; i++)
		q = q->next;
	node* n = (node*)malloc(sizeof(node));
	n->data = e;
	n->prev = q;
	n->next = q->next;
	q->next->prev = n;
	q->next = n;
}

void delete(node* p, int r) {
	node* q = p;
	for (int i = 1; i <= r; i++)
		q = q->next;
	q->prev->next = q->next;
	q->next->prev = q->prev;
	free(q);
}

void get(node* p, int r) {
	node* q = p;
	for (int i = 0; i < r; i++)
		q = q->next;
	char e = q->data;
	printf("%c\n", e);
}

void print(node* h, node*t) {
	for (node* q = h->next; q!=t; q = q->next)
		printf("%c", q->data);
	printf("\n");
}

int main()
{
	node* h = (node*)malloc(sizeof(node));
	node* t = (node*)malloc(sizeof(node));

	init(h, t);

	int i, r, d, n;
	char c, e;

	scanf("%d", &d);
	getchar();

	for (i = 0; i < d; i++) {
		scanf("%c", &c);
		getchar();
		n = count(h, t);
		if (c == 'A') {
			scanf("%d %c", &r, &e);
			getchar();
			if (r<1 || r>n + 1)
				printf("invalid position\n");
			else
				add(h, r, e);
		}
		else if (c == 'D') {
			scanf("%d", &r);
			getchar();
			if (r<1 || r>n)
				printf("invalid position\n");
			else
				delete(h, r);
		}
		else if (c == 'G') {
			scanf("%d", &r);
			getchar();
			if (r<1 || r>n)
				printf("invalid position\n");
			else
				get(h, r);
		}
		else if(c=='P'){
			print(h, t);
		}
	}

	return 0;
}
