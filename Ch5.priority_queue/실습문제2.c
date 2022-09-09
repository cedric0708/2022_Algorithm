#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	int *data;
}queue;

void array(queue* q, int n) {
	int tmp = 0,num=0;
	for(int i=1; i<n; i++){
		num = q->data[i];
		for (int j = i-1; j >= 0; j--) {
			if (num < q->data[j]) {
				tmp = q->data[j];
				q->data[j] = num;
				q->data[j+1] = tmp;
			}
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
