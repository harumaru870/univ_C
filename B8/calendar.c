#include <stdio.h>

// 2. 閏年を判定する関数
int Leap(int year) {
    if (year % 400 == 0) return 1; // 400で割り切れる：閏年
    else if (year % 100 == 0) return 0; // 100で割り切れる：平年
    else if (year % 4 == 0) return 1; // 4で割り切れる：閏年
    else return 0; // いずれでもないので平年
}

// 3. 指定した年月の日数を求める関数
int DayMonth(int year, int month) {
    switch (month) {
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        case 2:
            return Leap(year) ? 29 : 28; // Leap関数を使い、閏年なら29日
        default:
            return 31;
    }
}

// 1. 曜日番号を求める関数
int Zeller(int year, int month, int day) {
    int Y, C;
    if (month == 1 || month == 2) {
        year--;
        month += 12;
    }
    C = year / 100;
    Y = year % 100;
    // ((day + (26 * (month + 1) / 10) + Y + Y/4 + 5 * C + C / 4) + 5) % 7
    // 上記の式は月曜=0,..,日曜=6となる
    return ((day + (26 * (month + 1) / 10) + Y + Y/4 + 5 * C + C / 4) + 5) % 7;
}

// 4. カレンダーを表示するmain関数
int main() {
    int year, month, day, i;
    int weekday, days_in_month;

    // 年と月を入力
    printf("西暦年を入力してください: ");
    scanf("%d", &year);
    printf("月を入力してください: ");
    scanf("%d", &month);

    // その月の1日の曜日と日数を計算
    weekday = Zeller(year, month, 1);
    days_in_month = DayMonth(year, month);

    // カレンダーのヘッダーを表示
    printf("\n %d年 %d月\n", year, month);
    printf(" Mon Tue Wed Thu Fri Sat Sun\n");

    // 1日の開始位置まで空白を表示
    for (i = 0; i < weekday; i++) {
        printf("    ");
    }

    // 1日から最終日まで日付を表示
    for (i = 1; i <= days_in_month; i++) {
        printf("%4d", i);
        // 現在の曜日が日曜(6)なら改行
        if ((weekday + i - 1) % 7 == 6) {
            printf("\n");
        }
    }
    printf("\n");

    return 0;
}
