#include <stdio.h>
#include <stdlib.h> // For rand(), srand()
#include <time.h>   // For time()

// チェックデジット計算
// cd = 11 - ( (5*a + 4*b + ... + 2*j) mod 11 )
// 計算結果が11の場合は0、10の場合は10として返す
int calculate_rits_check_digit(const int first_ten_digits[10]) {
    int weights[10] = {5, 4, 3, 2, 7, 6, 5, 4, 3, 2};
    long long s = 0;
    for (int i = 0; i < 10; i++) {
        s += (long long)weights[i] * first_ten_digits[i];
    }
    int cd_value = 11 - (s % 11);
    if (cd_value == 11) {
        return 0;
    }
    return cd_value;
}

int main() {
    // 乱数生成
    srand(time(NULL));

    // 学籍番号（11桁）。
    const int hypothetical_student_id[11] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 3};


    int student_id_for_p2[11];
    // ループで配列をコピー
    for (int i = 0; i < 11; i++) {
        student_id_for_p2[i] = hypothetical_student_id[i];
    }

    // 元のIDの11桁目（チェックデジット）を保存
    int original_check_digit = student_id_for_p2[10];

    // IDの先頭10桁を格納・変更するための配列
    int modified_first_ten_digits[10];
    for (int i = 0; i < 10; i++) {
        modified_first_ten_digits[i] = student_id_for_p2[i];
    }

    // 先頭10桁のうち、ランダムに1つの桁を選ぶ
    int index_to_change = rand() % 10;
    int original_digit_value = modified_first_ten_digits[index_to_change];
    
    // 選んだ桁を、元の値とは異なる新しい値(0-9)に変更する
    int new_digit_value;
    do {
        new_digit_value = rand() % 10; // 0-9のランダムな値を生成
    } while (new_digit_value == original_digit_value); // 元の値と同じ場合は再生成
    
    modified_first_ten_digits[index_to_change] = new_digit_value;

    // 変更後の先頭10桁からチェックデジットを再計算
    int new_recalculated_cd = calculate_rits_check_digit(modified_first_ten_digits);

    // 新しいチェックデジットと元のチェックデジットを比較
    // 一致しなければ「IDカードは不正です」とだけ出力
    if (new_recalculated_cd != original_check_digit) {
        printf("IDカードは不正です\n");
    }
    // 一致した場合は、問題文の指示に従い何も出力しない

    return 0;
}
