#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

int* hash, m;



int h(int x, int m) {

	return x % m;

}



int getNextBucket(int v, int i) {

	return (v + i) % m;

}





void insertItem(int x) {

	int v = h(x, m), i = 0, b;

	while (i < m) {

		b = getNextBucket(v, i);

		if (hash[b] == 0) {

			hash[b] = x;

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



void searchItem(int x) {

	int v = h(x, m), i = 0, b;

	while (i < m) {

		b = getNextBucket(v, i);

		if (hash[b] == 0) {

			printf("-1\n");

			return;

		}

		else if (hash[b] == x) {

			printf("%d %d\n", b, hash[b]);

			return;

		}

		else {

			i = i + 1;

		}

	}

	printf("-1\n");

}



int main() {

	int n, key;

	char select;

	scanf("%d", &m);

	hash = (int*)malloc(sizeof(int) * m);

	for (int i = 0; i < m; i++) {

		*(hash + i) = 0;

	}

	scanf("%d", &n);

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

		}

		else if (select == 'e') {

			break;

		}

	}

	return 0;

}
