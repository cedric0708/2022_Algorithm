#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n;

typedef struct listnode {
	int elem;
	struct listnode* next;
}listnode;

typedef struct listype {
	listnode* h;
}listype;

void init(listype* l) {
	l->h = NULL;
}

int isempty(listype* l) {
	return l->h == NULL;
}

int listsize(listype* l) {
	listnode* p = l->h;
	int c = 0;
	if (p == NULL)
		return 0;
	else {
		while (p->next != NULL) {
			p = p->next;
			c++;
		}
		return c+1;
	}
}

int get(listype *l, int pos) {
	listnode* p = l->h;
	return p->elem;
}

void insertlast(listype* l, int e) {
	listnode* node = (listnode*)malloc(sizeof(listnode));
	node->elem = e;
	node->next = NULL;

	listnode* p = l->h;
	if (p == NULL)
		l->h = node;
	else {
		while (p->next != NULL)
			p = p->next;
		p->next = node;
	}
}//맨 뒤에 삽입

int deletefirst(listype* l) {
	listnode* p = l->h;

	int e = p->elem;
	l->h = p->next;
	free(p);
	return e;
}//맨 앞 삭제

void partition(listype* l, listype* l1, listype* l2, int n) {
	listnode* p = l->h;

	l1 = l;

	for (int i = 0; i < (n / 2) - 1; i++) {

		p = p->next;

	}

	l2 = p->next;

	p->next = NULL;
}


listype* merge(listype *l1, listype *l2) {
	listype L;
	init(&L);
	while (!isempty(l1) && !isempty(l2)) {
		if (get(l1, 1) <= get(l2, 1))
			insertlast(&L, deletefirst(l1));
		else
			insertlast(&L, deletefirst(l2));
	}
	while(!isempty(l1))
		insertlast(&L, deletefirst(l1));
	while (!isempty(l2))
		insertlast(&L, deletefirst(l2));
	return &L;
}

void mergesort(listype *l) {
	listype l1, l2;
	init(&l1);
	init(&l2);
	if (listsize(l) > 1) {
		partition(l, &l1, &l2, n);
		mergesort(&l1);
		mergesort(&l2);
		l = merge(&l1, &l2);
	}
}

void print(listype* l) {
	for (listnode* p = l->h; p->next != NULL; p = p->next)
		printf(" %d", p->elem);
}


int main()
{
	listype l;
	init(&l);
	int d;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &d);
		insertlast(&l, d);
	}
	mergesort(&l);

	return 0;
}
