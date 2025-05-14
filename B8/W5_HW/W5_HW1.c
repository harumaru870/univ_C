#include <stdio.h>

int main(void) {
    int x;

    printf("整数を入力してください: ");
    if (scanf("%d", &x) != 1) {
        printf("数値以外が入力されました。\n");
        return 1;
    }

    x += 5;

    if (x % 3 == 0) {
        printf("%d は 3 の倍数です。\n", x);
    } else {
        printf("%d は 3 の倍数ではありません。\n", x);
    }

    return 0;
}