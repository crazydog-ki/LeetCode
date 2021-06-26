// Created by crazydog-ki
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/crazydog-ki

#include <iostream>
using namespace std;

#include <vector>

#pragma mark - 方法一: 动态规划
int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    if (obstacleGrid.empty() || obstacleGrid[0].empty()) return 0;
    int m = (int)obstacleGrid.size();
    int n = (int)obstacleGrid[0].size();
    vector<vector<long>> dp(m, vector<long>(n, 0));
    // dp初始化
    for (int i = 0; i < m; i++) {
        if (obstacleGrid[i][0] == 1) break;
        dp[i][0] = 1;
    }
    for (int j = 0; j < n; j++) {
        if (obstacleGrid[0][j] == 1) break;
        dp[0][j] = 1;
    }
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = (obstacleGrid[i][j]==1) ? 0 : dp[i-1][j]+dp[i][j-1];
        }
    }
    return (int)dp[m-1][n-1];
}
