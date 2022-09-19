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

void insertitem(int key) {
	n += 1;
	h[n] = key;
	upheap(n);
}

int removemax() {
	int key;
	key = h[1];
	h[1] = h[n];
	n -= 1;
	downheap(1);

	return key;
}

void printheap() {
	for (int i = 1; i <= n; i++)
		printf(" %d", h[i]);
	printf("\n");
}

int main()
{
	char ch;
	int d;

	while (1) {
		scanf("%c", &ch);
		getchar();
		if (ch == 'q')
			break;
		else if (ch == 'i') {
			scanf("%d", &d);
			getchar();
			insertitem(d);
			printf("0\n");
		}
		else if (ch == 'd') {
			printf("%d\n", removemax());
		}
		else if (ch == 'p') {
			printheap();
		}
	}

	return 0;
}
