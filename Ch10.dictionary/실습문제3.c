#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>


int main() {
    
    char *str;
    int a, b, n, m, k=0;

    scanf("%d %d %d", &a, &b, &n);
    getchar();
    str = (char*)malloc(sizeof(char) * (n + 1));
    gets(str);

    for (int i = 0; i < n; i++) {
        m = (a + b) / 2;
        if (str[i] == 'Y') {
            a = m + 1;
        }
        else if (str[i] == 'N') {
            b = m;
        }
        if (a == b) {
            k = a;
        }
    }

    printf("%d", k);

    return 0;
}
