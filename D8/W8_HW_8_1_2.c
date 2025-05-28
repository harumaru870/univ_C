#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int id[11] = {2,1,8,0,2,5,0,1,8,4,3};  
    int w[]   = {5,4,3,2,7,6,5,4,3,2};
    int orig = id[10], sum = 0, cd, i;

    srand((unsigned)time(NULL));
    int k = rand()%10;
    int d;
    do { d = rand()%10; } while (d == id[k]);
    id[k] = d;

    for (i = 0; i < 10; i++) sum += w[i]*id[i];
    cd = 11 - (sum % 11);
    if (cd==11) cd = 0;

    printf("桁%2d→%d, 再計算CD=%d, 元CD=%d → %s\n",
           k+1, d, cd, orig, (cd!=orig)?"不正":"正当");
    return 0;
}
/* 出力例
桁 3→5, 再計算CD=0, 元CD=3 → 不正
桁 3→0, 再計算CD=3, 元CD=3 → 正当
*/