#include <stdio.h>
int Leap(int year) {
    if (year % 400 == 0) {
        return 1; // 400で割り切れる年は閏年
    } else if (year % 100 == 0) {
        return 0; // 100で割り切れる年は平年
    } else if (year % 4 == 0) {
        return 1; // 4で割り切れる年は閏年
    } else {
        return 0; // それ以外は平年
    }
}

int main() {
    int year;

    // ユーザーからの入力を受け取る
    printf("西暦年を入力してください: ");
    scanf("%d", &year);

    // Leap関数を呼び出して結果を判定
    if (Leap(year)) { // 戻り値が1 (true) の場合
        printf("%d年は閏年です。\n", year);
    } else { // 戻り値が0 (false) の場合
        printf("%d年は平年です。\n", year);
    }

    // --- 動作確認 ---
    printf("\n--- 動作確認 ---\n");
    int test_years[] = {2000, 1900, 2024, 2023};
    int i;
    for (i = 0; i < 4; i++) {
        if (Leap(test_years[i])) {
            printf("%d年 -> 閏年\n", test_years[i]);
        } else {
            printf("%d年 -> 平年\n", test_years[i]);
        }
    }

    return 0;
}
