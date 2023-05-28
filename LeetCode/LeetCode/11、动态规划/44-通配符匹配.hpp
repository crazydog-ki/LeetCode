// Created by crazydog-ki
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/crazydog-ki

#include <iostream>
using namespace std;

#include <string>
#include <vector>

/**通配符匹配
给定一个字符串(s)和一个字符模式(p)，实现一个支持'?'和‘*'的通配符匹配。
 
提示：
1. '?'可以匹配任何单个字符。
2. '*'可以匹配任意字符串（包括空字符串）。
3. 两个字符串完全匹配才算匹配成功。
 
说明：
1. s可能为空，且只包含从a-z的小写字母。
2. p可能为空，且只包含从a-z的小写字母，以及字符'?'和‘*'。
 */
#pragma mark - 方法1-动态规划
bool isMatch1(string s, string p) {
    int sLen = (int)s.length(), pLen = (int)p.length();
    /// dp[i][j]表示s的前i个字符和p的前j个字符能否匹配
    vector<vector<bool>> dp(sLen+1, vector<bool>(pLen+1, false));
    /// 构建临界条件
    /// 模式串、字符串均为空
    dp[0][0] = true;
    /// 模式串为空
    for (int k = 1; k <= sLen; k++) dp[k][0] = false;
    /// 字符串为空
    for (int m = 1; m <= pLen; m++) {
        dp[0][m] = dp[0][m-1] && p[m-1]=='*';
        if (dp[0][m] == false) break;
    }
    /// 基于状态转移方程动态规划
    for (int i = 1; i <= sLen; i++) {
        for (int j = 1; j <= pLen; j++) {
            if ('a'<=p[j-1] && p[j-1]<='z') dp[i][j] = dp[i-1][j-1] && s[i-1]==p[j-1];
            else if (p[j-1] == '?') dp[i][j] = dp[i-1][j-1];
            else if (p[j-1] == '*') dp[i][j] = dp[i][j-1] || dp[i-1][j];
        }
    }
    return dp[sLen][pLen];
}
#pragma mark - 方法2-贪心
bool isMatch(string s, string p) {
    
}
