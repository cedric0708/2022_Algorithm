#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct listnode {
	int elem;
	struct listnode* next;
}listnode;

void insertlast(listnode** l, int e) {
	listnode* node = (listnode*)malloc(sizeof(listnode));
	node->elem = e;
	node->next = NULL;

	listnode* p = *l;
	if (*l == NULL)
		*l = node;
	else {
		while (p->next != NULL)
			p = p->next;
		p->next = node;
	}
}

void partition(listnode* l, listnode** l1, listnode** l2, int n) {
	listnode* p = l;
	*l1 = l;

	for (int i = 0; i < (n / 2) - 1; i++) {
		p = p->next;
	}
	
	*l2 = p->next;
	p->next = NULL;
}

listnode* merge(listnode** l1, listnode** l2) {
	listnode *L, *p, *a=*l1, *b=*l2;
	if (a->elem <= b->elem) {
		L = a;
		a = a->next;
		p = L;
	}
	else {
		L = b;
		b = b->next;
		p = L;
	}
	while (a!=NULL && b!=NULL) {
		if (a->elem <= b->elem) {
			p->next = a;
			a = a->next;
			p = p->next;
		}
		else
		{
			p->next = b;
			b = b->next;
			p = p->next;
		}
	}
	while (a != NULL)
	{
		p->next = a;
		a = a->next;
		p = p->next;
	}
	while (b != NULL)
	{
		p->next = b;
		b = b->next;
		p = p->next;
	}
	return L;
}

void mergesort(listnode** l, int n) {
	listnode *l1, *l2, *p=*l;
	if (n > 1) {
		partition(p, &l1, &l2, n);
		if (n % 2 == 0) {
			mergesort(&l1, n / 2);
			mergesort(&l2, n / 2);
		}
		else {
			mergesort(&l1, n / 2);
			mergesort(&l2, (n / 2) + 1);
		}
		*l = merge(&l1, &l2);
	}
}

void print(listnode* l) {
	listnode* p = l;
	while (p != NULL) {
		printf(" %d", p->elem);
		p = p->next;
	}
}


int main()
{
	listnode *l=NULL;
	int n, d;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &d);
		insertlast(&l, d);
	}
	mergesort(&l, n);
	print(l);

	return 0;
}
