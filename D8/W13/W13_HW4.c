#include <stdio.h>

void str_copy(char *ss1, char *ss2){
    /* ss2 の文字を ss1 に '\0' までコピー */
    while (*ss1++ = *ss2++)
        ;  /* 代入結果が非ゼロ（'\0' でない）限り繰り返す */
}

int main(void) {
    char str1[128] = "DATA";
    char str2[128] = "123456789";

    str_copy(str1, str2);
    printf("str1=%s\n", str1);  /* str1=123456789 を出力 */

    return 0;
}
