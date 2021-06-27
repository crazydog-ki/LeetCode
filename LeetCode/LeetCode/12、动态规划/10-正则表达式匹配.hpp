// Created by crazydog-ki
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/crazydog-ki

#include <iostream>
using namespace std;

#include <string>
#include <vector>

/**正则表达式匹配
 给你一个字符串s和一个字符规律p，请你来实现一个支持'.'和'*'的正则表达式匹配。
 '.' 匹配任意单个字符
 '*' 匹配零个或多个前面的那一个元素
 所谓匹配，是要涵盖整个字符串s的，而不是部分字符串。
 
 提示：
 （1）0 <= s.length <= 20
 （2）0 <= p.length <= 30
 （3）s可能为空，且只包含从a-z的小写字母
 （4）p可能为空，且只包含从a-z的小写字母，以及字符.和*
 （5）保证每次出现字符*时，前面都匹配到有效的字符
 */

#pragma mark - 方法1-暴力递归枚举
bool isMatch1(string s, string p) {
    if (p.size()==0) return s.empty();
    
    bool match = !s.empty() && (s[0]==p[0] || p[0]=='.');
    if (2<=p.size() && p[1]=='*') {
        return isMatch1(s, p.substr(2)) || (match && isMatch1(s.substr(1), p));
    } else return match && isMatch1(s.substr(1), p.substr(1));
}

#pragma mark - 方法2-dfs深度优先搜索
int sLen = 0;
int pLen = 0;
vector<vector<bool>> memo;
bool dfs(string &s, string &p, int i, int j) {
    // 已在cache缓存
    if (!memo[i][j]) return false;
    
    // 处理边界，dfs回溯出口
    if (i==sLen) {
        memo[i][j] = (j==pLen) || (j+1<pLen&&p[j+1]=='*'&&dfs(s, p, i, j+2));
        return memo[i][j];
    } else if(j==pLen) {
        memo[i][j] = false;
        return false;
    }
    
    if(s[i]==p[j] || p[j]=='.') {
        if(j+1<pLen && p[j+1]=='*') {
            memo[i][j] = dfs(s, p, i+1, j) || dfs(s, p, i+1, j+2) || dfs(s, p, i, j+2);
            return memo[i][j];
        } else {
            memo[i][j] = dfs(s, p, i+1, j+1);
            return memo[i][j];
        }
    } else {
        if(j+1<pLen && p[j+1]=='*') {
            memo[i][j] = dfs(s, p, i, j+2); // aba ac*ba
            return memo[i][j];
        } else {
            memo[i][j] = false;
            return false;
        }
    }
}

bool isMatch2(string s, string p) {
    sLen = (int)s.length();
    pLen = (int)p.length();
    
    // cache缓存
    memo = vector<vector<bool>>(sLen+1, vector<bool>(pLen+1, true));
    return dfs(s, p, 0, 0);
}

#pragma mark - 方法3-动态规划
bool isMatch3(string s, string p) {
    int sLen = (int)s.length();
    int pLen = (int)p.length();
    if (sLen!=0 && pLen==0) return false;
    vector<vector<bool>> dp(sLen+1, vector<bool>(pLen+1));
    dp[0][0] = true;
    for (int j = 1; j <= pLen; j++) dp[0][j] = (p[j-1]=='*' && dp[0][j-2]);
    for (int i = 1; i <= sLen; i++) {
        for (int j = 1; j <= pLen; j++) {
            // abbc abb.
            if (s[i-1]==p[j-1] || p[j-1]=='.') dp[i][j] = dp[i-1][j-1];
            else if (p[j-1] == '*') {
                if (s[i-1]==p[j-2] || p[j-2]=='.') {
                    // abbc ab*c              abc ab*c        abbbc ab*c
                    dp[i][j] = dp[i][j-2] || dp[i-1][j-2] || dp[i-1][j];
                } else {
                    // abbc abbcd*
                    dp[i][j] = dp[i][j-2];
                }
            }
        }
    }
    return dp[sLen][pLen];
}

void test() {
    
}
