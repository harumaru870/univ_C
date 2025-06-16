#include <stdio.h>

int str_char(const char s[], int c) {
    int i = 0;
    // 文字列の終わり（ヌル文字）までループ
    while (s[i] != '\0') {
        // 文字が見つかった場合
        if (s[i] == c) {
            // 1から始まるインデックスを返す
            return i + 1;
        }
        i++;
    }
    // 文字が見つからなかった場合
    return 0;
}

int main(void) {
    char str1[128] = "incformation";
    char str2[128] = "infformation";
    int index;

    index = str_char(str1, 'c');
    printf("%d\n", index);

    index = str_char(str2, 'c');
    printf("%d\n", index);

    return 0;
}
