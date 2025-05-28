#include <stdio.h>
#define MAX_PEOPLE 100

int main(void) {
    int i, j, num;
    int tensu[MAX_PEOPLE];
    int bunpu[11] = {0};  /* 0～9→bunpu[0]…90～99→bunpu[9], 100点→bunpu[10] */
    int max_count = 0;

    /* 1. 人数と点数の読み込み */
    printf("Number of people? ");
    if (scanf("%d", &num) != 1 || num < 1 || num > MAX_PEOPLE) {
        puts("Invalid number of people.");
        return 1;
    }
    for (i = 0; i < num; i++) {
        printf("score of #%d? ", i + 1);
        scanf("%d", &tensu[i]);
        if (tensu[i] == 100) {
            bunpu[10]++;
        } else if (tensu[i] >= 0 && tensu[i] <= 99) {
            bunpu[tensu[i] / 10]++;
        }
    }

    /* 2. 各ビンの最大カウントを求める */
    for (i = 0; i < 11; i++) {
        if (bunpu[i] > max_count) {
            max_count = bunpu[i];
        }
    }

    /* 3. 横向き分布図の出力 */
    puts("\n--Distribution chart--");
    /* 星を上から積み上げる */
    for (j = max_count; j > 0; j--) {
        for (i = 0; i < 11; i++) {
            if (bunpu[i] >= j) {
                /* ビンごとに幅3文字で"*"(星)を中央寄せで表示 */
                printf("  *");
            } else {
                printf("   ");
            }
        }
        putchar('\n');
    }
    /* 軸線 */
    for (i = 0; i < 11; i++) {
        printf("---");
    }
    putchar('\n');
    /* ラベル 0,10,20,…,100 */
    for (i = 0; i < 10; i++) {
        printf("%3d", i * 10);
    }
    printf("%4d\n", 100);

    return 0;
}
/*
Number of people? 6
score of #1? 12
score of #2? 31
score of #3? 56
score of #4? 78
score of #5? 89
score of #6? 100

--Distribution chart--
     *     *     *     *  *     *
---------------------------------
  0 10 20 30 40 50 60 70 80 90 100
*/