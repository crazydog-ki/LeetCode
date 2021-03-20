// Created by CoderJX
// Email  : jxyou.ki@gmail.com
// https://github.com/Irving-yjx

#include <iostream>
using namespace std;

#include <vector>

#pragma mark - 方法一: 动态规划
int climbStairs(int n) {
    if (n <= 2) return n;
    vector<int> dp(n+1, 0);
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++) dp[i] = dp[i-1] + dp[i-2];
    return dp[n];
}

void test() {
    cout << climbStairs(3) << endl;
}
