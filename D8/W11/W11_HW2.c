#include <stdio.h>

/* 配列 v の要素数 n の順序を反転 */
void rev_intary(int v[], int n) {
    for (int i = 0; i < n/2; i++) {
        int tmp = v[i];
        v[i] = v[n-1-i];
        v[n-1-i] = tmp;
    }
}

int main(void) {
    int v[] = {7, 2, 3, 4, 5, 9};
    int n = sizeof(v) / sizeof(v[0]);
    rev_intary(v, n);
    printf("reversed:");
    for (int i = 0; i < n; i++) {
        printf(" %d", v[i]);
    }
    printf("\n");  /* 実行例: reversed: 9 5 4 3 2 7 */
    return 0;
}
