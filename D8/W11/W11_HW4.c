#include <stdio.h>

void put_count(void) {
    static int i = 0;       /* 呼び出しごとに保持される */
    printf("put_count : %d\n", i++);
}

int main(void) {
    for (int k = 0; k < 5; k++) {
        put_count();
    }
    return 0;
}
