#include <stdio.h>

int main(void) {
    int i, j, num;
    int tensu[100];         /* 最大100人まで読み込み可能 */
    int bunpu[11] = {0};    /* 0～9: bunpu[0], …, 90～99: bunpu[9], 100: bunpu[10] */

    /* 1. 人数と点数の読み込み */
    printf("Number of people? ");
    if (scanf("%d", &num) != 1 || num < 1 || num > 100) {
        puts("Invalid number of people.");
        return 1;
    }

    for (i = 0; i < num; i++) {
        printf("score of #%d? ", i + 1);
        scanf("%d", &tensu[i]);
        if (tensu[i] == 100) {
            bunpu[10]++;            /* 100点だけは10番目に */
        } else if (tensu[i] >= 0 && tensu[i] <= 99) {
            bunpu[tensu[i] / 10]++; /* 0–9→0, 10–19→1, …, 90–99→9 */
        } else {
            /* 範囲外の入力は無視 or エラー扱いにしてもよい */
        }
    }

    /* 2. 昇順で度数分布を出力 */
    puts("\n--Distribution chart--");
    for (i = 0; i <= 9; i++) {
        printf("%2d ~ %2d: ", i * 10, i * 10 + 9);
        for (j = 0; j < bunpu[i]; j++) {
            putchar('*');
        }
        putchar('\n');
    }
    /* 100点 */
    printf("  100: ");
    for (j = 0; j < bunpu[10]; j++) {
        putchar('*');
    }
    putchar('\n');

    return 0;
}
/* 出力例
Number of people? 6
score of #1? 12
score of #2? 45 
score of #3? 56
score of #4? 78
score of #5? 82 
score of #6? 91

--Distribution chart--
 0 ~  9: 
10 ~ 19: *
20 ~ 29: 
30 ~ 39: 
40 ~ 49: *
50 ~ 59: *
60 ~ 69: 
70 ~ 79: *
80 ~ 89: *
90 ~ 99: *
  100: 
*/