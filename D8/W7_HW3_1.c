#include <stdio.h>

int main(void) {
    int h;
    printf("How many stacks do you make to draw an upside-down pyramid: ");
    if (scanf("%d", &h) != 1 || h <= 0) {
        return 1;
    }

    for (int i = 1; i <= h; i++) {
        int digit = i % 10;
        int count = 2 * (h - i + 1) - 1;

        // Print leading spaces
        for (int j = 0; j < i - 1; j++) {
            putchar(' ');
        }

        // Print the digits
        for (int j = 0; j < count; j++) {
            putchar('0' + digit);
        }
        putchar('\n');
    }

    return 0;
}

/*出力結果
How many stacks do you make to draw an upside-down pyramid: 4
1111111
 22222
  333
   4

*/