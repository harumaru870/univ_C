#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LEN 20

typedef struct {
    char name[NAME_LEN];
    int math;
    int info;
    int english;
} Student;

void load_students(Student students[], int *n, const char *filename);
void print_stats_by_subject(Student students[], int n, int subject); 

int main(void) {
    Student students[MAX_STUDENTS];
    int n = 0;
    int subject;

    load_students(students, &n, "students_scores.csv");

    printf("\n--- 科目を選んでください ---\n");
    printf("0: 数学\n");
    printf("1: 情報処理\n");
    printf("2: 英語\n");
    printf("選択 > ");
    scanf("%d", &subject);

    if (subject < 0 || subject > 2) {
        printf("無効な選択です．\n");
        return 1;
    }

    print_stats_by_subject(students, n, subject);
    return 0;
}

void load_students(Student students[], int *n, const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("ファイルを開けません: %s\n", filename);
        exit(1);
    }

    char line[128];
    fgets(line, sizeof(line), fp);  // ヘッダを読み飛ばす

    while (fgets(line, sizeof(line), fp) != NULL) {
        sscanf(line, "%[^,],%d,%d,%d",
               students[*n].name,
               &students[*n].math,
               &students[*n].info,
               &students[*n].english);
        (*n)++;
    }
    fclose(fp);
}

void print_stats_by_subject(Student students[], int n, int subject) {
    int sum = 0, max = 0, min = 100;
    int score;
    const char *subject_name[] = {"数学", "情報処理", "英語"};

    for (int i = 0; i < n; i++) {
        switch (subject) {
            case 0: score = students[i].math;    break;
            case 1: score = students[i].info;    break;
            case 2: score = students[i].english; break;
        }
        sum += score;
        if (score > max) max = score;
        if (score < min) min = score;
    }

    printf("\n【%s】\n", subject_name[subject]);
    printf("平均: %.2f, 最高: %d, 最低: %d\n",
           (double)sum / n, max, min);
}
