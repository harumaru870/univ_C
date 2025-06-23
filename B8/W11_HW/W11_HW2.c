#include <stdio.h>
#include <stdlib.h> // abs() 関数のために必要
#include <limits.h> // ULLONG_MAX のために必要

// 非常に大きな数を扱うため、unsigned long long型を使用
typedef unsigned long long u_long_long;

// n番目のフィボナッチ数を計算する関数
// f0=1, f1=1, fn=fn-2+fn-1
u_long_long calculate_fibonacci(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }

    u_long_long f_prev2 = 1; // f(n-2)
    u_long_long f_prev1 = 1; // f(n-1)
    u_long_long f_current;

    for (int i = 2; i <= n; i++) {
        f_current = f_prev2 + f_prev1;
        f_prev2 = f_prev1;
        f_prev1 = f_current;
    }
    return f_current;
}

// nのk乗を計算する関数
u_long_long calculate_power(int base, int exp) {
    u_long_long result = 1;
    if (exp == 0) {
        return 1;
    }
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

int main(void) {
    int k;
    printf("整数kを入力してください: ");
    scanf("%d", &k);

    // 【修正点1】自明な解 n=1 を避けるため、n=2 から探索を開始する
    //           それに伴い、初期値をn=2の時の値に設定する
    int result_n = 2;
    u_long_long fib_val_init = calculate_fibonacci(2);
    u_long_long pow_val_init = calculate_power(2, k);
    u_long_long min_diff;

    if (fib_val_init > pow_val_init) {
        min_diff = fib_val_init - pow_val_init;
    } else {
        min_diff = pow_val_init - fib_val_init;
    }

    // 【修正点2】ループの開始を n=3 からに変更 (n=2は初期値として設定済み)
    for (int n = 3; n <= 100; n++) {
        u_long_long fib_val = calculate_fibonacci(n);
        u_long_long pow_val = calculate_power(n, k);

        // 差の絶対値を計算
        u_long_long current_diff;
        if (fib_val > pow_val) {
            current_diff = fib_val - pow_val;
        } else {
            current_diff = pow_val - fib_val;
        }
        
        // もし現在の差が最小なら、最小値とその時のnを更新
        if (current_diff < min_diff) {
            min_diff = current_diff;
            result_n = n;
        }
    }

    printf("フィボナッチ数fnとn^kの差が最小になる整数nは %d です。(n>1の範囲)\n", result_n);

    return 0;
}
