#include <stdio.h>

int rec(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;
    return rec(n-1) + rec(n-3);
}

int main(void) {
    for (int n = 0; n <= 20; n++) {
        printf("a[%2d] = %d\n", n, rec(n));
    }
    return 0;
}
