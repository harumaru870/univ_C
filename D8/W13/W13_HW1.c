#include <stdio.h>

void adjust_point(int *n){
    /* 100 未満なら 100 を、それ以外はそのまま */
    if (*n < 100) {
        *n = 100;
    }
}

int main(void){
    int na = 256, nb = 13;
    int *ptr1 = &na, *ptr2 = &nb;

    adjust_point(ptr1);
    printf("%d\n", na);  /* 256 (そのまま) */
    adjust_point(ptr2);
    printf("%d\n", nb);  /* 13 < 100 → 100 に変更 */

    return 0;
}
