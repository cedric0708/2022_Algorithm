#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

int m, n, q, * hash;

int h(int x) {

	return x % m;

}



int h2(int x) {

	return q - (x % q);

}



int getNextBucket(int v, int i, int k) {

	return(v + i * h2(k) % m) % m;

}





void insertItem(int k) {

	int v = h(k);

	int i = 0, b;

	while (i < m) {

		b = getNextBucket(v, i, k);

		if (hash[b] == 0) {

			hash[b] = k;

			for (int j = 0; j < i; j++) {

				printf("C");

			}

			printf("%d\n", b);

			return;

		}

		else {

			i = i + 1;

		}

	}

}



void searchItem(int k) {

	int v = h(k);

	int i = 0, b;

	while (i < m) {

		b = getNextBucket(v, i, k);

		if (hash[b] == 0) {

			printf("-1\n");

			return;

		}

		else if (hash[b] == k) {

			printf("%d %d\n", b, hash[b]);

			return;

		}

		else {

			i = i + 1;

		}

	}

	printf("-1\n");

}



void printTable() {

	for (int i = 0; i < m; i++) {

		printf(" %d", hash[i]);

	}

	printf("\n");

}



int main() {

	int key;

	char select;

	scanf("%d", &m);

	hash = (int*)malloc(sizeof(int) * m);

	for (int i = 0; i < m; i++) {

		*(hash + i) = 0;

	}

	scanf("%d", &n);

	scanf("%d", &q);

	while (1) {

		scanf("%c", &select);

		if (select == 'i') {

			scanf("%d", &key);

			insertItem(key);

			getchar();

		}

		else if (select == 's') {

			scanf("%d", &key);

			searchItem(key);

			getchar();

		}

		else if (select == 'p') {

			printTable();

			getchar();

		}

		else if (select == 'e') {

			printTable();

			break;

		}

	}

	return 0;

}
