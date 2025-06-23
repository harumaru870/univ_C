#include <stdio.h>
#include <math.h>

int max(int x, int y, int z) {
    int m = x > y ? x : y;
    return m > z ? m : z;
}

int min(int x, int y, int z) {
    int m = x < y ? x : y;
    return m < z ? m : z;
}

int sum(int x, int y, int z) {
    return x + y + z;
}

double average(int x, int y, int z) {
    return sum(x, y, z) / 3.0;
}

double variance(int x, int y, int z) {
    double avg = average(x, y, z);
    return ((x - avg) * (x - avg) + (y - avg) * (y - avg) + (z - avg) * (z - avg)) / 3.0;
}

int main() {
    int x, y, z;
    printf("3つの整数を入力してください: ");
    scanf("%d %d %d", &x, &y, &z);
    printf("最大値: %d\n", max(x, y, z));
    printf("最小値: %d\n", min(x, y, z));
    printf("合計値: %d\n", sum(x, y, z));
    printf("平均値: %.2f\n", average(x, y, z));
    printf("分散値: %.2f\n", variance(x, y, z));
    return 0;
} 
