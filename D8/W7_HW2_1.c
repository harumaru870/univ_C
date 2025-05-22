#include <stdio.h>
int main(void) {
    int h;
    printf("How many stacks do you make to draw a pyramid: ");
    if (scanf("%d", &h) != 1 || h <= 0) {
        return 1;
    }

    for (int i = 1; i <= h; i++) {
        int spaces = h - i;
        int stars = (i - 1) * 2 + 1;

        // Print spaces
        for (int j = 0; j < spaces; j++) {
            putchar(' ');
        }

        // Print stars
        for (int j = 0; j < stars; j++) {
            putchar('*');
        }

        putchar('\n');
    }

    return 0;
}
/*出力結果
How many stacks do you make to draw a pyramid: 5
    *
   ***
  *****
 *******
 
*/