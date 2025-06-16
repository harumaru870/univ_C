#include <stdio.h>

void rev_string(char s[]) {
    int i = 0;
    int len = 0;
    char temp;

    // まず文字列の長さを計算する
    while (s[len] != '\0') {
        len++;
    }

    // 文字列の先頭と末尾から文字を交換していく（ループは長さの半分まで）
    for (i = 0; i < len / 2; i++) {
        temp = s[i];
        s[i] = s[len - 1 - i];
        s[len - 1 - i] = temp;
    }
}

int main(void) {
    char str[128] = "information";
    rev_string(str);
    // 反転した文字列を表示
    printf("%s\n", str);
    return 0;
}
