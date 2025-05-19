#include <stdio.h>

// ユークリッドの互除法で最大公約数を求める関数
int gcd(int a, int b) {
    while (b != 0) {
        int tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

int main(void) {
    int x, y;
    printf("2つの整数を入力してください: ");
    scanf("%d %d", &x, &y);

    if (gcd(x, y) == 1) {
        printf("%d と %d は互いに素です。\n", x, y);
    } else {
        printf("%d と %d は互いに素ではありません。\n", x, y);
    }

    return 0;
}