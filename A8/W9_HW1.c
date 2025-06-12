#include <stdio.h>
#include <stdlib.h> // for malloc/free, not strictly needed for fixed size array but good practice
#include <math.h>   // for sqrt and pow

#define MAX_STUDENTS 10
#define NUM_SUBJECTS 2

int main() {
    int num_students;
    double scores[MAX_STUDENTS][NUM_SUBJECTS];

    // 学生数の入力
    printf("学生の人数を入力してください（1〜10人まで）：");
    scanf("%d", &num_students);

    if (num_students <= 0 || num_students > MAX_STUDENTS) {
        printf("無効な学生数です。1から%dの範囲で入力してください。\n", MAX_STUDENTS);
        return 1;
    }

    // テストの得点の入力
    printf("各学生の2科目の得点を入力してください。\n");
    for (int i = 0; i < num_students; i++) {
        printf("%d人目の学生の得点:\n", i + 1);
        for (int j = 0; j < NUM_SUBJECTS; j++) {
            printf("  科目%d: ", j + 1);
            scanf("%lf", &scores[i][j]);
            if (scores[i][j] < 0 || scores[i][j] > 100) {
                printf("得点は0〜100の範囲で入力してください。\n");
                return 1; // エラー終了
            }
        }
    }

    // 各科目の計算と結果の表示
    for (int j = 0; j < NUM_SUBJECTS; j++) { // 科目ごとにループ
        double min_score = 101.0; // 最小点初期値 (ありえない高い値)
        double max_score = -1.0;  // 最高点初期値 (ありえない低い値)
        double sum_score = 0.0;
        double average = 0.0;
        double variance = 0.0;

        printf("\n--- 科目%d の結果 ---\n", j + 1);

        // 最低点、最高点、合計点の計算
        for (int i = 0; i < num_students; i++) {
            double current_score = scores[i][j];
            if (current_score < min_score) {
                min_score = current_score;
            }
            if (current_score > max_score) {
                max_score = current_score;
            }
            sum_score += current_score;
        }

        // 平均点の計算
        average = sum_score / num_students;

        // 分散の計算
        for (int i = 0; i < num_students; i++) {
            variance += pow(scores[i][j] - average, 2);
        }
        variance /= num_students;

        // 結果の出力
        printf("  最低点: %.2f\n", min_score);
        printf("  最高点: %.2f\n", max_score);
        printf("  平均点: %.2f\n", average);
        printf("  分散:   %.2f\n", variance);
    }

    return 0;
}
