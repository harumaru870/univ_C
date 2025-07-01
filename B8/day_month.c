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

int DayMonth(int year, int month) {
    switch (month) {
        case 4: // 4, 6, 9, 11月は30日
        case 6:
        case 9:
        case 11:
            return 30;
        case 2: // 2月は閏年かどうかで日数が変わる
            if (Leap(year)) {
                return 29; // 閏年なら29日
            } else {
                return 28; // 平年なら28日
            }
        default: // それ以外の月は31日
            return 31;
    }
}

int main() {
    int year, month;

    // ユーザーからの入力を受け取る
    printf("西暦年を入力してください: ");
    scanf("%d", &year);
    printf("月を入力してください: ");
    scanf("%d", &month);

    // DayMonth関数を呼び出して結果を表示
    printf("\n%d年%d月は %d 日まであります。\n", year, month, DayMonth(year, month));

    // --- 動作確認 ---
    printf("\n--- 動作確認 ---\n");
    printf("2024年2月 -> %d日 (29ならOK)\n", DayMonth(2024, 2));
    printf("2023年2月 -> %d日 (28ならOK)\n", DayMonth(2023, 2));
    printf("2023年9月 -> %d日 (30ならOK)\n", DayMonth(2023, 9));
    printf("2023年10月 -> %d日 (31ならOK)\n", DayMonth(2023, 10));

    return 0;
}
