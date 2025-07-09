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

int n_students;
int sort_subject;  // 0: math, 1: info, 2: english
Student students[MAX_STUDENTS];

int cmp_subject(const void *a, const void *b) {
    const Student *s1 = a;
    const Student *s2 = b;
    int sc1, sc2;
    switch (sort_subject) {
        case 0: sc1 = s1->math;    sc2 = s2->math;    break;
        case 1: sc1 = s1->info;    sc2 = s2->info;    break;
        case 2: sc1 = s1->english; sc2 = s2->english; break;
        default: sc1 = sc2 = 0;
    }
    return sc1 - sc2;
}

int load_students(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        fprintf(stderr, "ファイルを開けません: %s\n", filename);
        return -1;
    }
    char line[128];
    int count = 0;
    fgets(line, sizeof(line), fp);  // ヘッダ行を飛ばす
    while (fgets(line, sizeof(line), fp) && count < MAX_STUDENTS) {
        sscanf(line, "%[^,],%d,%d,%d",
               students[count].name,
               &students[count].math,
               &students[count].info,
               &students[count].english);
        count++;
    }
    fclose(fp);
    return count;
}

int main(void) {
    n_students = load_students("students_scores.csv");
    if (n_students < 0) return 1;

    printf("\n--- 科目を選んでください---\n");
    printf("0: 数学\n");
    printf("1: 情報処理\n");
    printf("2: 英語\n");
    printf("選択 > ");
    if (scanf("%d", &sort_subject) != 1 ||
        sort_subject < 0 || sort_subject > 2) {
        printf("無効な選択です．\n");
        return 1;
    }

    qsort(students, n_students, sizeof(Student), cmp_subject);

    const char *subject_name[] = {"数学", "情報処理", "英語"};
    printf("\n【%s の成績（昇順）】\n", subject_name[sort_subject]);
    for (int i = 0; i < n_students; i++) {
        int score = (sort_subject == 0 ? students[i].math
                   : sort_subject == 1 ? students[i].info
                   : students[i].english);
        printf("%s : %d\n", students[i].name, score);
    }
    return 0;
}
