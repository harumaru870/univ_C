#include <stdio.h>
int Zeller(int year, int month, int day) {
    int Y, C;
    int weekday;

    // 1月と2月は前年の13月、14月として扱う
    if (month == 1 || month == 2) {
        year--;
        month += 12;
    }

    // 西暦年の上2桁と下2桁を計算
    C = year / 100;
    Y = year % 100;

    // 指定された公式で曜日を計算
    weekday = ((day + (26 * (month + 1) / 10) + Y + Y/4 + 5 * C + C / 4) + 5) % 7;

    return weekday;
}

int main() {
    int year, month, day;
    int weekday;

    // ユーザーからの入力を受け取る
    printf("西暦年を入力してください: ");
    scanf("%d", &year);
    printf("月を入力してください: ");
    scanf("%d", &month);
    printf("日を入力してください: ");
    scanf("%d", &day);

    // Zeller関数を呼び出して曜日番号を取得
    weekday = Zeller(year, month, day);

    // 結果を表示
    printf("\n入力された %d年%d月%d日 の曜日番号は %d です。\n", year, month, day, weekday);
    printf("(月曜:0, 火曜:1, 水曜:2, 木曜:3, 金曜:4, 土曜:5, 日曜:6)\n");

    // 動作確認 (2020年6月27日 -> 5)
    printf("\n--- 動作確認 ---\n");
    int test_year = 2020, test_month = 6, test_day = 27;
    int test_weekday = Zeller(test_year, test_month, test_day);
    printf("%d年%d月%d日の曜日番号: %d (5が出ればOK)\n", test_year, test_month, test_day, test_weekday);

    return 0;
}
