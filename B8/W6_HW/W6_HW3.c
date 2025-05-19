#include <stdio.h>

int main() {
    int number, absolute;

    printf("整数を入力してください: ");
    scanf("%d", &number);

    absolute = (number < 0) ? -number : number;

    printf("絶対値は: %d\n", absolute);

    return 0;
}