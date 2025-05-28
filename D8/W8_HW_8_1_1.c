/* プログラム8.1.1: 学籍番号11桁のチェックデジット検証 */
#include <stdio.h>

int main(void) {
   
    int id[11] = {2,1,8,0,2,5,0,1,8,4,3};
    int w[10] = {5,4,3,2,7,6,5,4,3,2};
    int sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += w[i] * id[i];
    }
    int cd = 11 - (sum % 11);
    if (cd == 11) cd = 0;       
    else if (cd == 10) cd = 10; 
    
    printf("計算したチェックデジット: %d\n", cd);
    printf("登録されているチェックデジット: %d\n", id[10]);
    if (cd == id[10]) {
        printf("正しいID\n");
    } else {
        printf("不正なID\n");
    }
    return 0;
}
/* 出力例
計算したチェックデジット: 3
登録されているチェックデジット: 3
正しいID
*/