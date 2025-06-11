#include <stdio.h>

/* 配列 v の要素数 n のうち最小値を返す */
int min_of(const int v[], int n) {
    int m = v[0];
    for (int i = 1; i < n; i++) {
        if (v[i] < m) m = v[i];
    }
    return m;
}

int main(void) {
    int v[] = {7, 2, 3, 4, 5};
    int n = sizeof(v) / sizeof(v[0]);
    printf("min = %d\n", min_of(v, n));  /* 実行例: min = 2 */
    return 0;
}
