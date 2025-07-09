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

/* 関数プロトタイプ宣言 */
void load_students(Student students[], int *n, const char *filename);
void search_student(Student students[], int n);

int main(void) {
    Student students[MAX_STUDENTS];
    int n = 0;

    load_students(students, &n, "students_scores.csv");
    search_student(students, n);

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

void search_student(Student students[], int n) {
    char query[NAME_LEN];
    int found = 0;

    printf("検索したい学生の名前を入力してください > ");
    scanf("%19s", query);  // 安全のため最大入力長を制限

    for (int i = 0; i < n; i++) {
        if (strcmp(students[i].name, query) == 0) {
            printf("\n%s さんの成績:\n", students[i].name);
            printf("数学       : %d\n", students[i].math);
            printf("情報処理   : %d\n", students[i].info);
            printf("英語       : %d\n", students[i].english);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\n該当する学生が見つかりませんでした．\n");
    }
}
