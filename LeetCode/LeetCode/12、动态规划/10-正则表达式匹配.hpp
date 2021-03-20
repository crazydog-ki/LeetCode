// Created by CoderJX
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/CoderJX

#include <iostream>
using namespace std;

#include <string>
#include <vector>

#pragma mark - 方法一: 动态规划
bool isMatch(string s,string p){
    int sLen = (int)s.length();
    int pLen = (int)p.length();
    vector<vector<bool>> dp(sLen+1, vector<bool>(pLen+1, false));
    // dp初始化
    dp[0][0] = true;
    for(int j = 2;j <= pLen;j++) dp[0][j] = (p[j-1]=='*'&&dp[0][j-2]);
    // dp状态转移
    for(int i = 0;i < sLen;i++){
        for(int j = 0;j < pLen;j++) {
            if(s[i]==p[j] || p[j]=='.') dp[i+1][j+1] = dp[i][j];
            else if(p[j] == '*') {
                // s多个b的情况 abb ab* dp[i+1][j+1] = dp[i][j+1]
                // s单个b的情况 ab  ab* dp[i+1][j+1] = dp[i+1][j]
                // s没有b的情况 a   a.* dp[i+1][j+1] = dp[i+1][j-1]
                if(s[i]==p[j-1] || p[j-1]=='.') dp[i+1][j+1] = dp[i][j+1] || dp[i+1][j] || dp[i+1][j-1];
                // a ab*
                else if(s[i] != p[j-1]) dp[i+1][j+1] = dp[i+1][j-1];
            }
        }
    }
    return dp[sLen][pLen];
}

