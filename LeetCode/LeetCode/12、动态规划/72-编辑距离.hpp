// Created by Irving_yjx
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/Irving-yjx

#include <iostream>
using namespace std;

#include <vector>
#include <string>

#pragma mark - 方法一: 动态规划
int minDistance(string word1, string word2) {
    int m = (int)word1.size();
    int n = (int)word2.size();
    // dp[i][j]: 表示word1前i个字符到word2前j个字符的最少步数
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    for (int i = 0; i <= m; i++) dp[i][0] = i; // word1删除
    for (int j = 0; j <= n; j++) dp[0][j] = j; // word1插入
    // dp状态转移
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            // word1的第i个字符==word2的第j个字符
            if (word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
            // dp[i-1][j-1]=>替换 dp[i-1][j]=>删除 dp[i][j-1]=>插入
            else dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
        }
    }
    return dp[m][n];
}
