#include <stdio.h>

/* 3つの整数 a, b, c のうち最小値を返す */
int min3(int a, int b, int c) {
    int m = a;
    if (b < m) m = b;
    if (c < m) m = c;
    return m;
}

int main(void) {
    int n1 = 3;
    int n2 = 10;
    int n3 = 6;
    printf("%d\n", min3(n1, n2, n3));  /* 実行例: 3 を出力 */
    return 0;
}
