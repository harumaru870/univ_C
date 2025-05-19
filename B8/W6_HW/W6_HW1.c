#include <stdio.h>

int main() {
    int a, b, c;

    printf("三辺の長さを入力してください（スペース区切り）: ");
    scanf("%d %d %d", &a, &b, &c);

    // 三角形の成立条件
    if (a + b > c && a + c > b && b + c > a) {
        if (a == b && b == c) {
            printf("正三角形です。\n");
        } else if (a == b || b == c || a == c) {
            printf("二等辺三角形です。\n");
        } else {
            printf("それ以外の三角形です。\n");
        }
    } else {
        printf("三角形ではありません。\n");
    }

    return 0;
}