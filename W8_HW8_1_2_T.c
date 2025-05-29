#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int id[11] = {2, 1, 8, 0, 2, 5, 0, 1, 8, 4, 3}; // 自分の学籍番号に置き換えてね
    int weights[10] = {5, 4, 3, 2, 7, 6, 5, 4, 3, 2};
    int i, sum = 0, cd, orig_cd = id[10];

    srand((unsigned)time(NULL));
    int k = rand() % 10; // 0～9のどれかの桁を選ぶ
    int new_digit;

    do {
        new_digit = rand() % 10;
    } while (new_digit == id[k]);

    id[k] = new_digit;

    for (i = 0; i < 10; i++) {
        sum += id[i] * weights[i];
    }

    cd = 11 - (sum % 11);
    if (cd == 11) cd = 0;

    printf("変更した桁: %d桁目 → %d\n", k + 1, new_digit);
    printf("再計算したCD: %d, 元のCD: %d\n", cd, orig_cd);

    if (cd != orig_cd) {
        printf("IDカードは不正です\n");
    } else {
        printf("IDカードは正当です\n");
    }

    return 0;
}
