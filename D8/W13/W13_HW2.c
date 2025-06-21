#include <stdio.h>

void sort(int *a, int N){
    for (int i = 0; i < N - 1; i++) {
        // a[0]～a[N-i-1] の中から最大値の位置を探す
        int *max = a;               // 仮に最初を最大とする
        for (int *p = a; p < a + (N - i); p++) {
            if (*p > *max) {
                max = p;
            }
        }
        // 最大値を a[N-i-1] と交換
        int tmp = *(a + (N - i - 1));
        *(a + (N - i - 1)) = *max;
        *max = tmp;
    }
}

int main(void){
    int bb[] = {27, 19, 6, 13};
    sort(bb, 4);
    printf("When arranged in asending order: %d, %d, %d, %d\n",
           bb[0], bb[1], bb[2], bb[3]);
    return 0;
}
