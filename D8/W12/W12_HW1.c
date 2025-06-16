#include <stdio.h>

void null_string(char s[]) {
    // 文字列の先頭にヌル文字を代入する
    s[0] = '\0';
}

int main(void) {
    char str[128] = "information";
    null_string(str);
    printf("%s\n", str);
    printf("finish\n");
    return 0;
}
