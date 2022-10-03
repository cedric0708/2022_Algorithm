#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int findpivot(int *a, int l, int r) {
	srand((unsigned int)time(NULL));
	int i = (rand() % (r-l+1))+l;
	return i;
}

int inplacepartition(int *a, int l, int r, int k) {
	int p = a[k];
	int tmp;
	tmp = a[k];
	a[k] = a[r];
	a[r] = tmp;
	int i = l;
	int j = r - 1;
	while (i <= j) {
		while (i <= j && a[i] <= p)
			i = i + 1;
		while (j >= i && a[j] >= p)
			j = j - 1;
		if (i < j) {
			tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
		}
	}
	tmp = a[i];
	a[i] = a[r];
	a[r] = tmp;

	return i;
}

void inplacequicksort(int* a, int l, int r) {
	if (l >= r)
		return;
	int k = findpivot(a, l, r);
	int m = inplacepartition(a, l, r, k);
	int n = inplacepartition(a, l, r, k);
	inplacequicksort(a, l, m - 1);
	inplacequicksort(a, n + 1, r);
}


int main()
{
	int* a;
	int n;
	scanf("%d", &n);
	a = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	inplacequicksort(a, 0, n - 1);
	
	for (int i = 0; i < n; i++)
		printf(" %d", a[i]);

	return 0;
}
