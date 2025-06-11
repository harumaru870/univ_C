#include <stdio.h>

/* 横方向に '*' を n 個並べて表示 */
void print1(int n) {
    for (int i = 0; i < n; i++) {
        putchar('*');
    }
    putchar('\n');
}

int main(void) {
    int num = 10;
    print1(num);  /* 実行例: ********** を表示 */
    return 0;
}
