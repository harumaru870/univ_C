#include <stdio.h>

/* 1 から n までの整数の和を返す */
int sumup(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    return sum;
}

int main(void) {
    int num = 10;
    printf("%d\n", sumup(num));  /* 実行例: 55 を出力 */
    return 0;
}
