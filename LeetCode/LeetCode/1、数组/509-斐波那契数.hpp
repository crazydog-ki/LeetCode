// Created by CoderJX
// Email  : jxyou.ki@gmail.com
// https://github.com/Irving-yjx

#include <iostream>
using namespace std;

#include <vector>
#include "tools.h"

#pragma mark - 方法二: 动态规划+优化内存
int fib2(int N) {
    if (N == 0) return 0;
    if (N == 1) return 1;
    int first = 0;
    int second = 1;
    int res = first + second;
    for (int i = 2; i <= N; i++) {
        res = first + second;
        first = second;
        second = res;
    }
    return res;
}

#pragma mark - 方法一: 动态规划
int fib(int N) {
    if (N == 0) return 0;
    if (N == 1) return 1;
    vector<int> dp(N+1, -1);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= N; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[N];
}

void test() {
    cout << fib2(5) << endl;
}
