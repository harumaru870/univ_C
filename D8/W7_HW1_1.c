#include <stdio.h>

int main(void) {
    int n;
    printf("How many asterisks do you display: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        return 1;
    }

    for (int i = 1; i <= n; i++) {
        putchar('*');
        if (i % 5 == 0) {
            putchar('\n');
        }
    }
    if (n % 5 != 0) {
        putchar('\n');
    }

    return 0;
}

/*出力結果

How many asterisks do you display: 12
*****
*****
**

*/