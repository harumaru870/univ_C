#include <stdio.h>

int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main() {
    int a, b;
    printf("二つの自然数を入力してください: ");
    scanf("%d %d", &a, &b);

    if (gcd(a, b) == 1) {
        printf("互いに素です。\n");
    } else {
        printf("互いに素ではありません。\n");
    }

    return 0;
}