#include <stdio.h>
#define NUMBER 1000

int main(void){
    int i;
    char a[][4]   = {"ABC", "DEF", "GHI"};
    char *ptr1[]  = {"abc", "def", "ghi"};
    char *ptr2[]  = {"Jkl", "mno", "pqr", "$$$"};  /* 区切り文字を末尾に配置 */

    /* 3 要素の配列 a を出力 */
    for (i = 0; i < 3; i++) {
        printf("%s\n", a[i]);
    }

    /* 3 要素の配列 ptr1 を出力 */
    for (i = 0; i < 3; i++) {
        printf("%s\n", ptr1[i]);
    }

    /* ptr2 の末尾 “$$$” が来るまでポインタでたどって出力 */
    for (char **p = ptr2; *p != "$$$"; p++) {
        printf("%s\n", *p);
    }

    return 0;
}
