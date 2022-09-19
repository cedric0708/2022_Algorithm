#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int h[100] = { 0 };
int n=0;

int isexternal(int idx) {
	return (2 * (idx) > n);
}

void downheap(int i) {
	if ((2*i)>n&&(2*i+1)>n) {
		return;
	}
	int s = 2 * i;
	if ((2*i+1)<=n) {
		if (h[2 * i+1] > h[s])
			s = 2 * i+1;
	}
	if (h[i] >= h[s])
		return;
	int tmp = h[i];
	h[i] = h[s];
	h[s] = tmp;
	downheap(s);
}


void rbuildheap(int i) {
	if (i > n)
		return;
	rbuildheap(2 * i);
	rbuildheap(2 * i + 1);
	downheap(i);
}

void buildheap() {
	for (int i = n / 2; i >= 1; i--)
		downheap(i);
}

void printheap() {
	for (int i = 1; i <= n; i++)
		printf(" %d", h[i]);
	printf("\n");
}

int main()
{
	int d;
	scanf("%d", &d);
	n = d;

	for (int i = 1; i <= d; i++) {
		scanf("%d", &h[i]);
	}
	rbuildheap(1);
	printheap();

	return 0;
}
