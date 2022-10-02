#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n;

void merge(int *a, int *b, int l, int m, int r) {
	int i, j, k;
	i = l, k = l, j = m + 1;
	while (i <= m && j <= r) {
		if (a[i] <= a[j]) {
			b[k++] = a[i++];
		}
		else {
			b[k++] = a[j++];
		}
	}
	while (i <= m) {
		b[k++] = a[i++];
	}
	while (j <= r) {
		b[k++] = a[j++];
	}
	for (int v = l; v <= r; v++)
		a[v] = b[v];
}

void rmergesort(int *a, int*b, int l, int r) {
	if (l < r) {
		int m = (l + r) / 2;
		rmergesort(a,b,  l, m);
		rmergesort(a,b,  m + 1, r);
		merge(a,b,  l, m, r);
	}
	else
		return;
}

void mergesort(int*a, int n) {
	int* b = (int*)malloc(sizeof(int) * n);
	rmergesort(a, b, 0, n - 1);
}

int main()
{
	scanf("%d", &n);
	int* a = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	mergesort(a, n);
	for (int i = 0; i < n; i++)
		printf(" %d", a[i]);

	return 0;
}
