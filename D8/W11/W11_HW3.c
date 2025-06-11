#include <stdio.h>

/* 4×3 行列 a と 3×4 行列 b の積を 4×4 行列 c に格納 */
void mat_mul(const int a[][3], const int b[][4], int c[][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            c[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main(void) {
    int a[4][3] = {
        {1, 2, 3},
        {1, 2, 3},
        {1, 2, 3},
        {1, 2, 3}
    };
    int b[3][4] = {
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 1, 1}
    };
    int c[4][4];

    mat_mul(a, b, c);

    printf("c =\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%2d ", c[i][j]);
        }
        printf("\n");
    }
    /* 実行例:
       c =
        6  6  6  6
        6  6  6  6
        6  6  6  6
        6  6  6  6
    */
    return 0;
}
