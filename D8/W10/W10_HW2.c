#include <stdio.h>

/* m の 2 乗を返す */
int sqr(int m) {
    return m * m;
}

/* n の 4 乗を返す */
int power4(int n) {
    /* ① n を 2 乗 → ② さらにその結果を 2 乗 */
    int t = sqr(n);
    return sqr(t);
}

int main(void) {
    int a = 3;
    printf("%d\n", power4(a));  /* 実行例: 81 を出力 */
    return 0;
}
