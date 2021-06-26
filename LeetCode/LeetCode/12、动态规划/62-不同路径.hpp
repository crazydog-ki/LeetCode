// Created by crazydog-ki
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/crazydog-ki

#include <iostream>
using namespace std;

#include <vector>

#pragma mark - 方法一: 动态规划
int uniquePaths(int m, int n) {
    // dp初始化: dp[0][j] = dp[i][0] = 1
    vector<vector<int>> dp(m, vector<int>(n, 1));
    // dp状态转移
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) dp[i][j] = dp[i][j-1] + dp[i-1][j];
    }
    return dp[m-1][n-1];
}
