#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int h[100] = { 0 };
int n = 0;

void upheap(int i) {
	if (i == 1)
		return;
	if (h[i] <= h[i / 2])
		return;
	int tmp = h[i];
	h[i] = h[i / 2];
	h[i / 2] = tmp;
	upheap(i / 2);
}

void downheap(int i) {
	if ((2 * i) > n && (2 * i + 1) > n) {
		return;
	}
	int s = 2 * i;
	if ((2 * i + 1) <= n) {
		if (h[2 * i + 1] > h[s])
			s = 2 * i + 1;
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

void insertitem(int key) {
	n += 1;
	h[n] = key;
	upheap(n);
}

void inplaceheapsort() {
	int tmp;
	buildheap();
	for (int i = 1; i <= n-1; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (h[i] > h[j]) {
				tmp = h[i];
				h[i] = h[j];
				h[j] = tmp;
			}
		}
	}
}

void printarray() {
	for (int i = 1; i <= n; i++)
		printf(" %d", h[i]);
}

int main()
{
	int d;

	scanf("%d", &d);
	n = d;

	for (int i = 1; i <= d; i++) {
		scanf("%d", &h[i]);
	}

	inplaceheapsort();
	printarray();

	return 0;
}
