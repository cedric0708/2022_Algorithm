#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int rfindelement(int *a, int k, int l, int r) {
	int min = 10000;
	int idx=0, cnt = 0;
	if (l > r)
		return -1;
	for (int i = 0; i <= r; i++) {
		if (a[i] == k) {
			return i;
		}
		if (a[i] < min && a[i]>=k) {
			min = a[i];
			idx = i;
			cnt++;
		}
	}
	if (cnt == 0)
		return r+1;
	else
		return idx;
}

int findelement(int *a, int n, int k) {
	return rfindelement(a, k, 0, n - 1);
}

int main()
{
	int n, k;
	int* a;
	scanf("%d %d", &n, &k);
	a = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	printf(" %d", findelement(a, n, k));

	return 0;
}
