#include <stdio.h>

#define MAX_NUM 100

int main() {
    int is_composite[MAX_NUM + 1]; // 要素番号100までなので、サイズは101

    // 1. 配列を0に初期化する
    for (int i = 0; i <= MAX_NUM; i++) {
        is_composite[i] = 0;
    }

    // 2. 2から50までを順にカウントアップしながら、そのカウント数の2倍以上で100以下となる
    for (int i = 2; i <= MAX_NUM / 2; i++) { // iは2から50まで
        // iの倍数をマークする。jはi*2からiずつ増やしていく
        for (int j = i * 2; j <= MAX_NUM; j += i) {
            is_composite[j]++;
        }
    }

    // 3. 配列の全要素について、入っている値が0のものだけを表示する
    printf("100以下の素数:\n");
    for (int i = 2; i <= MAX_NUM; i++) {
        if (is_composite[i] == 0) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}
