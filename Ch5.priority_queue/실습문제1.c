#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	int *data;
}queue;

void array(queue* q, int n) {
	int index = 0, tmp = 0;
	for (int i = n-1; i > 0; i--) {
		int max = 0;
		for (int j = 0; j <= i; j++) {
			if (q->data[j] > max) {
				max = q->data[j];
				index = j;
			}
		}
		if (index == i)
			continue;
		else {
			tmp = q->data[i];
			q->data[i] = q->data[index];
			q->data[index] = tmp;
		}
	}
}

int main()
{
	queue q;
	int n, d;

	scanf("%d", &n);
	q.data = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &d);
		q.data[i] = d;
	}
	array(&q, n);

	for (int i = 0; i < n; i++)
		printf(" %d", q.data[i]);

	return 0;
}
